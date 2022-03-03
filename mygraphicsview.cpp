#include "mygraphicsview.h"
/*******************
 * 功能：构造函数
 * ***********/
MyGraphicsView::MyGraphicsView()
{
    this->resize(800,480);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setBackgroundBrush(QBrush(QPixmap(":/pictures/road.jpg").scaled(800,480)));

    scence =new QGraphicsScene();
    this->setScene(scence);
    this->setSceneRect(0,0,this->width()-2,this->height()-2);
    this->Timer=new QTimer();
    Timer->start(100);

    this->InitItem();
    this->initConnect();
}
/*******************
 * 功能：初始化试图内的图元
 * ***********/
void MyGraphicsView::InitItem()
{
    car=new MyGraphicsItem(":/pictures/car.png",true,scence);
    weilan=new MyGraphicsItem(":/pictures/walk.png",false,nullptr);
    scence->addItem(car);
    scence->addItem(weilan);
    car->setPos(0,this->height()*3/4);//设置图元的初始位置
    weilan->setPos(600,this->height()*3/4);//设置图元的初始位置
}

void MyGraphicsView::initConnect()
{
    connect(Timer,SIGNAL(timeout()),scence,SLOT(advance()));
    connect(car,SIGNAL(hideStartViewSignal()),this,SLOT(hideStartViewSlot()));
}

void MyGraphicsView::hideStartViewSlot()
{
    //判断是否有设置信息，--需要访问数据库，有进入主界面
    int ret=model->isSetMsg();
    if(ret==1)
    {
        this->views->showView(MAINVIEW);
        this->views->hideView(STARTVIEW);
        //有设置路径，则编码线程开始
        decode->start();
    }
    else
    {
        this->views->showView(SETMSGVIEW);
        this->views->hideView(STARTVIEW);
    }
}
