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

    // Esto lo comente porque me estaba dando error de undelared identifier

//    void acomodar(NodoHeap* hijo) {
//        NodoHeap* padre;
//        if (paridad(hijo->indice)) {
//            int k = hijo->indice / 2;
//            padre = buscarIndice(k);
//        } else {
//            int k = (hijo->indice - 1) / 2;
//            padre = buscarIndice(k);
//        }
//        // aqui hago el swap si valor de hijo > valor de padre
//        // necesito primero arreglar swap
//    }

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
        NodoHeap* temp = primerNodo;
        while (temp != NULL) {
            if (temp->indice == _indice) {
                return temp;
            }
            temp = temp->siguiente;
        }
        return nullptr;
    }

    void swap(NodoHeap* padre,NodoHeap* hijo) {
        // necesito ayuda aca
    }

//    void imprimir() {
//            if (isEmpty()) {
//                return;
//            }
//            else {
//                NodoHeap* tmp = primerNodo;
//                while (tmp != NULL) {
//                    qDebug() << "[ #" << tmp->indice << " : " << tmp->nodoDoble->persona->id << " ] ->";
//                    tmp = tmp->siguiente;
//                }
//                qDebug() << "\n";
//            }
//        }
//    };
