#include "VReplay.h"

VReplay::VReplay()
{
    initWidget();
    initLayout();
    initConnect();
}

void VReplay::initWidget()
{
    this->LabVideo=new QLabel(this);
    this->BtnExport=new QPushButton(this);
    this->BtnShot=new QPushButton(this);
    BtnSpeed=new QPushButton(this);
    BtnStop=new QPushButton(this);

    LabName=new QLabel(this);
}


void VReplay::initLayout()
{
    LabVideo->setGeometry(50,80,650,350);
    LabVideo->setPixmap(QPixmap(":/pictures/background.jpg").scaled(650,350));

    BtnExport->setGeometry(this->width()-80,110,60,30);
    BtnExport->setText("导出");
    BtnExport->setObjectName("borderBtn");
    BtnShot->setGeometry(this->width()-80,this->height()-80,60,30);
    BtnShot->setText("截图");
    BtnShot->setObjectName("borderBtn");
    BtnSpeed->setGeometry(this->width()-80,this->height()-30,60,30);
    BtnSpeed->setText("倍速");
    BtnSpeed->setObjectName("borderBtn");

    BtnStop->setGeometry(this->width()/2-50,this->height()-35,30,30);
    BtnStop->setIconSize(BtnStop->rect().size());
    BtnStop->setIcon(QIcon(QPixmap(":/pictures/stop.png").scaled(BtnStop->rect().size())));//先是暂停状态
    BtnStop->setObjectName("NoBorder");

    LabName->setGeometry(this->width()/2-80,20,300,50);
    LabName->setText("videoName");
    LabName->setObjectName("tips");
}

void VReplay::initConnect()
{
    connect(this->BtnStop,SIGNAL(clicked(bool)),this,SLOT(PlayOrNot()));
    connect(this->BtnExport,SIGNAL(clicked(bool)),this,SLOT(exportSlot()));
    connect(this->BtnShot,SIGNAL(clicked(bool)),this,SLOT(shotSlot()));

}
/*******************
 * 功能：设置video名字
 * ***********/
void VReplay::setName(QString name)
{
    this->videoName=name;
    return;
}

void VReplay::returnSlot()
{
    this->views->showView(MAINVIEW);
    views->hideView(REPLAYVIEW);
}

void VReplay::PlayOrNot()
{
    QString replayfile;
    replayfile=this->views->replayFilename;
}

void VReplay::exportSlot()
{
    //复制到另一个文件下
}

void VReplay::shotSlot()
{

}

void VReplay::showVideoSlot(QImage imag)
{
     this->LabVideo->setPixmap(QPixmap::fromImage(imag).scaled(650,350));
}
