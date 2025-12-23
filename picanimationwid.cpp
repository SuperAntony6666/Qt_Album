#include "picanimationwid.h"

PicAnimationWid::PicAnimationWid(QWidget *parent)
    : QWidget{parent}, _factor(0.0), _cur_item(nullptr), _b_start(false)
{
    _timer = new QTimer;
    connect(_timer, &QTimer::timeout, this, &PicAnimationWid::TimeOut);
}

PicAnimationWid::~PicAnimationWid()
{

}

void PicAnimationWid::SetPixmap(QTreeWidgetItem *item)
{
    if(!item){
        return;
    }
    auto *tree_item = dynamic_cast<ProTreeItem*>(item);
    auto path = tree_item->GetPath();
    _pixmap1.load(path);
    _cur_item = tree_item;
    //检测其是否在map中添加
    if(_map_item.find(path) == _map_item.end()){
        _map_item[path] = tree_item;
        //发送更新逻辑
        emit SigUpPreList(item);
    }
    //
    emit SigUpSelectItem(item);
    //双缓冲绘图
    auto *next_item = tree_item->GetNextItem();
    if(!next_item){
        return;
    }
    auto next_path = next_item->GetPath();
    _pixmap2.load(next_path);
    if(_map_item.find(next_path) == _map_item.end()){
        _map_item[next_path] = next_item;
        emit SigUpPreList(next_item);
    }
}

void PicAnimationWid::Start()
{
    emit SigStart();
    emit SigStartMusic();
    _factor = 0.0;
    _timer->start(25);
    _b_start = true;
}

void PicAnimationWid::Stop()
{
    emit SigStop();
    emit SigStopMusic();
    //重置为初始状态
    _timer->stop();
    _factor = 0.0;
    _b_start = false;
}

void PicAnimationWid::SlidePre()
{
    Stop();
    if(!_cur_item){
        return;
    }
    auto *cur_pro_item = dynamic_cast<ProTreeItem*> (_cur_item);
    auto *pre_item = cur_pro_item->GetNextItem();
    if(!pre_item){
        return;
    }
    SetPixmap(pre_item);
    update();
}

void PicAnimationWid::SlideNext()
{
    Stop();
    if(!_cur_item){
        return;
    }
    auto *cur_pro_item = dynamic_cast<ProTreeItem*> (_cur_item);
    auto *next_item = cur_pro_item->GetNextItem();
    if(!next_item){
        return;
    }
    SetPixmap(next_item);
    update();
}


// void PicAnimationWid::paintEvent(QPaintEvent *event)
// {
//     QPainter painter(this);
//     painter.setRenderHint(QPainter::Antialiasing, true);

//     int w = width();
//     int h = height();

//     // 绘制第一张图（渐隐）
//     if(!_pixmap1.isNull()){
//         painter.setOpacity(1.0 - _factor); // 设置透明度
//         QPixmap scaled1 = _pixmap1.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//         int x = (w - scaled1.width()) / 2;
//         int y = (h - scaled1.height()) / 2;
//         painter.drawPixmap(x, y, scaled1);
//     }

//     // 绘制第二张图（渐现）
//     if(!_pixmap2.isNull() && _factor > 0){
//         painter.setOpacity(_factor); // 设置透明度
//         QPixmap scaled2 = _pixmap2.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//         int x = (w - scaled2.width()) / 2;
//         int y = (h - scaled2.height()) / 2;
//         painter.drawPixmap(x, y, scaled2);
//     }
// }


void PicAnimationWid::paintEvent(QPaintEvent *event)
{
    if(_pixmap1.isNull()){
        return;
    }
    QPainter painter(this);
    //抗锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);
    //QRect获取绘制区域，并取宽高
    QRect rect = geometry();
    int w = rect.width();
    int h = rect.height();
    //pixmap等比拉伸
    _pixmap1 = _pixmap1.scaled(w, h, Qt::KeepAspectRatio);
    //获取alpha遮罩来填充初始化透明
    int alpha = 255 * (1.0 - _factor);
    QPixmap alphaPixmap(_pixmap1.size());
    alphaPixmap.fill(Qt::transparent);
    //QPainter p1接收和设置绘制图像逻辑
    QPainter p1(&alphaPixmap);
    p1.setCompositionMode(QPainter::CompositionMode_Source);
    //从0，0开始绘制
    p1.drawPixmap(0, 0, _pixmap1);
    //让图片渐隐
    p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p1.fillRect(alphaPixmap.rect(), QColor(0, 0, 0, alpha));
    p1.end();

    //图片大小不一，因此做居中处理
    int x = (w - _pixmap1.width()) / 2;
    int y = (h - _pixmap1.height()) / 2;
    painter.drawPixmap(x, y, alphaPixmap);

    if(_pixmap2.isNull()){
        return;
    }
    _pixmap2 = _pixmap2.scaled(w, h, Qt::KeepAspectRatio);
    alpha = 255 * _factor;
    QPixmap alphaPixmap2(_pixmap2.size());
    alphaPixmap2.fill(Qt::transparent);
    QPainter p2(&alphaPixmap2);
    p2.setCompositionMode(QPainter::CompositionMode_Source);
    p2.drawPixmap(0, 0, _pixmap2);
    p2.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p2.fillRect(alphaPixmap.rect(), QColor(0, 0, 0, alpha));
    p2.end();
    x = (w - _pixmap1.width()) / 2;
    y = (h - _pixmap2.height()) / 2;
    painter.drawPixmap(x, y, alphaPixmap2);
}

void PicAnimationWid::UpSelectPixmap(QTreeWidgetItem *item)
{
    if(!item){
        return;
    }
    auto *tree_item = dynamic_cast<ProTreeItem*>(item);
    auto path = tree_item->GetPath();
    _pixmap1.load(path);
    _cur_item = tree_item;
    if(_map_item.find(path) == _map_item.end()){
        _map_item[path] = tree_item;
        qDebug() << "Set Pixmap Path is" << path;
    }

    auto *next_item = tree_item->GetNextItem();
    if(!next_item){
        return;
    }
    auto next_path = next_item->GetPath();
    _pixmap2.load(next_path);
    if(_map_item.find(next_path) == _map_item.end()){
        _map_item[next_path] = next_item;
    }
}

void PicAnimationWid::SlotUpSelectShow(QString path)
{
    auto iter = _map_item.find(path);
    if(iter == _map_item.end()){
        return;
    }
    UpSelectPixmap(iter.value());
    update();
}

void PicAnimationWid::SlotStartorStop()
{
    if(!_b_start){
        _factor = 0;
        _timer->start();
        _b_start = true;
        emit SigStartMusic();
    }
    else{
        _timer->stop();
        _factor = 0;
        update();
        _b_start = false;
        emit SigStopMusic();
    }
}

void PicAnimationWid::TimeOut()
{
    //判空，动画停止
    if(!_cur_item){
        Stop();
        update();
        return;
    }

    _factor = _factor + 0.01;
    if(_factor >= 1){
        _factor = 0;
        auto * cur_pro_item = dynamic_cast<ProTreeItem*>(_cur_item);
        auto * next_pro_item = cur_pro_item->GetNextItem();
        if(!next_pro_item){
            Stop();
            update();
            return;
        }
        SetPixmap(next_pro_item);
        update();
        return;
    }
    update();
}
