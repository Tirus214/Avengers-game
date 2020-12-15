#include "mainwindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    Mundo* m = new Mundo();
    m->crearPersonas(5);
    m->lista->toString();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
