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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *textlabel;
    QPushButton *actionConfigure;
    QPushButton *actionConnect;
    QPushButton *actionDisconnect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(269, 238);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textlabel = new QLabel(centralwidget);
        textlabel->setObjectName(QStringLiteral("textlabel"));
        textlabel->setGeometry(QRect(30, 30, 231, 31));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        textlabel->setFont(font);
        actionConfigure = new QPushButton(centralwidget);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        actionConfigure->setGeometry(QRect(180, 160, 80, 20));
        actionConnect = new QPushButton(centralwidget);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionConnect->setGeometry(QRect(0, 140, 80, 20));
        actionDisconnect = new QPushButton(centralwidget);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionDisconnect->setGeometry(QRect(0, 170, 80, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 269, 22));
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
        textlabel->setText(QApplication::translate("MainWindow", "Hello\357\274\214Wd!kfkkkfk", Q_NULLPTR));
        actionConfigure->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
