#ifndef PICANIMATIONWID_H
#define PICANIMATIONWID_H
#include <QWidget>
#include <QTimer>
#include <QMap>
#include <QTreeWidgetItem>
#include <QPainter>
#include "protreeitem.h"

class PicAnimationWid : public QWidget
{
    Q_OBJECT
public:
    explicit PicAnimationWid(QWidget *parent = nullptr);
    ~PicAnimationWid();
    void SetPixmap(QTreeWidgetItem* item);
    void Start();
    void Stop();
    void SlidePre();
    void SlideNext();

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    float _factor;
    QTimer *_timer;
    QPixmap _pixmap1;
    QPixmap _pixmap2;
    QTreeWidgetItem* _cur_item;
    QMap<QString, QTreeWidgetItem*> _map_item;
    bool _b_start;
    void UpSelectPixmap(QTreeWidgetItem *item);

public slots:
    void SlotUpSelectShow(QString path);
    void SlotStartorStop();

private slots:
    void TimeOut();

signals:
    void SigUpPreList(QTreeWidgetItem* );
    void SigUpSelectItem(QTreeWidgetItem* );
    void SigStart();
    void SigStop();
    void SigStartMusic();
    void SigStopMusic();
};

#endif // PICANIMATIONWID_H
