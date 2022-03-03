#include "SViewManage.h"

SViewManage *SViewManage::instance=nullptr;
/*************************
 * 添加界面
 * ******************/
int SViewManage::addView(int id, QWidget* view)
{
    map<int,QWidget*>::iterator temp=this->Views->find(id);//查看此页面是否已经存在
    if(temp!=Views->end())//如果已经存在就返回错误
    {
        return 0;
    }
    Views->insert(Value_type(id,view));
    return 1;//插入成功
}

SViewManage::SViewManage()
{
    this->Views=new map<int,QWidget*>();//实例化窗体map
}

SViewManage *SViewManage::getInstance()
{
    if(instance==nullptr)
    {
        instance=new SViewManage();
    }
    return instance;
}
/*******************
 * 功能：显示界面
 * ***********/
int SViewManage::showView(int id)
{
    map<int,QWidget*>::iterator temp= Views->find(id);//没找到则temp为end()
    if(temp!=Views->end())
    {
        temp->second->show();
        return 1;
    }
    return 0;//没找到
}

int SViewManage::hideView(int id)
{
    map<int,QWidget*>::iterator temp= Views->find(id);//没找到则temp为end()
    if(temp!=Views->end())
    {
        temp->second->hide();
        return 1;
    }
    return 0;//没找到
}
QWidget *SViewManage::getView(int id)
{

    map<int,QWidget*>::iterator temp_it = Views->find(id);
    if(temp_it!=Views->end()){
        return temp_it->second;
    }
    return nullptr;
}

void SViewManage::setReplayfileName(QString replayFilename)
{
    this->replayFilename=replayFilename;
}
