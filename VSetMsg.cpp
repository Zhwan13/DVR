#include "VSetMsg.h"
#include<iostream>
using namespace std;

VSetMsg::VSetMsg()
{
//    this->setWindowFlag(Qt::FramelessWindowHint);

    this->initWidget();
    this->initLayout();
    this->initConnect();

}

void VSetMsg::initWidget()
{
    this->SetTitle=new QLabel(this);
    this->LabVideoPath=new QLabel(this);//视频存储位置
    this->EdtVideoPath=new MyLineEdit(this);
    this->LabPicPath=new QLabel(this);//图片存储位置
    this->EdtPicPath=new MyLineEdit(this);
    this->LabDelay=new QLabel(this);//采集间隔时间
    this->EdtDelay=new MyLineEdit(this);
    this->LabCameraPath=new QLabel(this);//摄像头设置
    this->EdtCameraPath=new MyLineEdit(this);
    this->BtnEnter=new QPushButton(this);
    this->BtnCancel=new QPushButton(this);

    this->ChooseDir=new QFileDialog(this);
    Csetmsg=new CSetMsg();
}

void VSetMsg::initLayout()
{
    SetTitle->move(60,30);//登录标签
    SetTitle->setText("SET UP");
    SetTitle->setObjectName("Title");

    LabVideoPath->move(100,120);
    LabVideoPath->setPixmap(QPixmap(":/pictures/video.png").scaled(30,30));

    EdtVideoPath->setGeometry(140,120,200,30);
    EdtVideoPath->setPlaceholderText("视频存储位置");

    LabPicPath->move(100,170);
    LabPicPath->setPixmap(QPixmap(":/pictures/photo.png").scaled(30,30));

    EdtPicPath->setGeometry(140,170,200,30);
    EdtPicPath->setPlaceholderText("图片存储位置");

    LabDelay->move(100,220);
    LabDelay->setPixmap(QPixmap(":/pictures/time.png").scaled(30,30));

    EdtDelay->setGeometry(140,220,200,30);
    EdtDelay->setPlaceholderText("采集间隔时间");

    LabCameraPath->move(100,270);
    LabCameraPath->setPixmap(QPixmap(":/pictures/camera.png").scaled(30,30));

    EdtCameraPath->setGeometry(140,270,200,30);
    EdtCameraPath->setPlaceholderText("摄像头配置");
    EdtCameraPath->setText(Csetmsg->getCameraInfo());
    EdtCameraPath->setEnabled(false);

    BtnEnter->setGeometry(130,320,80,30);
    BtnEnter->setText("ENTER");
    BtnEnter->setObjectName("borderBtn");

    BtnCancel->setGeometry(250,320,80,30);
    BtnCancel->setText("CANCEL");
    BtnCancel->setObjectName("borderBtn");

    ChooseDir->setWindowTitle("文件保存位置");
    ChooseDir->setFileMode(QFileDialog::Directory);//返回文件路径，带文件名
//    ChooseDir->setDefaultSuffix("mp4");// 默认后缀mp4
}

void VSetMsg::initConnect()
{
    connect(BtnEnter,SIGNAL(clicked()),this,SLOT(enterSlot()));
    connect(EdtPicPath,SIGNAL(MouseClickSignal()),this,SLOT(PhoPosChoose()));//图片位置选择
    connect(EdtVideoPath,SIGNAL(MouseClickSignal()),this,SLOT(VidPosChoose()));
//    connect(BtnReturn,SIGNAL(clicked()),this,SLOT(ReturnSLOT()));
}
/*******************
 * 功能：判断设置信息是否合格
 * ***********/
void VSetMsg::enterSlot()
{
    int ret=Csetmsg->checkInput(EdtVideoPath->text(),EdtPicPath->text(),EdtDelay->text(),EdtCameraPath->text());
    if(ret==0)
    {
        QMessageBox::information(this,"Tips","输入内容不能为空",QMessageBox::Ok);
    }
    else if(ret==1)
    {
        QMessageBox::information(this,"Tips","视频和照片不能存储在同一目录下",QMessageBox::Ok);
    }
    else if(ret==3)
    {
        QMessageBox::information(this,"Tips","间隔时间不能为0",QMessageBox::Ok);
        return;
    }
    else
    {
        Csetmsg->updateTable(EdtVideoPath->text(),EdtPicPath->text(),EdtDelay->text(),EdtCameraPath->text());

        //线程重新启动
        decode->exit();
        decode->start();
        this->views->showView(MAINVIEW);
        this->views->hideView(SETMSGVIEW);
        this->EdtVideoPath->clear();
        this->EdtPicPath->clear();
        this->EdtDelay->clear();
        this->EdtCameraPath->clear();
    }
}

void VSetMsg::returnSlot()
{
    this->views->showView(MAINVIEW);
    this->views->hideView(SETMSGVIEW);
}
/*******************
 * 功能：选择照片存储的位置，并设置给编辑框
 * ***********/
void VSetMsg::PhoPosChoose()
{
    this->ChooseDir->exec();
    if(ChooseDir->selectedFiles().isEmpty())
        return;
    else
        this->EdtPicPath->setText(ChooseDir->selectedFiles()[0]);
}
/*******************
 * 功能：设置视频存储的位置，并设置给编辑框
 * ***********/
void VSetMsg::VidPosChoose()
{
    this->ChooseDir->exec();
    if(ChooseDir->selectedFiles().isEmpty())
        return;
    else
        this->EdtVideoPath->setText(ChooseDir->selectedFiles()[0]);
}
