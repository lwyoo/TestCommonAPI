/****************************************************************************
** Meta object code from reading C++ file 'MyQuickItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyQuickItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyQuickItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyQuickItem_t {
    QByteArrayData data[11];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQuickItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQuickItem_t qt_meta_stringdata_MyQuickItem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyQuickItem"
QT_MOC_LITERAL(1, 12, 19), // "handleWindowChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "QQuickWindow*"
QT_MOC_LITERAL(4, 47, 3), // "win"
QT_MOC_LITERAL(5, 51, 23), // "slotBeforeSynchronizing"
QT_MOC_LITERAL(6, 75, 25), // "slotSceneGraphInvalidated"
QT_MOC_LITERAL(7, 101, 19), // "slotBeforeRendering"
QT_MOC_LITERAL(8, 121, 18), // "slotAfterRendering"
QT_MOC_LITERAL(9, 140, 16), // "slotFrameSwapped"
QT_MOC_LITERAL(10, 157, 12) // "testFunction"

    },
    "MyQuickItem\0handleWindowChanged\0\0"
    "QQuickWindow*\0win\0slotBeforeSynchronizing\0"
    "slotSceneGraphInvalidated\0slotBeforeRendering\0"
    "slotAfterRendering\0slotFrameSwapped\0"
    "testFunction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQuickItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   57,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void MyQuickItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyQuickItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleWindowChanged((*reinterpret_cast< QQuickWindow*(*)>(_a[1]))); break;
        case 1: _t->slotBeforeSynchronizing(); break;
        case 2: _t->slotSceneGraphInvalidated(); break;
        case 3: _t->slotBeforeRendering(); break;
        case 4: _t->slotAfterRendering(); break;
        case 5: _t->slotFrameSwapped(); break;
        case 6: _t->testFunction(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyQuickItem::staticMetaObject = { {
    &QQuickItem::staticMetaObject,
    qt_meta_stringdata_MyQuickItem.data,
    qt_meta_data_MyQuickItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyQuickItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQuickItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyQuickItem.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int MyQuickItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
