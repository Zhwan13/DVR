#ifndef CTRANSCODE_H
#define CTRANSCODE_H
#include"FTranscode.h"
#include"SingleDBOption.h"
#include"SModel.h"
#include<QDir>
/*******************
 * 功能：转码控制器
 * ***********/
class CTranscode
{
public:
    CTranscode();
    void transcodeToMp4();//转码mp4
    void transcodeToAvi();//转码成Avi

    void setInFile(QString filename);
    void setOutFile(QString outfilename);
    int checkMsg(QString outDir,QString inDir);//检查信息是否完整
    QString getDir();

    SModel *model=SModel::getInstance();

private:
    FTranscode *ToMp4;

    QString inFile;
    QString outFile;
    SingleDBOption *DBdata=SingleDBOption::getInstance();

};

#endif // CTRANSCODE_H
