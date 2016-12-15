/****************************************************************************
** Meta object code from reading C++ file 'form1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../form1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawWidget_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawWidget_t qt_meta_stringdata_DrawWidget = {
    {
QT_MOC_LITERAL(0, 0, 10) // "DrawWidget"

    },
    "DrawWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject DrawWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrawWidget.data,
      qt_meta_data_DrawWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DrawWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DrawWidget.stringdata0))
        return static_cast<void*>(const_cast< DrawWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DrawWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_form1_t {
    QByteArrayData data[8];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_form1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_form1_t qt_meta_stringdata_form1 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "form1"
QT_MOC_LITERAL(1, 6, 8), // "tChanged"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "AddEquation"
QT_MOC_LITERAL(4, 28, 11), // "DelEquation"
QT_MOC_LITERAL(5, 40, 4), // "sett"
QT_MOC_LITERAL(6, 45, 5), // "t_str"
QT_MOC_LITERAL(7, 51, 9) // "calculate"

    },
    "form1\0tChanged\0\0AddEquation\0DelEquation\0"
    "sett\0t_str\0calculate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x08 /* Private */,
       4,    0,   43,    2, 0x08 /* Private */,
       5,    1,   44,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void form1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form1 *_t = static_cast<form1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->AddEquation(); break;
        case 2: _t->DelEquation(); break;
        case 3: _t->sett((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->calculate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (form1::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&form1::tChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject form1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_form1.data,
      qt_meta_data_form1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *form1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_form1.stringdata0))
        return static_cast<void*>(const_cast< form1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int form1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void form1::tChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
