#ifndef VANSWER_H
#define VANSWER_H
#include "VBase.h"
#include<QComboBox>
#include<QFont>
#include"VResetPwd.h"

/***********
 * 忘记密码回答问题界面
 * *********************/

class VAnswer:public VBase
{
    Q_OBJECT
public:
    VAnswer();
    void initWidget();
    void initLayout();
    void initConnect();

private:
    QLabel *LabTitle;
    QLabel *LabTip;//提示信息
    QComboBox *box;//下拉框
    MyLineEdit *EdtAnswer;
    QPushButton *BtnConfirm;
//    QPushButton *BtnReturn;
signals:
//    void showResetSignal();
    void returnLoginSignal();

public slots:
    void ResetLSlot();
    void returnSlot();
};

#endif // VANSWER_H
