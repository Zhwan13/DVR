#include "mygraphicsitem.h"
#include<iostream>
using namespace  std;

MyGraphicsItem::MyGraphicsItem(QString ImgPath,bool canMove,QGraphicsScene *scene)
{
    this->img.load(ImgPath);
    this->canMove=canMove;
    this->scene=scene;
}

QRectF MyGraphicsItem::boundingRect() const
{
    return QRectF(0,-img.height()/2,img.width(),img.height());
}

void MyGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,-img.height()/2,img);//x,y have to as the same as bounding;
}

void MyGraphicsItem::advance(int phase)
{
    if(this->canMove)
    {
        QPointF point=mapToScene(0,0);//get item position in scene;
        if(this->collidingItems().count()>0)
        {
            this->doColliding();
            delete this;
        }
        else {
            this->setPos(point.x()+5,point.y());
        }
    }
}

void MyGraphicsItem::doColliding()//碰撞检测
{
//    MyGraphicsItem *bom=new MyGraphicsItem(":/pictures/bom.png",false,nullptr);
//    scene->addItem(bom);
//    bom->setPos(this->pos());
    emit hideStartViewSignal();
}
