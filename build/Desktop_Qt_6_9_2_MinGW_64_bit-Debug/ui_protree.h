/********************************************************************************
** Form generated from reading UI file 'protree.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTREE_H
#define UI_PROTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include "protreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ProTree
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *ProTree_label;
    ProTreeWidget *ProTree_Widget;

    void setupUi(QDialog *ProTree)
    {
        if (ProTree->objectName().isEmpty())
            ProTree->setObjectName("ProTree");
        ProTree->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(ProTree);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        ProTree_label = new QLabel(ProTree);
        ProTree_label->setObjectName("ProTree_label");

        verticalLayout->addWidget(ProTree_label);

        ProTree_Widget = new ProTreeWidget(ProTree);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        ProTree_Widget->setHeaderItem(__qtreewidgetitem);
        ProTree_Widget->setObjectName("ProTree_Widget");

        verticalLayout->addWidget(ProTree_Widget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ProTree);

        QMetaObject::connectSlotsByName(ProTree);
    } // setupUi

    void retranslateUi(QDialog *ProTree)
    {
        ProTree->setWindowTitle(QCoreApplication::translate("ProTree", "Dialog", nullptr));
        ProTree_label->setText(QCoreApplication::translate("ProTree", "\351\241\271\347\233\256\347\233\256\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProTree: public Ui_ProTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTREE_H
