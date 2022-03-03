#ifndef VMAIN_H
#define VMAIN_H
#include"VBase.h"
#include<QImage>
#include"SingleDBOption.h"
#include<QTimer>//时间更新
#include<QDateTime>//用来设置日历的最大显示日期
#include"SModel.h"
#include"cdecode.h"
#include<QCameraImageCapture>
/*******************
 * 功能：主界面
 * ***********/
class VMain:public VBase
{
    Q_OBJECT
public:
    VMain();
    void initWidget();
    void initLayout();
    void initConnect();
    int isLogin();//判断是否有登录

private:
    SingleDBOption *DBdata=SingleDBOption::getInstance();
    SModel *model=SModel::getInstance();

    QTimer *timer;
    QLabel *LabTitle;//标题
    QLabel *LabDate;//时间
    //解码
    CDecode *fdecode;       //解码线程

    QLabel *LabMain;//主界面显示图形
    QPushButton *BtnSet;//设置按钮
    QPushButton *BtnExit;//退出按钮
    QPushButton *Btnmenu;//显示菜单按钮
    QPushButton *BtnTakeapicture;//拍照转码
    QPushButton *BtnReplay;//回放
    QPushButton *BtnPhoto;//照片
    QPushButton *BtnTranscoding;//转码
    int flag=0;

    QImage saveimag;//点击拍照后需要保存的照片

signals:

public slots:
    //界面显示的各种槽函数
    void TimeUpdata();//显示时间槽函数
    void showImgSlot(QImage imag);//显示实时画面
    void ShowOrHideBtn();//显示或者隐藏菜单
    //界面切换槽函数
    void showSetView();//显示设置界面
        //业务功能-拍照-回放-照片-转码按键
    void takeAphotoSlot();
    void replaySlot();
    void photosSlot();
    void transcodingSlot();

    void returnSlot();//窗体基类的虚函数

};

#endif // VMAIN_H
