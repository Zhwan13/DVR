#ifndef CSETMSG_H
#define CSETMSG_H
#include"VBase.h"
#include<QString>
#include"SingleDBOption.h"
#include"SModel.h"
#include<QCameraInfo>
/*******************
 * 功能：设置信息控制器
 * ***********/
class CSetMsg
{
public:
    CSetMsg();
    int checkInput(QString videoPath,QString picPath,QString delay,QString cameraPath);

    QString getCameraInfo();//获取摄像头数据
    int updateTable(QString videoPath,QString photoPath,QString delayTime,QString cameraName);
private:
    SingleDBOption *DBdata;
    SModel *model;

//    QString
public slots:
    void returnSlot();
};

#endif // CSETMSG_H
