#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QDebug>
#include "wizard.h"
#include "protree.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建菜单
    QMenu *menu_file = menuBar()->addMenu("文件(&F)");
    //创建项目动作 + 快捷键
    QAction *create_pro = new QAction(QIcon(":/icon/createpro.png"), tr("创建项目"), this);
    create_pro->setShortcut(QKeySequence("Ctrl+N"));
    menu_file->addAction(create_pro);

    //打开项目动作 + 快捷键
    QAction *open_pro = new QAction(QIcon(":/icon/openpro.png"), tr("打开项目"), this);
    open_pro->setShortcut(QKeySequence("Ctrl+O"));
    menu_file->addAction(open_pro);

    //创建设置菜单
    QMenu *menu_setting = menuBar()->addMenu("设置(&S)");

    //设置背景音乐 + 快捷键
    QAction *set_music = new QAction(QIcon(":/icon/music.png"), tr("设置音乐"), this);
    set_music->setShortcut(QKeySequence("Ctrl+M"));
    menu_setting->addAction(set_music);

    //连接信号和槽
    connect(create_pro, QAction::triggered, this, &MainWindow::SlotCreatePro);
    connect(open_pro, QAction::triggered, this, &MainWindow::SlotOpenPro);

    //连接Protree
    _protree = new ProTree();
    ui->pro_Layout->addWidget(_protree);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotCreatePro(bool)
{
    qDebug() << "create slot is triggered" << Qt::endl;
    //
    Wizard wizard(this);
    wizard.setWindowTitle(tr("创建项目"));
    auto *page = wizard.page(0);
    page->setTitle(tr("设置项目配置"));

    //连接信号和槽，把项目配置传回来

    wizard.show();
    wizard.exec();
    //断开所有信息
}

void MainWindow::SlotOpenPro(bool)
{
    qDebug() << "Open slot is triggered" << Qt::endl;
}
