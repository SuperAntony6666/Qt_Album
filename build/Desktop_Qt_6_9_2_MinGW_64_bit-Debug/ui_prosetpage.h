/********************************************************************************
** Form generated from reading UI file 'prosetpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROSETPAGE_H
#define UI_PROSETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_ProSetPage
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *Name_label;
    QLineEdit *Name_Edit;
    QLabel *Path_label;
    QLineEdit *Path_Edit;
    QPushButton *browse_Btn;
    QLabel *tips;

    void setupUi(QWizardPage *ProSetPage)
    {
        if (ProSetPage->objectName().isEmpty())
            ProSetPage->setObjectName("ProSetPage");
        ProSetPage->resize(559, 332);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProSetPage->sizePolicy().hasHeightForWidth());
        ProSetPage->setSizePolicy(sizePolicy);
        ProSetPage->setMinimumSize(QSize(0, 0));
        ProSetPage->setMaximumSize(QSize(16777215, 16777215));
        ProSetPage->setSizeIncrement(QSize(0, 0));
        ProSetPage->setBaseSize(QSize(0, 0));
        gridLayout = new QGridLayout(ProSetPage);
        gridLayout->setObjectName("gridLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Name_label = new QLabel(ProSetPage);
        Name_label->setObjectName("Name_label");
        Name_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(Name_label, 0, 0, 1, 1);

        Name_Edit = new QLineEdit(ProSetPage);
        Name_Edit->setObjectName("Name_Edit");

        gridLayout_2->addWidget(Name_Edit, 0, 1, 1, 1);

        Path_label = new QLabel(ProSetPage);
        Path_label->setObjectName("Path_label");
        Path_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(Path_label, 1, 0, 1, 1);

        Path_Edit = new QLineEdit(ProSetPage);
        Path_Edit->setObjectName("Path_Edit");

        gridLayout_2->addWidget(Path_Edit, 1, 1, 1, 1);

        browse_Btn = new QPushButton(ProSetPage);
        browse_Btn->setObjectName("browse_Btn");

        gridLayout_2->addWidget(browse_Btn, 1, 2, 1, 1);

        tips = new QLabel(ProSetPage);
        tips->setObjectName("tips");

        gridLayout_2->addWidget(tips, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(ProSetPage);

        QMetaObject::connectSlotsByName(ProSetPage);
    } // setupUi

    void retranslateUi(QWizardPage *ProSetPage)
    {
        ProSetPage->setWindowTitle(QCoreApplication::translate("ProSetPage", "WizardPage", nullptr));
        Name_label->setText(QCoreApplication::translate("ProSetPage", "Name:", nullptr));
        Path_label->setText(QCoreApplication::translate("ProSetPage", "Path:", nullptr));
        browse_Btn->setText(QCoreApplication::translate("ProSetPage", "browse", nullptr));
        tips->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProSetPage: public Ui_ProSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROSETPAGE_H
