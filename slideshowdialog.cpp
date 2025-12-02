#include "slideshowdialog.h"
#include "ui_slideshowdialog.h"

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

    ui->picAnimation->SetPixmap(_first_item);
    ui->picAnimation->Start();
}


SlideShowDialog::~SlideShowDialog()
{
    delete ui;
}
