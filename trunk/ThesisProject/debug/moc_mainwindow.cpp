/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri 22. May 22:03:30 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThesisProject[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      28,   14,   14,   14, 0x08,
      41,   14,   14,   14, 0x08,
      52,   14,   14,   14, 0x08,
      68,   14,   14,   14, 0x08,
      84,   14,   14,   14, 0x08,
      98,   14,   14,   14, 0x08,
     117,   14,   14,   14, 0x08,
     131,   14,   14,   14, 0x08,
     145,   14,   14,   14, 0x08,
     164,   14,   14,   14, 0x08,
     184,   14,   14,   14, 0x08,
     198,   14,   14,   14, 0x08,
     217,   14,   14,   14, 0x08,
     236,   14,   14,   14, 0x08,
     248,   14,   14,   14, 0x08,
     268,   14,   14,   14, 0x08,
     286,   14,   14,   14, 0x08,
     309,   14,   14,   14, 0x08,
     344,   14,   14,   14, 0x08,
     367,   14,   14,   14, 0x08,
     398,   14,   14,   14, 0x08,
     415,   14,   14,   14, 0x08,
     441,   14,   14,   14, 0x08,
     458,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ThesisProject[] = {
    "ThesisProject\0\0showNormal()\0addGesture()\0"
    "addEvent()\0addAsociation()\0removeGesture()\0"
    "removeEvent()\0removeAsociation()\0"
    "rotateX(bool)\0rotateY(bool)\0"
    "startApplication()\0runHandDiagnostic()\0"
    "stopCapture()\0ViewCaptureState()\0"
    "captureNextFrame()\0openAbout()\0"
    "openConfiguration()\0importAllEvents()\0"
    "importOpenFileEvents()\0"
    "importExecutionApplicationEvents()\0"
    "importPressKeyEvents()\0"
    "importCombinedKeyPressEvents()\0"
    "importGestures()\0saveConfigurationinFile()\0"
    "byeApplication()\0analizeChange(QListWidgetItem*)\0"
};

const QMetaObject ThesisProject::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ThesisProject,
      qt_meta_data_ThesisProject, 0 }
};

const QMetaObject *ThesisProject::metaObject() const
{
    return &staticMetaObject;
}

void *ThesisProject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThesisProject))
        return static_cast<void*>(const_cast< ThesisProject*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ThesisProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showNormal(); break;
        case 1: addGesture(); break;
        case 2: addEvent(); break;
        case 3: addAsociation(); break;
        case 4: removeGesture(); break;
        case 5: removeEvent(); break;
        case 6: removeAsociation(); break;
        case 7: rotateX((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: rotateY((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: startApplication(); break;
        case 10: runHandDiagnostic(); break;
        case 11: stopCapture(); break;
        case 12: ViewCaptureState(); break;
        case 13: captureNextFrame(); break;
        case 14: openAbout(); break;
        case 15: openConfiguration(); break;
        case 16: importAllEvents(); break;
        case 17: importOpenFileEvents(); break;
        case 18: importExecutionApplicationEvents(); break;
        case 19: importPressKeyEvents(); break;
        case 20: importCombinedKeyPressEvents(); break;
        case 21: importGestures(); break;
        case 22: saveConfigurationinFile(); break;
        case 23: byeApplication(); break;
        case 24: analizeChange((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
