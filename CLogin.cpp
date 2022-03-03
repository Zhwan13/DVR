#include "CLogin.h"

CLogin::CLogin()
{
    DBdata=SingleDBOption::getInstance();
//    DBdata->openDataBase();
}

void CLogin::setAccount(QString accountinput)
{
    this->accountinput=accountinput;
}

void CLogin::setPwd(QString pwdinput)
{
    this->pwdinput=pwdinput;
}

void CLogin::setVertify(QString verifyinput)
{
    this->verifyinput=verifyinput;
}

/**************
 * 功能：检查输入的数据是否符合条件
 * **************/
int CLogin::checkInput()
{
    if(accountinput.isEmpty()||pwdinput.isEmpty())
    {
        return 0;
    }
    else if(verifyinput.isEmpty()||verifyinput!="vwo7")
    {
        return 1;//验证码为空
    }
    else if(this->login())
    {
        return 2;//登录成功
    }
    else
    {
        return 3;//登录失败
    }
}



/**************
 * 功能：登录逻辑，通过访问数据库进行验证
 * **************/
int CLogin::login()
{
    char **pResult=nullptr;//用完要自己释放
    int row;//行
    int col;//列
    QString sql="select *from t_user where Account = '"+this->accountinput+"';";
    int ret=DBdata->getTable(sql,pResult,row,col);
    if(ret==0)//成功
    {
        flag=0;
        for(int i=5;i<=row*col;i=i+5)
        {
            cout<<pResult[i+1]<<endl;//账号
            cout<<pResult[i+2]<<endl;//名字
            cout<<pResult[i+3]<<endl;//密码
//            cout<<row*col<<endl;
            //cout<<"-------"<<endl;
            if((strcmp(pResult[i+1],accountinput.toStdString().c_str())==0)&&(strcmp(pResult[i+3],pwdinput.toStdString().c_str())==0))
            {
                qDebug()<<QString(pResult[i+1])+"-"+accountinput+"-"+QString(pResult[i+1])+"-"+pwdinput;
                flag=1;//密码和账号都对应
            }
        }
    }
    if(flag==1)
        cout<<"loginsuccess"<<endl;
    else
        cout<<"login failed"<<endl;

    return flag;
}

/**************
 * 功能：登录成功后对数据库的数据进行更改
 * **************/
void CLogin::setType()
{
    QString sql="update t_user SET type = 1 where Account = '"
            +this->DBdata->account+"';";
    DBdata->OptionSQL(sql);
}

/**************
 * 功能：检查是否有某账号，用于判定重置密码的账号是否存在
 * **************/
int CLogin::checkAccount(QString accountinput)
{
    char **pResult=nullptr;
    int row;//行
    int col;//列
    QString sql;//找到存储路径
    sql="SELECT * from t_user WHERE Account = '"+accountinput+"';";//查询
    qDebug()<<sql;
    DBdata->getTable(sql,pResult,row,col);
    if(row>=1)
    {
        return 1;
    }
    return 0;
}

