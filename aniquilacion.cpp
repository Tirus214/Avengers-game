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

void Midnight::acomodarHeap(NodoHeap * hijo){
    if (heap->isEmpty()) {
        return;
    } else {
        NodoHeap* padre = NULL;
        padre = heap->getPadre(hijo);
        while (hijo->nodoDoble->persona->cantAccionesBuenas < padre->nodoDoble->persona->cantAccionesBuenas){
            heap->swapConReturnNodos(hijo,padre);
            hijo = padre;
            padre = heap->getPadre(hijo);
            if (padre == NULL) break;
        }
    }
}

void Midnight::recorrerHeap(){
    if (heap->isEmpty()) {
        return;
    } else {
        NodoHeap * tmp = heap->primerNodo;
        if (tmp->anterior == NULL && tmp->siguiente == NULL) return;
        while (tmp != NULL) {
            if (heap->getPadre(tmp) != NULL)
            acomodarHeap(tmp);
            tmp = tmp->siguiente;
            imprimir();
        }
        matarPersonas();
    }
}


void Midnight::matarPersonas(){
    if (heap->isEmpty()) {
        return;
    }
    else {
        int cantidadAEliminar = (heap->contador)*0.05;
        NodoHeap* tmp = heap->primerNodo;
        for (int i = 0; i <= cantidadAEliminar; i++){
            tmp->nodoDoble->persona->estadoActual = "Muerto";
            tmp = tmp->siguiente;
        }
        return;
    }
}

void Midnight::imprimir(){
    if (heap->isEmpty()) {
        return;
    } else {
        NodoHeap* tmp = heap->primerNodo;
        while (tmp != NULL) {
            qDebug() << " [ #" << tmp->indice << " ID: " << tmp->nodoDoble->persona->id << " Acciones buenas: " << tmp->nodoDoble->persona->cantAccionesBuenas << "Estado:" << tmp->nodoDoble->persona->estadoActual << " ] ->";
            tmp = tmp->siguiente;
        }
        qDebug() << "\n";
        return;
    }
}

NodoHeap* Nebula::randNodoArbol(){
    std::uniform_int_distribution<int> distribution(0,tamanoArbol);
    int random = distribution(*QRandomGenerator::global());
    if (arbolEntrada->isEmpty()) {
        return NULL;
    }
    else {
        if (random == 0) return arbolEntrada->primerNodo;
        NodoHeap* tmp = arbolEntrada->primerNodo;
        for (int i = 0; i <= random; i++){
            tmp = tmp->siguiente;
        }
        return tmp;
    }
}


void Nebula::matarPersonas(){
    NodoHeap* nodoSeleccionado = randNodoArbol();

}
