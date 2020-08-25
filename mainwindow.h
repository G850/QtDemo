#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public://公共sgjdfj
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionConfigure_toggled(bool checked);

private:
    void initActionsConnections();
    void show11(void);

private://私人的
    Ui::MainWindow *ui;

    SettingsDialog *settings;

//    void MainWindow::closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
