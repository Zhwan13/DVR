#include "CRegister.h"
#include<QDebug>
CRegister::CRegister()
{
    DBdata=SingleDBOption::getInstance();
}
/*******************
 * 功能：注册逻辑和输入信息判定
 * ***********/
int CRegister::Register(QString accountInput,QString nameInput, QString pwdInput,QString repwdInput)
{
    //是否有空
    if(accountInput.isEmpty()||nameInput.isEmpty()||pwdInput.isEmpty()||repwdInput.isEmpty())
    {
        return 0;
    }
    //判断输入的是否合格
    else if(checkAccount(accountInput)==1)//账号已存在
    {
        return 1;
    }
    else if(strcmp(pwdInput.toStdString().c_str(),repwdInput.toStdString().c_str())!=0)//两次密码不一致
    {
        return 2;
    }
    else if(accountInput.length()<8||pwdInput.length()<6)
    {
        return 3;
    }
    else
    {
        QString sql="INSERT INTO t_user (Account,Name,Pwd,type) VALUES ('"+accountInput+"','"+nameInput+"','"+pwdInput+"',0);";
        DBdata->OptionSQL(sql);
        return 4;//注册成功
    }
}
/*******************
 * 功能：检查账号是否已经存在，已存在就不能注释
 * ***********/
int CRegister::checkAccount(QString accountInput)
{
    char **pResult=nullptr;//用完要自己释放
    int row;//行
    int col;//列
    QString sql="select *from t_user where Account = "+accountInput;
    DBdata->getTable(sql,pResult,row,col);
    if(row>0)
        return 1;//已存在
    else
        return 0;//未找到
}
