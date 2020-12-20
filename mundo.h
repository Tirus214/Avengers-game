#ifndef MUNDO_H
#define MUNDO_H
#include "listadoble.h"


struct Mundo{
    ListaDoble * listaPersonas;
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
    }

    void crearPersonas(int num);
    int aleatorio(int min, int max);
};

#endif // MUNDO_H
