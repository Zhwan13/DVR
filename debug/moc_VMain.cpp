/****************************************************************************
** Meta object code from reading C++ file 'VMain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VMain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VMain_t {
    QByteArrayData data[12];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VMain_t qt_meta_stringdata_VMain = {
    {
QT_MOC_LITERAL(0, 0, 5), // "VMain"
QT_MOC_LITERAL(1, 6, 10), // "TimeUpdata"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "showImgSlot"
QT_MOC_LITERAL(4, 30, 4), // "imag"
QT_MOC_LITERAL(5, 35, 13), // "ShowOrHideBtn"
QT_MOC_LITERAL(6, 49, 11), // "showSetView"
QT_MOC_LITERAL(7, 61, 14), // "takeAphotoSlot"
QT_MOC_LITERAL(8, 76, 10), // "replaySlot"
QT_MOC_LITERAL(9, 87, 10), // "photosSlot"
QT_MOC_LITERAL(10, 98, 15), // "transcodingSlot"
QT_MOC_LITERAL(11, 114, 10) // "returnSlot"

    },
    "VMain\0TimeUpdata\0\0showImgSlot\0imag\0"
    "ShowOrHideBtn\0showSetView\0takeAphotoSlot\0"
    "replaySlot\0photosSlot\0transcodingSlot\0"
    "returnSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VMain *_t = static_cast<VMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TimeUpdata(); break;
        case 1: _t->showImgSlot((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->ShowOrHideBtn(); break;
        case 3: _t->showSetView(); break;
        case 4: _t->takeAphotoSlot(); break;
        case 5: _t->replaySlot(); break;
        case 6: _t->photosSlot(); break;
        case 7: _t->transcodingSlot(); break;
        case 8: _t->returnSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VMain::staticMetaObject = {
    { &VBase::staticMetaObject, qt_meta_stringdata_VMain.data,
      qt_meta_data_VMain,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VMain.stringdata0))
        return static_cast<void*>(this);
    return VBase::qt_metacast(_clname);
}

int VMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
