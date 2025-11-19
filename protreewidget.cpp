#include "protreewidget.h"
#include <QDir>
#include <QDebug>
#include <QMenu>
#include <QGuiApplication>
#include <QProgressDialog>
#include <QFileDialog>
#include "const.h"
#include "protreeitem.h"
#include "removeprodialog.h"


ProTreeWidget::ProTreeWidget(QWidget *parent) : QTreeWidget(parent),_active_item(nullptr), _right_btn_item(nullptr),
    _dialog_progress(nullptr), _selected_item(nullptr), _thread_create_pro(nullptr), _thread_open_pro(nullptr), _open_progress_dialog(nullptr){
    this->header()->hide();
    connect(this, &ProTreeWidget::itemPressed, this, &ProTreeWidget::SlotItemPressed);
    //添加导入动作
    _action_import = new QAction(QIcon(":/icon/import.png"), tr("导入文件"), this);
    _action_setstart = new QAction(QIcon(":/icon/core.png"), tr("设为活动项目"), this);
    _action_close = new QAction(QIcon(":/icon/close.png"), tr("关闭项目"), this);
    _action_slideshow = new QAction(QIcon(":/icon/slideshow.png"), tr("轮播图播放"), this);
    //向项目里导入文件
    connect(_action_import, &QAction::triggered, this, &ProTreeWidget::SlotImport);
    //设置活动项目,加粗字体
    connect(_action_setstart, &QAction::triggered, this, &ProTreeWidget::SlotSetActive);
    //关闭项目，从目录树中移除
    connect(_action_close, &QAction::triggered, this, &ProTreeWidget::SlotClosePro);
}

void ProTreeWidget::AddProToTree(const QString &name, const QString &path)
{
    //打开路径，创建文件夹显示在左侧
    QDir dir(path);
    QString file_path = dir.absoluteFilePath(name);
    //判断重名
    if(_set_path.find(file_path) != _set_path.end()){
        qDebug() << "file has loaded";
        return;
    }
    //构造项目用的文件夹
    QDir pro_dir(file_path);
    //如果文件夹不存在则创建
    if(!pro_dir.exists()){
        bool enable = pro_dir.mkpath(file_path);
        if(!enable){
            qDebug() << "pro_dir make path failed";
            return;
        }
    }

    //加入set
    _set_path.insert(file_path);
    auto *item = new ProTreeItem(this, name, file_path, TreeItemPro);
    item->setData(0,Qt::DisplayRole, name);
    item->setData(0,Qt::DecorationRole, QIcon(":/icon/dir.png"));
    item->setData(0,Qt::ToolTipRole, file_path);
}

void ProTreeWidget::SlotOpenPro(const QString &path)
{
    //判断是否打开过，打开的路径在set里
    if(_set_path.find(path) != _set_path.end()){
        return;
    }
    _set_path.insert(path);
    int file_count = 0;
    QDir pro_dir(path);
    QString pro_name = pro_dir.dirName();

    _thread_open_pro = std::make_shared<OpenTreeThread>(path, file_count, this, nullptr);
    _thread_open_pro->start();

    _open_progress_dialog = new QProgressDialog(this);
    //线程和进度条连接
    connect(_thread_open_pro.get(), &OpenTreeThread::SigUpdateProgress, this, &ProTreeWidget::SlotUpdateOpenProgress);
    //完成逻辑
    connect(_thread_open_pro.get(), &OpenTreeThread::SigFinishProgress, this, &ProTreeWidget::SlotFinishOpenProgress);
    //取消逻辑
    connect(_open_progress_dialog, &QProgressDialog::canceled, this, &ProTreeWidget::SlotCancelOpenProgress);
    //取消信号和线程连接
    connect(this, &ProTreeWidget::SigCancelOpenProgress, _thread_open_pro.get(), &OpenTreeThread::SlotCancelProgress);

    _thread_open_pro->start();
    //对话框初始化(固定宽高比)
    _open_progress_dialog->setWindowTitle("Please Wait...");
    _open_progress_dialog->setFixedWidth(PROGRESS_WIDTH);
    _open_progress_dialog->setRange(0, PROGRESS_WIDTH);
    _open_progress_dialog->exec();
}


void ProTreeWidget::SlotItemPressed(QTreeWidgetItem *pressedItem, int column)
{
    //右键点击，弹出菜单
    if(QGuiApplication::mouseButtons() == Qt::RightButton){
        //动作加入菜单
        QMenu menu(this);
        int itemtype = (int)(pressedItem->type());
        //是不是选中的项目条目
        if(itemtype == TreeItemPro){
            _right_btn_item = pressedItem;
            menu.addAction(_action_import);
            menu.addAction(_action_setstart);
            menu.addAction(_action_close);
            menu.addAction(_action_slideshow);
            menu.exec(QCursor::pos());
        }
    }
}

