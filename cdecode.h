#ifndef CDECODE_H
#define CDECODE_H
#include<QDebug>
#include<QString>
#include<QImage>
#include"CEncode.h"
#include<QDateTime>
#include<QThread>
#include<QCameraInfo>
#include"SModel.h"
#include"SingleDBOption.h"
#include"QDir"

extern "C"{
#include"libavcodec/avcodec.h"
#include"libavformat/avformat.h"
#include"libswscale/swscale.h"
#include"libavutil/pixfmt.h"
}

/**************
 * 功能：对摄像头数据进行解码
 * **************/

class CDecode:public QThread
{
    Q_OBJECT
public:
    static CDecode*getInstance();
    void registerFFMPEG();
    void initValue();
    void openStreaming();
    void openDecode();
    void DecodeFrame();
    void CloseSpace();
private:
    CDecode();
    static CDecode *instance;
    SModel *model=SModel::getInstance();
    SingleDBOption *DBdata=SingleDBOption::getInstance();

    AVFormatContext *fmatC;//封装格式上下文结构体
    AVCodecContext *codec;//编码器上下文结构体
    AVCodec *code;
    AVPacket *pkt;//存储一帧压缩编码数据,pkt里面有指针,要给指针开空间（深拷贝）

    AVFrame *picture;
    AVFrame *dstFrame;
    AVFrame *dstFrameRGB;

    int got_picture_ptr;
    int videoIndex;
    int VideoFlag;//作为存储视频的区分位
    int size;

    int FrameCount;
    QString SaveImgPath;
    int ret;
    CEncode *EncodeVideo;
    int numbyte;

    QString ObjectName;//判断是回放的还是实时播放的解码

protected:
    void run();

signals:
    void sendImgSignal(QImage img);


};

#endif // CDECODE_H
