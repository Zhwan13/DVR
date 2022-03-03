#-------------------------------------------------
#
# Project created by QtCreator 2020-06-27T11:17:50
#
#-------------------------------------------------

QT       += core gui
QT +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DVR
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    CLogin.cpp \
    VAnswer.cpp \
    VMain.cpp \
    VBase.cpp \
    SingleDBOption.cpp \
    VLogin.cpp \
    VRegister.cpp \
    VResetPwd.cpp \
    MyLineEdit.cpp \
    CRegister.cpp \
    mygraphicsitem.cpp \
    mygraphicsview.cpp \
    SViewManage.cpp \
    SModel.cpp \
    VSetMsg.cpp \
    CSetMsg.cpp \
    VReplay.cpp \
    VReplayChoose.cpp \
    VPhotos.cpp \
    TJGGFrame.cpp \
    CEncode.cpp \
    cdecode.cpp \
    CTranscode.cpp \
    VTranscode.cpp \
    FTranscode.cpp \
    CReplayChoose.cpp

HEADERS += \
    CLogin.h \
    VAnswer.h \
    VMain.h \
    VBase.h \
    SingleDBOption.h \
    sqlite3.h \
    VLogin.h \
    VRegister.h \
    VResetPwd.h \
    MyLineEdit.h \
    CRegister.h \
    mygraphicsitem.h \
    mygraphicsview.h \
    SViewManage.h \
    SModel.h \
    VSetMsg.h \
    CSetMsg.h \
    VReplay.h \
    VReplayChoose.h \
    VPhotos.h \
    TJGGFrame.h \
    CEncode.h \
    cdecode.h \
    CTranscode.h \
    VTranscode.h \
    FTranscode.h \
    CReplayChoose.h

INCLUDEPATH+=$$PWD/ffmpeg/include

LIBS += $$PWD/ffmpeg/lib/avdevice.lib \
        $$PWD/ffmpeg/lib/avcodec.lib \
        $$PWD/ffmpeg/lib/swscale.lib \
        $$PWD/ffmpeg/lib/avformat.lib \
        $$PWD/ffmpeg/lib/avutil.lib \
        $$PWD/ffmpeg/lib/avfilter.lib \
        $$PWD/ffmpeg/lib/swresample.lib \
        $$PWD/ffmpeg/lib/postproc.lib \
        $$PWD/ffmpeg/sqlite3.lib


RESOURCES += \
    img.qrc \
    qss.qrc



DESTDIR =bin
