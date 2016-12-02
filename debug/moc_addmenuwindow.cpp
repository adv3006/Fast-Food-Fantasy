/****************************************************************************
** Meta object code from reading C++ file 'addmenuwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addmenuwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addmenuwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddMenuWindow_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddMenuWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddMenuWindow_t qt_meta_stringdata_AddMenuWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AddMenuWindow"
QT_MOC_LITERAL(1, 14, 8), // "MenuItem"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "newName"
QT_MOC_LITERAL(4, 32, 8), // "newPrice"
QT_MOC_LITERAL(5, 41, 9), // "OKClicked"
QT_MOC_LITERAL(6, 51, 11), // "PriceChange"
QT_MOC_LITERAL(7, 63, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(8, 85, 22) // "on_buttonBox_destroyed"

    },
    "AddMenuWindow\0MenuItem\0\0newName\0"
    "newPrice\0OKClicked\0PriceChange\0"
    "on_buttonBox_accepted\0on_buttonBox_destroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddMenuWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,
       5,    2,   50,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   58,    2, 0x08 /* Private */,
       8,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Float,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Float,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddMenuWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddMenuWindow *_t = static_cast<AddMenuWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MenuItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->OKClicked(); break;
        case 2: _t->OKClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->PriceChange((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->on_buttonBox_accepted(); break;
        case 5: _t->on_buttonBox_destroyed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddMenuWindow::*_t)(QString , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddMenuWindow::MenuItem)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AddMenuWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddMenuWindow::OKClicked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AddMenuWindow::*_t)(QString , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddMenuWindow::OKClicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AddMenuWindow::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddMenuWindow::PriceChange)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject AddMenuWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddMenuWindow.data,
      qt_meta_data_AddMenuWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddMenuWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddMenuWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddMenuWindow.stringdata0))
        return static_cast<void*>(const_cast< AddMenuWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddMenuWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void AddMenuWindow::MenuItem(QString _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddMenuWindow::OKClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void AddMenuWindow::OKClicked(QString _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AddMenuWindow::PriceChange(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
