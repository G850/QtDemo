#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>

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
    void ChartShow(void);

private:
    void initActionsConnections();
    void settingsShow(void);

private://私人的
    void showStatusMessage(const QString &message);

    Ui::MainWindow *ui;
    QLabel *status;
    Console *console;
    QSerialPort *serial;
    SettingsDialog *settings;

//    void MainWindow::closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
