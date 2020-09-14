#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QMessageBox>
#include <QtWidgets/QLabel>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <QtCore/QtMath>
#include <QSplineSeries>
#include <QValueAxis>

#include <QtSerialPort/QSerialPortInfo>


QLineSeries *series = new QLineSeries();

uint16_t test_11111 = 0;
uint16_t test_22221 = 0;

double axisYmin = 0;
double axisYmax = 5;
double axisXmin = 0;
double axisXmax = 97;
int chartViewLength = 97;

double ceshidjfgh = 0;

MainWindow::MainWindow(QWidget *parent) : //构造函数
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    chart(new QChart),
    tip(0),
    timer(new QTimer),
    count(0),
    isStopping(false)
{
    ui->setupUi(this);//设置UI

    serial = new QSerialPort(this); //创建串口
    
    settings = new SettingsDialog;

//------------------------------------------------------------------------------

    initUI();

    timer->setInterval(50); //50ms定时器
    timer->start();

    initSlot();

//------------------------------------------------------------------------------
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
int test1=0;
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
    QString data;// = ui->writeTextEdit->toPlainText();
    QByteArray bytes;// = data.toLocal8Bit();
    QSerialPort::Parity parity1 = static_cast<QSerialPort::Parity>(5);

    ui->readPlainTextEdit->insertPlainText(data);         //插入纯文本
    ui->readPlainTextEdit->centerCursor();   //滚动文档以使光标垂直居中。

    data[0] = 0x00;
    data[1] = 0x01;
    data[2] = 0x02;
    data[3] = 0x03;
    data[4] = 0x04;
    data[5] = 0x05;
    data[6] = 0x06;
    parity1 = static_cast<QSerialPort::Parity>(5);
    serial->setParity(parity1);   //第9位0，MarkParity
    bytes = data.toLocal8Bit();
    serial->setBreakEnabled(true);
    serial->setBreakEnabled(false);
    serial->write(bytes);
}

void MainWindow::readData()
{
    int tmp11 = 0;
    QByteArray tmp;
    QByteArray data = serial->readAll();    //折线类 QSplineSeries，曲线类，画出来更平滑，QScatterSeries，点类，画出来是一个个单独的点。
    ui->readPlainTextEdit->insertPlainText(data);    //方便插槽，用于在当前光标位置插入文本。
    ui->readPlainTextEdit->centerCursor();   //滚动文档以使光标垂直居中。

//    if(data.contains("cs:"))

//    ui->paramLineEdit->text().append(':');
//    ui->paramLineEdit->text().length();

//    data.indexOf();
//    if()

        if(data.left(ui->paramLineEdit->text().size()) == ui->paramLineEdit->text())
        {
            tmp11 = data.indexOf("\r\n");
            for(int i = 0; i < tmp11; i++)
            {
                if(data[i]>='0' && data[i]<='9')
                {
                    tmp.append(data[i]);
                }
            }
            ceshidjfgh = tmp.toDouble();
        }

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

void MainWindow::wheelEvent(QWheelEvent *event) //鼠标滚轮
{
    if (event->delta() > 0) {   //大于0是向前
        if(ui->XcheckBox->isChecked() == true)
        {
            chartViewLength = chartViewLength - 10;
            if(chartViewLength <= 0)chartViewLength=1;
        }

        if((ui->YcheckBox->isChecked() == true)||(ui->autoCheckBox->isChecked() == false))
        {
            chart->zoom(1.1);   //大于1.0放大视图
        }
    } else
    {
        if(ui->XcheckBox->isChecked() == 1)
        {
            chartViewLength = chartViewLength + 10;
        }

        if((ui->YcheckBox->isChecked() == 1)||(ui->autoCheckBox->isChecked() == 0))
        {
            chart->zoom(10.0/11);   //而0.0到1.0的系数会缩小视图。
        }
    }

    QWidget::wheelEvent(event);
}

void MainWindow::initUI()
{
//    ui->comboBox->addItem("TCP");
//    ui->comboBox->addItem("UDP");

//    auto ports = QSerialPortInfo::availablePorts();
//    for (auto port : ports) {
//        ui->comboBox->addItem(port.portName());
//    }

    initChart();
}

void MainWindow::initChart()
{
    series = new QLineSeries;   //创建一条线

    chart->addSeries(series);   //将线载入图表

//    series->setUseOpenGL(true);

    chart->createDefaultAxes(); //创建轴
    chart->axisY()->setRange(0, 5);    //Y轴最大最小值
    chart->axisX()->setRange(0, 96);    //X轴最大最小值

    chart->axisX()->setTitleFont(QFont("Microsoft YaHei", 10, QFont::Normal, true));    //标签
    chart->axisY()->setTitleFont(QFont("Microsoft YaHei", 10, QFont::Normal, true));
//    chart->axisX()->setTitleText("Time/sec");
//    chart->axisY()->setTitleText("Speed/m");

    chart->axisX()->setGridLineVisible(true);  //网格
    chart->axisY()->setGridLineVisible(true);

    /* hide legend */
    chart->legend()->hide();    //隐藏图表

    chartView = new ChartView(chart);   //创建窗体
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->mainHorLayout->addWidget(chartView);    //在mainHorLayout处填入窗体
}

void MainWindow::initSlot()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot())); //定时器连接
    connect(ui->stopBtn, SIGNAL(clicked(bool)), this, SLOT(buttonSlot()));
    connect(series, SIGNAL(hovered(QPointF, bool)), this, SLOT(tipSlot(QPointF,bool)));
}

