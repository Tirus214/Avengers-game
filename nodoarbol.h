#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "listadoble.h"


struct NodoArbol{
    NodoDoble * nodoPersona;
    NodoArbol * hijoIzquierdo;
    NodoArbol * hijoDerecho;
    int feromonas;

    NodoArbol(NodoDoble * _nodo){
        nodoPersona = _nodo;
        hijoIzquierdo = hijoDerecho = NULL;
        feromonas = 0;
    }
};

#endif // NODOARBOL_H
