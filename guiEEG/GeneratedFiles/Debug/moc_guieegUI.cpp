/****************************************************************************
** Meta object code from reading C++ file 'guieegUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../guieegUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guieegUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_guiEEG_t {
    QByteArrayData data[9];
    char stringdata[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_guiEEG_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_guiEEG_t qt_meta_stringdata_guiEEG = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 33),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 33),
QT_MOC_LITERAL(4, 76, 32),
QT_MOC_LITERAL(5, 109, 28),
QT_MOC_LITERAL(6, 138, 26),
QT_MOC_LITERAL(7, 165, 16),
QT_MOC_LITERAL(8, 182, 17)
    },
    "guiEEG\0on_pushButton_1min_record_clicked\0"
    "\0on_pushButton_long_record_clicked\0"
    "on_pushButton_cus_record_clicked\0"
    "on_pushButton_2_stop_clicked\0"
    "on_pushButton_open_clicked\0disconnectDevice\0"
    "update_time_label"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_guiEEG[] = {

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
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void guiEEG::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        guiEEG *_t = static_cast<guiEEG *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_1min_record_clicked(); break;
        case 1: _t->on_pushButton_long_record_clicked(); break;
        case 2: _t->on_pushButton_cus_record_clicked(); break;
        case 3: _t->on_pushButton_2_stop_clicked(); break;
        case 4: _t->on_pushButton_open_clicked(); break;
        case 5: _t->disconnectDevice(); break;
        case 6: _t->update_time_label(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject guiEEG::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_guiEEG.data,
      qt_meta_data_guiEEG,  qt_static_metacall, 0, 0}
};


const QMetaObject *guiEEG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *guiEEG::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_guiEEG.stringdata))
        return static_cast<void*>(const_cast< guiEEG*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int guiEEG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
