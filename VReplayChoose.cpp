#include "VReplayChoose.h"


VReplayChoose::VReplayChoose()
{
    CreplayChoose=new CReplayChoose();
    this->initWidget();
    this->initLayout();
    this->initConnect();
}

VReplayChoose::~VReplayChoose()
{
}

void VReplayChoose::initWidget()
{
    Title=new QLabel(this);
    LabSearchDate=new QLabel(this);
    this->EdtbeginDate=new MyLineEdit(this);//查找日期当天的视频

    this->Scrollarea=new QScrollArea(this);
    JGGView=new TJGGFrame();
    calendarBegin=new QCalendarWidget(this);
    Btnenter=new QPushButton(this);
    Btnreturn=new QPushButton(this);

}
void VReplayChoose::initLayout()
{
    this->Title->move(this->width()/2-280,10);
    this->Title->setText("STORED VIDEO");
    Title->setObjectName("Title");

    LabSearchDate->setGeometry(130,80,30,30);
    LabSearchDate->setPixmap(QPixmap(":/pictures/date.png").scaled(30,30));
    LabSearchDate->setObjectName("tips");

    EdtbeginDate->setGeometry(180,80,120,30);
    EdtbeginDate->setPlaceholderText("BeginDate");

    calendarBegin->move(130,110);
    calendarBegin->setDateEditEnabled(true);
    calendarBegin->setGridVisible(true);
    QDate nowDate=QDate::currentDate();//获取当前日期
    calendarBegin->setDateRange(QDate(2020,1,1),nowDate);//最后可选择的日期不超过今天
    calendarBegin->hide();

    //九宫格视图
    Scrollarea->setGeometry(30,115,630,360);
    JGGView->setObject("videos");
    Scrollarea->setWidget(this->JGGView);
    Scrollarea->setStyleSheet("border-color:#d4237a");
    Scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Btnenter->setGeometry(this->width()-100,250,80,30);
    Btnenter->setText("ENTER");
    Btnenter->setObjectName("borderBtn");

    Btnreturn->setGeometry(this->width()-100,300,80,30);
    Btnreturn->setText("RETURN");
    Btnreturn->setObjectName("borderBtn");

}
void VReplayChoose::initConnect()
{
    //编辑框结合日历
    connect(EdtbeginDate,SIGNAL(MouseClickSignal()),this,SLOT(ShowBeginCalendarSlot()));
    connect(calendarBegin,SIGNAL(clicked(QDate)),this,SLOT(BeginDateSelectedSlot(QDate)));
    //点击界面其他位置时日历也被关闭
    connect(this,SIGNAL(WidgetClicked()),this,SLOT(hideCalendar()));
    connect(Btnreturn,SIGNAL(clicked(bool)),this,SLOT(returnSlot()));
    //九宫格
    connect(JGGView,SIGNAL(nameSignal(QString)),this,SLOT(selectVideoSlot(QString)));
    connect(Btnenter,SIGNAL(clicked(bool)),this,SLOT(enterSlot()));
}




void VReplayChoose::clearEdt()
{
    this->EdtbeginDate->clear();

}

//关于日历的槽函数
void VReplayChoose::ShowBeginCalendarSlot()
{
    calendarBegin->show();
}
/***********************
 * 选中数据发送到这里
 * *********************/
void VReplayChoose::BeginDateSelectedSlot(QDate Date)
{
    this->EdtbeginDate->setText(Date.toString("yyyy年MM月dd日"));//把日历选择的时间设置到编辑框内
    this->calendarBegin->hide();//隐藏日历
    QString Dayname=Date.toString("yyyy-MM-dd");
    JGGView->setDir(CreplayChoose->model->getvideoDir(),Dayname);
}

void VReplayChoose::hideCalendar()
{
    this->calendarBegin->hide();
}

void VReplayChoose::selectVideoSlot(QString filename)
{
    this->views->setReplayfileName(filename);
}

void VReplayChoose::enterSlot()
{
    qDebug()<<this->views->replayFilename;
    if(this->views->replayFilename.isEmpty()||this->views->replayFilename.isNull())
    {
        QMessageBox::information(this,"tips","还未选择播放文件",NULL);
    }
    this->views->showView(REPLAYVIEW);
}
void VReplayChoose::returnSlot()
{
    this->clearEdt();
    this->views->showView(MAINVIEW);
    this->views->hideView(REPLAYCHOOSEVIEW);
}
