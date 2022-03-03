#include "VBase.h"

VBase::VBase(QWidget *parent): QWidget(parent)
{
    isMove=false;
    this->setWindowFlags(Qt::FramelessWindowHint);//hint frame
   //窗体单例
    views=SViewManage::getInstance();

    this->Basewidget();
    this->BaseLayout();
    this->BaseConnect();
}

void VBase::Basewidget()
{
    BtnClose=new QPushButton(this);
    BtnMin=new QPushButton(this);
    BtnReturn=new QPushButton(this);
}

void VBase::BaseLayout()
{
    //窗体icon
    QIcon icon(":/pictures/app.png");
    this->setWindowIcon(icon);

    //窗体初始位置
    this->setGeometry(500,100,800,480);
    QDesktopWidget* desktop = QApplication::desktop(); //获取桌面
    move((desktop->width()-this->width())/2,(desktop->height() - this->height())/2);//设置窗体居中显示
    //窗体背景
    QPixmap winBackground=QPixmap(":/pictures/backgroud-pink-blue.jpg");
    winBackground=winBackground.scaled(800,480);
    QPalette loginPalette;
    loginPalette.setBrush(QPalette::Background,QBrush(winBackground));
    this->setPalette(loginPalette);
    setAutoFillBackground(true);
    //设置圆角
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(), 10, 10);
    setMask(bmp);
    //窗体控件
    //关闭按钮
    BtnClose->move(this->width()-30,0);
    BtnClose->setFixedSize(30,30);
    BtnClose->setIconSize(BtnClose->rect().size());
    BtnClose->setIcon(QIcon(QPixmap(":/pictures/close (1).png").scaled(BtnClose->rect().size())));
    BtnClose->setObjectName("NoBorder");
    //最小化按钮
    BtnMin->move(this->width()-60,0);
    BtnMin->setFixedSize(25,30);
    BtnMin->setIconSize(BtnMin->rect().size());
    BtnMin->setIcon(QIcon(QPixmap(":/pictures/min (1).png").scaled(BtnMin->rect().size())));
    BtnMin->setObjectName("NoBorder");
    //返回按钮
    BtnReturn->setGeometry(30,45,30,30);
    BtnReturn->setIconSize(BtnReturn->rect().size());
    BtnReturn->setIcon(QIcon(QPixmap(":/pictures/back.png").scaled(BtnReturn->rect().size())));
    BtnReturn->setObjectName("NoBorder");
}

void VBase::BaseConnect()
{
    connect(BtnClose,SIGNAL(clicked()),this,SLOT(close()));
    connect(BtnMin,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect(BtnReturn,SIGNAL(clicked()),this,SLOT(returnSlot()));
}

/*******************
 * 功能：检测按钮时间，与下个函数共同实现按住界面拖动界面
 * ***********/
void VBase::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        this->isMove=true;
        mouseClickPoint=event->globalPos();
        frameLTPoint=this->frameGeometry().topLeft();//界面frame左顶点坐标
        emit WidgetClicked();
    }
}

void VBase::mouseMoveEvent(QMouseEvent *event)
{
    if(this->isMove)
    {
        QPoint movPoint=event->globalPos();
        QPoint dis=movPoint-mouseClickPoint;
        this->move(frameLTPoint+dis);
    }
}
