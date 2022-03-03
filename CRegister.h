#ifndef CREGISTER_H
#define CREGISTER_H
#include<QString>
#include"SingleDBOption.h"


/**************
 * 功能：注册控制器，注册逻辑以及对注册界面各种输入信息的判定
 * **************/
class CRegister
{
public:
    CRegister();
    int Register(QString accountInput,QString nameInput,QString pwdInput,QString repwdInput);
    int checkAccount(QString accountInput);

private:
    SingleDBOption *DBdata;//数据库单例
};

#endif // CREGISTER_H
