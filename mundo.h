#ifndef MUNDO_H
#define MUNDO_H
#include "listadoble.h"
#include "filemanager.h"


struct Mundo{
    ListaDoble * listaPersonas;
    FileManager * fileManager;
    QString listaNombresHombre[500];
    QString listaNombresMujer[500];
    QString listaApellidos[20];
    QString listaCreencias[10];
    QString listaProfesiones[50];
    QString listaPaises[100];

    int index;

    Mundo(){
        listaPersonas = new ListaDoble();
        index = 0;
        fileManager = new FileManager();
        obtenerArray("Apellidos", listaApellidos);
    }

    void crearPersonas(int num);
    int aleatorio(int min, int max);
    void obtenerArray(QString nombre, QString array[]);
    void makeStaticArray(QStringList arrayList, QString *arreglo);
    void imprimir();
};

#endif // MUNDO_H
