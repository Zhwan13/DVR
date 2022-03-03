#ifndef VREGISTER_H
#define VREGISTER_H

//#include "user.h"
//#include"singledata.h"
#include"SingleDBOption.h"

#include "VBase.h"
#include "CRegister.h"
#include<QMessageBox>
#include<QTimer>
#include<QRegExpValidator>

#include <iostream>
#include <stdio.h>

using namespace std;
/*******************
 * 功能：注册界面
 * ***********/
class VRegister : public VBase
{
    Q_OBJECT

public:
    explicit VRegister();
    void initWidget();
    void initLayout();
    void initConnect();
    void clearEdt();
    bool eventFilter(QObject *watched,QEvent *event);

    ~VRegister();

private:
    QLabel *RegisterTitle;

    QLabel *LabAccount;
    QLabel *LabUsername;
    QLabel *Labuserpass;
    QLabel *LabRepass;
    QLabel *LabAccountTip;//输入账号勾
    QLabel *LabNameTip;//输入账号勾
    QLabel *LabPassTip;//输入账号勾
    QLabel *LabRepassTip;//输入账号勾

    MyLineEdit *EdtAccount;
    MyLineEdit *EdtName;
    MyLineEdit *EdtPass;
    MyLineEdit *EdtRepass;

    QPushButton *BtnPassVisible;//密码是否可见
    QPushButton *BtnRepassVisible;//确认密码是否可见
    QPushButton *BtnRegister;

    int PwdFlag,RepwdFlag;//用来判断密码明文还是密文

    //单例
    SingleDBOption *DBdata;

    //控制器
    CRegister *Cregister;

signals:
    void showLoginSignal();

public slots:
    void registerSlot();
    void NameFilterslot(QString s);
    void returnSlot();
};

#endif // VREGISTER_H
