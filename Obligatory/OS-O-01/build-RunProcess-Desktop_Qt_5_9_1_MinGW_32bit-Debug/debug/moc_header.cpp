/****************************************************************************
** Meta object code from reading C++ file 'header.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RunProcess/header.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'header.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_timeThread_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_timeThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_timeThread_t qt_meta_stringdata_timeThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "timeThread"
QT_MOC_LITERAL(1, 11, 15), // "interruptSignal"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "timeThread\0interruptSignal\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_timeThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void timeThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        timeThread *_t = static_cast<timeThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->interruptSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (timeThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&timeThread::interruptSignal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject timeThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_timeThread.data,
      qt_meta_data_timeThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *timeThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *timeThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_timeThread.stringdata0))
        return static_cast<void*>(const_cast< timeThread*>(this));
    return QThread::qt_metacast(_clname);
}

int timeThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void timeThread::interruptSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_IO_t {
    QByteArrayData data[4];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IO_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IO_t qt_meta_stringdata_IO = {
    {
QT_MOC_LITERAL(0, 0, 2), // "IO"
QT_MOC_LITERAL(1, 3, 11), // "sendNewTask"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10) // "newTaskStr"

    },
    "IO\0sendNewTask\0\0newTaskStr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IO[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void IO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IO *_t = static_cast<IO *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendNewTask((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IO::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IO::sendNewTask)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject IO::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IO.data,
      qt_meta_data_IO,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *IO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IO::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IO.stringdata0))
        return static_cast<void*>(const_cast< IO*>(this));
    return QObject::qt_metacast(_clname);
}

int IO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void IO::sendNewTask(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_processScheduling_t {
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_processScheduling_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_processScheduling_t qt_meta_stringdata_processScheduling = {
    {
QT_MOC_LITERAL(0, 0, 17), // "processScheduling"
QT_MOC_LITERAL(1, 18, 19), // "callForUpDateLcdNum"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "time"
QT_MOC_LITERAL(4, 44, 15), // "askRefreshQueue"
QT_MOC_LITERAL(5, 60, 7), // "timeAdd"
QT_MOC_LITERAL(6, 68, 18) // "checkTaskFile_5sec"

    },
    "processScheduling\0callForUpDateLcdNum\0"
    "\0time\0askRefreshQueue\0timeAdd\0"
    "checkTaskFile_5sec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_processScheduling[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void processScheduling::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        processScheduling *_t = static_cast<processScheduling *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->callForUpDateLcdNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->askRefreshQueue(); break;
        case 2: _t->timeAdd(); break;
        case 3: _t->checkTaskFile_5sec(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (processScheduling::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processScheduling::callForUpDateLcdNum)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (processScheduling::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processScheduling::askRefreshQueue)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject processScheduling::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_processScheduling.data,
      qt_meta_data_processScheduling,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *processScheduling::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *processScheduling::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_processScheduling.stringdata0))
        return static_cast<void*>(const_cast< processScheduling*>(this));
    return QObject::qt_metacast(_clname);
}

int processScheduling::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void processScheduling::callForUpDateLcdNum(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void processScheduling::askRefreshQueue()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
