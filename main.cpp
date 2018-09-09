#include "gamewindow.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GameWindow window;
    window.show();
    return app.exec();
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
}
