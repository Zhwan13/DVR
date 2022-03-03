#ifndef SMODEL_H
#define SMODEL_H
#include"SingleDBOption.h"
#include<QDateTime>
/*******************
 * 没写完的模板单例
 * ***********/
class SModel
{
public:
    static SModel *getInstance();
    int isSetMsg();//是否有设置信息
    QString getCameraInfo();
    QString  getvideoDir();
    QString getphotoDir();
    int getvideosCount();//获取数据库视频条数
    int getphotosCount();
    QString getTime();
    QString getNowtimeStr();//获取当前时间字符串yyyy-MM-dd

    void InserttVideo(QString filename,QString videodir);

private:
    SModel();
    static SModel *instance;
    SingleDBOption *DBdata;

};

#endif // SMODEL_H
