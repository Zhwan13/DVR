#include "cdecode.h"

CDecode *CDecode::instance=nullptr;
CDecode *CDecode::getInstance()
{
    if(CDecode::instance==nullptr)
    {
        instance=new CDecode();
    }
    return instance;
}
CDecode::CDecode()
{
    EncodeVideo=new CEncode();
    registerFFMPEG();
    initValue();
}
/*******************
 * 功能：注册组件
 * ***********/
void CDecode::registerFFMPEG()
{
    av_register_all();//注册组件
    avdevice_register_all();
}

void CDecode::initValue()
{
    ret=-1;
    videoIndex =-1;
    FrameCount=0;

//    codec->bit_rate=0;//初始化为0
//    codec->time_base.num=1;  //下面两行：一秒钟25帧
//    codec->time_base.den=10;
//    codec->frame_number=1;//每包一个视频帧
}

/*******************
 * 功能：对摄像头数据进行解码并发送到主界面
 * ***********/
void CDecode::openStreaming()
{

    QString videoDir=model->getvideoDir();
//    if(videoDir.isEmpty()||videoDir.isEmpty())
//        SaveImgPath=QString("D:/DVR/VideoFirstImg");//默认创建位置
//    else
        SaveImgPath=QString("%1").arg(videoDir);//第一帧保存路径和视频一样
    QDir dir(SaveImgPath);
        if(!dir.exists())
        {
            if(dir.mkdir(SaveImgPath))
            {
                qDebug()<<"creat videofile succeed";
            }
        }
    fmatC=avformat_alloc_context();

    //打开输入视频文件
    AVDictionary *options=NULL;
    av_dict_set_int(&options,"rtbufsize",3041280*10,0);
    AVInputFormat *fmt=av_find_input_format("dshow");//封装格式结构体

    //获取摄像头名字
    QString video="video="+model->getCameraInfo();
    char *ch=const_cast<char *>((video.toStdString()).c_str());

    ret=avformat_open_input(&fmatC,ch,fmt,&options);
    if(ret!=0)
    {
        qDebug()<<"camera open failed";
        return;
    }
    //查看是否有流媒体信息
    ret=avformat_find_stream_info(fmatC,NULL);
    if(ret<0)
    {
        qDebug()<<"find info failed!";
        return;
    }
    for(int i=0;i<fmatC->nb_streams;i++)//nb_streams表示流信息，是音频还是视频
    {
        if(fmatC->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoIndex =i;
            break;
        }
    }
    if(videoIndex==-1)//如果videoIndex为-1 说明没有找到视频流
    {
        qDebug()<<"find video index failed";
        return;
    }
    codec=fmatC->streams[videoIndex]->codec;//编码器上下文结构体
    this->openDecode();
    this->DecodeFrame();
}

