#include "CSetMsg.h"

CSetMsg::CSetMsg()
{
    DBdata=SingleDBOption::getInstance();
    model=SModel::getInstance();
}
/*******************
 * 功能：对设置的内容进行判断，主要是判空
 * ***********/
int CSetMsg::checkInput(QString videoPath,QString picPath,QString delay,QString cameraPath)
{
    if(videoPath.isEmpty()||picPath.isEmpty()||delay.isEmpty()||cameraPath.isEmpty())
    {
        return 0;//有编辑框内容为空
    }
    else if(videoPath==picPath)
        return 1;
    else if(delay=="0")
        return 3;
    return 2;
}
/*******************
 * 功能：自动检测计算机的摄像头并返回
 * 返回值：摄像头名称
 * ***********/
QString CSetMsg::getCameraInfo()
{
    int index=0;
    QStringList CameraNamestr;
    foreach (const QCameraInfo &CameraName, QCameraInfo::availableCameras()) {
        CameraNamestr<<CameraName.description();
    }
    return CameraNamestr.at(index);
}

int CSetMsg::updateTable(QString videoPath, QString photoPath, QString delayTime, QString cameraName)
{
    QString sql;
    if(model->isSetMsg()==0)//里面没有存数据
    {
        sql="INSERT INTO t_setMsg (Sid,VideoPos,PicturePos,DelayTime,cameraMsg) VALUES (001,'"+videoPath+
                "','"+photoPath+
                "','"+delayTime+
                "','"+cameraName+"');";
    }
    else//已经有一条数据
    {
        sql="UPDATE t_setMsg SET VideoPos='"+videoPath+
            "',PicturePos='"+photoPath+
            "',DelayTime='"+delayTime+
            "',cameraMsg='"+cameraName+"';";
    }
    qDebug()<<sql;
    DBdata->OptionSQL(sql);
    return 1;
}

