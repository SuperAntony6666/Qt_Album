#include "protree.h"
#include "ui_protree.h"

ProTree::ProTree(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProTree)
{
    ui->setupUi(this);
    //设置宽长度(378)
    this->setMaximumWidth(378);
    this->setMinimumWidth(378);
}

ProTree::~ProTree()
{
    delete ui;
}

void ProTree::AddProToTree(const QString name, const QString path)
{
    ui->ProTree_Widget->AddProToTree(name, path);
}
