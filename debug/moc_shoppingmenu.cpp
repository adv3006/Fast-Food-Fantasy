/****************************************************************************
** Meta object code from reading C++ file 'shoppingmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shoppingmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shoppingmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_shoppingMenu_t {
    QByteArrayData data[11];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_shoppingMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_shoppingMenu_t qt_meta_stringdata_shoppingMenu = {
    {
QT_MOC_LITERAL(0, 0, 12), // "shoppingMenu"
QT_MOC_LITERAL(1, 13, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "on_next_clicked"
QT_MOC_LITERAL(4, 52, 15), // "on_prev_clicked"
QT_MOC_LITERAL(5, 68, 20), // "on_addToCart_clicked"
QT_MOC_LITERAL(6, 89, 14), // "modifyCartItem"
QT_MOC_LITERAL(7, 104, 8), // "QAction*"
QT_MOC_LITERAL(8, 113, 34), // "on_cart_customContextMenuRequ..."
QT_MOC_LITERAL(9, 148, 3), // "pos"
QT_MOC_LITERAL(10, 152, 23) // "on_okay_cancel_accepted"

    },
    "shoppingMenu\0on_buttonBox_accepted\0\0"
    "on_next_clicked\0on_prev_clicked\0"
    "on_addToCart_clicked\0modifyCartItem\0"
    "QAction*\0on_cart_customContextMenuRequested\0"
    "pos\0on_okay_cancel_accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_shoppingMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::QPoint,    9,
    QMetaType::Void,

       0        // eod
};

void shoppingMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        shoppingMenu *_t = static_cast<shoppingMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonBox_accepted(); break;
        case 1: _t->on_next_clicked(); break;
        case 2: _t->on_prev_clicked(); break;
        case 3: _t->on_addToCart_clicked(); break;
        case 4: _t->modifyCartItem((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->on_cart_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->on_okay_cancel_accepted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject shoppingMenu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_shoppingMenu.data,
      qt_meta_data_shoppingMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *shoppingMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *shoppingMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_shoppingMenu.stringdata0))
        return static_cast<void*>(const_cast< shoppingMenu*>(this));
    return QDialog::qt_metacast(_clname);
}

int shoppingMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
