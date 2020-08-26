#include "console.h"
#include <QScrollBar>
#include <QtCore/QDebug>

Console::Console(QWidget *parent)
    : QPlainTextEdit(parent)
    , localEchoEnabled(false)
{
    document()->setMaximumBlockCount(100);
    QPalette p =palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    setPalette(p);
}

void Console::putData(const QByteArray &data)
{
    insertPlainText(QString(data));         //插入纯文本

    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Console::setLocalEchoEnabled(bool set)     //设置本地回显已启用
{
    localEchoEnabled = set;
}

//void Console::keyPressEvent(QKeyEvent *e)       //键按下事件
//{
//    switch (e->key()) {
//    case Qt::Key_Backspace:
//    case Qt::Key_Left:
//    case Qt::Key_Right:
//    case Qt::Key_Up:
//    case Qt::Key_Down:
//        break;
//    default:
//        if (localEchoEnabled)
//            QPlainTextEdit::keyPressEvent(e);
//        emit getData(e->text().toLocal8Bit());
//    }
//}

//void Console::mousePressEvent(QMouseEvent *e)       //鼠标按下事件
//{
//    Q_UNUSED(e)
//    setFocus();
//}

//void Console::mouseDoubleClickEvent(QMouseEvent *e)     //鼠标双击事件
//{
//    Q_UNUSED(e)
//}

//void Console::contextMenuEvent(QContextMenuEvent *e)    //上下文菜单事件
//{
//    Q_UNUSED(e)
//}

