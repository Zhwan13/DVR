#ifndef VRESETPWD_H
#define VRESETPWD_H

#include"SingleDBOption.h"
#include "VBase.h"
#include<iostream>
using namespace std;
/***************************
 * 重置密码界面
 * *******************/
class VResetPwd:public VBase
{
    Q_OBJECT
public:
    VResetPwd();
    void initWidget();
    void initLayout();
    void initConnect();
private:
    SingleDBOption *DBdata=SingleDBOption::getInstance();

    QLabel *ResetTitle;
    QLabel *Labuserpass;
    MyLineEdit *EdtPass;
    QPushButton *BtnPassVisible;//密码是否可见
    QLabel *LabPassTip;//输入账号勾

    QLabel *LabRepass;
    MyLineEdit *EdtRepass;
    QLabel *LabRepassTip;//输入账号勾
    QPushButton *BtnRepassVisible;//确认密码是否可见

    QPushButton *BtnReset;//重置密码
//    QPushButton *BtnReturn;//返回界面

signals:


public slots:
//    void returnAnswerSlot();
    void resetPwdSlot();
    void returnSlot();

};
#endif // VRESETPWD_H
