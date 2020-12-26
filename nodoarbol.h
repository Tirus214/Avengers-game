#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "listadoble.h"


struct NodoArbol{
    NodoDoble * nodoPersona;
    NodoArbol * hijoIzquierdo;
    NodoArbol * hijoDerecho;

    NodoArbol(NodoDoble * _nodo){
        nodoPersona = _nodo;
        hijoIzquierdo = hijoDerecho = NULL;
    }
};

#endif // NODOARBOL_H
