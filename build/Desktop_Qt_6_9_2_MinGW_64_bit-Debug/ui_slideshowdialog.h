/********************************************************************************
** Form generated from reading UI file 'slideshowdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDESHOWDIALOG_H
#define UI_SLIDESHOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <picanimationwid.h>
#include <picbutton.h>
#include <picstatebtn.h>
#include <prelistwid.h>

QT_BEGIN_NAMESPACE

class Ui_SlideShowDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *SlideShow;
    QGridLayout *gridLayout;
    QWidget *slidePrewid;
    QVBoxLayout *verticalLayout_3;
    PicButton *slidePreBtn;
    PicAnimationWid *picAnimation;
    QHBoxLayout *horizontalLayout_2;
    PicStateBtn *PlayBtn;
    PicButton *CloseBtn;
    QWidget *slideNextwid;
    QVBoxLayout *verticalLayout_2;
    PicButton *slideNextBtn;
    QWidget *PreShow;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    PreListWid *PrelistWidget;

    void setupUi(QDialog *SlideShowDialog)
    {
        if (SlideShowDialog->objectName().isEmpty())
            SlideShowDialog->setObjectName("SlideShowDialog");
        SlideShowDialog->resize(753, 532);
        verticalLayout = new QVBoxLayout(SlideShowDialog);
        verticalLayout->setObjectName("verticalLayout");
        SlideShow = new QWidget(SlideShowDialog);
        SlideShow->setObjectName("SlideShow");
        gridLayout = new QGridLayout(SlideShow);
        gridLayout->setObjectName("gridLayout");
        slidePrewid = new QWidget(SlideShow);
        slidePrewid->setObjectName("slidePrewid");
        slidePrewid->setMinimumSize(QSize(80, 0));
        slidePrewid->setMaximumSize(QSize(80, 16777215));
        verticalLayout_3 = new QVBoxLayout(slidePrewid);
        verticalLayout_3->setObjectName("verticalLayout_3");
        slidePreBtn = new PicButton(slidePrewid);
        slidePreBtn->setObjectName("slidePreBtn");

        verticalLayout_3->addWidget(slidePreBtn);


        gridLayout->addWidget(slidePrewid, 1, 0, 1, 1);

        picAnimation = new PicAnimationWid(SlideShow);
        picAnimation->setObjectName("picAnimation");

        gridLayout->addWidget(picAnimation, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        PlayBtn = new PicStateBtn(SlideShow);
        PlayBtn->setObjectName("PlayBtn");

        horizontalLayout_2->addWidget(PlayBtn);

        CloseBtn = new PicButton(SlideShow);
        CloseBtn->setObjectName("CloseBtn");

        horizontalLayout_2->addWidget(CloseBtn);


        gridLayout->addLayout(horizontalLayout_2, 0, 2, 1, 1);

        slideNextwid = new QWidget(SlideShow);
        slideNextwid->setObjectName("slideNextwid");
        slideNextwid->setMinimumSize(QSize(80, 0));
        slideNextwid->setMaximumSize(QSize(80, 16777215));
        verticalLayout_2 = new QVBoxLayout(slideNextwid);
        verticalLayout_2->setObjectName("verticalLayout_2");
        slideNextBtn = new PicButton(slideNextwid);
        slideNextBtn->setObjectName("slideNextBtn");

        verticalLayout_2->addWidget(slideNextBtn);


        gridLayout->addWidget(slideNextwid, 1, 2, 1, 1);


        verticalLayout->addWidget(SlideShow);

        PreShow = new QWidget(SlideShowDialog);
        PreShow->setObjectName("PreShow");
        horizontalLayout = new QHBoxLayout(PreShow);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(PreShow);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 120));
        widget->setMaximumSize(QSize(16777215, 120));
        PrelistWidget = new PreListWid(widget);
        PrelistWidget->setObjectName("PrelistWidget");
        PrelistWidget->setGeometry(QRect(10, 10, 16777215, 110));
        PrelistWidget->setMinimumSize(QSize(0, 110));
        PrelistWidget->setMaximumSize(QSize(16777215, 110));
        PrelistWidget->setFlow(QListView::Flow::LeftToRight);

        horizontalLayout->addWidget(widget);


        verticalLayout->addWidget(PreShow);

        verticalLayout->setStretch(0, 7);
        verticalLayout->setStretch(1, 1);

        retranslateUi(SlideShowDialog);

        QMetaObject::connectSlotsByName(SlideShowDialog);
    } // setupUi

    void retranslateUi(QDialog *SlideShowDialog)
    {
        SlideShowDialog->setWindowTitle(QCoreApplication::translate("SlideShowDialog", "Dialog", nullptr));
        slidePreBtn->setText(QString());
        PlayBtn->setText(QString());
        CloseBtn->setText(QString());
        slideNextBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SlideShowDialog: public Ui_SlideShowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDESHOWDIALOG_H
