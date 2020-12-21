#include "mainwindow.h"
#include <QApplication>
#include "filemanager.h"


int main(int argc, char *argv[])
{
    Mundo * m = new Mundo();
    m->imprimir();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
