/****************************************************************************
** Meta object code from reading C++ file 'VReplayChoose.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VReplayChoose.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VReplayChoose.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VReplayChoose_t {
    QByteArrayData data[10];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VReplayChoose_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VReplayChoose_t qt_meta_stringdata_VReplayChoose = {
    {
QT_MOC_LITERAL(0, 0, 13), // "VReplayChoose"
QT_MOC_LITERAL(1, 14, 10), // "returnSlot"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "ShowBeginCalendarSlot"
QT_MOC_LITERAL(4, 48, 21), // "BeginDateSelectedSlot"
QT_MOC_LITERAL(5, 70, 4), // "Date"
QT_MOC_LITERAL(6, 75, 12), // "hideCalendar"
QT_MOC_LITERAL(7, 88, 15), // "selectVideoSlot"
QT_MOC_LITERAL(8, 104, 8), // "filename"
QT_MOC_LITERAL(9, 113, 9) // "enterSlot"

    },
    "VReplayChoose\0returnSlot\0\0"
    "ShowBeginCalendarSlot\0BeginDateSelectedSlot\0"
    "Date\0hideCalendar\0selectVideoSlot\0"
    "filename\0enterSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VReplayChoose[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    1,   46,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void VReplayChoose::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VReplayChoose *_t = static_cast<VReplayChoose *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnSlot(); break;
        case 1: _t->ShowBeginCalendarSlot(); break;
        case 2: _t->BeginDateSelectedSlot((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 3: _t->hideCalendar(); break;
        case 4: _t->selectVideoSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->enterSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VReplayChoose::staticMetaObject = {
    { &VBase::staticMetaObject, qt_meta_stringdata_VReplayChoose.data,
      qt_meta_data_VReplayChoose,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VReplayChoose::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VReplayChoose::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VReplayChoose.stringdata0))
        return static_cast<void*>(this);
    return VBase::qt_metacast(_clname);
}

int VReplayChoose::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
