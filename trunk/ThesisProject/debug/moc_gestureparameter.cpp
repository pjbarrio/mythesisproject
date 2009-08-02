/****************************************************************************
** Meta object code from reading C++ file 'gestureparameter.h'
**
** Created: Mon 27. Jul 17:10:01 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/GestureParameters/gestureparameter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestureparameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GestureParameter[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      40,   17,   17,   17, 0x08,
      64,   17,   17,   17, 0x08,
      73,   17,   17,   17, 0x08,
      97,   17,   17,   17, 0x08,
     123,   17,   17,   17, 0x08,
     162,   17,   17,   17, 0x08,
     206,   17,   17,   17, 0x08,
     245,   17,   17,   17, 0x08,
     287,   17,   17,   17, 0x08,
     313,   17,   17,   17, 0x08,
     344,   17,   17,   17, 0x08,
     378,   17,   17,   17, 0x08,
     409,   17,   17,   17, 0x08,
     445,   17,   17,   17, 0x08,
     471,   17,   17,   17, 0x08,
     510,   17,   17,   17, 0x08,
     540,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GestureParameter[] = {
    "GestureParameter\0\0setDetectedCount(int)\0"
    "setMaxRelatedRatio(int)\0accept()\0"
    "bufferSizeModified(int)\0"
    "relaxedCountModified(int)\0"
    "distanceCalculatorAGMModified(QString)\0"
    "nonVaryingAccelerationRateModified(QString)\0"
    "accelerationThresholdModified(QString)\0"
    "desaccelerationThresholdModified(QString)\0"
    "walkedPixelsModified(int)\0"
    "minimumPointCountModified(int)\0"
    "distanceThresholdModified(double)\0"
    "maxGestureTimeModified(double)\0"
    "valuesNormalizatorModified(QString)\0"
    "relaxedRatioModified(int)\0"
    "distanceCalculatorDTWModified(QString)\0"
    "dtwAlgorithmModified(QString)\0"
    "rateModified(double)\0"
};

const QMetaObject GestureParameter::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GestureParameter,
      qt_meta_data_GestureParameter, 0 }
};

const QMetaObject *GestureParameter::metaObject() const
{
    return &staticMetaObject;
}

void *GestureParameter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GestureParameter))
        return static_cast<void*>(const_cast< GestureParameter*>(this));
    return QDialog::qt_metacast(_clname);
}

int GestureParameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setDetectedCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setMaxRelatedRatio((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: accept(); break;
        case 3: bufferSizeModified((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: relaxedCountModified((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: distanceCalculatorAGMModified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: nonVaryingAccelerationRateModified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: accelerationThresholdModified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: desaccelerationThresholdModified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: walkedPixelsModified((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: minimumPointCountModified((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: distanceThresholdModified((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: maxGestureTimeModified((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: valuesNormalizatorModified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: relaxedRatioModified((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: distanceCalculatorDTWModified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: dtwAlgorithmModified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: rateModified((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
