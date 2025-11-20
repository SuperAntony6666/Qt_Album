#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include "picshow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ReloadPic();

protected:
    virtual void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    QWidget *_protree;
    QWidget *_picshow;

private slots:
    void SlotCreatePro(bool);
    void SlotOpenPro(bool);

signals:
    void SigOpenPro(QString path);
};
#endif // MAINWINDOW_H
