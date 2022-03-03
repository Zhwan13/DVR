#ifndef VLOGIN_H
#define VLOGIN_H

#include"SingleDBOption.h"
#include<QTimer>
#include "VBase.h"
#include"CLogin.h"
#include<QRegExpValidator>

/*******************
 * 功能：登录界面
 * ***********/
class VLogin : public VBase
{
    Q_OBJECT

public:
    explicit VLogin();
    void initWidget();
    void initLayout();
    void initConnect();

    void clearEdt();

    ~VLogin();
//    bool login();
    bool eventFilter(QObject *watched,QEvent *event);

private:
    //定时器
    QTimer *timer;
    //提示窗体
    QMessageBox *msgBox;

    //控制器
    CLogin *Clogin;
    //控件
    QLabel *logintitle;
    QLabel *tips;
    QLabel *LabUsername;
    MyLineEdit *EdtName;
    QLabel *LabNameTip;//输入账号勾

    QLabel *Labuserpass;
    MyLineEdit *EdtPass;
    QLabel *LabPassTip;//输入密码勾
    QPushButton *BtnPassVisible;//密码是否可见
    int PwdFlag;//用来判断密码该显示还是该隐藏

    MyLineEdit *EdtVerify;//验证码
    QPushButton *PicVerify;//验证码图片

    QPushButton *BtnLogin;
    QPushButton *BtnRegis;

    QPushButton *BtnFindPwd;//忘记密码按钮

signals:

public slots:
    void showRegisterView();
//    void showLogin();
    void loginSlog();
    void showAnswerView();
    void returnSlot();
//    void showResetPwdView_slot();
};

#endif // VLOGIN_H
