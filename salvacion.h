#ifndef SALVACION_H
#define SALVACION_H
#include "heap.h"
#include "mundo.h"
#include "arbol.h"

struct Antman{
    int cantidadHormigas;
    ListaDoble * listaPersonas;
    Mundo * mundo;
    int contador;
    NodoArbol * inicio;
    NodoArbol * final;
    Arbol * arbolEntrada;

    //constructor
    Antman (Mundo * _mundo) {
        cantidadHormigas = 0;
        mundo = _mundo;
        arbolEntrada = mundo->arbolOrdenado;
        listaPersonas = mundo->listaPersonas;
        contador = 0;
        inicio = NULL;
        final = NULL;
    }


    //métodos
    void dejarFeromonas();
    void escogerNodo();
    void salvarPersonas();
    void clearFeromonas(NodoArbol *);
    NodoArbol * desempate(NodoArbol *,NodoArbol *);
};


struct Ironman{
    int contador;
    Heap * heapEntrada;
    Mundo * mundo;

    //constructor
    Ironman (Mundo * _mundo){
        mundo = _mundo;
        heapEntrada = mundo->arbolHeap;
        contador = 0;
    }

    void detonarBombas();
    void salvarPersonas(NodoHeap *);
    void salvarAscendientes(Persona*);
    void salvarDescendientes(Persona*);
};

#endif // SALVACION_H
