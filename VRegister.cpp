#include "VRegister.h"

VRegister::VRegister()
{
    this->initWidget();
    this->initLayout();
    this->initConnect();

    DBdata=SingleDBOption::getInstance();
    Cregister =new CRegister();

}

void VRegister::initWidget()
{
    this->setWindowFlags(Qt::FramelessWindowHint);//hint frame

    RegisterTitle=new QLabel(this);
    LabAccount=new QLabel(this);
    EdtAccount=new MyLineEdit(this);
    LabAccountTip=new QLabel(this);

    LabUsername=new QLabel(this);
    EdtName=new MyLineEdit(this);
    LabNameTip=new QLabel(this);

    Labuserpass=new QLabel(this);
    EdtPass=new MyLineEdit(this);
    LabPassTip=new QLabel(this);

    LabRepass=new QLabel(this);
    EdtRepass=new MyLineEdit(this);
    LabRepassTip=new QLabel(this);

    BtnPassVisible=new QPushButton(this);
    BtnRepassVisible=new QPushButton(this);
    PwdFlag=RepwdFlag=0;

    BtnRegister=new QPushButton(this);

//    msgBox=new QMessageBox(QMessageBox::Information,tr("你好"),tr("你好"));
}

void VRegister::initLayout()
{
    RegisterTitle->move(60,30);//登录标签
    RegisterTitle->setText("SIGN UP");
    RegisterTitle->setObjectName("Title");

    LabAccount->move(100,120);
    LabAccount->setPixmap(QPixmap(":/pictures/user (1).png").scaled(30,30));

    EdtAccount->setGeometry(140,120,200,30);
    EdtAccount->setMaxLength(8);
    EdtAccount->setPlaceholderText("账号/不小于8位英文或数字");
    EdtAccount->installEventFilter(this);//安装事件过滤器

    LabAccountTip->move(340,120);//输入后显示勾勾
    LabAccountTip->setPixmap(QPixmap(":/pictures/benefits (1).png").scaled(30,30));
    LabAccountTip->setVisible(false);

    LabUsername->move(100,170);
    LabUsername->setPixmap(QPixmap(":/pictures/user (1).png").scaled(30,30));

    EdtName->setGeometry(140,170,200,30);
    EdtName->setMaxLength(8);
    EdtName->setPlaceholderText("用户名/中文或英文");
    QRegExp regx("^[\u4e00-\u9fa5a-zA-Z]+$");//只能输入英文和英文
    QValidator *validator0=new QRegExpValidator(regx,EdtPass);
    EdtPass->setValidator(validator0);
    EdtName->installEventFilter(this);//安装事件过滤器

    LabNameTip ->move(340,170);//输入后显示勾勾
    LabNameTip->setPixmap(QPixmap(":/pictures/benefits (1).png").scaled(30,30));
    LabNameTip->setVisible(false);

    Labuserpass->move(100,220);
    Labuserpass->setPixmap(QPixmap(":/pictures/lock (1).png").scaled(30,30));

    EdtPass->setGeometry(140,220,200,30);
    EdtPass->setEchoMode(QLineEdit::Password);
    EdtPass->setMaxLength(16);
    EdtPass->setPlaceholderText("密码/6~16位英文或数字");
    QRegExp regx1("^[A-Za-z0-9]+$");//只能输入英文和数字
    QValidator *validator1=new QRegExpValidator(regx1,EdtPass);
    EdtPass->setValidator(validator1);
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
    EdtRepass->setEchoMode(QLineEdit::Password);
    EdtRepass->setMaxLength(16);
    QValidator *validator2=new QRegExpValidator(regx1,EdtRepass);
    EdtPass->setValidator(validator2);
    EdtRepass->setPlaceholderText("确认密码/6~16位英文或数字");
    EdtRepass->installEventFilter(this);//安装事件过滤器

    LabRepassTip->move(340,270);//输入后显示勾勾
    LabAccountTip->setPixmap(QPixmap(":/pictures/benefits (1).png").scaled(30,30));
    LabAccountTip->setVisible(false);

    BtnRepassVisible->move(140+200-25,270);
    BtnRepassVisible->setFixedSize(25,25);
    BtnRepassVisible->setIconSize(BtnRepassVisible->rect().size());
    BtnRepassVisible->setIcon(QIcon(QPixmap(":/pictures/view (1).png").scaled(BtnRepassVisible->rect().size())));
    BtnRepassVisible->setObjectName("NoBorder");
    BtnRepassVisible->installEventFilter(this);//安装事件过滤器

    //Button
    BtnRegister->move(140,320);
    BtnRegister->setText("Sign Up");
    BtnRegister->setFont(QFont("幼圆",20));
    BtnRegister->setObjectName("btn");
    BtnRegister->installEventFilter(this);//安装事件过滤器
}

void VRegister::initConnect()
{
    connect(BtnRegister,SIGNAL(clicked()),this,SLOT(registerSlot()));
    connect(EdtName, SIGNAL(textChanged(QString)), this, SLOT(NameFilterslot(QString)));
}
/*******************
 * 功能：清除编辑框内容
 * ***********/
void VRegister::clearEdt()
{
    this->EdtAccount->clear();
    this->EdtName->clear();
    this->EdtPass->clear();
    this->EdtRepass->clear();
}

