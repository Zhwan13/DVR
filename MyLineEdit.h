#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H
#include<QLineEdit>
#include<QFocusEvent>
#include<QMouseEvent>
/*******************
 * 功能：重写的编辑框
 * ***********/
class MyLineEdit:public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent=Q_NULLPTR);
    void focusOutEvent(QFocusEvent *e);
    void mousePressEvent(QMouseEvent *event);
//    void focusInEvent(QFocusEvent *e);
signals:
    void focusOut();//编辑框失去焦点时发送信号
    void MouseClickSignal();


};

#endif // MYLINEEDIT_H
