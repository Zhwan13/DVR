#ifndef FTRANSCODE_H
#define FTRANSCODE_H
extern "C"{
#include"libavcodec/avcodec.h"
#include"libavformat/avformat.h"
#include"libswscale/swscale.h"
#include"libavutil/pixfmt.h"
#include "libavdevice/avdevice.h"
}
#include<QString>
#include<QDebug>
/*******************
 * 功能：转码逻辑
 * ***********/
class FTranscode
{
public:
    FTranscode();
    ~FTranscode();
    void openH264File(QString h264File);
    void outToDst(QString dstFile);
private:
     AVFormatContext *fmatc;
     int video_index;
};

#endif // FTRANSCODE_H
