#ifndef DECODEVIDEO_H
#define DECODEVIDEO_H

#include<QString>
#include<QDebug>
#include<QObject>
#include<QImage>
#include<QThread>
#include<QFile>
#include"cencodeedvideo.h"
#include <windows.h>
//#include "tool.h"
#include "SingleDBOption.h"
#include <QDir>

extern "C"
{
   #include "libavcodec/avcodec.h"
   #include "libavformat/avformat.h"
   #include "libswscale/swscale.h"
   #include "libavutil/pixfmt.h"
   #include "libavdevice/avdevice.h"

}

#include<libavdevice/avdevice.h>


class DecodeVideo:public QThread
{
    Q_OBJECT
public:
    DecodeVideo();
    void RegisterAll();
    void InitValue();
    void OpenStreaming();
    void OpenDecode();
    void DecodeFrame();
    void CloseSpace();
private:
    int ret;
    int VideoIndex;
    int TakePhotoBtnFlag;
    int ImgeNumber;
    int FrameCount=0;
    int NumByte;
    int DecodeFlag;
    int FrameSize;
    int ImgeFlag;
    int GotPicture;
    QString   FileName;
    FILE *H264File;
    FILE *YuvFile;
    AVPacket *Pkt;
    AVFrame *Picture;
    AVFrame *DstFrame;
    AVFrame *DstFrameRGB;
    AVCodecContext *Codec;
    AVCodec *Code;
    AVFormatContext *Fmatc;
    CEncodeedVideo *EncodeVideo;

    Tool tool;
    QString SaveImgPath;
    QString VideoFlag;
    SingleDBOption *db;
    bool StartFlag=true;
private:
    void run();
signals:
    void Sendimg(QImage img);

};

#endif // DECODEVIDEO_H
