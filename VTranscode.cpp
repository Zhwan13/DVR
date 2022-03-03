#include "VTranscode.h"

VTranscode::VTranscode()
{
    this->initWidget();
    this->initLayout();
    this->initConnect();
}

void VTranscode::initWidget()
{
    transcode=new CTranscode();

    this->LabTitle=new QLabel(this);
    LabDate=new QLabel(this);
    this->EdtbeginDate=new MyLineEdit(this);//查找起始日期

    JGGView=new TJGGFrame();
    Scrollarea=new QScrollArea(this);

    calendarBegin=new QCalendarWidget(this);

    LabFormat=new QLabel(this);//“转码格式”
    FormatChooseBox=new QComboBox(this);
    EdtDir=new MyLineEdit(this);
    Progress=new QProgressBar(this);//进度条
    BtnDir=new QPushButton(this);
    ChooseDir=new QFileDialog(this);
    BtnEnter=new QPushButton(this);
    Btnreturn=new QPushButton(this);

}

void VTranscode::initLayout()
{
    LabTitle->move(this->width()/2-230,10);
    LabTitle->setText("TRANSCODE");
    LabTitle->setObjectName("Title");

    LabDate->setGeometry(80,90,30,30);
    LabDate->setPixmap(QPixmap(":/pictures/date.png").scaled(30,30));

    EdtbeginDate->setGeometry(130,90,120,30);

    calendarBegin->move(130,120);
    calendarBegin->setDateEditEnabled(true);
    calendarBegin->setGridVisible(true);
    QDate nowDate=QDate::currentDate();//获取当前日期
    calendarBegin->setDateRange(QDate(2020,1,1),nowDate);//最后可选择的日期不超过今天
    calendarBegin->hide();

    Scrollarea->setGeometry(30,140,630,180);
    JGGView->setObject("videos");
    Scrollarea->setWidget(this->JGGView);
    Scrollarea->setStyleSheet("border-color:#d4237a");

    Scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    LabFormat->move(100,340);
    LabFormat->setText("转码格式");
    LabFormat->setObjectName("tips");

    FormatChooseBox->setGeometry(200,340,80,30);
    FormatChooseBox->addItem("mp4");
//    FormatChooseBox->addItem("avi");

    EdtDir->setGeometry(90,390,230,30);
    EdtDir->setPlaceholderText("输出文件保存路径");
//    EdtDir->setEnabled(false);

    BtnDir->setGeometry(320,390,150,30);
    BtnDir->setText("选择保存目录");
    BtnDir->setObjectName("btn");

    ChooseDir->setWindowTitle("文件保存位置");
    ChooseDir->setFileMode(QFileDialog::AnyFile);//返回文件路径，带文件名
    ChooseDir->setDefaultSuffix("mp4");// 默认后缀mp4

    Progress->setGeometry(90,440,350,30);

    BtnEnter->move(this->width()-250,350);
    BtnEnter->setText("ENTER");
    BtnEnter->setObjectName("btn");

    Btnreturn->move(this->width()-250,400);
    Btnreturn->setText("CANCEL");
    Btnreturn->setObjectName("btn");
}

void VTranscode::initConnect()
{
    connect(EdtbeginDate,SIGNAL(MouseClickSignal()),this,SLOT(ShowBeginCalendar()));
    connect(calendarBegin,SIGNAL(clicked(QDate)),this,SLOT(BeginDateSelected(QDate)));
    connect(this,SIGNAL(WidgetClicked()),this,SLOT(hideCalendar()));

    connect(FormatChooseBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(formatSlot(QString)));
    connect(BtnDir,SIGNAL(clicked(bool)),this,SLOT(DirWidgetShow()));
    connect(Btnreturn,SIGNAL(clicked(bool)),this,SLOT(returnSlot()));//两个返回按钮对应同一个槽函数
    connect(BtnEnter,SIGNAL(clicked(bool)),this,SLOT(TrancodeSlot()));//确认开始转换

    //九宫格传文件名出来
    connect(JGGView,SIGNAL(nameSignal(QString)),this,SLOT(setInDir(QString)));
}


void VTranscode::resetJGG()
{
    //    JGGView->setDir(transcode->getDir());
}

void VTranscode::setInDir(QString inDir)
{
    this->inDir=inDir;
}
void VTranscode::returnSlot()
{
    this->views->showView(MAINVIEW);
    this->views->hideView(TRANSCODEVIEW);
}
//槽函数
void VTranscode::ShowBeginCalendar()
{
//    if(calendarEnd->isVisible())
//        calendarEnd->hide();
    calendarBegin->show();
}

void VTranscode::BeginDateSelected(QDate Date)
{
    this->EdtbeginDate->setText(Date.toString("yyyy年MM月dd日"));
    this->calendarBegin->hide();
    QString Dayname=Date.toString("yyyy-MM-dd");
    JGGView->setDir(transcode->model->getvideoDir(),Dayname);
}

void VTranscode::hideCalendar()
{
    this->calendarBegin->hide();
}

void VTranscode::formatSlot(QString format)
{
    ChooseDir->setDefaultSuffix(format);
}

void VTranscode::DirWidgetShow()
{
    this->ChooseDir->exec();
    if(ChooseDir->selectedFiles().isEmpty())
        return;
    else
        this->EdtDir->setText(ChooseDir->selectedFiles()[0]);
}

/*******************
 * 转码槽函数
 * *********************/
void VTranscode::TrancodeSlot()
{
    int ret=this->transcode->checkMsg(this->EdtDir->text(),this->inDir);//检查待转码文件和转码后文件保存位置是否设置
    if(ret==0)
    {
        QMessageBox::information(this,"Tips","请选择文件保存目录",QMessageBox::Ok);
        return;
    }
    else if(ret==2)//没有选择转码文件
    {
        QMessageBox::information(this,"Tips","请选择转码文件",QMessageBox::Ok);
        return;
    }
    //设置文件名
    transcode->setInFile(this->inDir);//待转码的视频路径
    transcode->setOutFile(this->EdtDir->text());//输出文件名
    if(this->FormatChooseBox->currentText()=="mp4")
    {
        transcode->transcodeToMp4();//转码成MP4
    }

}
