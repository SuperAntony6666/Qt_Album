#include <QEvent>
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

void PicStateBtn::SetNormalIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_normal);
    this->setIcon(tmpPixmap);
    _cur_state = PicBtnStateNormal;
}

void PicStateBtn::SetHoverIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_hover);
    this->setIcon(tmpPixmap);
    _cur_state = PicBtnStateHover;
}

void PicStateBtn::SetPressedIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_pressed);
    this->setIcon(tmpPixmap);
    _cur_state = PicBtnStatePressed;
}

void PicStateBtn::SetNormalStopIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_normal_stop);
    this->setIcon(tmpPixmap);
    _cur_state = PicBtnStateStopNormal;
}

void PicStateBtn::SetHoverStopIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_hover_stop);
    this->setIcon(tmpPixmap);
    _cur_state = PicBtnStateStopHover;
}

void PicStateBtn::SetPressedStopIcon()
{
    QPixmap tmpPixmap;
    tmpPixmap.load(_pressed_stop);
    this->setIcon(tmpPixmap);
    _cur_state = PicBtnStateStopPressed;
}



bool PicStateBtn::event(QEvent *event){
    switch(event->type()){
        case QEvent::Enter:
            if(_cur_state < PicBtnStateStopNormal){
                SetHoverIcon();
            }
            else{
                SetHoverStopIcon();
            }
            break;

        case QEvent::Leave:
            if(_cur_state < PicBtnStateStopNormal){
                SetNormalIcon();
            }
            else{
                SetNormalStopIcon();
            }
            break;
        case QEvent::MouseButtonPress:
            if(_cur_state < PicBtnStateStopNormal){
                SetPressedIcon();
            }
            else{
                SetPressedStopIcon();
            }
            break;
        case QEvent::MouseButtonRelease:
            if(_cur_state < PicBtnStateStopNormal){
                SetHoverStopIcon();
            }
            else{
                SetHoverIcon();
            }
            break;

        default:
            break;
    }
    return QPushButton::event(event);
}


