/****************************************************************************
** Meta object code from reading C++ file 'protreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../protreewidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protreewidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13ProTreeWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto ProTreeWidget::qt_create_metaobjectdata<qt_meta_tag_ZN13ProTreeWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ProTreeWidget",
        "SigCancelProgress",
        "",
        "SigCancelOpenProgress",
        "SigUpdateSelected",
        "SigUpdatePic",
        "SigClearSelected",
        "SlotOpenPro",
        "path",
        "SlotPreShow",
        "SlotNextShow",
        "SlotItemPressed",
        "QTreeWidgetItem*",
        "pressedItem",
        "column",
        "SlotImport",
        "SlotUpdateProgress",
        "count",
        "SlotFinishProgress",
        "SlotCancelProgress",
        "SlotSetActive",
        "SlotClosePro",
        "SlotUpdateOpenProgress",
        "SlotFinishOpenProgress",
        "SlotCancelOpenProgress",
        "SlotDoubleClickedItem",
        "doubleItem",
        "col"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'SigCancelProgress'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'SigCancelOpenProgress'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'SigUpdateSelected'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'SigUpdatePic'
        QtMocHelpers::SignalData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'SigClearSelected'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'SlotOpenPro'
        QtMocHelpers::SlotData<void(const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Slot 'SlotPreShow'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'SlotNextShow'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'SlotItemPressed'
        QtMocHelpers::SlotData<void(QTreeWidgetItem *, int)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 12, 13 }, { QMetaType::Int, 14 },
        }}),
        // Slot 'SlotImport'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'SlotUpdateProgress'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'SlotFinishProgress'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'SlotCancelProgress'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'SlotSetActive'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'SlotClosePro'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'SlotUpdateOpenProgress'
        QtMocHelpers::SlotData<void(int)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'SlotFinishOpenProgress'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'SlotCancelOpenProgress'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'SlotDoubleClickedItem'
        QtMocHelpers::SlotData<void(QTreeWidgetItem *, int)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 12, 26 }, { QMetaType::Int, 27 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ProTreeWidget, qt_meta_tag_ZN13ProTreeWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ProTreeWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ProTreeWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ProTreeWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13ProTreeWidgetE_t>.metaTypes,
    nullptr
} };

void ProTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ProTreeWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->SigCancelProgress(); break;
        case 1: _t->SigCancelOpenProgress(); break;
        case 2: _t->SigUpdateSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->SigUpdatePic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->SigClearSelected(); break;
        case 5: _t->SlotOpenPro((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->SlotPreShow(); break;
        case 7: _t->SlotNextShow(); break;
        case 8: _t->SlotItemPressed((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->SlotImport(); break;
        case 10: _t->SlotUpdateProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->SlotFinishProgress(); break;
        case 12: _t->SlotCancelProgress(); break;
        case 13: _t->SlotSetActive(); break;
        case 14: _t->SlotClosePro(); break;
        case 15: _t->SlotUpdateOpenProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->SlotFinishOpenProgress(); break;
        case 17: _t->SlotCancelOpenProgress(); break;
        case 18: _t->SlotDoubleClickedItem((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ProTreeWidget::*)()>(_a, &ProTreeWidget::SigCancelProgress, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProTreeWidget::*)()>(_a, &ProTreeWidget::SigCancelOpenProgress, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProTreeWidget::*)(const QString & )>(_a, &ProTreeWidget::SigUpdateSelected, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProTreeWidget::*)(const QString & )>(_a, &ProTreeWidget::SigUpdatePic, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProTreeWidget::*)()>(_a, &ProTreeWidget::SigClearSelected, 4))
            return;
    }
}

const QMetaObject *ProTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ProTreeWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int ProTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void ProTreeWidget::SigCancelProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProTreeWidget::SigCancelOpenProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ProTreeWidget::SigUpdateSelected(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ProTreeWidget::SigUpdatePic(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ProTreeWidget::SigClearSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
