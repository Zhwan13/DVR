#include "VMain.h"


VMain::VMain()
{
    //解码
    fdecode=CDecode::getInstance();

    this->initWidget();
    this->initLayout();
    this->initConnect();

//    fdecode->start();
}

void VMain::initWidget()
{

    QPixmap winBackground=QPixmap(":/pictures/background2.jpeg");//主界面背景
    winBackground=winBackground.scaled(800,480);
    QPalette mainPalette;
    mainPalette.setBrush(QPalette::Background,QBrush(winBackground));

    this->setPalette(mainPalette);
    setAutoFillBackground(true);

    this->timer=new QTimer();//定时器
    timer->start(500);

    this->LabTitle=new QLabel(this);
    this->LabMain=new QLabel(this);//视频显示界面
    this->LabDate=new QLabel(this);//显示时间

    this->BtnSet=new QPushButton(this);
    this->BtnExit=new QPushButton(this);
    this->Btnmenu=new QPushButton(this);
    this->BtnTakeapicture =new QPushButton(this);
    this->BtnReplay =new QPushButton(this);
    this->BtnPhoto =new QPushButton(this);
    this->BtnTranscoding=new QPushButton(this);
}

void VMain::initLayout()
{
    this->LabTitle->move(100,10);
    this->LabTitle->setText("DRIVING RECORDER");
    LabTitle->setObjectName("Title");

    this->LabMain->setGeometry(20,80,750,380);
    LabMain->setPixmap(QPixmap(":/pictures/background.jpg").scaled(750,380));

    this->LabDate->setGeometry(30,80,200,30);//时间标签
    LabDate->setObjectName("tips");


    this->BtnSet->setGeometry(this->width()-100,360,80,30);//设置按钮
    BtnSet->setText("设置");
    BtnSet->setObjectName("borderBtn");

    BtnExit->setGeometry(this->width()-100,420,80,30);//退出按钮
    BtnExit->setText("退出");
    BtnExit->setObjectName("borderBtn");

    Btnmenu->setGeometry(this->width()-60,60,30,30);//菜单按钮
    Btnmenu->setIconSize(Btnmenu->rect().size());
    Btnmenu->setIcon(QIcon(QPixmap(":/pictures/unfold.png")));
    Btnmenu->setObjectName("NoBorder");

    BtnTakeapicture->setGeometry(this->width()-100,120,80,30);
    BtnTakeapicture->setText("拍照");
    BtnTakeapicture->setObjectName("borderBtn");

    BtnReplay->setGeometry(this->width()-100,180,80,30);
    BtnReplay->setText("回放");
    BtnReplay->setObjectName("borderBtn");

    BtnPhoto->setGeometry(this->width()-100,240,80,30);
    BtnPhoto->setText("照片");
    BtnPhoto->setObjectName("borderBtn");

    BtnTranscoding->setGeometry(this->width()-100,300,80,30);
    BtnTranscoding->setText("转码");
    BtnTranscoding->setObjectName("borderBtn");

    BtnReturn->hide();
}

void VMain::initConnect()
{
    connect(BtnSet,SIGNAL(clicked()),this,SLOT(showSetView()));
    connect(BtnExit,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(Btnmenu,SIGNAL(clicked()),this,SLOT(ShowOrHideBtn()));
    connect(BtnReplay,SIGNAL(clicked(bool)),this,SLOT(replaySlot()));
    connect(BtnPhoto,SIGNAL(clicked()),this,SLOT(photosSlot()));
    connect(BtnTranscoding,SIGNAL(clicked(bool)),this,SLOT(transcodingSlot()));
    connect(timer,SIGNAL(timeout()),this,SLOT(TimeUpdata()));//定时器用来更新时间
    connect(BtnTakeapicture,SIGNAL(clicked(bool)),this,SLOT(takeAphotoSlot()));
    //实时记录画面
    connect(this->fdecode,SIGNAL(sendImgSignal(QImage)),this,SLOT(showImgSlot(QImage)));
}
/*************
 *判断是否有登录
 *
 * 返回值：如果有登录，返回1，无登录，返回0
 * **********/
int VMain::isLogin()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql;//找到存储路径
    sql="SELECT * from t_user WHERE type = 1;";//查询是否有type为1(登录)
    DBdata->getTable(sql,pResult,row,col);
    if(row>=1)
    {
        return 1;
    }
    return 0;

}
/*******************
 * 功能：实现时间实时显示在主界面
 * ***********/
