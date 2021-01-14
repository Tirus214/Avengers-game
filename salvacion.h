#ifndef SALVACION_H
#define SALVACION_H
#include "heap.h"
#include "mundo.h"
#include "arbol.h"

struct Antman{
    int cantidadHormigas;
    Arbol * arbolEntrada;
    Mundo * mundo;
    int contador = 0;

    //métodos
    void dejarFeromonas();
    NodoArbol * escogerNodo();
    void salvarPersonas(NodoArbol *);
    void clearFeromonas(NodoArbol *);
};

#endif // SALVACION_H
