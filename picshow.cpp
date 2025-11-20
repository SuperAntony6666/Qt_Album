#include "picshow.h"
#include "ui_picshow.h"

PicShow::PicShow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PicShow)
{
    ui->setupUi(this);
    ui->PreBtn->SetIcon(":/icon/previous.png",
                        ":/icon/previous_hover.png",
                        ":/icon/previous_press.png");
    ui->NextBtn->SetIcon(":/icon/next.png",
                         ":/icon/next_hover.png",
                         ":/icon/next_press.png");

    //随鼠标滑动显示或隐藏左右移按钮
    QGraphicsOpacityEffect *opacity_pre = new QGraphicsOpacityEffect(this);
    opacity_pre->setOpacity(0);
    ui->PreBtn->setGraphicsEffect(opacity_pre);

    QGraphicsOpacityEffect *opacity_next = new QGraphicsOpacityEffect(this);
    opacity_next->setOpacity(0);
    ui->NextBtn->setGraphicsEffect(opacity_next);

    //使用属性动画类让控件在透明度范围变化
    _animation_show_pre = new QPropertyAnimation(opacity_pre, "opacity", this);
    _animation_show_pre->setEasingCurve(QEasingCurve::Linear);
    _animation_show_pre->setDuration(500);

    _animation_show_next = new QPropertyAnimation(opacity_next, "opacity", this);
    _animation_show_next->setEasingCurve(QEasingCurve::Linear);
    _animation_show_next->setDuration(500);


}

PicShow::~PicShow()
{
    delete ui;
}

bool PicShow::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::Enter:
        ShowPreNextBtn(true);
        break;
    case QEvent::Leave:
        ShowPreNextBtn(false);
        break;
    default:
        break;
    }
    return QDialog::event(event);
}

void PicShow::ShowPreNextBtn(bool b_show)
{
    //需要隐藏及目前状态可见隐藏
    if(!b_show && _b_btnvisible){
        _animation_show_pre->stop();
        //从完全可见到不可见
        _animation_show_pre->setStartValue(1);
        _animation_show_pre->setEndValue(0);
        _animation_show_pre->start();

        _animation_show_next->stop();
        _animation_show_next->setStartValue(1);
        _animation_show_next->setEndValue(0);
        _animation_show_next->start();

        _b_btnvisible = false;
        return;
    }
    if(b_show && !_b_btnvisible){
        _animation_show_pre->stop();
        _animation_show_pre->setStartValue(0);
        _animation_show_pre->setEndValue(1);
        _animation_show_pre->start();

        _animation_show_next->stop();
        _animation_show_next->setStartValue(0);
        _animation_show_next->setEndValue(1);
        _animation_show_next->start();

        _b_btnvisible = true;
    }
}

void PicShow::SlotSelectedItem(const QString &path)
{
    _selected_path = path;

    //从路径加载图像
    _pix_map.load(path);
    auto width = this->width() - 20;
    auto height = this->height() - 20;
    _pix_map = _pix_map.scaled(width, height, Qt::KeepAspectRatio);
    ui->label->setPixmap(_pix_map);
}


