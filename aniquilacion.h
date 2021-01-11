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

struct Midnight {
    // atributos
    Heap * heap;
    Mundo * mundo;
    ListaDoble * listaPersona;


    // constructor
    Midnight (Mundo * _mundo) {
        heap = new Heap();
        mundo = _mundo;
        mundo->llenarHeap(heap);
        listaPersona = mundo->listaPersonas;
        recorrerHeap();
        imprimir();

    }

    // metodos
    void acomodarHeap(NodoHeap *);
    void imprimir();
    void recorrerHeap();
    void matarPersonas();
};

struct Nebula{
    // atributos
    Mundo * mundo;
    ListaDoble * listaPersona = mundo->listaPersonas;
    Heap * arbolEntrada = mundo->arbolHeap;
    int tamanoArbol = mundo->arbolHeap->contarNodos();


    void matarPersonas();
    NodoHeap * randNodoArbol();

};


#endif // ANIQUILACION_H
