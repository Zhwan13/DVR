#include "FTranscode.h"

FTranscode::FTranscode()
{
    fmatc=avformat_alloc_context();//fmatc用来存输入的codec
}

FTranscode::~FTranscode()
{
    avformat_close_input(&fmatc);
    av_free(fmatc);
}
/*******************
 * 功能：打开文件
 * ***********/
void FTranscode::openH264File(QString h264File)
{
    int ret=-1;
    av_register_all();

    ret=avformat_open_input(&fmatc,h264File.toStdString().c_str(),NULL,NULL);
    if(ret<0)
    {
        qDebug()<<"open_input failed";
        return;
    }
    ret=avformat_find_stream_info(fmatc,NULL);//查找视频流信息
    if(ret<0)
    {
        qDebug()<<"find failed";
        return;
    }
    video_index=-1;
    for(int i=0;i<fmatc->nb_streams;i++)
    {
        if(fmatc->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            video_index=i;//找到视频流对应的index
            break;
        }
    }
    if(-1==video_index)
    {
        qDebug()<<"find_video_index failed";
        return;
    }
    qDebug()<<"init input file success";
    //读取一帧数据
}
/*******************
 * 功能：输出视频文件
 * ***********/
void FTranscode::outToDst(QString dstFile)
{
    AVFormatContext *outFmat=avformat_alloc_context();//封装
    AVPacket* pkt=(AVPacket *)av_malloc(sizeof(AVPacket));
//    qDebug()<<dstFile;
    AVOutputFormat *out_avfmat=av_guess_format(NULL,dstFile.toStdString().c_str(),NULL);//编码格式
    if(NULL==out_avfmat)//猜测
    {
        qDebug()<<"guess format failed";
        return;
    }
    outFmat->oformat=out_avfmat;
    AVStream *out_stream=avformat_new_stream(outFmat,NULL);
    AVStream *in_stream=fmatc->streams[video_index];
    if(NULL==out_stream)
    {
        qDebug()<<"AVStream new stream failed";
        return;
    }
    //初始化参数
    out_stream->codec=in_stream->codec;
    out_stream->codec->codec_tag=0;
    out_stream->codec->flags=in_stream->codec->flags;
    out_stream->codec->time_base.num=in_stream->avg_frame_rate.den;
    out_stream->codec->time_base.den=in_stream->avg_frame_rate.num;

    int ret=avio_open(&outFmat->pb,dstFile.toStdString().c_str(),AVIO_FLAG_WRITE);
    if(ret<0)
    {
        qDebug()<<"avio_open failed\n";
        return;
    }
    ret=avformat_write_header(outFmat,NULL);
    if(ret<0)
    {
        qDebug()<<"write_header failed\n";
        return;
    }
    int frameCount=0;
    while(av_read_frame(fmatc,pkt)>=0)
    {
        if(pkt->stream_index==video_index)
        {
            frameCount++;
//            qDebug()<<"frame:"<<frameCount;
            if(AV_NOPTS_VALUE==pkt->pts)
            {
                AVRational time_basel= in_stream->time_base;
                //两帧之间的持续时间
                int64_t calc_duration=(double)AV_TIME_BASE/av_q2d(in_stream->r_frame_rate);
                pkt->pts=(double)(frameCount*calc_duration)/
                        (double)(av_q2d(time_basel)*AV_TIME_BASE);
                pkt->dts=pkt->pts;
                pkt->duration=(double)calc_duration
                        /(double)(av_q2d(time_basel)*AV_TIME_BASE);
            }
            //转换算法（固定的）-设置时间基
            pkt->pts=av_rescale_q_rnd(pkt->pts,
                                      in_stream->time_base,
                                    out_stream->time_base,
                                    (AVRounding)(AV_ROUND_INF|AV_ROUND_PASS_MINMAX));//时间基转换，
            pkt->dts=av_rescale_q_rnd(pkt->dts,
                                      in_stream->time_base,
                                    out_stream->time_base,
                                    (AVRounding)(AV_ROUND_INF|AV_ROUND_PASS_MINMAX));//时间基转换，
            pkt->duration=av_rescale_q(pkt->duration,
                                       in_stream->time_base,
                                       out_stream->time_base);
            pkt->pos=-1;
            pkt->flags|=AV_PKT_FLAG_KEY;
            pkt->stream_index=0;
            av_interleaved_write_frame(outFmat,pkt);
        }
        av_packet_unref(pkt);
    }
    av_write_trailer(outFmat);

    avcodec_close(outFmat->streams[0]->codec);
//    av_freep(&outFmat->streams[0]->codec);
    avio_close(outFmat->pb);
    av_free(outFmat);


    av_packet_free(&pkt);
}
