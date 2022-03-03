#ifndef VREPLAYCHOOSE_H
#define VREPLAYCHOOSE_H

#include"VBase.h"
//#include"VReplay.h"
#include"MyLineEdit.h"
#include"CReplayChoose.h"
#include"TJGGFrame.h"
#include<QCalendarWidget>
#include<QScrollArea>
#include<QDate>
#include<QTimer>

#include<iostream>
using namespace std;
/*******************
 * 功能：回放选择界面
 * ***********/
class VReplayChoose:public VBase
{
    Q_OBJECT
public:
    VReplayChoose();
    ~VReplayChoose();

    void initWidget();
    void initLayout();
    void initConnect();
    void clearEdt();

private:
    QLabel *Title;
    QLabel *LabSearchDate;//查找时间
    QString showDay;//日期-文件名

    MyLineEdit *EdtbeginDate;//查找开始日期
    QCalendarWidget *calendarBegin;//开始日历
    QPushButton *Btnenter;
    QPushButton *Btnreturn;

    TJGGFrame *JGGView;
    QScrollArea *Scrollarea;

    CReplayChoose *CreplayChoose;

public slots:
    void returnSlot();
    void ShowBeginCalendarSlot();//显示结束日期的日历
    void BeginDateSelectedSlot(QDate Date);
    void hideCalendar();//日历都被隐藏
    void selectVideoSlot(QString filename);//获取九宫格时候
    void enterSlot();
};

#endif // VREPLAYCHOOSE_H
