#ifndef ANIQUILACION_H
#define ANIQUILACION_H
#include "heap.h"
#include "mundo.h"

// Cada estructura de aniquilacion tiene un heap exclusivo pero comparten el mismo mundo
// Cada Heap de cada
struct CorvusGlaive {
    // atributos
    Heap * heap;
    Mundo * mundo;

    // constructor
    CorvusGlaive (Mundo * _mundo) {
        heap = new Heap();
        mundo = _mundo;
        insertarAHeap();
    }

    // metodos
    void imprimir();
    void insertarAHeap();
    void insertarAHeap_aux(NodoDoble*);
    void acomodarHeap(NodoHeap*);
};

#endif // ANIQUILACION_H
