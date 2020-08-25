#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
//    Q_INIT_RESOURCE(Demo);//初始化资源

    QApplication app(argc, argv);//必须要有的
//    QCoreApplication::setApplicationName("QtProject");
//    QCoreApplication::setApplicationName("Application Example");
//    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
//    QCommandLineParser parser;//创建命令函结构体
//    parser.setApplicationDescription(QCoreApplication::applicationName());//设置应用说明
//    parser.addHelpOption();//添加帮助选项
//    parser.addVersionOption();//添加版本选项
//    parser.addPositionalArgument("file", "The file to open.");//添加位置参数
//    parser.process(a);//处理应用a

//    MainWindow w;
//    w.show();//git UI 测试akjfhkah

//    return a.exec();//执行

    MainWindow mainWin;
    mainWin.show();
    return app.exec();

}
