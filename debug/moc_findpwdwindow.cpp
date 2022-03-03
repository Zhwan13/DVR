/****************************************************************************
** Meta object code from reading C++ file 'findpwdwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../findpwdwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findpwdwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FindPwdWindow_t {
    QByteArrayData data[6];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FindPwdWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FindPwdWindow_t qt_meta_stringdata_FindPwdWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FindPwdWindow"
QT_MOC_LITERAL(1, 14, 18), // "returnAnswerSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "resetSuccessSignal"
QT_MOC_LITERAL(4, 53, 16), // "returnAnswerSlot"
QT_MOC_LITERAL(5, 70, 9) // "resetSlot"

    },
    "FindPwdWindow\0returnAnswerSignal\0\0"
    "resetSuccessSignal\0returnAnswerSlot\0"
    "resetSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FindPwdWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FindPwdWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FindPwdWindow *_t = static_cast<FindPwdWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnAnswerSignal(); break;
        case 1: _t->resetSuccessSignal(); break;
        case 2: _t->returnAnswerSlot(); break;
        case 3: _t->resetSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FindPwdWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FindPwdWindow::returnAnswerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FindPwdWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FindPwdWindow::resetSuccessSignal)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FindPwdWindow::staticMetaObject = {
    { &VBase::staticMetaObject, qt_meta_stringdata_FindPwdWindow.data,
      qt_meta_data_FindPwdWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FindPwdWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FindPwdWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FindPwdWindow.stringdata0))
        return static_cast<void*>(this);
    return VBase::qt_metacast(_clname);
}

int FindPwdWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FindPwdWindow::returnAnswerSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FindPwdWindow::resetSuccessSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
