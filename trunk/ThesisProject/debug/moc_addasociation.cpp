/****************************************************************************
** Meta object code from reading C++ file 'addasociation.h'
**
** Created: Tue 16. Jun 18:20:23 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/AddAsociation/addasociation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addasociation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddAsociation[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      50,   14,   14,   14, 0x08,
      87,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddAsociation[] = {
    "AddAsociation\0\0saveEventClicked(QListWidgetItem*)\0"
    "saveGestureClicked(QListWidgetItem*)\0"
    "addSelectedItems()\0"
};

const QMetaObject AddAsociation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddAsociation,
      qt_meta_data_AddAsociation, 0 }
};

const QMetaObject *AddAsociation::metaObject() const
{
    return &staticMetaObject;
}

void *AddAsociation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddAsociation))
        return static_cast<void*>(const_cast< AddAsociation*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddAsociation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: saveEventClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: saveGestureClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: addSelectedItems(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
