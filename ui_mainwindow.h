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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(683, 380);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        actionConfigure = new QPushButton(centralwidget);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        actionConfigure->setGeometry(QRect(100, 310, 80, 20));
        actionConnect = new QPushButton(centralwidget);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionConnect->setGeometry(QRect(10, 280, 80, 20));
        actionDisconnect = new QPushButton(centralwidget);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionDisconnect->setGeometry(QRect(10, 310, 80, 20));
        writeTextEdit = new QTextEdit(centralwidget);
        writeTextEdit->setObjectName(QStringLiteral("writeTextEdit"));
        writeTextEdit->setGeometry(QRect(10, 170, 331, 70));
        statusBar = new QLabel(centralwidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(10, 250, 331, 16));
        readPlainTextEdit = new QPlainTextEdit(centralwidget);
        readPlainTextEdit->setObjectName(QStringLiteral("readPlainTextEdit"));
        readPlainTextEdit->setGeometry(QRect(10, 10, 331, 151));
        readPlainTextEdit->setFrameShadow(QFrame::Plain);
        actionClear = new QPushButton(centralwidget);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionClear->setGeometry(QRect(100, 280, 80, 20));
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
        actionConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200", Q_NULLPTR));
        writeTextEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\221\351\200\201\346\265\213\350\257\225\357\274\201\357\274\201\357\274\201</p></body></html>", Q_NULLPTR));
        statusBar->setText(QApplication::translate("MainWindow", "\350\275\254\346\200\201\346\240\217", Q_NULLPTR));
        readPlainTextEdit->setPlainText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\265\213\350\257\225\357\274\201\357\274\201\357\274\201", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
