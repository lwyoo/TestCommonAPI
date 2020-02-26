/****************************************************************************
** Meta object code from reading C++ file 'MyQuickItemProxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyQuickItemProxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyQuickItemProxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyQuickItemProxy_t {
    QByteArrayData data[13];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQuickItemProxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQuickItemProxy_t qt_meta_stringdata_MyQuickItemProxy = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MyQuickItemProxy"
QT_MOC_LITERAL(1, 17, 16), // "testValueChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "value"
QT_MOC_LITERAL(4, 41, 19), // "handleWindowChanged"
QT_MOC_LITERAL(5, 61, 13), // "QQuickWindow*"
QT_MOC_LITERAL(6, 75, 3), // "win"
QT_MOC_LITERAL(7, 79, 23), // "slotBeforeSynchronizing"
QT_MOC_LITERAL(8, 103, 25), // "slotSceneGraphInvalidated"
QT_MOC_LITERAL(9, 129, 19), // "slotBeforeRendering"
QT_MOC_LITERAL(10, 149, 18), // "slotAfterRendering"
QT_MOC_LITERAL(11, 168, 16), // "slotFrameSwapped"
QT_MOC_LITERAL(12, 185, 9) // "testValue"

    },
    "MyQuickItemProxy\0testValueChanged\0\0"
    "value\0handleWindowChanged\0QQuickWindow*\0"
    "win\0slotBeforeSynchronizing\0"
    "slotSceneGraphInvalidated\0slotBeforeRendering\0"
    "slotAfterRendering\0slotFrameSwapped\0"
    "testValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQuickItemProxy[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   60, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   52,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void MyQuickItemProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyQuickItemProxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->testValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->handleWindowChanged((*reinterpret_cast< QQuickWindow*(*)>(_a[1]))); break;
        case 2: _t->slotBeforeSynchronizing(); break;
        case 3: _t->slotSceneGraphInvalidated(); break;
        case 4: _t->slotBeforeRendering(); break;
        case 5: _t->slotAfterRendering(); break;
        case 6: _t->slotFrameSwapped(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyQuickItemProxy::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyQuickItemProxy::testValueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MyQuickItemProxy *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->testValue(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MyQuickItemProxy *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTestValue(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MyQuickItemProxy::staticMetaObject = { {
    &QQuickItem::staticMetaObject,
    qt_meta_stringdata_MyQuickItemProxy.data,
    qt_meta_data_MyQuickItemProxy,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyQuickItemProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQuickItemProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyQuickItemProxy.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int MyQuickItemProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MyQuickItemProxy::testValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
