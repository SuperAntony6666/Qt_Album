#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QObject>
#include <QDebug>
#include <QFileDialog>
#include "protreewidget.h"
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

    //连接信号和槽(创建项目和打开项目)
    connect(create_pro, QAction::triggered, this, &MainWindow::SlotCreatePro);
    connect(open_pro, QAction::triggered, this, &MainWindow::SlotOpenPro);

    //连接Protree
    _protree = new ProTree();
    ui->pro_Layout->addWidget(_protree);

    //获取treewidget
    QTreeWidget *tree_widget = dynamic_cast<ProTree*>(_protree)->GetTreeWidget();
    auto *pro_tree_widget = dynamic_cast<ProTreeWidget*>(tree_widget);
    connect(this, &MainWindow::SigOpenPro, pro_tree_widget, &ProTreeWidget::SlotOpenPro);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotCreatePro(bool)
{

    Wizard wizard(this);
    wizard.setWindowTitle(tr("创建项目"));
    auto *page = wizard.page(0);
    page->setTitle(tr("设置项目配置"));

    //连接信号和槽，把项目配置传回来
    connect(&wizard, &Wizard::SigProSetting, dynamic_cast<ProTree*> (_protree), &ProTree::AddProToTree);
    // QObject::connect(wizard, &Wizard::SigProSetting, dynamic_cast<ProTree*>(_protree), &ProTree::AddProToTree);
    wizard.show();
    wizard.exec();
    //断开所有信息
    disconnect();
}

void MainWindow::SlotOpenPro(bool)
{
    //创建及设置文件对话框（目录模式）
    QFileDialog file_dialog;
    file_dialog.setFileMode(QFileDialog::Directory);
    file_dialog.setWindowTitle(tr("选择打开文件"));
    file_dialog.setDirectory(QDir::currentPath());
    file_dialog.setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if(file_dialog.exec()){
        fileNames = file_dialog.selectedFiles();
    }
    if(fileNames.length() <= 0){
        return;
    }
    QString import_path = fileNames.at(0);
    emit SigOpenPro(import_path);
}


