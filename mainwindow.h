#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public://公共sgjdfj
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private://私人的
    Ui::MainWindow *ui;

//    void MainWindow::closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
