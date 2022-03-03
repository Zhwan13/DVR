#include "VLogin.h"
#include<QDebug>

VLogin::VLogin()
{
    this->initWidget();
    this->initLayout();
    this->initConnect();
//    SuData=singleData::getInstance();
//    MySqlite3 *mysqlite =new MySqlite3();
//    mysqlite->openDatebase("database/T-TEST.db");//open database
    Clogin=new CLogin();

    this->timer=new QTimer();
    timer->start(200);

}

void VLogin::initWidget()
{
    logintitle=new QLabel(this);
    tips=new QLabel(this);
    BtnRegis=new QPushButton(this);
    LabUsername=new QLabel(this);
    EdtName=new MyLineEdit(this);
    LabNameTip=new QLabel(this);
    Labuserpass=new QLabel(this);
    EdtPass=new MyLineEdit(this);
    LabPassTip=new QLabel(this);
    BtnPassVisible=new QPushButton(this);//密码的小眼睛
    BtnFindPwd=new QPushButton(this);
    PicVerify=new QPushButton(this);//验证码图片
    EdtVerify=new MyLineEdit(this);//验证码输入框
    BtnLogin=new QPushButton(this);
}

void VLogin::initLayout()
{
    logintitle->move(70,60);//登录标签
    logintitle->setText("SIGN IN");
    logintitle->setObjectName("Title");

    tips->move(130,130);
    tips->setText("no Account？");
    tips->setFont(QFont("幼圆",12));
    tips->setObjectName("tips");

    BtnRegis->move(300,135);//注册按键
    BtnRegis->setText("Sign up");
    BtnRegis->setFont(QFont("幼圆",12));
    BtnRegis->setObjectName("NoBorder");

    LabUsername->move(130,160);
    LabUsername->setPixmap(QPixmap(":/pictures/user (1).png").scaled(30,30));

    EdtName->setGeometry(170,160,200,30);
    EdtName->setMaxLength(8);
    EdtName->setPlaceholderText("账号长度不小于8位");
//    EdtName->setFont(QFont("幼圆",12));
//    EdtName->setObjectName("EdtName");
    EdtName->installEventFilter(this);//安装事件过滤器

    LabNameTip->move(370,160);//输入后显示勾勾
    LabNameTip->setPixmap(QPixmap(":/pictures/benefits (1).png").scaled(30,30));
    LabNameTip->setVisible(false);

    Labuserpass->move(130,220);
    Labuserpass->setPixmap(QPixmap(":/pictures/lock (1).png").scaled(30,30));

    EdtPass->setGeometry(170,220,200,30);
    QRegExp regx("^[A-Za-z0-9]+$");//只能输入英文和数字
    QValidator *validator=new QRegExpValidator(regx,EdtPass);
    EdtPass->setValidator(validator);
    EdtPass->setEchoMode(QLineEdit::Password);
    EdtPass->setMaxLength(16);
    EdtPass->setPlaceholderText("密码6~16位");
    EdtPass->installEventFilter(this);
//    EdtPass->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");

    LabPassTip->move(370,220);
    LabPassTip->setPixmap(QPixmap(":/pictures/benefits (1).png").scaled(30,30));
    LabPassTip->setVisible(false);

    BtnPassVisible->move(340,220);
    BtnPassVisible->setFixedSize(25,25);
    BtnPassVisible->setIconSize(BtnPassVisible->rect().size());
    BtnPassVisible->setIcon(QIcon(QPixmap(":/pictures/view (1).png").scaled(BtnPassVisible->rect().size())));
    BtnPassVisible->setObjectName("NoBorder");
    BtnPassVisible->installEventFilter(this);//安装事件过滤器
    PwdFlag=0;

    //忘记密码
    BtnFindPwd->move(270,260);
    BtnFindPwd->setText("Forget Password?");
    BtnFindPwd->setObjectName("NoBorder");
    BtnFindPwd->setFont(QFont("幼圆",12));
    BtnFindPwd->setStyleSheet("color:#d4237a");

    //验证码
    EdtVerify->setGeometry(170,280,80,30);
    EdtVerify->setMaxLength(4);
    EdtVerify->setObjectName("EdtVerify");
//    EdtVerify->setFont(QFont("幼圆",12));
    EdtVerify->setPlaceholderText("验证码");
    EdtVerify->installEventFilter(this);

    //验证码图片（button类型的）
    PicVerify->setGeometry(270,280,80,30);
    PicVerify->setIconSize(PicVerify->rect().size());
    PicVerify->setIcon(QIcon(QPixmap(":/pictures/PicVerify.jpg").scaled(PicVerify->rect().size())));


    BtnLogin->move(140,320);
    BtnLogin->setText("Sign In");
    BtnLogin->setFont(QFont("幼圆",20));
    BtnLogin->setObjectName("btn");


}

