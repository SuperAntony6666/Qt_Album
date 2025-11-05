#include "wizard.h"
#include "ui_wizard.h"

Wizard::Wizard(QWidget *parent)
    : QWizard(parent)
    , ui(new Ui::Wizard)
{
    ui->setupUi(this);
}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::done(int result)
{
    //如果QDialog拒绝，返回
    if(result == QDialog::Rejected){
        return;
    }
    //否则接受name path
    QString name, path;
    ui->wizardPage1->GetProsettings(name, path);
    //发送信号连接主窗口左边显示
    emit SigProSetting(name, path);
    QWizard::done(result);
}
