#include "mainwindow.h"
#include "functions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    functions w;
    w.show();
    return a.exec();
}
