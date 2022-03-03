#ifndef VSETMSG_H
#define VSETMSG_H
#include"VBase.h"
#include"CSetMsg.h"
#include"cdecode.h"
#include<QMessageBox>
#include<QFileDialog>
/*******************
 * 功能：设置存储路径界面
 * ***********/
class VSetMsg : public VBase
{
    Q_OBJECT
public:
    explicit VSetMsg();

    void initWidget();
    void initLayout();
    void initConnect();

private:
    //线程单例
    CDecode *decode=CDecode::getInstance();
    QLabel *SetTitle;
    QLabel *LabVideoPath;
    MyLineEdit *EdtVideoPath;
    QLabel *LabPicPath;
    MyLineEdit *EdtPicPath;
    QLabel *LabDelay;
    MyLineEdit *EdtDelay;
    QLabel *LabCameraPath;
    MyLineEdit *EdtCameraPath;
    QPushButton *BtnEnter;
    QPushButton *BtnCancel;

    QFileDialog *ChooseDir;//选择的位置
    //控制器
    CSetMsg *Csetmsg;

signals:
    void showMainView();

public slots:
    void enterSlot();
    void returnSlot();
    void PhoPosChoose();
    void VidPosChoose();
};

#endif // VSETMSG_H
