#ifndef CREPLAYCHOOSE_H
#define CREPLAYCHOOSE_H
#include"SingleDBOption.h"
#include"SModel.h"
#include<QDebug>
#include<QDir>

/**************
 * 功能：回放选择界面的控制器，主要函数是找到视频存储位置，并用九宫格显示
 * **************/
class CReplayChoose
{
public:
    CReplayChoose();
    SModel *model=SModel::getInstance();
private:
    SingleDBOption *DBdata;

};

#endif // CREPLAYCHOOSE_H
