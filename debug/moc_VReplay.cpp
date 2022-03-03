/****************************************************************************
** Meta object code from reading C++ file 'VReplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VReplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VReplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VReplay_t {
    QByteArrayData data[8];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VReplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VReplay_t qt_meta_stringdata_VReplay = {
    {
QT_MOC_LITERAL(0, 0, 7), // "VReplay"
QT_MOC_LITERAL(1, 8, 10), // "returnSlot"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "PlayOrNot"
QT_MOC_LITERAL(4, 30, 10), // "exportSlot"
QT_MOC_LITERAL(5, 41, 8), // "shotSlot"
QT_MOC_LITERAL(6, 50, 13), // "showVideoSlot"
QT_MOC_LITERAL(7, 64, 4) // "imag"

    },
    "VReplay\0returnSlot\0\0PlayOrNot\0exportSlot\0"
    "shotSlot\0showVideoSlot\0imag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VReplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    7,

       0        // eod
};

void VReplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VReplay *_t = static_cast<VReplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnSlot(); break;
        case 1: _t->PlayOrNot(); break;
        case 2: _t->exportSlot(); break;
        case 3: _t->shotSlot(); break;
        case 4: _t->showVideoSlot((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VReplay::staticMetaObject = {
    { &VBase::staticMetaObject, qt_meta_stringdata_VReplay.data,
      qt_meta_data_VReplay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VReplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VReplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VReplay.stringdata0))
        return static_cast<void*>(this);
    return VBase::qt_metacast(_clname);
}

int VReplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
