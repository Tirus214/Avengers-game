#ifndef HEAP_H
#define HEAP_H
#include "nodoheap.h"


struct Heap{
    // contador , para averiguar nivel y cantidad de nodos (sacar indice, etc)
    int contador = 0;

    NodoHeap* primerNodo;
    NodoHeap* ultimoNodo;

    Heap(){
        primerNodo = ultimoNodo = NULL;
    }

    bool isEmpty();
    void insertarAlInicio (NodoDoble*);
    void insertarAlFinal (NodoDoble*);
    // nuevos
    void insertar(NodoDoble*);
    bool paridad(int);
    NodoHeap* buscarIndice(int);
    void swap(NodoHeap* padre,NodoHeap* hijo);
    void acomodar(NodoHeap*);
    void imprimir();
};

#endif // HEAP_H
