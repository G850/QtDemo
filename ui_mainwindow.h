/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *actionConfigure;
    QPushButton *actionConnect;
    QPushButton *actionDisconnect;
    QTextEdit *writeTextEdit;
    QLabel *statusBar;
    QPlainTextEdit *readPlainTextEdit;
    QPushButton *actionClear;
    QPushButton *actionSend;
    QtCharts::QChartView *graphicsView;
    QPushButton *chartPushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mainHorLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(683, 596);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        actionConfigure = new QPushButton(centralwidget);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        actionConfigure->setGeometry(QRect(100, 280, 80, 20));
        actionConnect = new QPushButton(centralwidget);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionConnect->setGeometry(QRect(10, 250, 80, 20));
        actionDisconnect = new QPushButton(centralwidget);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionDisconnect->setGeometry(QRect(10, 280, 80, 20));
        writeTextEdit = new QTextEdit(centralwidget);
        writeTextEdit->setObjectName(QStringLiteral("writeTextEdit"));
        writeTextEdit->setGeometry(QRect(10, 170, 331, 70));
        statusBar = new QLabel(centralwidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(10, 310, 331, 16));
        readPlainTextEdit = new QPlainTextEdit(centralwidget);
        readPlainTextEdit->setObjectName(QStringLiteral("readPlainTextEdit"));
        readPlainTextEdit->setGeometry(QRect(10, 10, 331, 151));
        readPlainTextEdit->setFrameShadow(QFrame::Plain);
        actionClear = new QPushButton(centralwidget);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionClear->setGeometry(QRect(100, 250, 80, 20));
        actionSend = new QPushButton(centralwidget);
        actionSend->setObjectName(QStringLiteral("actionSend"));
        actionSend->setGeometry(QRect(190, 250, 80, 20));
        graphicsView = new QtCharts::QChartView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(360, 10, 311, 231));
        chartPushButton = new QPushButton(centralwidget);
        chartPushButton->setObjectName(QStringLiteral("chartPushButton"));
        chartPushButton->setGeometry(QRect(190, 280, 80, 20));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(289, 250, 381, 301));
        mainHorLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainHorLayout->setObjectName(QStringLiteral("mainHorLayout"));
        mainHorLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 683, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionConfigure->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200", Q_NULLPTR));
        writeTextEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\221\351\200\201\346\265\213\350\257\225\357\274\201\357\274\201\357\274\201</p></body></html>", Q_NULLPTR));
        statusBar->setText(QApplication::translate("MainWindow", "\350\275\254\346\200\201\346\240\217", Q_NULLPTR));
        readPlainTextEdit->setPlainText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\265\213\350\257\225\357\274\201\357\274\201\357\274\201", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", Q_NULLPTR));
        actionSend->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        chartPushButton->setText(QApplication::translate("MainWindow", "\345\233\276\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
