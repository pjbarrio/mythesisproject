/****************************************************************************
** Meta object code from reading C++ file 'addgesture.h'
**
** Created: Tue 26. May 20:23:08 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/AddGesture/addgesture.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addgesture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddGesture[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddGesture[] = {
    "AddGesture\0\0newGesture()\0accept()\0"
};

const QMetaObject AddGesture::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddGesture,
      qt_meta_data_AddGesture, 0 }
};

const QMetaObject *AddGesture::metaObject() const
{
    return &staticMetaObject;
}

void *AddGesture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddGesture))
        return static_cast<void*>(const_cast< AddGesture*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddGesture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newGesture(); break;
        case 1: accept(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
