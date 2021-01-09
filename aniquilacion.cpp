#include "aniquilacion.h"

void CorvusGlaive::acomodarHeap(){
    return;
}




NodoHeap* Midnight::acomodarHeap(NodoHeap * hijo){
    NodoHeap* padre = NULL;
    padre = heap->getPadre(hijo);
    bool insertado = false;
    while (hijo->nodoDoble->persona->cantAccionesBuenas < padre->nodoDoble->persona->cantAccionesBuenas){
        hijo = heap->swapConReturn(hijo,padre);
        padre = heap->getPadre(hijo);
        insertado = true;
    }
    return hijo;
}

void Midnight::matarPersonas(){
    int cantidadAEliminar = (heap->contarNodos())*0.05;
    if (heap->isEmpty()) {
        return;
    }
    else {
        NodoHeap* tmp = heap->primerNodo;
        for (int i = 0; i >= cantidadAEliminar; i++){
            tmp->nodoDoble->persona->estadoActual = "Muerto";
            tmp = tmp->siguiente;
        }
        return;
    }
}

void Nebula::matarPersonas(){

}
