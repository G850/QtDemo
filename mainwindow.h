#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>

#include <QChart>
#include <QLineSeries>

#include <QTimer>

#include "chartview.h"
#include "callout.h"

QT_CHARTS_USE_NAMESPACE //QChart命名空间

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui {
class MainWindow;

}
QT_END_NAMESPACE

class Console;
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public://公共sgjdfj
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void writeData();
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void clearReadArea(void);
//--------------------------------------------------------
    void timerSlot();
    void buttonSlot();
    void tipSlot(QPointF position, bool isHovering);
//--------------------------------------------------------

private:
    void initActionsConnections();
    void settingsShow(void);
//--------------------------------------------------------
    void wheelEvent(QWheelEvent *event);

    void initUI();
    void initChart();
    void initSlot();

    void updateData();
//--------------------------------------------------------
private://私人的
    void showStatusMessage(const QString &message);

    Ui::MainWindow *ui;
    QLabel *status;
    Console *console;
    QSerialPort *serial;
    SettingsDialog *settings;
//--------------------------------------------------------
    ChartView *chartView;
    QChart *chart;
    Callout *tip;
    QLineSeries *series;
    QTimer *timer;
    quint16 count;
    bool isStopping;
//--------------------------------------------------------
//    void MainWindow::closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
