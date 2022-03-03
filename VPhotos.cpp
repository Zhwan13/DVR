#include "VPhotos.h"

VPhotos::VPhotos()
{
    DBdata=SingleDBOption::getInstance();
    this->initWidget();
    this->initLayout();
    this->initConnect();

}

void VPhotos::initWidget()
{
    Title=new QLabel(this);
    this->Scrollarea=new QScrollArea(this);
    JGGView=new TJGGFrame();
    LabDate=new QLabel(this);
    Btnreturn=new QPushButton(this);
    this->EdtbeginDate=new MyLineEdit(this);//查找起始日期
    calendarBegin=new QCalendarWidget(this);
}


void VPhotos::initLayout()
{
    this->Title->move(this->width()/2-280,10);
    this->Title->setText("SHOT PHOTOS");
    Title->setObjectName("Title");

    Scrollarea->setGeometry(30,115,630,360);
    JGGView->setObject("photos");
    Scrollarea->setWidget(this->JGGView);
    Scrollarea->setStyleSheet("border-color:#d4237a");

    Scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //日期标签---改成日历图标
    LabDate->setGeometry(130,80,30,30);
    LabDate->setPixmap(QPixmap(":/pictures/date.png").scaled(30,30));

    EdtbeginDate->setGeometry(180,80,120,30);
    EdtbeginDate->setPlaceholderText("BeginDate");

    calendarBegin->move(130,110);
    calendarBegin->setDateEditEnabled(true);
    calendarBegin->setGridVisible(true);
    QDate nowDate=QDate::currentDate();//获取当前日期
    calendarBegin->setDateRange(QDate(2020,1,1),nowDate);//最后可选择的日期不超过今天
    calendarBegin->hide();

    Btnreturn->move(this->width()-100,400);
    Btnreturn->setText("RETURN");
    Btnreturn->setObjectName("borderBtn");
}

void VPhotos::initConnect()
{
    connect(EdtbeginDate,SIGNAL(MouseClickSignal()),this,SLOT(ShowCalendarSlot()));
    connect(calendarBegin,SIGNAL(clicked(QDate)),this,SLOT(DateSelectedSlot(QDate)));
    //点击界面其他位置时日历也被关闭
    connect(this,SIGNAL(WidgetClicked()),this,SLOT(hideCalendar()));
    connect(Btnreturn,SIGNAL(clicked(bool)),this,SLOT(close()));
}

/*******************
 * 功能：查找照片存储位置
 * ***********/
QString VPhotos::getPhotoDir()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql;//找到存储路径
    sql="SELECT * FROM t_setMsg";//查询
    DBdata->getTable(sql,pResult,row,col);
    if(row>=1)//成功
    {
        qDebug()<<pResult[7];
        return QString(pResult[7]);
    }
    else
    {
        return NULL;
    }
}
void VPhotos::returnSlot()
{//返回行车记录仪主界面
    this->views->showView(MAINVIEW);
    views->hideView(PHOTOSVIEW);
}
//日历相关槽函数
void VPhotos::ShowCalendarSlot()
{
    calendarBegin->show();
}

void VPhotos::DateSelectedSlot(QDate Date)
{
    this->EdtbeginDate->setText(Date.toString("yyyy年MM月dd日"));
    this->calendarBegin->hide();
    QString Dayname=Date.toString("yyyy-MM-dd");
    this->JGGView->setDir(this->getPhotoDir(),Dayname);
}

void VPhotos::hideCalendar()
{
    this->calendarBegin->hide();
}
