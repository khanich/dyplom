#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //db
    MainWindow w;//sharedptr

    w.show();
    return a.exec();
}
