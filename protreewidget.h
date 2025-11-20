#ifndef PROTREEWIDGET_H
#define PROTREEWIDGET_H

#include <QTreeWidget>
#include <QSet>
#include <QHeaderView>
#include <QAction>
#include <QProgressDialog>
#include <QGuiApplication>
#include "protreeitem.h"
#include "protreethread.h"
#include "opentreethread.h"

class ProTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    ProTreeWidget(QWidget *parent = nullptr);
    void AddProToTree(const QString &name, const QString &path);

private:
    QSet<QString> _set_path;
    QTreeWidgetItem * _right_btn_item;
    //保存当前启动项目
    QTreeWidgetItem *_active_item;
    QTreeWidgetItem *_selected_item;
    //目录树右键导入、设置开始项、关闭、滑动展示
    QAction * _action_import;
    QAction * _action_setstart;
    QAction * _action_close;
    QAction * _action_slideshow;
    QProgressDialog* _dialog_progress;
    QProgressDialog* _open_progress_dialog;
    std::shared_ptr<ProTreeThread> _thread_create_pro;
    std::shared_ptr<OpenTreeThread> _thread_open_pro;

public slots:
    void SlotOpenPro(const QString &path);

private slots:
    void SlotItemPressed(QTreeWidgetItem *pressedItem, int column);
    void SlotImport();
    void SlotUpdateProgress(int count);
    void SlotFinishProgress();
    void SlotCancelProgress();
    void SlotSetActive();
    void SlotClosePro();

    void SlotUpdateOpenProgress(int count);
    void SlotFinishOpenProgress();
    void SlotCancelOpenProgress();

    void SlotDoubleClickedItem(QTreeWidgetItem *doubleItem, int col);

signals:
    void SigCancelProgress();
    void SigCancelOpenProgress();
    void SigUpdateSelected(const QString &);
};

#endif // PROTREEWIDGET_H