void VMain::TimeUpdata()
{
    QDateTime time=QDateTime::currentDateTime();
    QString nowTime=time.toString("yyyy-MM-dd hh:mm:ss");
    this->LabDate->setText(nowTime);
}
/*******************
 * 功能：接收发来的图片，在主界面显示出来，实现播放
 * ***********/
void VMain::showImgSlot(QImage imag)
{
    this->saveimag=imag;//传来的照片作为属性
    this->LabMain->setPixmap(QPixmap::fromImage(imag).scaled(750,380));
}

void VMain::showSetView()
{
    if(isLogin()==0)
    {
        views->showView(LOGINVIEW);
        return;
    }
    else
    this->views->showView(SETMSGVIEW);
}

void VMain::returnSlot()//主界面没有返回按钮
{
}
/*******************
 * 功能：缩放按钮
 * ***********/
void VMain::ShowOrHideBtn()
{
    if(flag==0)//隐藏
    {
        this->BtnTakeapicture->hide();
        this->BtnReplay->hide();
        this->BtnPhoto->hide();
        this->BtnTranscoding->hide();
        this->Btnmenu->setIcon(QIcon(QPixmap(":/pictures/fold.png")));
    }
    else
    {//显示出各个功能按钮
        this->BtnTakeapicture->show();
        this->BtnReplay->show();
        this->BtnPhoto->show();
        this->BtnTranscoding->show();
        this->Btnmenu->setIcon(QIcon(QPixmap(":/pictures/unfold.png")));
    }
    flag=!flag;
}

void VMain::takeAphotoSlot()
{
    //拍照
    if(isLogin()==0)
    {
        views->showView(LOGINVIEW);
        return;
    }
    else
    {
//        qDebug()<<"保存图片";
        QString SaveImgPath=model->getphotoDir();//获取照片存储路径
        int PhotosFlag=model->getphotosCount();
        QDateTime time=QDateTime::currentDateTime();
        QString nowTime=time.toString("yyyy-MM-dd");
        QString photosaved=QString("%1/%2-%3.png").arg(SaveImgPath).arg(nowTime).arg(PhotosFlag);//图片存储的路径和文件名
        bool ret=this->saveimag.save(photosaved);
//        if(ret==true)
//        {
//            qDebug()<<"图片保存成功";
//        }
//        else
//            qDebug()<<"图片保存失败";
        //写入数据库
        QString photoname=QString("%2-%3.png").arg(nowTime).arg(PhotosFlag);
        QString sql="INSERT INTO t_photos (photofile) VALUES ('"+photoname+"');";
        DBdata->OptionSQL(sql);

    }
}

void VMain::replaySlot()
{
    //回放界面
    if(isLogin()==0)
    {
        views->showView(LOGINVIEW);
        return;
    }
    else
    {
        views->showView(REPLAYCHOOSEVIEW);
    }

}

void VMain::photosSlot()
{
    //显示照片
    if(isLogin()==0)
    {
        views->showView(LOGINVIEW);
        return;
    }
    else
    views->showView(PHOTOSVIEW);
}
/*******************
 * 功能：转码
 * ***********/
void VMain::transcodingSlot()
{

    if(isLogin()==0)
    {
        views->showView(LOGINVIEW);
        return;
    }
    else
    views->showView(TRANSCODEVIEW);
}
