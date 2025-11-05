#include "prosetpage.h"
#include "ui_prosetpage.h"
#include <QLineEdit>
#include <QDir>
#include <QFileDialog>

ProSetPage::ProSetPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::ProSetPage)
{
    ui->setupUi(this);
    //保证两个lineEdit是空的时候无法点击下一步
    registerField("proPath", ui->Path_Edit);
    registerField("proName*", ui->Name_Edit);

    //连接信号和槽
    connect(ui->Path_Edit, &QLineEdit::textChanged, this, &ProSetPage::completeChanged);
    connect(ui->Name_Edit, &QLineEdit::textChanged, this, &ProSetPage::completeChanged);

    //读取当前位置即路径，设置光标位置
    QString cur_path = QDir::currentPath();
    ui->Path_Edit->setText(cur_path);
    ui->Path_Edit->setCursorPosition(ui->Path_Edit->text().size());
    ui->Name_Edit->setClearButtonEnabled(true);
    ui->Path_Edit->setClearButtonEnabled(true);
}

ProSetPage::~ProSetPage()
{
    delete ui;
}

void ProSetPage::GetProsettings(QString &name, QString &path)
{
    name = ui->Name_Edit->text();
    path = ui->Path_Edit->text();
}


bool ProSetPage::isComplete() const
{
    if(ui->Path_Edit->text() == "" || ui->Name_Edit->text() == ""){
        return false;
    }

    //判断是否文件夹是否合理
    QDir dir(ui->Path_Edit->text());
    if(!dir.exists())
    {
        // qDebug()<<"file path is not exists" << Qt::endl;
        ui->tips->setText("project path is not exists");
        return false;
    }

    //判断路径是否存在
    QString absFilePath = dir.absoluteFilePath(ui->Name_Edit->text());
       // qDebug() << "absFilePath is " << absFilePath;

    QDir dist_dir(absFilePath);
    if(dist_dir.exists()){
        ui->tips->setText("project has exists, change path or name!");
        return false;
    }

    ui->tips->setText("");
    return QWizardPage::isComplete();
}

//添加浏览按钮点击后选择文件夹的操作
void ProSetPage::on_browse_Btn_clicked()
{
    //打开文件对话框
    QFileDialog file_dialog;
    //设置打开模式
    file_dialog.setFileMode(QFileDialog::Directory);
    file_dialog.setWindowTitle(tr("选择导入的文件"));
    //打开目录，默认打开目录是当前项目目录
    auto path = QDir::currentPath();
    file_dialog.setDirectory(path);
    //展示模式设置
    file_dialog.setViewMode(QFileDialog::Detail);
    //缓存文件名列表
    QStringList file_name;
    if(file_dialog.exec()){
        file_name = file_dialog.selectedFiles();
    }
    //健壮性
    if(file_name.length() <= 0){
        return;
    }
    //获取打开的文件夹
    QString import_path = file_name.at(0);
    qDebug() << "import path is " << import_path;
    ui->Path_Edit->setText(import_path);

}

