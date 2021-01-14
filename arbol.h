#ifndef ARBOL_H
#define ARBOL_H
#include "nodoarbol.h"


struct Arbol{
    NodoArbol * raiz;

    Arbol(){
        raiz = NULL;
    }

    void insertar (NodoDoble*);
    NodoArbol* insertar(NodoDoble*, NodoArbol*);
    NodoDoble* buscar (int id, NodoArbol* nodoArbol);
    int obtenerNumeroElementos(NodoArbol*);
    int peso (NodoArbol*);
    int obtenerAltura(NodoArbol*);
    NodoArbol* borrarElemento(int);
    NodoArbol* borrarElemento(int, NodoArbol*);
    void anchura(NodoArbol*);
    int altura(NodoArbol*);
    int cantHojas(NodoArbol*);
    int cantNodos2(NodoArbol*);
    void nodos_nivel (NodoArbol*, int, int);
    int contadorNodos(NodoArbol*);
    NodoArbol* mayor (NodoArbol* arbol);
    bool isEmpty(NodoArbol *);
};

#endif // ARBOL_H
