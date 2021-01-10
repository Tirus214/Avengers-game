#include "aniquilacion.h"

void CorvusGlaive::imprimir(){
    if (heap->isEmpty()) {
        return;
    } else {
        NodoHeap* tmp = heap->primerNodo;
        while (tmp != NULL) {
            qDebug() << " [ #" << tmp->indice << " ID: " << tmp->nodoDoble->persona->id << " C.Pecados: " << tmp->nodoDoble->persona->cantPecados << " ] ->";
            tmp = tmp->siguiente;
        }
        qDebug() << "\n";
        return;
    }
}

void CorvusGlaive::acomodarHeap(NodoHeap* hijo) {
    if (hijo == heap->primerNodo) {
        return;
    } else {
        // Averiguar el padre
        NodoHeap* padre = heap->getPadre(hijo);
        // Comparamos hijo con padre
        if (hijo->nodoDoble->persona->cantPecados > padre->nodoDoble->persona->cantPecados) {
            int siguienteIndice = padre->indice;
            heap->swap(hijo,padre);
            acomodarHeap(heap->buscarIndice(siguienteIndice));
        }
        return;
    }
}

void CorvusGlaive::insertarAHeap_aux(NodoDoble* nodo) {
    NodoHeap* nuevo = new NodoHeap(nodo);
    if (heap->isEmpty()) {
        nuevo->indice = heap->contador + 1;
        heap->primerNodo = heap->ultimoNodo = nuevo;
        heap->contador++;
        return;
    } else {
        NodoHeap* temp = heap->primerNodo;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        nuevo->indice = heap->contador + 1;
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
        heap->contador++;
        acomodarHeap(nuevo);
        return;
    }
}

void CorvusGlaive::insertarAHeap() {
    if (!mundo->listaPersonas->isEmpty()) {
        NodoDoble* tmp = mundo->listaPersonas->primerNodo;
        do {
            insertarAHeap_aux(tmp);
            tmp = tmp->siguiente;
        } while (tmp != mundo->listaPersonas->primerNodo);
    }
    return;
}
