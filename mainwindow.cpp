#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) //构造函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//设置UI

    console = new Console; //控制台参数
    console->setEnabled(false);
//    setCentralWidget(console);

    serial = new QSerialPort(this); //创建串口
    
    settings = new SettingsDialog;

    ui->actionConnect->setEnabled(true);       //连接
    ui->actionDisconnect->setEnabled(false);   //断开
    ui->actionConfigure->setEnabled(true);     //配置

//    status = new QLabel;
//    ui->statusBar->addWidget(status);

    initActionsConnections();       //初始化连接动作

    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);

    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);      //读数据

//    connect(ui->textEdit_2, &Console::getData, this, &MainWindow::writeData);          //写数据
}

MainWindow::~MainWindow()   //xi构函数
{
    delete ui;//删除UI
    delete settings;
}

void MainWindow::initActionsConnections()       //初始化动作连接
{
    connect(ui->actionConnect,    &QPushButton::clicked, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QPushButton::clicked, this, &MainWindow::closeSerialPort);
//    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
//    connect(ui->actionConfigure, &QAction::triggered, settings, &SettingsDialog::show);
    connect(ui->actionConfigure,  &QPushButton::clicked, this, &MainWindow::settingsShow);
    connect(ui->actionClear,      &QPushButton::clicked, this, &MainWindow::clearReadArea);
//    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
//    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::settingsShow(void)
{
    settings->show();
}

void MainWindow::openSerialPort()       //打开串口
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if(serial->open(QIODevice::ReadWrite))
    {
//        console->setEnabled(true);
//        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("连接到 %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    }else
    {
//        QMessageBox::critical(this, tr("错误"), serial->errorString());
        showStatusMessage(tr("打开错误"));
    }
}

void MainWindow::closeSerialPort()  //关闭串口
{
    if (serial->isOpen())
        serial->close();
//    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("断开连接"));
}

void MainWindow::showStatusMessage(const QString &message)      //显示状态消息
{
    ui->statusBar->setText(message);
}

void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    ui->readPlainTextEdit->insertPlainText(data);    //方便插槽，用于在当前光标位置插入文本。
    ui->readPlainTextEdit->centerCursor();   //滚动文档以使光标垂直居中。
//    console->putData(data);
}

void MainWindow::handleError(QSerialPort::SerialPortError error)    //处理错误
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("严重 错误"), serial->errorString());
        closeSerialPort();      //关闭串口
    }
}

void MainWindow::clearReadArea(void)
{
    ui->readPlainTextEdit->clear();

}
