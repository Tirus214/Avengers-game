#ifndef HEAP_H
#define HEAP_H
#include "nodoheap.h"


struct Heap{
    NodoHeap* primerNodo;
    NodoHeap* ultimoNodo;

    Heap(){
        primerNodo = ultimoNodo = NULL;
    }

    bool isEmpty();
    void insertarAlInicio (NodoDoble*);
    void insertarAlFinal (NodoDoble*);
};

#endif // HEAP_H