void VLogin::initConnect()
{
    connect(BtnRegis,SIGNAL(clicked()),this,SLOT(showRegisterView()));
    connect(BtnLogin,SIGNAL(clicked()),this,SLOT(loginSlog()));
    connect(BtnFindPwd,SIGNAL(clicked()),this,SLOT(showAnswerView()));

}

void VLogin::clearEdt()
{
    this->EdtName->clear();
    this->EdtPass->clear();
    this->EdtVerify->clear();

}

VLogin::~VLogin()
{
}
/*******************
 * 功能：键盘按键抬起事件监听，实现输入的数据达标后提示勾
 * ***********/
bool VLogin::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==this->EdtName)//监视账号输入框
    {
        if(event->type()==QEvent::KeyRelease)
        {
            QString input1=this->EdtName->text();
            if(input1.length()>=8)
            {
                LabNameTip->setVisible(true);
            }
            else
            {
                LabNameTip->setVisible(false);
            }
        }
    }
    else if(watched==this->EdtPass)//监视密码输入框
    {

        if(event->type()==QEvent::KeyRelease)
        {
            QString input2=this->EdtPass->text();
            if(input2.length()>=6)
            {
                LabPassTip->setVisible(true);
            }
            else
            {
                LabPassTip->setVisible(false);
            }

            if((((QKeyEvent *)event)->key()==Qt::Key_Enter||((QKeyEvent *)event)->key()==Qt::Key_Return)&&(!input2.isEmpty()))
            {
                this->loginSlog();
                return true;
            }
            else {
                return false;
            }
        }
    }

    else if(watched==this->BtnPassVisible)//监视小眼睛按钮
    {
        if(event->type()==QEvent::MouseButtonPress)//鼠标点击
        {
            PwdFlag=!PwdFlag;
            if(PwdFlag)
                {
                EdtPass->setEchoMode(QLineEdit::Normal);
                }
            else
                {
                EdtPass->setEchoMode(QLineEdit::Password);
                }
            return true;
        }
        else
            return false;

    }
    return false;
}

void VLogin::showRegisterView()
{
    clearEdt();
    this->views->showView(REGISTERVIEW);
    this->views->hideView(LOGINVIEW);

}


void VLogin::loginSlog()
{
    Clogin->setAccount(EdtName->text());
    Clogin->setPwd(EdtPass->text());
    Clogin->setVertify(EdtVerify->text());
    int ret=Clogin->checkInput();
    if(ret==0)//账号或密码输入为空
    {
        QMessageBox::information(this,"Tips","账号或密码输入不能为空",QMessageBox::Ok);
    }
    else if(ret==1)//验证码输入不正确
    {
        QMessageBox::information(this,"Tips","验证码输入错误",QMessageBox::Ok);
    }
    else if(ret==2)//登录成功
    {
        QMessageBox::information(this,"Tips","登录成功",QMessageBox::Ok);
        Clogin->DBdata->setAccount(this->EdtName->text());
        Clogin->setType();//设置数据库里的type为1
        views->showView(MAINVIEW);
        views->hideView(LOGINVIEW);
        clearEdt();
        return;
    }
    else //账号或密码输入不正确，登录失败
    {
        QMessageBox::information(this,"Tips","账号或密码错误",QMessageBox::Ok);

    }
    return;
}

void VLogin::showAnswerView()
{
//    answerView->show();
//    findPwdView->hide();
    if(this->EdtName->text().isEmpty())
    {
        QMessageBox::information(this,"Tips","账号不能为空！",QMessageBox::Ok);
        return;
    }
    else
    {
        if(Clogin->checkAccount(this->EdtName->text()))//有注册
        {
            Clogin->DBdata->setAccount(this->EdtName->text());

            this->views->showView(ANSWERVIEW);
            this->views->hideView(LOGINVIEW);
        }
        else
        {
            QMessageBox::information(this,"Tips","该账号还未注册！",QMessageBox::Ok);
            clearEdt();
            return;
        }

    }

}

void VLogin::returnSlot()
{
    this->views->hideView(LOGINVIEW);
    this->views->showView(MAINVIEW);
}
