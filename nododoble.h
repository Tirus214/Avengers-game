#ifndef NODODOBLE_H
#define NODODOBLE_H
#include "persona.h"

struct NodoDoble{
    Persona * persona;
    NodoDoble * siguiente;
    NodoDoble * anterior;

    NodoDoble(Persona * _persona){
        persona = _persona;
        siguiente = anterior = NULL;
    }
};

#endif // NODODOBLE_H
