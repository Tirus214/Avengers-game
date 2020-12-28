#ifndef NODOHEAP_H
#define NODOHEAP_H
#include "listadoble.h"


struct NodoHeap{
    NodoDoble * nodoDoble;
    NodoHeap * siguiente;
    NodoHeap * anterior;

    NodoHeap(NodoDoble * _nodo){
        nodoDoble = _nodo;
        siguiente = anterior = NULL;
    }


};

#endif // NODOHEAP_H
