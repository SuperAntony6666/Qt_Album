#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //打开qss并加载
    MainWindow w;
    QFile file(":/style/style.qss");
    if(file.open(QFile::ReadOnly)){
        QString styleSheet = QLatin1String(file.readAll());
        a.setStyleSheet(styleSheet);
        qDebug() << "qss open success" << Qt::endl;
    }
    else{
        qDebug() << "qss open error" << Qt::endl;
    }
    w.setWindowTitle("Album");
    w.showMaximized();
    return a.exec();
}
