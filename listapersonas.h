#ifndef ListaPersonas_H
#define ListaPersonas_H
#include "nododoble.h"


struct ListaPersonas{
    NodoDoble * primerNodo;

    ListaPersonas(){
        primerNodo = NULL;
    }

    void insertarAlFinal(Persona * persona);
    bool isEmpty();
    void toString();
};

#endif // ListaPersonas_H