//导入动作槽函数
void ProTreeWidget::SlotImport()
{
    //文件对话框(点导入时弹出)
    QFileDialog file_dialog;
    //设置文件模式、title、变量存储路径
    file_dialog.setFileMode(QFileDialog::Directory);
    file_dialog.setWindowTitle(tr("选中导入文件"));
    QString path = "";
    //右键为空，返回
    if(!_right_btn_item){
        qDebug() << "_right_btn_item is empty";
        return;
    }
    //获取路径
    path = dynamic_cast<ProTreeItem*> (_right_btn_item)->GetPath();
    //文件对话框设置默认路径
    file_dialog.setDirectory(path);
    //设置展现形式
    file_dialog.setViewMode(QFileDialog::Detail);
    //str_list缓存
    QStringList fileNames;
    if(file_dialog.exec()){
        fileNames = file_dialog.selectedFiles();
    }
    if(fileNames.length() <= 0){
        return;
    }
    QString import_path = fileNames.at(0);
    int file_count = 0;
    //创建模态对话框（进度条）
    _dialog_progress = new QProgressDialog(this);
    //耗时操作放在线程操作中
    _thread_create_pro = std::make_shared<ProTreeThread>(std::ref(import_path), std::ref(path),
                                                         _right_btn_item,
                                                         std::ref(file_count), this,_right_btn_item,nullptr);
    //线程和进度条连接
    connect(_thread_create_pro.get(), &ProTreeThread::SigUpdateProgress, this, &ProTreeWidget::SlotUpdateProgress);
    //完成逻辑
    connect(_thread_create_pro.get(), &ProTreeThread::SigFinishProgress, this, &ProTreeWidget::SlotFinishProgress);
    //取消逻辑
    connect(_dialog_progress, &QProgressDialog::canceled, this, &ProTreeWidget::SlotCancelProgress);
    //取消信号和线程连接
    connect(this, &ProTreeWidget::SigCancelProgress, _thread_create_pro.get(), &ProTreeThread::SlotCancelProgress);

    _thread_create_pro->start();
    //对话框初始化(固定宽高比)
    _dialog_progress->setWindowTitle("Please Wait...");
    _dialog_progress->setFixedWidth(PROGRESS_WIDTH);
    _dialog_progress->setRange(0, PROGRESS_WIDTH);
    _dialog_progress->exec();
}

void ProTreeWidget::SlotUpdateProgress(int count)
{
    if(!_dialog_progress){
        qDebug() << "_dialog_progress is empty";
    }
    if(count >= PROGRESS_MAX){
        _dialog_progress->setValue(count % PROGRESS_MAX);
    }
    else{
        _dialog_progress->setValue(count);
    }
}

void ProTreeWidget::SlotFinishProgress()
{
    _dialog_progress->setValue(PROGRESS_MAX);
    _dialog_progress->deleteLater();
}

void ProTreeWidget::SlotCancelProgress()
{
    emit SigCancelProgress();
    delete _dialog_progress;
    _dialog_progress = nullptr;
}

void ProTreeWidget::SlotSetActive()
{
    //非法操作返回
    if(!_right_btn_item){
        return;
    }
    //定义字体，设置粗体
    QFont nullFont;
    nullFont.setBold(false);
    if(_active_item){
        _active_item->setFont(0, nullFont);
    }
    _active_item = _right_btn_item;
    nullFont.setBold(true);
    _active_item->setFont(0, nullFont);

}

void ProTreeWidget::SlotClosePro()
{
    //remove初始化
    RemoveProDialog remove_pro_dialog;
    //判断执行结果，!acc返回
    auto res = remove_pro_dialog.exec();
    if(res != QDialog::Accepted){
        return;
    }
    //判断勾选状态
    bool b_removed = remove_pro_dialog.IsRemoved();
    //获取widget中的索引,以及当前条目,获取删除路径
    auto index_right_btn = this->indexOfTopLevelItem(_right_btn_item);
    auto *protreeitem = dynamic_cast<ProTreeItem*>(_right_btn_item);
    auto *select_path = dynamic_cast<ProTreeItem*>(_selected_item);
    auto delete_path = protreeitem->GetPath();
    _set_path.remove(delete_path);
    if(b_removed){
        QDir delete_dir(delete_path);
        delete_dir.removeRecursively();
    }
    //如果删除条目和当前激活条目是同一个
    if(protreeitem == _active_item){
        _active_item = nullptr;
    }

    delete this->takeTopLevelItem(index_right_btn);
    _right_btn_item = nullptr;
}

void ProTreeWidget::SlotUpdateOpenProgress(int count)
{
    if(!_open_progress_dialog){
        qDebug() << "_open_progress_dialog is empty";
    }
    if(count >= PROGRESS_MAX){
        _open_progress_dialog->setValue(count % PROGRESS_MAX);
    }
    else{
        _open_progress_dialog->setValue(count);
    }
}

void ProTreeWidget::SlotFinishOpenProgress()
{
    _open_progress_dialog->setValue(PROGRESS_MAX);
    _open_progress_dialog->deleteLater();
}

void ProTreeWidget::SlotCancelOpenProgress()
{
    emit SigCancelOpenProgress();
    delete _open_progress_dialog;
    _open_progress_dialog = nullptr;
}



