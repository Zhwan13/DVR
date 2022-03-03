#include "MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void MyLineEdit::focusOutEvent(QFocusEvent *e)
{
    QLineEdit::focusOutEvent(e);//显式调用父类
    emit focusOut();//发送失去焦点信号
}

void MyLineEdit::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        emit MouseClickSignal();
    }
    QLineEdit::mousePressEvent(event);
}

//void MyLineEdit::focusInEvent(QFocusEvent *e)
//{
//    QLineEdit::focusInEvent(e);//显式调用父类
//    emit MouseClickSignal();
//}
