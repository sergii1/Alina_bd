#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget dsk;
    QSize size = dsk.availableGeometry().size();
    size.setHeight(size.height()-45);
    w.resize(size);
    w.show();
    return a.exec();
}
