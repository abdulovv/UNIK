/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[20];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[17];
    char stringdata5[16];
    char stringdata6[19];
    char stringdata7[16];
    char stringdata8[24];
    char stringdata9[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "on_PUSH_clicked"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 14),  // "on_POP_clicked"
        QT_MOC_LITERAL(43, 16),  // "on_FRONT_clicked"
        QT_MOC_LITERAL(60, 15),  // "on_SIZE_clicked"
        QT_MOC_LITERAL(76, 18),  // "on_ISEMPTY_clicked"
        QT_MOC_LITERAL(95, 15),  // "on_BACK_clicked"
        QT_MOC_LITERAL(111, 23),  // "on_RANDOMRANDOM_clicked"
        QT_MOC_LITERAL(135, 16)   // "on_FUNCT_clicked"
    },
    "MainWindow",
    "on_PUSH_clicked",
    "",
    "on_POP_clicked",
    "on_FRONT_clicked",
    "on_SIZE_clicked",
    "on_ISEMPTY_clicked",
    "on_BACK_clicked",
    "on_RANDOMRANDOM_clicked",
    "on_FUNCT_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_PUSH_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_POP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_FRONT_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SIZE_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ISEMPTY_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BACK_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_RANDOMRANDOM_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_FUNCT_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_PUSH_clicked(); break;
        case 1: _t->on_POP_clicked(); break;
        case 2: _t->on_FRONT_clicked(); break;
        case 3: _t->on_SIZE_clicked(); break;
        case 4: _t->on_ISEMPTY_clicked(); break;
        case 5: _t->on_BACK_clicked(); break;
        case 6: _t->on_RANDOMRANDOM_clicked(); break;
        case 7: _t->on_FUNCT_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
