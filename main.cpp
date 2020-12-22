#include "mainwindow.h"
#include <QApplication>
#include "filemanager.h"


int main(int argc, char *argv[])
{
    QString ape[20];
    FileManager * f = new FileManager();
    f->leer("Apellidos", ape);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
