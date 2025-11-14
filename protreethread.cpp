#include "protreethread.h"
#include <QDir>
#include "const.h"
#include "protreeitem.h"


ProTreeThread::ProTreeThread(const QString &src_path, const QString &dist_path, QTreeWidgetItem *parent_item,
                             int file_count, QTreeWidget *self, QTreeWidgetItem *root, QObject *parent)
                            :QThread(parent), _src_path(src_path), _dist_path(dist_path), _parent_item(parent_item),
                            _file_count(file_count), _self(self), _root(root), _bstop(false)
{

}

ProTreeThread::~ProTreeThread()
{

}

void ProTreeThread::run()
{
    CreateProTree(_src_path, _dist_path, _parent_item, _file_count, _self, _root);
    //删除
    if(_bstop){
        auto path = dynamic_cast<ProTreeItem*> (_root)->GetPath();
        //获取root索引
        auto index = _self->indexOfTopLevelItem(_root);
        delete _self->takeTopLevelItem(index);
        QDir dir(path);
        dir.removeRecursively();
        return;
    }
    emit SigFinishProgress(_file_count);
}

void ProTreeThread::CreateProTree(const QString &src_path, const QString &dist_path, QTreeWidgetItem *parent_item,
                                  int &file_count, QTreeWidget *self, QTreeWidgetItem *root, QTreeWidgetItem *preItem)
{
    //_bstop停止状态
    if(_bstop){
        return;
    }
    //拷贝选择，默认true
    bool needcopy = true;
    if(src_path == dist_path){
        needcopy = false;
    }
    //导入读取路径及过滤器设置(文件夹、文件、除. ../其余)
    QDir import_dir(src_path);
    QStringList nameFilters;
    import_dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    //按文件夹名字排序
    import_dir.setSorting(QDir::Name);
    //递归取文件夹文件(文件夹内套文件夹，取里面内容)
    QFileInfoList list = import_dir.entryInfoList();
    for(int i = 0; i < list.size(); i++){
        if(_bstop){
            return;
        }
        QFileInfo fileInfo = list.at(i);
        bool bIsDir = fileInfo.isDir();
        //如果是目录，递归读取
        if(bIsDir){
            if(_bstop){
                return;
            }
            //file_count更新信号
            file_count++;
            emit SigUpdateProgress(file_count);
            //目的路径构造文件夹
            QDir dist_dir(dist_path);
            QString sub_dist_path = dist_dir.absoluteFilePath(fileInfo.fileName());
            QDir sub_dist_dir(sub_dist_path);
            if(!sub_dist_dir.exists()){
                bool ok = sub_dist_dir.mkpath(sub_dist_path);
                if(!ok){
                    qDebug() << "sub_dist_dir mkpath failed";
                    continue;
                }
            }
            auto *item = new ProTreeItem(parent_item, fileInfo.fileName(), sub_dist_path, root, TreeItemDir);
            item->setData(0, Qt::DisplayRole, fileInfo.fileName());
            item->setData(0, Qt::DecorationRole, QIcon(":/icon/dir.png"));
            item->setData(0, Qt::ToolTipRole, sub_dist_path);
            CreateProTree(fileInfo.absoluteFilePath(), sub_dist_path, item, file_count, self, root, preItem);
        }
        //如果不是目录，判断格式是否为图片格式，file_count调整
        else{
            if(_bstop){
                return;
            }
            const QString & suffix = fileInfo.completeSuffix();
            if(suffix != "jpg" && suffix != "jepg" && suffix != "png"){
                continue;
            }
            file_count++;
            //通知文件数量有更新
            emit SigUpdateProgress(file_count);
            //是否需要拷贝
            if(!needcopy){
                continue;
            }
            //目的路径构造文件夹拷贝、判断拷贝是否成功
            QDir dist_dir(dist_path);
            QString dist_file_path = dist_dir.absoluteFilePath(fileInfo.fileName());
            if(!QFile::copy(fileInfo.absoluteFilePath(), dist_file_path)){
                continue;
            }
            //失败继续，成功创建item
            auto *item = new ProTreeItem(parent_item, fileInfo.fileName(), dist_file_path, root, TreeItemPic);
            item->setData(0, Qt::DisplayRole, fileInfo.fileName());
            item->setData(0, Qt::DecorationRole, QIcon(":/icon/pic.png"));
            item->setData(0, Qt::ToolTipRole, dist_file_path);

            if(preItem){
                auto *pre_proitem = dynamic_cast<ProTreeItem*> (preItem);
                pre_proitem->SetNextItem(preItem);
            }
            item->SetPreItem(preItem);
            preItem = item;
        }
    }
}

void ProTreeThread::SlotCancelProgress()
{
    this->_bstop = true;
}
