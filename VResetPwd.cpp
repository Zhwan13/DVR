#include "VResetPwd.h"

VResetPwd::VResetPwd()
{
    this->initWidget();
    this->initLayout();
    this->initConnect();
}

void VResetPwd::initWidget()
{
    ResetTitle=new  QLabel(this);
    Labuserpass=new QLabel(this);
    EdtPass=new MyLineEdit(this);
    LabPassTip=new QLabel(this);

    LabRepass=new QLabel(this);
    EdtRepass=new MyLineEdit(this);
    LabRepassTip=new QLabel(this);

    BtnPassVisible=new QPushButton(this);
    BtnRepassVisible=new QPushButton(this);

    BtnReset=new QPushButton(this);
//    BtnReturn=new QPushButton(this);
}

void VResetPwd::initLayout()
{
//    BtnReturn->move(60,40);
//    BtnReturn->setFixedSize(30,30);
//    BtnReturn->setIconSize(BtnReturn->rect().size());
//    BtnReturn->setIcon(QIcon(QPixmap(":/pictures/back.png").scaled(BtnReturn->rect().size())));
//    BtnReturn->setObjectName("NoBorder");

    ResetTitle->move(60,60);
    ResetTitle->setText("RESET PASSWORD");
    ResetTitle->setObjectName("Title");

    Labuserpass->move(100,220);
    Labuserpass->setPixmap(QPixmap(":/pictures/lock (1).png").scaled(30,30));

    EdtPass->setGeometry(140,220,200,30);
//    EdtPass->setFont(QFont("幼圆",12));
    EdtPass->setEchoMode(QLineEdit::Password);
    EdtPass->setMaxLength(6);
    EdtPass->setPlaceholderText("密码");
    EdtPass->installEventFilter(this);//安装事件过滤器

    LabPassTip->move(340,220);//输入后显示勾勾
    LabPassTip->setPixmap(QPixmap(":/pictures/benefits (1).png").scaled(30,30));
    LabPassTip->setVisible(false);

    BtnPassVisible->move(140+200-25,220);
    BtnPassVisible->setFixedSize(25,25);
    BtnPassVisible->setIconSize(BtnPassVisible->rect().size());
    BtnPassVisible->setIcon(QIcon(QPixmap(":/pictures/view (1).png").scaled(BtnPassVisible->rect().size())));
    BtnPassVisible->setObjectName("NoBorder");
    BtnPassVisible->installEventFilter(this);//安装事件过滤器

    LabRepass->move(100,270);
    LabRepass->setPixmap(QPixmap(":/pictures/lock (1).png").scaled(30,30));

    EdtRepass->setGeometry(140,270,200,30);
//    EdtRepass->setFont(QFont("幼圆",12));
    EdtRepass->setEchoMode(QLineEdit::Password);
    EdtRepass->setMaxLength(6);
    EdtRepass->setPlaceholderText("确认密码");
    EdtRepass->installEventFilter(this);//安装事件过滤器

    LabRepassTip->move(340,270);//输入后显示勾勾

    BtnRepassVisible->move(140+200-25,270);
    BtnRepassVisible->setFixedSize(25,25);
    BtnRepassVisible->setIconSize(BtnRepassVisible->rect().size());
    BtnRepassVisible->setIcon(QIcon(QPixmap(":/pictures/view (1).png").scaled(BtnRepassVisible->rect().size())));
    BtnRepassVisible->setObjectName("NoBorder");
    BtnRepassVisible->installEventFilter(this);//安装事件过滤器

    BtnReset->move(140,320);
    BtnReset->setText("Reset Password");
//    BtnReset->setFont(QFont("幼圆",20));
    BtnReset->setObjectName("btn");
    BtnReset->installEventFilter(this);//安装事件过滤器

}

void VResetPwd::initConnect()
{
//    connect(this->BtnReturn,SIGNAL(clicked()),this,SLOT(returnAnswerSlot()));
    connect(BtnReset,SIGNAL(clicked(bool)),this,SLOT(resetPwdSlot()));
}

/*******************
 * 功能：在数据库里重置密码
 * ***********/
void VResetPwd::resetPwdSlot()
{
    //判断是否能重置密码，再发送信号显示登录界面
    if(this->EdtPass->text().isEmpty()||this->EdtRepass->text().isEmpty())
    {
        QMessageBox::information(this,"Tips","Edit box cannot be empty!",QMessageBox::Ok);
        return;
    }
    if(this->EdtPass->text()==this->EdtRepass->text())
    {
        QString sql="update t_user SET Pwd = '"
                +this->EdtPass->text()+"' where Account = '"
                +this->DBdata->account+"';";
        DBdata->OptionSQL(sql);
        this->views->showView(LOGINVIEW);
        this->views->hideView(RESETPWDVIEW);
        return;
    }
    else
        QMessageBox::information(this,"Tips","Edit box cannot be empty!",QMessageBox::Ok);
}
void VResetPwd::returnSlot()
{
    this->EdtPass->clear();
    this->EdtRepass->clear();

    this->views->showView(LOGINVIEW);
    this->views->hideView(RESETPWDVIEW);
}
