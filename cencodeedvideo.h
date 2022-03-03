#ifndef CENCODEEDVIDEO_H
#define CENCODEEDVIDEO_H

#include<QString>
#include<QDebug>
extern "C"
{
   #include "libavcodec/avcodec.h"
   #include "libavformat/avformat.h"
   #include "libswscale/swscale.h"
   #include "libavutil/pixfmt.h"
}
#include "singledb.h"
#include "tool.h"
#include <QThread>
#include "singleqq.h"

class CEncodeedVideo:public QThread
{
public:
    CEncodeedVideo();
    void initEncode(int Width,int Height);
    void SetFileName(QString FileName);
    void encodeFrame(AVFrame *frame);
    void write_trailer();
    void getFlag(QString Time);
    void SettoTable(QString Name,QString Path,QString Time);
    void CloseLiu();
    void run();
private:
    int Width;
    int Height;
    int Count = 0;
    AVFormatContext *fmatc;
    AVCodecContext *acodec;
    AVPacket *pkt;
    QString VideoTemp;
    SingleDB *db;
    SingleQQ *qq;
    Tool tool;
    QString SaveImgPath;
};

#endif // CENCODEEDVIDEO_H
