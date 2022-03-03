#include "VAnswer.h"

VAnswer::VAnswer()
{
    this->initWidget();
    this->initLayout();
    this->initConnect();
}
void VAnswer::initWidget()
{
    //控件
    this->LabTitle=new QLabel(this);
    this->LabTip=new QLabel(this);
    this->box=new QComboBox(this);
    this->EdtAnswer=new MyLineEdit(this);
    this->BtnConfirm=new QPushButton(this);
//    this->BtnReturn=new  QPushButton(this);

}

void VAnswer::initLayout()
{
    LabTitle->move(70,60);
    LabTitle->setText("FORGET PASSWORD");
    LabTitle->setObjectName("Title");
    LabTip->move(60,130);
    LabTip->setText("CHOOSE A QUESTION TO ANSWER");
    LabTip->setObjectName("tips");
//    LabTip->setFont(QFont("幼圆",20));

    box->setGeometry(150,160,150,25);
    box->addItem("Your name?");
    box->addItem("Your birthday?");

    EdtAnswer->setGeometry(150,220,150,25);

    BtnConfirm->move(140,260);
    BtnConfirm->setText("确定");
    BtnConfirm->setObjectName("btn");
}

void VAnswer::initConnect()
{

    connect(BtnConfirm,SIGNAL(clicked()),this,SLOT(ResetLSlot()));
    connect(BtnReturn,SIGNAL(clicked()),this,SLOT(returnSlot()));

}
/*******************
 * 功能：重置密码槽函数
 * ***********/
void VAnswer::ResetLSlot()
{
    //问题答对了后显示重置密码界面
    int flag=0;
    if(this->box->currentText()=="Your name?")
    {
        if(this->EdtAnswer->text()=="zhang")
            flag=1;
    }
    else if(this->box->currentText()=="Your birthday?")
    {
        if(this->EdtAnswer->text()=="1008")
            flag=1;
    }

    if(flag==1)
    {
        this->EdtAnswer->clear();
        this->views->showView(RESETPWDVIEW);//显示重置密码界面
        this->views->hideView(ANSWERVIEW);//隐藏当前界面
        return;
    }
    QMessageBox::information(this,"Tips","the answer error!",QMessageBox::Ok);
    this->EdtAnswer->clear();
    return;
}

void VAnswer::returnSlot()
{
    this->EdtAnswer->clear();

    this->views->showView(LOGINVIEW);//返回登录界面
    this->views->hideView(ANSWERVIEW);//隐藏当前界面
}


