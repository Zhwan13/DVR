#include "SModel.h"
#include<QCameraInfo>
SModel *SModel::instance=nullptr;
SModel *SModel::getInstance()
{
    if(SModel::instance==nullptr)
    {
        instance=new SModel();
    }
    return instance;
}
/*******************
 * 功能：判断是否已经设置了路径
 * ***********/
int SModel::isSetMsg()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql;//找到存储路径
    sql="SELECT * FROM t_setMsg";//查询
    DBdata->getTable(sql,pResult,row,col);
    if(row==1)
    {
        return 1;
    }
    return 0;
}

QString SModel::getCameraInfo()
{
    int index=0;
    QStringList CameraNamestr;
    foreach (const QCameraInfo &CameraName, QCameraInfo::availableCameras()) {
        CameraNamestr<<CameraName.description();
    }
    return CameraNamestr.at(index);
}

/**************
 * 功能：通过访问数据库找到视频存储位置
 * **************/

QString SModel::getvideoDir()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql;//找到存储路径
    sql="SELECT * FROM t_setMsg";//查询
    DBdata->getTable(sql,pResult,row,col);
    if(row>=1)//成功
    {
        qDebug()<<pResult[6];
        return QString(pResult[6]);
    }
    else
        return NULL;
}

QString SModel::getphotoDir()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql;//找到存储路径
    sql="SELECT * FROM t_setMsg";//查询
    DBdata->getTable(sql,pResult,row,col);
    if(row>=1)//成功
    {
        qDebug()<<pResult[7];
        return QString(pResult[7]);
    }
    else
        return NULL;
}
/**************************
 * 功能：获取数取库视频表里的行数，即多少视频
 * ***********************/
int SModel::getvideosCount()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列,
    QString sql;//找到存储路径
    sql="SELECT * FROM t_videos";//查询
    DBdata->getTable(sql,pResult,row,col);
    if(row==0)
        return 0;
    return row;
}

int SModel::getphotosCount()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列,
    QString sql;//找到存储路径
    sql="SELECT * FROM t_photos";//查询
    DBdata->getTable(sql,pResult,row,col);
    return row;
}



/******************
 * 获取数据库存储的间隔时间
 *返回值：间隔时间（int）
 * *************/
QString SModel::getTime()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql;//找到存储路径
    sql="SELECT * FROM t_setMsg";//查询
    DBdata->getTable(sql,pResult,row,col);
    if(row>=1)//成功
    {
//        qDebug()<<pResult[8];
        return QString(pResult[8]);
    }
    else
        return NULL;//如果没有输入默认
}

QString SModel::getNowtimeStr()
{
    QDateTime time=QDateTime::currentDateTime();
    QString nowday=time.toString("yyyy-MM-dd");
    return nowday;
}

/********************
 * 设置t_videos里的信息
 *
 * *******/
void SModel::InserttVideo(QString filename, QString videodir)
{
    //第一帧与视频名字一样，后缀不同
    QString VideoName=filename+".h264";
    QString firstframe=filename+".png";
    QString sql="INSERT INTO t_videos (videofilename,VideoPos,firstFramename) VALUES ('"+VideoName+"','"+videodir+"','"+firstframe+"');";
    DBdata->OptionSQL(sql);
}

SModel::SModel()
{
    DBdata=SingleDBOption::getInstance();

}

