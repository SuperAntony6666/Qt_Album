#include "protreewidget.h"
#include <QDir>
#include <QDebug>
#include "const.h"
#include "protreeitem.h"

ProTreeWidget::ProTreeWidget(QWidget *parent) {

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
