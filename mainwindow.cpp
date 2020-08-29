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

QLineSeries *series = new QLineSeries();

uint16_t test_11111 = 0;
uint16_t test_22221 = 0;

//QList<QSplineSeries *> Serieslist;
//QChart *m_chart = new QChart();
//QValueAxis *axisX = new QValueAxis;

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

    timer->setInterval(50);
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

//    if(data.contains("cs:"))
//    {
//        for (int i = 0; i < data.length(); i++) {

//            test_22221 = data.at(i);
//            test_11111 = j++;

//            QPointF p((qreal) test_11111, test_22221);
//            *series << p;
//        }
//        ChartShow();
//    }
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
    chart->setTitle("图表测试"); //设置图表抬头

    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    //渲染设置：抗锯齿
}

void MainWindow::ChartShow2(void)
{
//    QChart *Chart = new QChart();
//    QChartView *ChartView = new QChartView(Chart, this);//画布

//    Chart = ChartView->chart();//画笔
//    ChartView->setRubberBand(QChartView::NoRubberBand);

//    ChartView->setRenderHint(QPainter::Antialiasing);
//    ChartView->resize(600, 600);
//    ChartView->setContentsMargins(0,0,0,0);
//    ChartView->show();
//    //设置X坐标轴
//    QValueAxis *AxisX = new QValueAxis;
//    AxisX->setRange(0, 100);
//    AxisX->setLabelFormat("%d");
//    AxisX->setGridLineVisible(true);//网格显示
//    AxisX->setTickCount(10);   //主要刻度
//    AxisX->setTitleText("altitude/(%)");//轴的标题
//    //设置y坐标轴
//    QValueAxis *AxisY = new QValueAxis;
//    AxisY->setRange(0, 20);
//    AxisY->setLabelFormat("%d");
//    AxisY->setGridLineVisible(true);
//    AxisY->setTickCount(10);//轴上有多少个标记数目
//    AxisY->setMinorTickCount(5);//主要刻度之间有多少网格线
//    AxisY->setTitleText("altitude/(%)");

//    Chart->addAxis(AxisX, Qt::AlignBottom);
//    Chart->addAxis(AxisY, Qt::AlignLeft);

//    Chart->legend()->setVisible(true);//设置图例可见
//    Chart->legend()->setLayoutDirection(Qt::LeftToRight);//布局方向：左到右
//    Chart->legend()->setAlignment(Qt::AlignLeft);//图表对齐方式：左对齐

//    QList<QPointF> mydata1;
//    for(int i=0; i<100; i++)
//    {
//        mydata1.append(QPointF(i, 0.1*i));
//    }
//    addSeries(mydata1);

//    Chart->setAxisX(AxisX, Serieslist.first());
//    Chart->setAxisY(AxisY, Serieslist.first());
}

void MainWindow::addSeries(QList<QPointF> &data)
{
//    QSplineSeries *series = new QSplineSeries(this);//平滑曲线的集合
//    Serieslist.append(series);//将曲线加到曲线列表中进行管理
//    series->setName(QString("line " + QString::number(Serieslist.count()))); //设置曲线对应的名字，用于图例显示
//    series->append(data);  //将数据加到曲线中
//    m_chart->addSeries(series);//将曲线增入chart中
//    axisX->setRange(0, series->count());  //坐标轴初始范围为图表中的数据数。 这个在绘制多条曲线中需注释
//    QPen splinePen ,linePen;
//    splinePen.setBrush(Qt::red);
//    splinePen.setColor(Qt::red);
//    series->setPen(splinePen);

//    QSplineSeries *lineSeries = new QSplineSeries(this);//折线类点的集合
//    lineSeries->setName(QStringLiteral("折线"));
//    QList<QPointF> lineData;
//    QPoint newPoint;
//    foreach (QPointF point, data) {
//       newPoint.setX(point.x() * 1.5);
//       newPoint.setY(point.y() * 1.5);
//       lineData.append(newPoint);
//    }
//    //    lineSeries->append(0,0);
//    //    lineSeries->append(10,10);
//    //    lineSeries->append(15,15);
//    lineSeries->append(lineData);
//    linePen.setBrush(Qt::yellow);
//    lineSeries->setPen(linePen);
//    Serieslist.append(lineSeries);
//    m_chart->addSeries(lineSeries);

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


void MainWindow::wheelEvent(QWheelEvent *event)
{
//    if (event->delta() > 0) {
//        chart->zoom(1.1);
//    } else {
//        chart->zoom(10.0/11);
//    }

//    QWidget::wheelEvent(event);
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
    series = new QLineSeries;

    chart->addSeries(series);

//    series->setUseOpenGL(true);

    chart->createDefaultAxes();
    chart->axisY()->setRange(-10, 10);
    chart->axisX()->setRange(0, 96);

    chart->axisX()->setTitleFont(QFont("Microsoft YaHei", 10, QFont::Normal, true));
    chart->axisY()->setTitleFont(QFont("Microsoft YaHei", 10, QFont::Normal, true));
    chart->axisX()->setTitleText("Time/sec");
    chart->axisY()->setTitleText("Speed/m");

    chart->axisX()->setGridLineVisible(false);
    chart->axisY()->setGridLineVisible(false);

    /* hide legend */
    chart->legend()->hide();

    chartView = new ChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->mainHorLayout->addWidget(chartView);
}

void MainWindow::initSlot()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
//    connect(ui->stopBtn, SIGNAL(clicked(bool)), this, SLOT(buttonSlot()));
    connect(series, SIGNAL(hovered(QPointF, bool)), this, SLOT(tipSlot(QPointF,bool)));
}

void MainWindow::updateData()
{
    int i;
    QVector<QPointF> oldData = series->pointsVector();
    QVector<QPointF> data;

    if (oldData.size() < 97) {
        data = series->pointsVector();  //以向量的形式返回系列中的点。 这比调用points（）更有效。
    } else {
        /* 添加之前老的数据到新的vector中，不复制最前的数据，即每次替换前面的数据
         * 由于这里每次只添加1个数据，所以为1，使用时根据实际情况修改
         */
        for (i = 1; i < oldData.size(); ++i) {
            data.append(QPointF(i - 1 , oldData.at(i).y()));
        }
    }

    qint64 size = data.size();
    /* 这里表示插入新的数据，因为每次只插入1个，这里为i < 1,
     * 但为了后面方便插入多个数据，先这样写
     */
    for(i = 0; i < 1; ++i){
        data.append(QPointF(i + size, 10 * sin(M_PI * count * 4 / 180)));
    }

    series->replace(data);

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
//    if (QObject::sender() == ui->stopBtn) {
//        if (!isStopping) {
//            timer->stop();
//        } else {
//            timer->start();
//        }
//        isStopping = !isStopping;
//    }
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

