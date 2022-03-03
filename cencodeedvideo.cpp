#include "cencodeedvideo.h"

CEncodeedVideo::CEncodeedVideo()
{
    qq=SingleQQ::getInstace();
    db=SingleDB::getInstance();
}

void CEncodeedVideo::initEncode(int Width, int Height)
{
    this->Width = Width;
    this->Height = Height;
}

void CEncodeedVideo::SetFileName(QString FileName)
{
    qDebug()<<FileName;
    av_register_all();
    fmatc=avformat_alloc_context();
    AVOutputFormat *avfmat = av_guess_format(nullptr,FileName.toStdString().c_str(),nullptr);
    if(avfmat == nullptr)
    {
        qDebug()<<"guess failed";
        return;
    }
    fmatc->oformat = avfmat;
    int ret = -1;
    ret = avio_open(&fmatc->pb,FileName.toStdString().c_str(),AVIO_FLAG_WRITE);
    if(ret < 0)
    {
        qDebug()<<"acio_open failed";
        return;
    }

    AVStream *Out_stream = avformat_new_stream(fmatc,nullptr);

    if(Out_stream == nullptr)
    {
        qDebug()<<"new stream failed";
        return;
    }

    acodec=Out_stream->codec;
    acodec->width = Width;
    acodec->height = Height;
    acodec->bit_rate = 400000;
    acodec->time_base={1,25};
    acodec->framerate={25,1};
    acodec->gop_size = 10;
    acodec->qmax = 51;
    acodec->qmin = 10;
    acodec->max_b_frames=1;
    acodec->pix_fmt=AV_PIX_FMT_YUV420P;
    acodec->codec_type = AVMEDIA_TYPE_VIDEO;
    acodec->codec_id = avfmat->video_codec;

    AVCodec *code = avcodec_find_encoder(acodec->codec_id);
    if(code == nullptr)
    {
        qDebug()<<"find encode failed";
        return;
    }

    ret = avcodec_open2(acodec,code,nullptr);
    if(ret != 0)
    {
        qDebug()<<"avcodec open2 failed";

    }

    ret = avformat_write_header(fmatc,nullptr);
    if(ret < 0)
    {
        qDebug()<<"avcodec open2 failed";
        return;
    }

    pkt = av_packet_alloc();
}

void CEncodeedVideo::encodeFrame(AVFrame *frame)
{
    int ret = -1;
    ret = avcodec_send_frame(acodec,frame);
    if(ret < 0)
    {
        qDebug()<<"send frame failed";
        return;
    }

    while(ret >= 0)
    {
        ret =avcodec_receive_packet(acodec,pkt);;
        if(ret == AVERROR(EAGAIN)|| ret ==AVERROR_EOF)
        {
            return;
        }
        else if (ret < 0)
        {
            qDebug()<<"receive pkt failed";
            return;
        }
        av_interleaved_write_frame(fmatc,pkt);
        av_packet_unref(pkt);
    }
}

void CEncodeedVideo::write_trailer()
{
    av_write_trailer(fmatc);
}

void CEncodeedVideo::CloseLiu()
{
    avformat_close_input(&fmatc);
}


void CEncodeedVideo::run()
{
//    while (1)
//    {
//        this->encodeFrame(this->qq->getQueueFrame()->dequeue());
//        if(Count == 500)
//        {
//            VideoTemp=this->db->getFlag(tool.GetNowTime());
//            this->write_trailer();
//            this->SetFileName(QString("E:/VideoPath/%1-%2.h264").arg(tool.GetNowTime()).arg(VideoTemp));
//            this->db->SettoTable(QString("%1-%2").arg(tool.GetNowTime()).arg(VideoTemp),"E:/VideoPath/",tool.GetNowTime());
//            Count = 0;
//        }
//        Count++;
//    }
}


