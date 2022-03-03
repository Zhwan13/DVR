#include "CEncode.h"

CEncode::CEncode()
{
//    pkt_index=0;
}



/*******************
 * 函数功能：初始化编码
 * ************/
void CEncode::initEncode(int width,int height)
{
    this->Width=width;
    this->Height=height;
}

void CEncode::SetFileName(QString filename)
{
    int ret=-1;

    av_register_all();//注册所有组件

    fmatc=avformat_alloc_context();//给封装格式上下文结构体开空间

//    qDebug()<<filename;
    AVOutputFormat *avofmat=av_guess_format(NULL,filename.toStdString().c_str(),NULL);//猜测是否有目标格式的编码器
    if(NULL==avofmat)//如果没有
    {
        qDebug()<<"Guess failed";
        return;
    }

    fmatc->oformat=avofmat;
    ret=avio_open(&fmatc->pb,filename.toStdString().c_str(),AVIO_FLAG_WRITE);
    if(ret<0){
        qDebug()<<"avio open failed";
        return;
    }

    //新建流
    AVStream *out_stream=avformat_new_stream(fmatc,NULL);
    if(NULL==out_stream)
    {
        qDebug()<<"new stream failed";
        return;
    }
//    codec=avcodec_alloc_context3();
    codec= out_stream->codec;
    codec->width=this->Width;
    codec->height=this->Height;
    codec->bit_rate=400000;//码率,码率越大，视频越大
    codec->time_base={1,25};//帧率
    codec->framerate={25,1};//与帧率相反
    codec->gop_size=10;//每组图片的数量
    codec->qmax=51;
    codec->qmin=10;//越小越清晰
    codec->max_b_frames=1;//设置需要b帧
    codec->pix_fmt=AV_PIX_FMT_YUV420P;
    codec->codec_type=AVMEDIA_TYPE_VIDEO;
    codec->codec_id=avofmat->video_codec;

    //查找编码器
    AVCodec *code=avcodec_find_encoder(codec->codec_id);
    if(code==NULL)
    {
        qDebug()<<"find encoder failed";
        return;
    }

    //打开编码器
    ret=avcodec_open2(codec,code,NULL);
    if(ret!=0){
        qDebug()<<"avcodec open failed";
        return;
    }
    //写头文件
    ret=avformat_write_header(fmatc,NULL);
    if(ret<0)
    {
        qDebug()<<"write header failed";
        return;
    }
    //给AVPacket码流数据pkt开空间
    pkt=av_packet_alloc();
}
/***************
*函数功能：编码一帧
*参数:YUV格式的AVframe,一帧
****************/
void CEncode::encodeFrame(AVFrame *frame)
{
    int ret=-1;
    ret=avcodec_send_frame(codec,frame);//发送一帧
    if(ret<0){
        qDebug()<<"send frame failed";
        return ;
    }
    while(ret>=0)
    {
//        frame->pts=pkt_index++;//显示时间基
        ret= avcodec_receive_packet(codec,pkt);// 接收,与avcodec_send_frame()配套使用
        if(ret==AVERROR(EAGAIN)||ret==AVERROR_EOF)
        {
            return;
        }
        else if(ret<0){
            qDebug()<<"receive pkt failed";
            return;
        }
//        pkt->stream_index=0;

        ret=av_interleaved_write_frame(fmatc,pkt);//写入一帧
        if(ret!=0)
        {
            qDebug()<<"write failed";
            return;
        }
//        qDebug()<<"encode a frame";
         av_packet_unref(pkt);
    }

}
/*********************
 * 函数功能：写文件尾巴
 * *****************/
void CEncode::write_trailer()
{
    av_write_trailer(fmatc);
}

void CEncode::CloseLiu()
{
    avformat_close_input(&fmatc);
}

//void CEncode::run()
//{

//}
