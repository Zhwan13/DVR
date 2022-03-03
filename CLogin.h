#ifndef CLOGIN_H
#define CLOGIN_H
#include<QString>
#include<QDebug>
#include<iostream>

#include"SingleDBOption.h"
using namespace std;

/**************
 * 功能：登入控制器，包含对登录界面的各种条件的判定
 * **************/
class CLogin
{
public:
    CLogin();
    void setAccount(QString accountinput);
    void setPwd(QString pwdinput);
    void setVertify(QString verifyinput);

    int checkAccount(QString accountinput);
    int checkInput();
    int login();

    void setType();//改变登录状态

    SingleDBOption *DBdata;
private:
    QString accountinput;
    QString pwdinput;
    QString verifyinput;//验证码

    int flag=0;//是否登录成功


    //数据库单例

};

#endif // CLOGIN_H
