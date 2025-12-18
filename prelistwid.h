#ifndef PRELISTWID_H
#define PRELISTWID_H

#include <QListWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QPainter>



class PreListWid : public QListWidget
{
public:
    PreListWid(QWidget* parent = nullptr);
    virtual ~PreListWid();

private:
    QMap<QString, QListWidgetItem*> _set_items;
    void AddListItem(const QString &path);
    int _global;
    int _last_index;
    QPoint _pos_origin;

public slots:
    void SlotUpPreList(QTreeWidgetItem *tree_item);
    void SlotUpSelectItem(QTreeWidgetItem *tree_item);
};

#endif // PRELISTWID_H
