#ifndef VTRANSCODE_H
#define VTRANSCODE_H
#include"VBase.h"
#include"TJGGFrame.h"
#include"CTranscode.h"
#include<QComboBox>
#include<QScrollArea>
#include<QProgressBar>
#include<QFileDialog>
#include<QCalendarWidget>
#include<QTimer>
/*******************
 * 功能：转码界面设置
 * ***********/
class VTranscode:public VBase
{
    Q_OBJECT
public:
    VTranscode();
    void initWidget();
    void initLayout();
    void initConnect();
    void resetJGG();//重置九宫格


private:
     QString inDir;//转码的文件名
    //控制器
    CTranscode *transcode;

    QLabel *LabTitle;
    QLabel *LabDate;
    //查找日期的按钮
    MyLineEdit *EdtbeginDate;//查找开始日期
//    MyLineEdit *EdtendDate;//查找结束日期
    QCalendarWidget *calendarBegin;//开始日历
//    QCalendarWidget *calendarEnd;//结束日期日历
    //九宫格
    TJGGFrame *JGGView;
    QScrollArea *Scrollarea;
    QLabel *LabFormat;//转码格式标签
    QComboBox *FormatChooseBox;//转码格式下拉框
    //选择路径按钮
    MyLineEdit *EdtDir;
    QPushButton *BtnDir;
    QFileDialog *ChooseDir;
    //确认返回按钮
    QPushButton *BtnEnter;
    QPushButton *Btnreturn;

    QTimer *Timer;
    QProgressBar *Progress;//进度条

public slots:
    void returnSlot();
    void ShowBeginCalendar();//显示日期的日历
    void BeginDateSelected(QDate Date);
    void hideCalendar();//日历都被隐藏

    void formatSlot(QString format);

    void DirWidgetShow();//选择目标视频存储目录

    void setInDir(QString inDir);//

    void TrancodeSlot();//转码处理函数



};

#endif // VTRANSCODE_H
