#ifndef SLIDESHOWDIALOG_H
#define SLIDESHOWDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "prelistwid.h"

namespace Ui {
class SlideShowDialog;
}

class SlideShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SlideShowDialog(QWidget *parent = nullptr, QTreeWidgetItem* first_item = nullptr, QTreeWidgetItem* last_item = nullptr);
    ~SlideShowDialog();

private:
    Ui::SlideShowDialog *ui;
    QTreeWidgetItem *_first_item;
    QTreeWidgetItem *_last_item;
};

#endif // SLIDESHOWDIALOG_H
