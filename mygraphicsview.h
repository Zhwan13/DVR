#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include"mygraphicsitem.h"
#include<QTimer>
#include"SViewManage.h"
#include"SModel.h"
#include"cdecode.h"
/*******************
 * 视图文件
 * ***********/
class MyGraphicsView:public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsView();
    void InitItem();
    void initConnect();
private:
    QGraphicsScene *scence;
    MyGraphicsItem *car;
    MyGraphicsItem *weilan;
    QTimer *Timer;
    //界面管理器单例
    SViewManage *views=SViewManage::getInstance();

    SModel *model=SModel::getInstance();
    CDecode *decode=CDecode::getInstance();
public slots:
    void hideStartViewSlot();

};

#endif // MYGRAPHICSVIEW_H
