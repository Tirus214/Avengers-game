#include "mainwindow.h"
#include <QApplication>
#include "filemanager.h"


int main(int argc, char *argv[])
{
    FileManager * f = new FileManager();
    qDebug() << f->leer("Paises");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
