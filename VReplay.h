#ifndef VREPLAY_H
#define VREPLAY_H
#include"VBase.h"
/*******************
 * 功能：回放界面
 * ***********/
class VReplay:public VBase
{
    Q_OBJECT
public:

    VReplay();
    void initWidget();
    void initLayout();
    void initConnect();

    void setName(QString name);
private:
    QLabel *LabName;
    QLabel *LabVideo;
    QPushButton *BtnExport;
    QPushButton *BtnShot;
    QPushButton *BtnSpeed;
    QPushButton *BtnStop;
    QString videoName;

public slots:
    void returnSlot();
    void PlayOrNot();//点击按钮开始播放视频
    void exportSlot();
    void shotSlot();

    void showVideoSlot(QImage imag);
};

#endif // VREPLAY_H
