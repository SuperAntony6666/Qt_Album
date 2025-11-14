#include "protreewidget.h"
#include <QDir>
#include <QDebug>
#include <QMenu>
#include <QGuiApplication>
#include <QProgressDialog>
#include <QFileDialog>
#include "const.h"
#include "protreeitem.h"


ProTreeWidget::ProTreeWidget(QWidget *parent) {
    this->header()->hide();
    connect(this, &ProTreeWidget::itemPressed, this, &ProTreeWidget::SlotItemPressed);
    //添加导入动作
    _action_import = new QAction(QIcon(":/icon/import.png"), tr("导入文件"), this);
    _action_setstart = new QAction(QIcon(":/icon/core.png"), tr("设为活动项目"), this);
    _action_close = new QAction(QIcon(":/icon/close.png"), tr("关闭项目"), this);
    _action_slideshow = new QAction(QIcon(":/icon/slideshow.png"), tr("轮播图播放"), this);
    connect(_action_import, &QAction::triggered, this, &ProTreeWidget::SlotImport);
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



