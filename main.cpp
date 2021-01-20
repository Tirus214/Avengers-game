#include "mainwindow.h"
#include <QApplication>
#include <QDate>


int main(int argc, char *argv[])
{
    /*QStringList paises;
    paises.append("Corea");

    ListaDoble * l = new ListaDoble();
    l->insertarAlFinal(new Persona(1,"juan", "perez", "cristiano", "profesor", paises));
    l->insertarAlFinal(new Persona(3,"juan", "perez", "cristiano", "profesor", paises));
    l->insertarAlFinal(new Persona(14,"juan", "perez", "cristiano", "profesor", paises));
    l->insertarAlFinal(new Persona(16,"juan", "perez", "cristiano", "profesor", paises));
    l->insertarAlFinal(new Persona(100,"juan", "perez", "cristiano", "profesor", paises));
    l->insertarAlFinal(new Persona(122,"juan", "perez", "cristiano", "profesor", paises));
    l->imprimir();*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
