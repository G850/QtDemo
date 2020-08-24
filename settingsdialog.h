#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT    //只有加入了Q_OBJECT，你才能使用QT中的signal和slot机制。

public:

//    explicit SettingsDialog(QWidget *parent = nullptr); //显性
//    ~SettingsDialog();

private:

//    Ui::SettingsDialog *ui;

};




#endif // SETTINGSDIALOG_H
