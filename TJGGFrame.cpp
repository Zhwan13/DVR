#include "TJGGFrame.h"

TJGGFrame::TJGGFrame()
{

    this->initWidget();
    this->initLayout();
    this->initConnect();
}

void TJGGFrame::initWidget()
{
    this->listWidget=new QListWidget();
}

void TJGGFrame::initLayout()
{

    // 窗口布局
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(listWidget);
    mainLayout->setMargin(0);
    this->setLayout(mainLayout);

    this->setWindowTitle("Image Preview");
    this->setMinimumSize(630,380);
    showWidget.setWindowTitle("Image show");
    showWidget.setAlignment(Qt::AlignCenter);//居中对齐

    const QSize IMAGE_SIZE(185, 95);
    const QSize ITEM_SIZE(185, 115);
    this->IMAGE_SIZE=IMAGE_SIZE;
    this->ITEM_SIZE=ITEM_SIZE;

    // QListWidget基本设置
    listWidget->setIconSize(IMAGE_SIZE);
    listWidget->setResizeMode(QListView::Adjust);
    listWidget->setViewMode(QListView::IconMode);
    listWidget->setMovement(QListView::Static);
    listWidget->setSpacing(3);//周围填充空白部分的大小

    this->setDir(this->strPath,nullptr);
}

void TJGGFrame::initConnect()
{    // 信号与槽
    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(slot_itemClicked(QListWidgetItem*)));
}

/******************************************************
     * 函数名：setDir
     * 参数列表dir
     * 参数解释：路径
     * 用处：设置九宫格显示的目录
     * 返回值：空
    *******************************************************/
void TJGGFrame::setDir(QString dire, QString filename)
{
    if(dire.isEmpty()||dire.isNull())
    {
        qDebug()<<"JGG dir not exist";
        return;
    }
    else
        this->strPath=dire;
    // 判断路径是否存在
    QDir dir(strPath);
    if (!dir.exists()) {
        cout<<"photo dir not exist";
        return;
    }
    this->imgList.clear();
    this->listWidget->clear();

    // 设置过滤器
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    QStringList filters;

    QString fileCheck=QString("%1*.png").arg(filename);
    filters <<fileCheck;
    dir.setNameFilters(filters);
    imgList = dir.entryList();
    if (imgList.count() <= 0) {
        if(this->ObjectName=="videos")
            QMessageBox::information(this,"tips","未找到该日期的视频！",NULL);
        else if(this->ObjectName=="photos")
            QMessageBox::information(this,"tips","未找到该日期的照片！",NULL);
        else{}
        qDebug()<<"no find item";
        return;
    }
    // 创建单元项
    for (int i = 0; i<imgList.count(); ++i) {
        QPixmap pixmap(strPath + "/" + imgList.at(i));
        QListWidgetItem *listWidgetItem = new QListWidgetItem(QIcon(pixmap.scaled(IMAGE_SIZE)), imgList.at(i));
        listWidgetItem->setSizeHint(ITEM_SIZE);
        listWidget->insertItem(i, listWidgetItem);
    }
}

void TJGGFrame::setObject(QString object)
{
    this->ObjectName=object;
}

// 最大化窗口显示图像
void TJGGFrame::slot_itemClicked(QListWidgetItem * item)
{
    if(this->ObjectName=="photos")
    {
        showWidget.setPixmap(QPixmap(strPath + "/" + imgList.at(listWidget->row(item))));
        showWidget.setGeometry(500,100,800,480);
        showWidget.show();
    }
    else if(this->ObjectName=="videos")
    {
        QString Phoname=strPath + "/" + imgList.at(listWidget->row(item));//name是图片的文件名
        //裁去图片文件名的后缀，补充上.h264后缀
        int suffix=Phoname.indexOf(".");//后缀
        QString Vidname=Phoname.left(suffix);
        Vidname=Vidname+".h264";
//        qDebug()<<"转码文件名"+Vidname;
        emit nameSignal(Vidname);
    }

}
