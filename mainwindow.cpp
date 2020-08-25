#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settingsdialog.h"

MainWindow::MainWindow(QWidget *parent) //构造函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//设置UI

    settings = new SettingsDialog;

//    settings->show();

    connect(ui->actionConfigure, SIGNAL(clicked()), this, SLOT(show11()));
//    connect(ui->actionConfigure, SIGNAL(clicked()), this, &SettingsDialog::show);

}

MainWindow::~MainWindow()   //xi构函数
{
    delete ui;//删除UI
    delete settings;
}

void MainWindow::initActionsConnections()       //初始化动作连接
{
//    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
//    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
//    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
//    connect(ui->actionConfigure, &QAction::triggered, settings, &SettingsDialog::show);
//    connect(ui->actionClear, &QAction::triggered, console, &Console::clear);
//    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
//    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::show11(void)
{
    settings->show();
}

//void MainWindow::on_actionConfigure_toggled(bool checked)
//{
////    settings->show();
//}
