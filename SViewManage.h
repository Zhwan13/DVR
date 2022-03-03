#ifndef SVIEWMANAGE_H
#define SVIEWMANAGE_H
#include<qmap.h>
#include<QMap>
#include<QWidget>
#include<algorithm>

#define STARTVIEW 0
#define LOGINVIEW 1
#define REGISTERVIEW 2
#define ANSWERVIEW 3
#define RESETPWDVIEW 4
#define SETMSGVIEW 5
#define MAINVIEW 6
#define REPLAYCHOOSEVIEW 7//视频回放选择界面
#define REPLAYVIEW 8//视频回放界面
#define PHOTOSVIEW 9
#define TRANSCODEVIEW 10


using std::map;

typedef  map<int,QWidget*>::value_type Value_type;

class SViewManage
{
public:
    static SViewManage *getInstance();
    int addView(int id, QWidget* view);
    int showView(int id);
    int hideView(int id);
    QWidget* getView(int id);           //得到视图对象

    void setReplayfileName(QString replayFilename);

    QString replayFilename;
private:
    SViewManage();

    static SViewManage *instance;
    map<int,QWidget*> *Views;

};

#endif // SVIEWMANAGE_H
