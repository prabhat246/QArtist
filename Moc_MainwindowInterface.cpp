/****************************************************************************
** Meta object code from reading C++ file 'MainWindowInterface.h'
**
** Created: Mon Nov 24 21:47:25 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindowInterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindowInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_MainWindowInterface[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      28,   20,   20,   20, 0x0a,
      36,   20,   20,   20, 0x0a,
      43,   20,   20,   20, 0x0a,
      52,   20,   20,   20, 0x0a,
      62,   20,   20,   20, 0x0a,
      74,   20,   20,   20, 0x0a,
      86,   20,   20,   20, 0x0a,
      98,   20,   20,   20, 0x0a,
     108,   20,   20,   20, 0x0a,
     121,   20,   20,   20, 0x0a,
     128,   20,   20,   20, 0x0a,
     138,   20,   20,   20, 0x0a,
     146,   20,   20,   20, 0x0a,
     161,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowInterface[] = {
    "MainWindowInterface\0\0open()\0close()\0"
    "save()\0exit_p()\0appnpr1()\0appnpr2_1()\0"
    "appnpr2_2()\0appnpr2_3()\0appnpr3()\0"
    "halftoning()\0blur()\0edgedet()\0canny()\0"
    "segmentation()\0zoomchecked(bool)\0"
};

const QMetaObject MainWindowInterface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowInterface,
      qt_meta_data_MainWindowInterface, 0 }
};

const QMetaObject *MainWindowInterface::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindowInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowInterface))
	return static_cast<void*>(const_cast< MainWindowInterface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open(); break;
        case 1: close(); break;
        case 2: save(); break;
        case 3: exit_p(); break;
        case 4: appnpr1(); break;
        case 5: appnpr2_1(); break;
        case 6: appnpr2_2(); break;
        case 7: appnpr2_3(); break;
        case 8: appnpr3(); break;
        case 9: halftoning(); break;
        case 10: blur(); break;
        case 11: edgedet(); break;
        case 12: canny(); break;
        case 13: segmentation(); break;
        case 14: zoomchecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        }
        _id -= 15;
    }
    return _id;
}
