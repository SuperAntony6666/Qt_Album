#include "picbutton.h"

PicButton::PicButton(QWidget* parent) {

}

void PicButton::SetIcon(const QString &normal, const QString &hover, const QString &pressed)
{
    //添加到类成员
    _normal = normal;
    _hover = hover;
    _pressed = pressed;
    //QPixmap添加图片
    QPixmap tmpPixmap;
    tmpPixmap.load(normal);
    this->resize(tmpPixmap.size());
    this->setIcon(tmpPixmap);
    this->setIconSize(tmpPixmap.size());
}

bool PicButton::event(QEvent *e)
{
    switch(e->type()){
        case QEvent::Enter:
            SetHoverIcon();
            break;
        case QEvent::Leave:
            SetNormalIcon();
            break;
        case QEvent::MouseButtonPress:
            SetPressedIcon();
            break;
        case QEvent::MouseButtonRelease:
            SetHoverIcon();
        default:
            break;
    }
    return QPushButton::event(e);
}

void PicButton::SetNormalIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_normal);
    this->setIcon(tmpPixmap);
}

void PicButton::SetHoverIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_hover);
    this->setIcon(tmpPixmap);
}

void PicButton::SetPressedIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_pressed);
    this->setIcon(tmpPixmap);
}
