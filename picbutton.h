#ifndef PICBUTTON_H
#define PICBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QEvent>

class PicButton : public QPushButton
{
public:
    PicButton(QWidget* parent = nullptr);
    //按钮状态(普通，悬浮，点击)
    void SetIcon(const QString &normal, const QString &hover, const QString &pressed);

protected:
    bool event(QEvent *e) override;

private:
    QString _normal;
    QString _hover;
    QString _pressed;
    void SetNormalIcon();
    void SetHoverIcon();
    void SetPressedIcon();

};

#endif // PICBUTTON_H
