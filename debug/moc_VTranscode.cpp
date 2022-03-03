/****************************************************************************
** Meta object code from reading C++ file 'VTranscode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VTranscode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VTranscode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VTranscode_t {
    QByteArrayData data[13];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VTranscode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VTranscode_t qt_meta_stringdata_VTranscode = {
    {
QT_MOC_LITERAL(0, 0, 10), // "VTranscode"
QT_MOC_LITERAL(1, 11, 10), // "returnSlot"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 17), // "ShowBeginCalendar"
QT_MOC_LITERAL(4, 41, 17), // "BeginDateSelected"
QT_MOC_LITERAL(5, 59, 4), // "Date"
QT_MOC_LITERAL(6, 64, 12), // "hideCalendar"
QT_MOC_LITERAL(7, 77, 10), // "formatSlot"
QT_MOC_LITERAL(8, 88, 6), // "format"
QT_MOC_LITERAL(9, 95, 13), // "DirWidgetShow"
QT_MOC_LITERAL(10, 109, 8), // "setInDir"
QT_MOC_LITERAL(11, 118, 5), // "inDir"
QT_MOC_LITERAL(12, 124, 12) // "TrancodeSlot"

    },
    "VTranscode\0returnSlot\0\0ShowBeginCalendar\0"
    "BeginDateSelected\0Date\0hideCalendar\0"
    "formatSlot\0format\0DirWidgetShow\0"
    "setInDir\0inDir\0TrancodeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VTranscode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    1,   56,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    1,   60,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void VTranscode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VTranscode *_t = static_cast<VTranscode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnSlot(); break;
        case 1: _t->ShowBeginCalendar(); break;
        case 2: _t->BeginDateSelected((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 3: _t->hideCalendar(); break;
        case 4: _t->formatSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->DirWidgetShow(); break;
        case 6: _t->setInDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->TrancodeSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VTranscode::staticMetaObject = {
    { &VBase::staticMetaObject, qt_meta_stringdata_VTranscode.data,
      qt_meta_data_VTranscode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VTranscode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VTranscode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VTranscode.stringdata0))
        return static_cast<void*>(this);
    return VBase::qt_metacast(_clname);
}

int VTranscode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
