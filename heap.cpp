#include "heap.h"

    bool Heap::isEmpty(){
        return primerNodo == NULL;
    }

    void Heap::insertarAlInicio (NodoDoble* nodo){
        if (isEmpty())
            primerNodo = ultimoNodo = new NodoHeap(nodo);
        else{
            NodoHeap * nuevo = new NodoHeap(nodo);
            nuevo->siguiente = primerNodo;
            primerNodo->anterior = nuevo;
            primerNodo = nuevo;
        }
    }

    void Heap::insertarAlFinal (NodoDoble* nodo){
        if (isEmpty())
            primerNodo = ultimoNodo = new NodoHeap(nodo);
        else{
            NodoHeap * nuevo = new NodoHeap(nodo);
            nuevo->anterior = ultimoNodo;
            ultimoNodo->siguiente = nuevo;
            ultimoNodo = nuevo;
        }
    }
