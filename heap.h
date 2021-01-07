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
    void swap(NodoHeap* hijo,NodoHeap* padre);
    NodoHeap* acomodar(NodoHeap*);
    void imprimir();
    NodoHeap* getPadre(NodoHeap*);
    NodoHeap* getHijoIzquierdo(NodoHeap*);
    NodoHeap* getHijoDerecho(NodoHeap*);
};

#endif // HEAP_H
