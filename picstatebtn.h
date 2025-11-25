#ifndef PICSTATEBTN_H
#define PICSTATEBTN_H

#include <QPushButton>
#include "const.h"

class PicStateBtn : public QPushButton
{
public:
    PicStateBtn(QWidget* parent = nullptr);
    void SetIcons(const QString& normal, const QString& hover, const QString& pressed,
                    const QString& normal_stop, const QString& hover_stop, const QString& pressed_stop);

private:
    QString _normal;
    QString _hover;
    QString _pressed;
    QString _normal_stop;
    QString _hover_stop;
    QString _pressed_stop;
    int _cur_state;
};

#endif // PICSTATEBTN_H
