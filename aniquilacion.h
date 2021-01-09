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
        mundo->llenarHeap(heap);
    }

    // metodos
    void acomodarHeap();
};

struct Midnight {
    // atributos
    Heap * heap;
    Mundo * mundo;
    ListaDoble * listaPersona = mundo->listaPersonas;


    // constructor
    Midnight (Mundo * _mundo) {
        heap = new Heap();
        mundo = _mundo;
        mundo->llenarHeap(heap);
    }

    // metodos
    NodoHeap* acomodarHeap(NodoHeap *);
    void matarPersonas();
};

struct Nebula{
    // atributos
    Mundo * mundo;
    ListaDoble * listaPersona = mundo->listaPersonas;
    Heap * arbolEntrada = mundo->arbolHeap;
    int tamañoArbol = mundo->arbolHeap->contarNodos();


    void matarPersonas();

};


#endif // ANIQUILACION_H
