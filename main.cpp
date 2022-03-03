#include "VLogin.h"
#include <QApplication>
#include<QDebug>
#include<QFontDatabase>
#include"SViewManage.h"
#include<QVector>

#include"mygraphicsview.h"//开始界面
#include"VLogin.h"
#include"VRegister.h"
#include"VAnswer.h"
#include"VResetPwd.h"
#include"VSetMsg.h"
#include"VMain.h"
#include"VReplayChoose.h"
#include"VReplay.h"
#include"VPhotos.h"
#include"VTranscode.h"


/******************************************************
 * 函数名：
 * 参数列表
 * 参数解释
 * 用处：
 * 返回值：
 *******************************************************/
void initViews(SViewManage *views)
{
    MyGraphicsView *startView=new MyGraphicsView();
    VLogin *loginView=new VLogin();
    VRegister *regisView=new VRegister();
    VAnswer *answerView=new VAnswer();
    VResetPwd *resetPwdView=new VResetPwd();
    VSetMsg *setMsgView=new VSetMsg();
    VMain *mainView=new VMain();
    VReplayChoose *replayChooseView=new VReplayChoose();
    VReplay *replayView=new VReplay();
    VPhotos *photosView=new VPhotos();
    VTranscode *transodeView=new VTranscode();

    views->addView(STARTVIEW,startView);
    views->addView(LOGINVIEW,loginView);
    views->addView(REGISTERVIEW,regisView);
    views->addView(ANSWERVIEW,answerView);
    views->addView(RESETPWDVIEW,resetPwdView);
    views->addView(SETMSGVIEW,setMsgView);
    views->addView(MAINVIEW,mainView);
    views->addView(REPLAYCHOOSEVIEW,replayChooseView);
    views->addView(REPLAYVIEW,replayView);
    views->addView(PHOTOSVIEW,photosView);
    views->addView(TRANSCODEVIEW,transodeView);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss(":/QStyleSheet.qss");
    if (qss.open(QFile::ReadOnly))
    {
        a.setStyleSheet(QLatin1String(qss.readAll()));
        qss.close();
    }

    SViewManage *views=SViewManage::getInstance();//界面管理器
    //界面初始化
    initViews(views);
    views->showView(STARTVIEW);
    return a.exec();
}
