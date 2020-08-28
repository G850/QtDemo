/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGroupBox *parametersBox;
    QFormLayout *formLayout;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsBox;
    QLabel *parityLabel;
    QComboBox *parityBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsBox;
    QLabel *flowControlLabel;
    QComboBox *flowControlBox;
    QGroupBox *selectBox;
    QFormLayout *formLayout_3;
    QComboBox *serialPortInfoListBox;
    QLabel *descriptionLabel;
    QLabel *manufacturerLabel;
    QLabel *serialNumberLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QGroupBox *groupBox_2;
    QCheckBox *localEchoCheckBox;
    QPushButton *applyButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(341, 289);
        parametersBox = new QGroupBox(SettingsDialog);
        parametersBox->setObjectName(QStringLiteral("parametersBox"));
        parametersBox->setGeometry(QRect(180, 10, 150, 171));
        formLayout = new QFormLayout(parametersBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, baudRateLabel);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, baudRateBox);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, dataBitsLabel);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dataBitsBox);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, parityLabel);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, parityBox);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, stopBitsLabel);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, stopBitsBox);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QStringLiteral("flowControlLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, flowControlLabel);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, flowControlBox);

        selectBox = new QGroupBox(SettingsDialog);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        selectBox->setGeometry(QRect(9, 9, 161, 171));
        formLayout_3 = new QFormLayout(selectBox);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, serialPortInfoListBox);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        formLayout_3->setWidget(1, QFormLayout::SpanningRole, descriptionLabel);

        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QStringLiteral("manufacturerLabel"));

        formLayout_3->setWidget(2, QFormLayout::SpanningRole, manufacturerLabel);

        serialNumberLabel = new QLabel(selectBox);
        serialNumberLabel->setObjectName(QStringLiteral("serialNumberLabel"));

        formLayout_3->setWidget(3, QFormLayout::SpanningRole, serialNumberLabel);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));

        formLayout_3->setWidget(4, QFormLayout::SpanningRole, locationLabel);

        vidLabel = new QLabel(selectBox);
        vidLabel->setObjectName(QStringLiteral("vidLabel"));

        formLayout_3->setWidget(5, QFormLayout::SpanningRole, vidLabel);

        pidLabel = new QLabel(selectBox);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));

        formLayout_3->setWidget(6, QFormLayout::SpanningRole, pidLabel);

        groupBox_2 = new QGroupBox(SettingsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 190, 321, 61));
        localEchoCheckBox = new QCheckBox(groupBox_2);
        localEchoCheckBox->setObjectName(QStringLiteral("localEchoCheckBox"));
        localEchoCheckBox->setGeometry(QRect(10, 30, 73, 18));
        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(250, 260, 80, 20));

        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Dialog", Q_NULLPTR));
        parametersBox->setTitle(QApplication::translate("SettingsDialog", "\351\200\211\346\213\251\345\217\202\346\225\260", Q_NULLPTR));
        baudRateLabel->setText(QApplication::translate("SettingsDialog", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        dataBitsLabel->setText(QApplication::translate("SettingsDialog", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        parityLabel->setText(QApplication::translate("SettingsDialog", "\345\245\207\345\201\266\344\275\215\357\274\232", Q_NULLPTR));
        stopBitsLabel->setText(QApplication::translate("SettingsDialog", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        flowControlLabel->setText(QApplication::translate("SettingsDialog", "\346\265\201\346\216\247\345\210\266\357\274\232", Q_NULLPTR));
        selectBox->setTitle(QApplication::translate("SettingsDialog", "\351\200\211\346\213\251\344\270\262\345\217\243", Q_NULLPTR));
        descriptionLabel->setText(QApplication::translate("SettingsDialog", "\346\217\217\350\277\260\357\274\232", Q_NULLPTR));
        manufacturerLabel->setText(QApplication::translate("SettingsDialog", "\345\210\266\351\200\240\345\225\206\357\274\232", Q_NULLPTR));
        serialNumberLabel->setText(QApplication::translate("SettingsDialog", "\345\272\217\345\210\227\345\217\267\357\274\232", Q_NULLPTR));
        locationLabel->setText(QApplication::translate("SettingsDialog", "\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        vidLabel->setText(QApplication::translate("SettingsDialog", "\344\276\233\345\272\224\345\225\206ID\357\274\232", Q_NULLPTR));
        pidLabel->setText(QApplication::translate("SettingsDialog", "\344\272\247\345\223\201ID\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SettingsDialog", "\351\231\204\345\212\240\351\200\211\351\241\271", Q_NULLPTR));
        localEchoCheckBox->setText(QApplication::translate("SettingsDialog", "\345\233\236\346\230\276", Q_NULLPTR));
        applyButton->setText(QApplication::translate("SettingsDialog", "\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
