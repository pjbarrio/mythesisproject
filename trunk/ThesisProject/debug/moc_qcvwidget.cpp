/*****************************************************************************
** Meta object code from reading C++ file 'qcvwidget.h'
**
** Created: Tue 26. May 20:23:03 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtOpenCV/qcv/qcvwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcvwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QCVWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QCVWidget[] = {
    "QCVWidget\0\0img\0showImage(const IplImage*)\0"
};

const QMetaObject QCVWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QCVWidget,
      qt_meta_data_QCVWidget, 0 }
};

const QMetaObject *QCVWidget::metaObject() const
{
    return &staticMetaObject;
}

void *QCVWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCVWidget))
        return static_cast<void*>(const_cast< QCVWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QCVWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showImage((*reinterpret_cast< const IplImage*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