void MainWindow::updateData()
{
    int i;
    static bool floag1 = 0;
    static bool floagY = 0;
    QVector<QPointF> oldData = series->pointsVector();
    QVector<QPointF> data;
    double appendData = 0;

    if (oldData.size() > chartViewLength)floag1 = true;

    data = series->pointsVector();

    qint64 size = data.size();  //数据长度
    /* 这里表示插入新的数据，因为每次只插入1个，这里为i < 1,
     * 但为了后面方便插入多个数据，先这样写
     */
    for(i = 0; i < 1; ++i){
        appendData = ceshidjfgh;//10 * sin(M_PI * count * 4 / 180);
        if(appendData > axisYmax)
        {
            axisYmax = appendData;
            floagY = true;
        }
        if(appendData < axisYmin)
        {
            axisYmin = appendData;
            floagY = true;
        }
        data.append(QPointF(i + size, appendData));   //添加新数据
    }

    if(ui->autoCheckBox->isChecked() == true)
    {
        if(floag1 == 1)
        {
            axisXmin = count - chartViewLength;

            if(axisXmin<0)
            {
                axisXmin = 0;
                chartViewLength = count;
            }

            if(axisXmax < count)
            {
                axisXmax = count;
            }
        }
        chart->axisX()->setRange(axisXmin, axisXmax);   //设置x坐标轴
        if(floagY == true)
        {
            chart->axisY()->setRange(axisYmin, axisYmax);   //自动调整Y轴
            floagY = false;
        }
    }

    series->replace(data);  //刷新数据

    count++;
}

void MainWindow::timerSlot()
{
    if (QObject::sender() == timer) {
        updateData();
    }
}

void MainWindow::buttonSlot()
{
    if (QObject::sender() == ui->stopBtn) {
        if (!isStopping) {
            timer->stop();
        } else {
            timer->start();
        }
        isStopping = !isStopping;
    }
}

void MainWindow::tipSlot(QPointF position, bool isHovering)
{
    if (tip == 0)
        tip = new Callout(chart);

    if (isHovering) {
        tip->setText(QString("X: %1 \nY: %2 ").arg(position.x()).arg(position.y()));
        tip->setAnchor(position);
        tip->setZValue(11);
        tip->updateGeometry();
        tip->show();
    } else {
        tip->hide();
    }
}

