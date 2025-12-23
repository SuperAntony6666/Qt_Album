/****************************************************************************
** Meta object code from reading C++ file 'picanimationwid.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../picanimationwid.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picanimationwid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN15PicAnimationWidE_t {};
} // unnamed namespace

template <> constexpr inline auto PicAnimationWid::qt_create_metaobjectdata<qt_meta_tag_ZN15PicAnimationWidE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PicAnimationWid",
        "SigUpPreList",
        "",
        "QTreeWidgetItem*",
        "SigUpSelectItem",
        "SigStart",
        "SigStop",
        "SigStartMusic",
        "SigStopMusic",
        "SlotUpSelectShow",
        "path",
        "SlotStartorStop",
        "TimeOut"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'SigUpPreList'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'SigUpSelectItem'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'SigStart'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'SigStop'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'SigStartMusic'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'SigStopMusic'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'SlotUpSelectShow'
        QtMocHelpers::SlotData<void(QString)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Slot 'SlotStartorStop'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'TimeOut'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<PicAnimationWid, qt_meta_tag_ZN15PicAnimationWidE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject PicAnimationWid::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15PicAnimationWidE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15PicAnimationWidE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15PicAnimationWidE_t>.metaTypes,
    nullptr
} };

void PicAnimationWid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PicAnimationWid *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->SigUpPreList((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1]))); break;
        case 1: _t->SigUpSelectItem((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1]))); break;
        case 2: _t->SigStart(); break;
        case 3: _t->SigStop(); break;
        case 4: _t->SigStartMusic(); break;
        case 5: _t->SigStopMusic(); break;
        case 6: _t->SlotUpSelectShow((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->SlotStartorStop(); break;
        case 8: _t->TimeOut(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PicAnimationWid::*)(QTreeWidgetItem * )>(_a, &PicAnimationWid::SigUpPreList, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PicAnimationWid::*)(QTreeWidgetItem * )>(_a, &PicAnimationWid::SigUpSelectItem, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PicAnimationWid::*)()>(_a, &PicAnimationWid::SigStart, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PicAnimationWid::*)()>(_a, &PicAnimationWid::SigStop, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PicAnimationWid::*)()>(_a, &PicAnimationWid::SigStartMusic, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (PicAnimationWid::*)()>(_a, &PicAnimationWid::SigStopMusic, 5))
            return;
    }
}

const QMetaObject *PicAnimationWid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PicAnimationWid::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15PicAnimationWidE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PicAnimationWid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void PicAnimationWid::SigUpPreList(QTreeWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void PicAnimationWid::SigUpSelectItem(QTreeWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void PicAnimationWid::SigStart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PicAnimationWid::SigStop()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PicAnimationWid::SigStartMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PicAnimationWid::SigStopMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
