#include "CTranscode.h"

CTranscode::CTranscode()
{
    ToMp4=new FTranscode();
}
/*******************
 * 功能：转成MP4格式
 * ***********/
void CTranscode::transcodeToMp4()
{
    ToMp4->openH264File(this->inFile);
    ToMp4->outToDst(this->outFile);
}
/*******************
 * 功能：转成AVI格式
 * ***********/
void CTranscode::transcodeToAvi()
{
//    qDebug()<<"CTRans-in"+this->inFile;
    ToMp4->openH264File(this->inFile);
//    qDebug()<<"CTRans-out"+this->outFile;
    ToMp4->outToDst(this->outFile);
}

/*******************
 * 功能：设置输入文件名
 * ***********/
void CTranscode::setInFile(QString filename)
{
    this->inFile=filename;
    return;
}
/*******************
 * 功能：设置输出文件名
 * ***********/
void CTranscode::setOutFile(QString outfilename)
{
    this->outFile=outfilename;
    return;
}
/*******************
 * 功能：对路径判空
 * ***********/
int CTranscode::checkMsg(QString outDir , QString inDir)
{
    if(outDir.isEmpty())
        return 0;//如果为空返回0
    else if(inDir.isEmpty()||inDir.isNull())
    {
        return 2;
    }
    else
        return 1;
}
/*******************
 * 功能：在数据库里查找文件存储位置
 * ***********/
QString CTranscode::getDir()
{

    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql;//找到存储路径
    sql="SELECT * FROM t_setMsg";//查询
    int ret=DBdata->getTable(sql,pResult,row,col);
    if(ret>=1)//成功
    {
        qDebug()<<pResult[6];
        return QString(pResult[6]);
    }
    else
    {
//        QString DefaultPath="D:/DVR";
//        QDir dir(DefaultPath);
//        if(!dir.exists())
//            dir.mkdir(DefaultPath);
//        return DefaultPath;
        return NULL;
    }
}
