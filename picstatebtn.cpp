#include "picstatebtn.h"

PicStateBtn::PicStateBtn(QWidget* parent) : QPushButton(parent)
{

}

void PicStateBtn::SetIcons(const QString &normal, const QString &hover, const QString &pressed,
                           const QString &normal_stop, const QString &hover_stop, const QString &pressed_stop)
{
    _normal = normal;
    _hover = hover;
    _pressed = pressed;
    _normal_stop = normal_stop;
    _hover_stop = hover_stop;
    _pressed_stop = pressed_stop;

    QPixmap tmpPixmap;
    tmpPixmap.load(normal);
    this->resize(tmpPixmap.size());
    this->setIcon(tmpPixmap);
    this->setIconSize(tmpPixmap.size());
    _cur_state = PicBtnStateNormal;
}
