#ifndef NODOHEAP_H
#define NODOHEAP_H
#include "listadoble.h"


struct NodoHeap{
    NodoDoble * nodoDoble;
    NodoHeap * siguiente;
    NodoHeap * anterior;
    // indice para averiguar relacion padre/hijo
    int indice;
    NodoHeap(NodoDoble * _nodo){
        nodoDoble = _nodo;
        siguiente = anterior = NULL;
    }
    // metodos
    void imprimir();
    void setIndice(int);
};

#endif // NODOHEAP_H
