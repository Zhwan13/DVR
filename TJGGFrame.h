#ifndef TJGGFRAME_H
#define TJGGFRAME_H
#include"VBase.h"
#include<QStringList>
#include<QListWidget>
#include<QListWidgetItem>
#include<QDir>
#include<QVBoxLayout>
#include<QDebug>
#include<iostream>
using namespace std;

#define SHOWVIDEO 1
#define SHOWPHOTO 2

/*******************
 * 功能：九宫格视图
 * ***********/
class TJGGFrame:public QWidget
{
    Q_OBJECT
public:
    TJGGFrame();
    void initWidget();//路径
    void initLayout();
    void initConnect();
    void setDir(QString dire,QString filename);//设置路径
    void setObject(QString object);

private:
    QStringList imgList;//文件目录下所有的图像文件名
    QListWidget *listWidget;//预览窗口
    QString strPath;//文件夹路径
    QLabel showWidget;//图片显示窗口

    QSize IMAGE_SIZE;
    QSize ITEM_SIZE;
    int flag;
    QString ObjectName;//判断是视频的还是照片的九宫格
signals:
    void nameSignal(QString);

public slots:
    void slot_itemClicked(QListWidgetItem*);
};

#endif // TJGGFRAME_H
