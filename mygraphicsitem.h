#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include<QPointF>
#include<QGraphicsScene>
#include<QObject>

/*******************
 * 图元文件
 * ***********/
class MyGraphicsItem:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    MyGraphicsItem(QString ImgPath,bool canMove,QGraphicsScene *scene);
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void advance(int phase);
    void doColliding();


private:
    QPixmap img;
    bool canMove;
    QGraphicsScene *scene;

signals:
    void hideStartViewSignal();
public slots:

};

#endif // MYGRAPHICSITEM_H
