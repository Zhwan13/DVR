#include "SingleDBOption.h"
#include<QDebug>
SingleDBOption *SingleDBOption::instance=nullptr;

SingleDBOption::SingleDBOption()
{
    this->setMsgflag=0;
    this->openDataBase();
}
/****************
 * 打开数据库
 * *************/
void SingleDBOption::openDataBase()
{
    this->ret=sqlite3_open("../data/data.db",&db);//dbPath.toStdString().c_str()
    ret=this->judgeRet(ret);
}


SingleDBOption::~SingleDBOption()
{
    this->closeDataBase();
}


/*****************
 * 判断是否成功执行数据库操作
 *************************/
int SingleDBOption::judgeRet(int ret)
{
    if(ret==SQLITE_OK){
        return 0;
    }
    else {
        char *errmsg=(char *)sqlite3_errmsg(db);
        cout<<"fail, error message:"<<errmsg<<endl;
        return 1;
    }
}

SingleDBOption *SingleDBOption::getInstance()
{
    if(instance==nullptr)
    {
        instance=new SingleDBOption();
    }
    return instance;
}
/*******************
 * 功能：关闭数据库
 * ***********/
void SingleDBOption::closeDataBase()
{
    int ret=sqlite3_close(db);
    ret=judgeRet(ret);
}
/*******************
 * 功能：获取表
 * ***********/
int SingleDBOption::getTable(QString sql, char **&pResult, int &row, int &col)//获取表,返回的结果是qResult
{
    char *errmsg;
    int ret=sqlite3_get_table(db,sql.toStdString().c_str(),&pResult,&row,&col,&errmsg);
    return this->judgeRet(ret);//返回0则获取到表
}

/*******************
 * 功能：数据库操作
 * ***********/
int SingleDBOption::OptionSQL(QString sql)
{
    sqlite3_stmt *stmt;
    ret=sqlite3_prepare(db,sql.toStdString().c_str(),-1,&stmt,nullptr);//-1就传的是sql语句的长度
    ret=this->judgeRet(ret);
    if(ret==0)//预编译成功
    {
        ret=sqlite3_step(stmt);
        if(ret==SQLITE_DONE)
        {
            //插入成功
            cout<<"get in ret"<<endl;
            return 1;
        }
    }
    else
    {
        cout<<"option failure"<<endl;
        return ret;
    }
    sqlite3_finalize(stmt);
    return -1;
}

void SingleDBOption::setAccount(QString account)
{
    this->account=account;
}

void SingleDBOption::checkMsg()
{
    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql="SELECT * FROM t_setMsg";//查询
    getTable(sql,pResult,row,col);
    if(row>=1)//成功
    {
        this->setMsgflag=1;
    }
    else
    {
        this->setMsgflag=0;
    }
}


