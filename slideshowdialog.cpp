#include "slideshowdialog.h"
#include "ui_slideshowdialog.h"
#include "protreewidget.h"

SlideShowDialog::SlideShowDialog(QWidget *parent, QTreeWidgetItem *first_item, QTreeWidgetItem *last_item)
    : QDialog(parent), _first_item(first_item), _last_item(last_item), ui(new Ui::SlideShowDialog)
{
    ui->setupUi(this);
    //隐藏窗口
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    ui->slidePreBtn->SetIcons(":/icon/previous.png",
                    ":/icon/previous_hover.png",
                    ":/icon/previous_press.png");
    ui->slideNextBtn->SetIcons(":/icon/next.png",
                     ":/icon/next_hover.png",
                     ":/icon/next_press.png");
    ui->CloseBtn->SetIcons(":/icon/closeshow.png",
                 ":/icon/closeshow_hover.png",
                 ":/icon/closeshow_press.png");
    ui->PlayBtn->SetIcons(":/icon/play.png",
                ":/icon/play_hover.png",
                ":/icon/play_press.png",
                ":/icon/pause.png",
                ":/icon/pause_hover.png",
                ":/icon/pause_press.png");
    connect(ui->CloseBtn, &QPushButton::clicked, this, &SlideShowDialog::close);
    connect(ui->slidePreBtn, &QPushButton::clicked, this, &SlideShowDialog::SlotSlidePre);
    connect(ui->slideNextBtn, &QPushButton::clicked, this, &SlideShowDialog::SlotSlideNext);


    auto *prelistWid = dynamic_cast<PreListWid*>(ui->PrelistWidget);
    connect(ui->picAnimation, &PicAnimationWid::SigUpPreList, prelistWid, &PreListWid::SlotUpPreList);
    connect(ui->picAnimation, &PicAnimationWid::SigUpSelectItem, prelistWid, &PreListWid::SlotUpSelectItem);
    connect(prelistWid, &PreListWid::SigUpSelectShow, ui->picAnimation, &PicAnimationWid::SlotUpSelectShow);
    connect(ui->PlayBtn, &PicStateBtn::clicked, ui->picAnimation, &PicAnimationWid::SlotStartorStop);
    connect(ui->picAnimation, &PicAnimationWid::SigStart, ui->PlayBtn, &PicStateBtn::SlotStart);
    connect(ui->picAnimation, &PicAnimationWid::SigStop, ui->PlayBtn, &PicStateBtn::SlotStop);
    auto _protree_widget = dynamic_cast<ProTreeWidget*>(parent);
    connect(ui->picAnimation, &PicAnimationWid::SigStartMusic, _protree_widget, &ProTreeWidget::SlotStartMusic);
    connect(ui->picAnimation, &PicAnimationWid::SigStopMusic, _protree_widget, &ProTreeWidget::SlotStopMusic);

    ui->picAnimation->SetPixmap(_first_item);
    ui->picAnimation->Start();



}


SlideShowDialog::~SlideShowDialog()
{
    delete ui;
}

void SlideShowDialog::SlotSlidePre()
{
    ui->picAnimation->SlideNext();
}

void SlideShowDialog::SlotSlideNext()
{
    ui->picAnimation->SlidePre();
}
