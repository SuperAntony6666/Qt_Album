#ifndef PROTREEWIDGET_H
#define PROTREEWIDGET_H

#include <QTreeWidget>
#include <QSet>
#include <QHeaderView>
#include <QAction>
#include <QProgressDialog>
#include "protreethread.h"

class ProTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    ProTreeWidget(QWidget *parent = nullptr);
    void AddProToTree(const QString &name, const QString &path);

private:
    QSet<QString> _set_path;
    QTreeWidgetItem * _right_btn_item;
    //目录树右键导入、设置开始项、关闭、滑动展示
    QAction * _action_import;
    QAction * _action_setstart;
    QAction * _action_close;
    QAction * _action_slideshow;
    QProgressDialog* _dialog_progress;
    std::shared_ptr<ProTreeThread> _thread_create_pro;

private slots:
    void SlotItemPressed(QTreeWidgetItem *pressedItem, int column);
    void SlotImport();
    void SlotUpdateProgress(int count);
    void SlotFinishProgress();
    void SlotCancelProgress();

signals:
    void SigCancelProgress();
};

#endif // PROTREEWIDGET_H
