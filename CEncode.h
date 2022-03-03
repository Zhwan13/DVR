#ifndef CENCODE_H
#define CENCODE_H
#include<QDebug>
#include<QString>
#include <QThread>
extern "C"{
//#include"libavcodec/avcodec.h"
#include"libavformat/avformat.h"
#include"libswscale/swscale.h"
#include"libavutil/pixfmt.h"
#include "libavdevice/avdevice.h"
}


/**************
 * 功能：对解码后的数据进行编码
 * **************/
class CEncode//:public QThread
{
public:
    CEncode();
    void initEncode(int width,int height);
    void SetFileName(QString filename);
    void encodeFrame(AVFrame *frame);
    void write_trailer();
    void CloseLiu();
//    void run();

private:
    AVCodecContext *codec;
    AVFormatContext *fmatc;//封装格式上下文结构体，保存视频文件封装格式相关信息
    AVPacket *pkt;
//    int pkt_index;

    int Width;
    int Height;
};


#endif // CENCODE_H
