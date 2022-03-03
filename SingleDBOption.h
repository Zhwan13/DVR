#ifndef SINGLEDBOPTION_H
#define SINGLEDBOPTION_H
#include<sqlite3.h>
#include<QString>
#include<iostream>
using namespace std;

/*****************
 * 数据库单例
 * **************/

class SingleDBOption
{
public:
    static SingleDBOption *getInstance();
    ~SingleDBOption();
    void openDataBase();
    void closeDataBase();
    int judgeRet(int ret);
    int getTable(QString sql, char **&qResult, int &row, int &col);
    int OptionSQL(QString sql);
    void setAccount(QString account);//获取账号
    void checkMsg();

    QString account;//需要重置密码的账号

private:
    static SingleDBOption* instance;
    SingleDBOption();
    sqlite3 *db;//数据库句柄
    int setMsgflag;//设置信息表里信息是否有数据
    int ret;

};

#endif // SINGLEDBOPTION_H
