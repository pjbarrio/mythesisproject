/****************************************************************************
** Meta object code from reading C++ file 'handdiagnostic.h'
**
** Created: Sat 16. May 20:09:09 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/HandDiagnostic/handdiagnostic.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handdiagnostic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HandDiagnostic[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HandDiagnostic[] = {
    "HandDiagnostic\0\0proceder()\0"
};

const QMetaObject HandDiagnostic::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HandDiagnostic,
      qt_meta_data_HandDiagnostic, 0 }
};

const QMetaObject *HandDiagnostic::metaObject() const
{
    return &staticMetaObject;
}

void *HandDiagnostic::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HandDiagnostic))
        return static_cast<void*>(const_cast< HandDiagnostic*>(this));
    return QDialog::qt_metacast(_clname);
}

int HandDiagnostic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: proceder(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
