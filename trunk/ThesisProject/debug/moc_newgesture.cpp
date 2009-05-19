/****************************************************************************
** Meta object code from reading C++ file 'newgesture.h'
**
** Created: Sat 16. May 20:09:13 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/newGesture/newgesture.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newgesture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewGesture[] = {

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
      21,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewGesture[] = {
    "NewGesture\0\0accept()\0viewGesture()\0"
};

const QMetaObject NewGesture::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewGesture,
      qt_meta_data_NewGesture, 0 }
};

const QMetaObject *NewGesture::metaObject() const
{
    return &staticMetaObject;
}

void *NewGesture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewGesture))
        return static_cast<void*>(const_cast< NewGesture*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewGesture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: viewGesture(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