bool VRegister::eventFilter(QObject *watched, QEvent *event)//监测是否有点击密码显示隐藏按键、是否有输入内容
{
    if(watched==EdtAccount)
    {
        if(event->type()==QEvent::KeyRelease)
        {
            QString input1=this->EdtAccount->text();
            if(input1.length()>=8)
            {
                LabAccountTip->setVisible(true);
            }
            else
            {
                LabAccountTip->setVisible(false);
            }
        }
    }
    if(watched==EdtName)
    {
        if(event->type()==QEvent::KeyRelease)
        {
            QString input2=this->EdtName->text();
            if(input2.isEmpty())
            {
                LabNameTip->setVisible(false);
            }
            else
            {
                LabNameTip->setVisible(true);
            }
        }
    }
    if(watched==EdtPass)
    {
        if(event->type()==QEvent::KeyRelease)
        {
            QString input3=this->EdtPass->text();
            if(input3.length()>=6)
            {
                LabPassTip->setVisible(true);
            }
            else
            {
                LabPassTip->setVisible(false);
            }
        }
    }
    else if(watched==this->EdtRepass||watched==this->BtnRegister)
    {
        if(event->type()==QEvent::KeyRelease)
        {
            QString input4=this->EdtRepass->text();
            if(input4.length()>=6)
            {
                LabRepassTip->setVisible(true);
            }
            else
            {
                LabRepassTip->setVisible(false);
            }
            //QKeyEvent *key;
            if(((QKeyEvent *)event)->key()==Qt::Key_Enter||((QKeyEvent *)event)->key()==Qt::Key_Return)
            {
                this->registerSlot();
                return true;
            }
            else {
                return false;
            }
        }
    }
    else if(watched==this->BtnPassVisible)//监视小眼睛按钮是否被点击
    {
        if(event->type()==QEvent::MouseButtonPress)//鼠标点击
        {
            PwdFlag=!PwdFlag;
            if(PwdFlag){
                EdtPass->setEchoMode(QLineEdit::Normal);
                }
            else{
                EdtPass->setEchoMode(QLineEdit::Password);
                }
            return true;
        }
        else
            return false;
    }
    else if(watched==this->BtnRepassVisible)//监视小眼睛按钮是否被点击
    {
        if(event->type()==QEvent::MouseButtonPress)//鼠标点击
        {
            RepwdFlag=!RepwdFlag;
            if(RepwdFlag)
                {
                EdtRepass->setEchoMode(QLineEdit::Normal);
                }
            else
                {
                EdtRepass->setEchoMode(QLineEdit::Password);
                }
            return true;
        }
        else
            return false;
    }

    return false;
}

VRegister::~VRegister()
{
}

void VRegister::registerSlot()
{
    int ret=Cregister->Register(EdtAccount->text(),EdtName->text(),EdtPass->text(),EdtRepass->text());
    if(ret==0)
    {
        QMessageBox::information(this,"Tips","Edit box cannot be empty!",QMessageBox::Ok);
    }
    else if(ret==1)
    {//账号已存在
        QMessageBox::information(this,"Tips"," account already exists!",QMessageBox::Ok);
    }
    else if(ret==2)
    {
        QMessageBox::information(this,"Tips"," The two passwords do not match.",QMessageBox::Ok);
    }

    else if(ret==3)
    {
        QMessageBox::information(this,"Tips","账号或密码输入不合格",QMessageBox::Ok);
    }
    else if(ret==4)
    {
        QMessageBox::information(this,"Tips","Register was successful!",QMessageBox::Ok);
        this->views->showView(LOGINVIEW);
        this->views->hideView(REGISTERVIEW);
        this->clearEdt();
        return;
    }
    else
    {
        QMessageBox::information(this,"Tips"," Register has failed!",QMessageBox::Ok);
    }
    this->clearEdt();
    LabAccountTip->hide();
    LabNameTip->hide();
    LabPassTip->hide();
    LabPassTip->hide();
    LabRepassTip->hide();

}

/*************
 * 用户名过滤中文字符
 * *************/
void VRegister::NameFilterslot(QString s)
{
    s.replace(QString::fromLocal8Bit("【"), "");
    s.replace(QString::fromLocal8Bit("】"), "");
    s.replace(QString::fromLocal8Bit("？"), "");
    s.replace(QString::fromLocal8Bit("！"), "");
    s.replace(QString::fromLocal8Bit("·"), "");
    s.replace(QString::fromLocal8Bit("￥"), "");
    s.replace(QString::fromLocal8Bit("……"), "");
    s.replace(QString::fromLocal8Bit("（"), "");
    s.replace(QString::fromLocal8Bit("）"), "");
    s.replace(QString::fromLocal8Bit("——"), "");
    s.replace(QString::fromLocal8Bit("、"), "");
    s.replace(QString::fromLocal8Bit("："), "");
    s.replace(QString::fromLocal8Bit("；"), "");
    s.replace(QString::fromLocal8Bit("“"), "");    //引号两边分开过滤
    s.replace(QString::fromLocal8Bit("”"), "");
    s.replace(QString::fromLocal8Bit("’"), "");    //引号两边分开过滤
    s.replace(QString::fromLocal8Bit("‘"), "");
    s.replace(QString::fromLocal8Bit("《"), "");
    s.replace(QString::fromLocal8Bit("》"), "");
    s.replace(QString::fromLocal8Bit("，"), "");
    s.replace(QString::fromLocal8Bit("。"), "");
    EdtName->setText(s);
}

void VRegister::returnSlot()
{

    this->clearEdt();//清除编辑框

    this->views->showView(LOGINVIEW);
    this->views->hideView(REGISTERVIEW);
}
