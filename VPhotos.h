#ifndef VPHOTOS_H
#define VPHOTOS_H

#include<QScrollArea>
#include"VBase.h"
#include"SingleDBOption.h"
#include"TJGGFrame.h"
#include<QCalendarWidget>
#include<QTimer>

/*******************
 * 功能：显示照片界面
 * ***********/
class VPhotos:public VBase
{
    Q_OBJECT
public:
    VPhotos();
    void initWidget();
    void initLayout();
    void initConnect();
    QString getPhotoDir();

private:

    QLabel *Title;
    TJGGFrame *JGGView;
    QScrollArea *Scrollarea;
    MyLineEdit *EdtbeginDate;//查找开始日期

    QCalendarWidget *calendarBegin;//开始日历
    //日期
    QLabel *LabDate;
    QPushButton *Btnreturn;
    SingleDBOption *DBdata;

//    QTimer *Timer;


public slots:
    void returnSlot();
    void ShowCalendarSlot();//显示结束日期的日历
    void DateSelectedSlot(QDate Date);
    void hideCalendar();//两个日历都被隐藏


};

#endif // VPHOTOS_H
