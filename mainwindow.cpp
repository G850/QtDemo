#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QMessageBox>
#include <QtWidgets/QLabel>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <QtCore/QtMath>

QT_CHARTS_USE_NAMESPACE //QChart命名空间

QLineSeries *series = new QLineSeries();

uint16_t test_11111 = 0;
uint16_t test_22221 = 0;


MainWindow::MainWindow(QWidget *parent) //构造函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//设置UI

    serial = new QSerialPort(this); //创建串口
    
    settings = new SettingsDialog;

//    QLineSeries *series = new QLineSeries();

//    series->append(0, 6);
//    series->append(2, 4);
//    series->append(3, 8);
//    series->append(7, 4);
//    series->append(10, 5);
//    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

//    QLineSeries *series = new QLineSeries();
//    for (int i = 0; i < 500; i++) {
//        QPointF p((qreal) i, qSin(M_PI / 50 * i) * 100);
//        p.ry() ++;//= qrand() % 20;
//        *series << p;
//    }

//    QChart *chart = new QChart();
//    chart->legend()->hide();    //图例影藏
//    chart->addSeries(series);   //添加坐标系
//    chart->createDefaultAxes(); //创建坐标轴
//    chart->setTitle("图表测试"); //设置图表抬头

//    ui->graphicsView->setChart(chart);
//    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    //渲染设置：抗锯齿


    ui->actionConnect->setEnabled(true);       //连接
    ui->actionDisconnect->setEnabled(false);   //断开
    ui->actionConfigure->setEnabled(true);     //配置

    initActionsConnections();       //初始化连接动作

    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);

    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);      //读数据

    connect(ui->actionSend, &QPushButton::clicked, this, &MainWindow::writeData);          //写数据


}

MainWindow::~MainWindow()   //析构函数
{
    delete ui;
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

//    connect(ui->chartPushButton,  &QPushButton::clicked, this, &MainWindow::ChartShow);
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
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("连接到 %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    }else
    {
        QMessageBox::critical(this, tr("错误"), serial->errorString());
        showStatusMessage(tr("打开错误"));
    }
}

void MainWindow::closeSerialPort()  //关闭串口
{
    if (serial->isOpen())
        serial->close();
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("断开连接"));
}

void MainWindow::showStatusMessage(const QString &message)      //显示状态消息
{
    ui->statusBar->setText(message);
}

void MainWindow::writeData()
{
    QString data = ui->writeTextEdit->toPlainText();
    QByteArray bytes = data.toLocal8Bit();

    ui->readPlainTextEdit->insertPlainText(data);         //插入纯文本
    ui->readPlainTextEdit->centerCursor();   //滚动文档以使光标垂直居中。

    serial->write(bytes);
}

void MainWindow::readData()
{
    static int j;
    QByteArray data = serial->readAll();    //折线类 QSplineSeries，曲线类，画出来更平滑，QScatterSeries，点类，画出来是一个个单独的点。
    ui->readPlainTextEdit->insertPlainText(data);    //方便插槽，用于在当前光标位置插入文本。
    ui->readPlainTextEdit->centerCursor();   //滚动文档以使光标垂直居中。

    for (int i = 0; i < data.length(); i++) {

        test_22221 = data.at(i);
        test_11111 = j++;

        QPointF p((qreal) test_11111, test_22221);
        *series << p;
    }
    ChartShow();
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

void MainWindow::ChartShow(void)
{
    QChart *chart = new QChart();
    chart->legend()->hide();    //图例影藏
    chart->addSeries(series);   //添加坐标系
    chart->createDefaultAxes(); //创建坐标轴
//    chart->axisX()
    chart->setTitle("图表测试"); //设置图表抬头

    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    //渲染设置：抗锯齿
}


//void Widget::timerEvent(QTimerEvent *event)    //定时器事件的重构
//{
//    if (event->timerId() == timeId)//定时器时间到，模拟数据填充
//    {
//        static QTime dataTime(QTime::currentTime());
//        long int eltime = dataTime.elapsed();  //上次start经过毫秒数
//        static int lastpointtime = 1;
//        int size = (eltime - lastpointtime);//数据个数
//        qDebug() << "size-->" << size;
//        foreach (QSplineSeries  *splineSeries, m_serieslist) {
//            if (splineSeries->isVisible())
//            {
//                QVector<QPointF> olddata = splineSeries->pointsVector();
//                olddata.append(QPointF(lastpointtime +olddata.count(), lastpointtime*0.3));//填充数据--->>相当于每一分钟增加一点
//                axisX->setRange(0, lastpointtime + splineSeries->count());//设置x坐标轴
//                //后期需更改为一开始固定，只有当数据个数超出坐标轴范围时坐标轴开始扩展。
//                splineSeries->replace(olddata);
//                lastpointtime++;
//            }
//        }

//    }
//}
