#ifndef ListaPersonas_H
#define ListaPersonas_H
#include "nododoble.h"


struct ListaDoble{
    NodoDoble * primerNodo;
    int index;

    ListaDoble(){
        primerNodo = NULL;
        index = 0;
    }

    void insertarAlFinal(Persona * persona);
    bool isEmpty();
    void imprimir();
    bool esta(int index);
    int largo();
};

#endif // ListaPersonas_H
