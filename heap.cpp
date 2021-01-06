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

    void Heap::insertar(NodoDoble* nodo) {
        NodoHeap* nuevo = new NodoHeap(nodo);
        if (isEmpty()) {
            nuevo->indice = contador + 1;
            primerNodo = ultimoNodo = nuevo;
            contador++;
            return;
        } else {
            NodoHeap* temp = primerNodo;
            while (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            nuevo->indice = contador + 1;
            temp->siguiente = nuevo;
            nuevo->anterior = temp;
            contador++;
            // acomodar();
            return;
        }
    }

    NodoHeap* Heap::acomodar(NodoHeap* hijo) {
        NodoHeap* padre = NULL;
        if (paridad(hijo->indice)) {
            int k = hijo->indice / 2;
            padre = buscarIndice(k);
            return padre;
        } else {
            int k = (hijo->indice - 1) / 2;
            padre = buscarIndice(k);
            return padre;
        }
        // aqui hago el swap si valor de hijo > valor de padre
        // necesito primero arreglar swap
    }

    bool Heap::paridad(int numero) {
        if (numero == 0) {
            return true;
        } else  if (numero == 1) {
            return false;
        } else {
            if ( numero % 2 == 0 ) {
                return true;
            }
            return false;
        }
    }

    NodoHeap* Heap::buscarIndice(int _indice) {
        if (isEmpty()) {
            return NULL;
        } else {
            NodoHeap* temp = primerNodo;
            while (temp != NULL) {
                if (temp->indice == _indice) {
                    return temp;
                }
                temp = temp->siguiente;
            }
        }
        return NULL;
    }

    void Heap::swap(NodoHeap* padre,NodoHeap* hijo) {
        // nuevos hijos padres
        NodoHeap copiaHijo = *hijo;
        NodoHeap copiaPadre = *padre;
        //aislar nodos
        copiaHijo.anterior = NULL;
        copiaHijo.siguiente = NULL;
        copiaPadre.anterior = NULL;
        copiaPadre.siguiente = NULL;
        // AISLO PADRE
        if (padre->indice == 1) {
            qDebug() << "Padre : " << padre->indice << " ID: " << padre->nodoDoble->persona->id;
            qDebug() << " Siguiente -> : " << padre->siguiente->indice << " ID: " << padre->siguiente->nodoDoble->persona->id;
        } else {
            qDebug() << "Padre : " << padre->indice << " ID: " << padre->nodoDoble->persona->id;
            qDebug() << " Siguiente -> : " << padre->siguiente->indice << " ID: " << padre->siguiente->nodoDoble->persona->id;
            qDebug() << " Anterior <- : " << padre->siguiente->indice << " ID: " << padre->anterior->nodoDoble->persona->id;
        }
        qDebug() << "Hijo : " << hijo->indice << " ID: " << hijo->nodoDoble->persona->id;
        qDebug() << " Siguiente -> : " << hijo->siguiente->indice << " ID: " << hijo->siguiente->nodoDoble->persona->id;
        // enlazo los siguientes para cada copia (futuro padre/hijo)
        copiaHijo.siguiente = padre->siguiente;
        copiaPadre.siguiente = hijo->siguiente;
        // desenlazo primero el hijo
        NodoHeap* anteriorHijoOrg = hijo->anterior;
        anteriorHijoOrg->siguiente = NULL;
        // inserto el nuevo hijo
        copiaPadre.imprimir();

        return;
    }

    void Heap::imprimir() {
        if (isEmpty()) {
            return;
        }
        else {
            NodoHeap* tmp = primerNodo;
            while (tmp != NULL) {
                qDebug() << "[ #" << tmp->indice << " : " << tmp->nodoDoble->persona->id << " ] ->";
                tmp = tmp->siguiente;
            }
            qDebug() << "\n";
            return;
        }
    }
