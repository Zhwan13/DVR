#include "decodevideo.h"

DecodeVideo::DecodeVideo()
{
    this->EncodeVideo = new CEncodeedVideo();
    this->RegisterAll();
    this->InitValue();
    this->db = SingleDBOption::getInstance();;
}

void DecodeVideo::RegisterAll()
{
    av_register_all();
    avdevice_register_all();
}

void DecodeVideo::InitValue()
{
    ret = -1;
    VideoIndex = -1;
    ImgeFlag = 25;
    FrameCount = 0;
    ImgeNumber = 0;
    DecodeFlag = 0;
    H264File =  nullptr;
    YuvFile = nullptr;
}

void DecodeVideo::OpenStreaming()
{
    SaveImgPath=QString("%1/VideoFirstImg").arg(db->RenturnVideoPath());
    qDebug()<<SaveImgPath;
    QDir dir(SaveImgPath);
    if(!dir.exists())
    {
        if(dir.mkdir(SaveImgPath))
        {
            qDebug()<<"succeed";
        }
    }
    Fmatc = avformat_alloc_context();
    AVInputFormat *fmt = av_find_input_format("dshow");

    AVDictionary *options = nullptr;
    av_dict_set_int(&options,"rtbufsize",3041280*10,0);
//    QString CameraName = QString("video=%1").arg(tool.GetCarameName(0));
    QString CameraName ="video=USB2.0 VGA UVC WebCam";
    qDebug()<<CameraName;
    ret = avformat_open_input(&Fmatc,CameraName.toStdString().c_str(),fmt,&options);
    if(ret != 0)
    {
        qDebug()<<"avformat open input error";
        return;
    }
    ret = avformat_find_stream_info(Fmatc,nullptr);
    if(ret < 0)
    {
        qDebug()<<"find info failed!";
        return;
    }
    for(int i=0;i<this->Fmatc->nb_streams;i++)
    {   // nb_streams -- 流媒体数量
        if(this->Fmatc->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO){
           VideoIndex = i;
            break ;
        }
    }
    if(VideoIndex == -1)
    {
        qDebug()<<"find video index failed!";
        return ;
    }

    Codec = this->Fmatc->streams[VideoIndex]->codec;
    this->OpenDecode();
    this->DecodeFrame();
}

void DecodeVideo::OpenDecode()
{
    Code = avcodec_find_decoder(Codec->codec_id);
    if(Code == NULL)
    {
        qDebug()<<"find decode failed!";
        return ;
    }
    ret = avcodec_open2(Codec,Code,NULL);
    if(ret != 0)
    {
        qDebug()<<"open coder failed!";
        return;
    }
}

void DecodeVideo::DecodeFrame()
{
    FrameSize = Codec->width*Codec->height;
    this->Pkt = (AVPacket *)malloc(sizeof(AVPacket));
    this->Picture = av_frame_alloc();
    this->DstFrame = av_frame_alloc();
    this->DstFrameRGB = av_frame_alloc();

    this->EncodeVideo->initEncode(Codec->width,Codec->height);
    VideoFlag=this->db->getFlag(tool.GetNowTime());
    this->EncodeVideo->SetFileName(QString("%1/%2-%3.h264").arg(db->RenturnVideoPath()).arg(tool.GetNowTime()).arg(VideoFlag));
    this->db->SettoTable(QString("%1-%2").arg(tool.GetNowTime()).arg(VideoFlag),db->RenturnVideoPath(),tool.GetNowTime());
    DstFrame->width = Codec->width;
    DstFrame->height = Codec->height;
    DstFrame->format = Codec->pix_fmt;
    DstFrameRGB->width = Codec->width;
    DstFrameRGB->height = Codec->height;
    DstFrameRGB->format = Codec->pix_fmt;

    NumByte = avpicture_get_size(AV_PIX_FMT_YUV420P,Codec->width,Codec->height);
    uint8_t *buffer = (uint8_t *)av_malloc(NumByte * sizeof(uint8_t));
    avpicture_fill((AVPicture *)DstFrame,buffer,AV_PIX_FMT_YUV420P,Codec->width,Codec->height);
    SwsContext *sws_context_YUV = sws_getContext(Codec->width,Codec->height,Codec->pix_fmt,
                                                 Codec->width,Codec->height,AV_PIX_FMT_YUV420P,
                                                 0,nullptr,nullptr,nullptr);

    NumByte = avpicture_get_size(AV_PIX_FMT_RGB32,Codec->width,Codec->height);
    uint8_t *bufferRGB = (uint8_t *)av_malloc(NumByte * sizeof(uint8_t));
    avpicture_fill((AVPicture *)DstFrameRGB,bufferRGB,AV_PIX_FMT_RGB32,Codec->width,Codec->height);
    SwsContext *sws_context_RGB = sws_getContext(Codec->width,Codec->height,Codec->pix_fmt,
                                                 Codec->width,Codec->height,AV_PIX_FMT_RGB32,
                                                 0,nullptr,nullptr,nullptr);

    av_new_packet(Pkt,FrameSize);
    while((ret = av_read_frame(Fmatc,Pkt)) == 0 )
    {
        if(Pkt->stream_index == VideoIndex)
        {
            GotPicture = -1;
            avcodec_decode_video2(Codec,Picture,&GotPicture,Pkt);
            if(GotPicture)
            {
                sws_scale(sws_context_YUV,Picture->data,Picture->linesize,0,Picture->height,
                          DstFrame->data,DstFrame->linesize);
                DstFrame->pts++;
                EncodeVideo->encodeFrame(DstFrame);
//                if(StartFlag&&FrameCount == 50)
//                {
//                    EncodeVideo->start();
//                    StartFlag=false;
//                }
                sws_scale(sws_context_RGB,Picture->data,Picture->linesize,0,Picture->height,
                          DstFrameRGB->data,DstFrameRGB->linesize);
                QImage img((uchar *)bufferRGB,Codec->width,Codec->height,QImage::Format_RGB32);

                if(FrameCount == 25*(db->ReturnTime().toInt()))
                {
                    VideoFlag=this->db->getFlag(tool.GetNowTime());
                    EncodeVideo->write_trailer();
                    EncodeVideo->CloseLiu();
                    EncodeVideo->SetFileName(QString("%1/%2-%3.h264").arg(db->RenturnVideoPath()).arg(tool.GetNowTime()).arg(VideoFlag));
                    this->db->SettoTable(QString("%1-%2").arg(tool.GetNowTime()).arg(VideoFlag),db->RenturnVideoPath(),tool.GetNowTime());
                    FrameCount = 0;
                }
                if(this->FrameCount == 0)
                {
                    img.save(QString("%1/%2-%3.png").arg(SaveImgPath).arg(tool.GetNowTime()).arg(VideoFlag));
                    qDebug()<<"ok";
                }

//                if(this->TakePhotoBtnFlag == 1)
//                {
//                    Sleep(2000);
//                    img.save("E:/Video/1.jpg");
//                    this->TakePhotoBtnFlag = 0;
//                }
                emit Sendimg(img);
                qDebug()<<"send img success";
            }
        }
        this->FrameCount++;
        av_packet_unref(Pkt);
    }

    this->CloseSpace();

}

void DecodeVideo::CloseSpace()
{
    av_free(Fmatc);
    avformat_close_input(&Fmatc);
    av_packet_free(&Pkt);
}


void DecodeVideo::run()
{
    this->OpenStreaming();
}