void CDecode::openDecode()
{
    //查找解码器
    code= avcodec_find_decoder(codec->codec_id);//编码器结构体，每个编码器对应一个该结构体
    if(code==NULL)
    {
        qDebug()<<"find decoder failed";
        return ;
    }

    //open解码器
    ret=avcodec_open2(codec,code,NULL);
    if(ret!=0)
    {
        qDebug()<<"code open failed";
        return;
    }
}
void CDecode::DecodeFrame()
{
    //read
    size=codec->width*codec->height;
    pkt =(AVPacket *)malloc((sizeof (AVPacket)));

    picture=av_frame_alloc();
    dstFrame=av_frame_alloc();
    dstFrameRGB=av_frame_alloc();

    EncodeVideo->initEncode(codec->width,codec->height);
    EncodeVideo->SetFileName(QString("%1/%2-%3.h264").arg(model->getvideoDir()).arg(model->getNowtimeStr()).arg(VideoFlag));;

    dstFrame->width = codec->width;
    dstFrame->height = codec->height;
    dstFrame->format = codec->pix_fmt;
    dstFrameRGB->width = codec->width;
    dstFrameRGB->height = codec->height;
    dstFrameRGB->format = codec->pix_fmt;

    //初始化YUV算法
    numbyte=avpicture_get_size(AV_PIX_FMT_YUV420P,codec->width,codec->height);
    uint8_t *buffer=(uint8_t*)av_malloc(numbyte*sizeof(uint8_t));//类似缓存的作用
    avpicture_fill((AVPicture *)dstFrame,buffer,AV_PIX_FMT_YUV420P,codec->width,codec->height);
    SwsContext *sws_contex_yuv=sws_getContext(codec->width,codec->height,
                                              codec->pix_fmt,codec->width,codec->height,
                                              AV_PIX_FMT_YUV420P,SWS_BICUBIC,NULL,NULL,NULL);
    //初始化RGB算法
    numbyte=avpicture_get_size(AV_PIX_FMT_RGB32,codec->width,codec->height);
    uint8_t *bufferRGB=(uint8_t*)av_malloc(numbyte*sizeof(uint8_t));//类似缓存的作用
    avpicture_fill((AVPicture *)dstFrameRGB,bufferRGB,AV_PIX_FMT_RGB32,codec->width,codec->height);
    SwsContext *sws_contex_rgb=sws_getContext(codec->width,codec->height,
                                          codec->pix_fmt,codec->width,
                                          codec->height,AV_PIX_FMT_RGB32,
                                          SWS_BICUBIC,NULL,NULL,NULL);
    av_new_packet(pkt,size);//分配packet的数据

    //从输入文件读取一帧压缩数据。
//    int saveflag=0;
//    int index=1;

    while(av_read_frame(fmatC,pkt)==0)//读一帧
    {
        if(pkt->stream_index==videoIndex)
        {
            got_picture_ptr=-1;
            ret=avcodec_decode_video2(codec,picture,&got_picture_ptr,pkt);
            if(ret<0)
            {
                qDebug()<<"decode error.\n";
                return;
            }
            if(got_picture_ptr)
            {//当没有帧可以解压时，得到的got_picture_ptr是0，否则是非0
                //convert
                sws_scale(sws_contex_yuv,
                          picture->data,picture->linesize,0,picture->height,
                          dstFrame->data,dstFrame->linesize);
                dstFrame->pts++;
                EncodeVideo->encodeFrame(dstFrame);//编码

                sws_scale(sws_contex_rgb,
                          picture->data,picture->linesize,0,picture->height,
                          dstFrameRGB->data,dstFrameRGB->linesize);
                QImage img((uchar *)bufferRGB,codec->width,codec->height,QImage::Format_RGB32);

                if(FrameCount == 25*((model->getTime()).toInt()))
                {
                    VideoFlag=model->getvideosCount();//获取视频的数量，用于视频命名，作为区分位
                    EncodeVideo->write_trailer();
                    EncodeVideo->CloseLiu();
                    EncodeVideo->SetFileName(QString("%1/%2-%3.h264").arg(model->getvideoDir()).arg(model->getNowtimeStr()).arg(VideoFlag));
//                    //写入文件名
                    model->InserttVideo(QString("%1-%2").arg(model->getNowtimeStr()).arg(VideoFlag),model->getvideoDir());
                    FrameCount = 0;
                }
                if(this->FrameCount == 0)
                {
                    img.save(QString("%1/%2-%3.png").arg(SaveImgPath).arg(model->getNowtimeStr()).arg(VideoFlag));//年月日+区分位
                }
                emit sendImgSignal(img);
            }
        }
        this->FrameCount++;
        av_packet_unref(pkt);//释放pkt
        msleep(0.02); //停一停  不然放的太快了
    }
    this->CloseSpace();
}

void CDecode::CloseSpace()
{
    av_free(fmatC);
    avformat_close_input(&fmatC);
    //    avcodec_close(codec);
    av_packet_free(&pkt);
}


void CDecode::run()
{
    this->openStreaming();
}
