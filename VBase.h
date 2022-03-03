#ifndef VBASE_H
#define VBASE_H
//工具
#include"MyLineEdit.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include<QBitmap>
#include<QPainter>//界面圆角
#include<QString>
#include<QMessageBox>
#include<QMouseEvent>
#include<QIcon>
#include<QPalette>
#include<QDesktopWidget>
#include<QApplication>

#include<QDebug>
#include"SViewManage.h"


/*******************
 * 功能：窗体基类
 * ***********/
class VBase : public QWidget
{
    Q_OBJECT
public:
    explicit VBase(QWidget *parent = nullptr);
    void Basewidget();
    void BaseLayout();
    void BaseConnect();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

protected:
    QPushButton *BtnClose;
    QPushButton *BtnMin;
    QPushButton *BtnReturn;//返回按钮
    bool isMove;
    QPoint mouseClickPoint;
    QPoint frameLTPoint;
    SViewManage *views;

signals:
    void WidgetClicked();//单击界面发送的信号

public slots:
    virtual void returnSlot()=0;//各界面的返回槽函数
};

#endif // VBASE_H
