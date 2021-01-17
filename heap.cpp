#include "heap.h"

    bool Heap::isEmpty(){
        return primerNodo == NULL;
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

    int Heap::contarNodos(){
        int contador = 0;
        if (isEmpty()) {
            return 0;
        }
        else {
            NodoHeap* tmp = primerNodo;
            while (tmp != NULL) {
                contador++;
            }
            return contador;
        }
    }

    int Heap::contarNodosRecibe(Heap * arbolHeap){
        int contador = 0;
        if (arbolHeap->isEmpty()) {
            return 0;
        }
        else {
            NodoHeap* tmp = arbolHeap->primerNodo;
            while (tmp != NULL) {
                contador++;
            }
            return contador;
        }
    }

    // Esta funcion no se usa es mejor una unica por heap que acomode segun criterio
    // (pecados,deportes,familia,etc)
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

    NodoHeap* Heap::getPadre(NodoHeap* hijo) {
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
    }

    NodoHeap* Heap::getHijoIzquierdo(NodoHeap* padre) {
        NodoHeap* hijoIzquierdo = NULL;
        int k = 2 * padre->indice;
        hijoIzquierdo = buscarIndice(k);
        return hijoIzquierdo;
    }

    NodoHeap* Heap::getHijoDerecho(NodoHeap* padre) {
        NodoHeap* hijoDerecho = NULL;
        int k = (2 * padre->indice) + 1;
        hijoDerecho = buscarIndice(k);
        return hijoDerecho;
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

    void Heap::swap(NodoHeap* i,NodoHeap* j) {
        if(i->anterior)  i->anterior->siguiente = j;
            if(j->anterior)  j->anterior->siguiente = i;
            if(i->siguiente) i->siguiente->anterior= j;
            if(j->siguiente) j->siguiente->anterior= i;
            std::swap(i->anterior, j->anterior);
            std::swap(i->siguiente, j->siguiente);

    }


//    void Heap::swap(NodoHeap* hijo,NodoHeap* padre) {
//        if (padre == primerNodo) {
//            // Coloco el nuevoHijo donde estaba el Padre
//            NodoHeap* nuevoHijo = new NodoHeap(hijo->nodoDoble);
//            nuevoHijo->setIndice(1);
//            nuevoHijo->siguiente = padre->siguiente;
//            padre->siguiente = padre->anterior = NULL;
//            //padre = NULL; // esto es para evitar usar mucha memoria entonces me vuelo todo lo anterior
//            primerNodo = nuevoHijo;
//            // Coloco el Padre donde estaba el hijo
//            NodoHeap* nuevoPadre = new NodoHeap(padre->nodoDoble);
//            nuevoPadre->setIndice(hijo->indice);
//            nuevoPadre->siguiente = hijo->siguiente;
//            nuevoPadre->anterior = hijo->anterior;
//            hijo->anterior = hijo->siguiente = NULL;
//            //hijo = NULL; // PROBANDO
//            if (nuevoPadre->siguiente != NULL) {
//                NodoHeap* refSiguienteHijo = nuevoPadre->siguiente;
//                refSiguienteHijo->anterior = nuevoPadre;
//            }
//            if (nuevoPadre->siguiente != NULL) {
//                NodoHeap* refAnteriorHijo = nuevoPadre->anterior;
//                refAnteriorHijo->siguiente = nuevoPadre;
//            }
//            return;
//        } else {
//            // Coloco el nuevoHijo donde estaba el Padre
//            NodoHeap* nuevoHijo = new NodoHeap(hijo->nodoDoble);
//            nuevoHijo->setIndice(padre->indice);
//            nuevoHijo->siguiente = padre->siguiente;
//            nuevoHijo->anterior = padre->anterior;
//            padre->siguiente = padre->anterior = NULL;
//            //padre = NULL; // PROBANDO
//            nuevoHijo->anterior = nuevoHijo;
//            nuevoHijo->siguiente->anterior = nuevoHijo;
//            // Coloco el Padre donde estaba el hijo
//            NodoHeap* nuevoPadre = new NodoHeap(padre->nodoDoble);
//            nuevoPadre->setIndice(hijo->indice);
//            nuevoPadre->siguiente = hijo->siguiente;
//            nuevoPadre->anterior = hijo->anterior;
//            hijo->anterior = hijo->siguiente = NULL;
//            //hijo = NULL; // PROBANDO
//            if (nuevoPadre->siguiente != NULL) {
//                NodoHeap* refSiguienteHijo = nuevoPadre->siguiente;
//                refSiguienteHijo->anterior = nuevoPadre;
//            }
//            if (nuevoPadre->siguiente != NULL) {
//                NodoHeap* refAnteriorHijo = nuevoPadre->anterior;
//                refAnteriorHijo->siguiente = nuevoPadre;
//            }
//            return;
//        }
//    }

    NodoHeap * Heap::swapConReturn(NodoHeap* i,NodoHeap* j) {
        if(i->anterior)  i->anterior->siguiente = j;
            if(j->anterior)  j->anterior->siguiente = i;
            if(i->siguiente) i->siguiente->anterior= j;
            if(j->siguiente) j->siguiente->anterior= i;
            std::swap(i->anterior, j->anterior);
            std::swap(i->siguiente, j->siguiente);
            return j;
    }


    NodoHeap * Heap::swapConReturnNodos(NodoHeap* i,NodoHeap* j) {
            std::swap(i->nodoDoble->persona,j->nodoDoble->persona);
            return j;
    }


//    void Heap::swap(NodoHeap *hijo, NodoHeap *padre) {
//        if (hijo->anterior) {
//            hijo->anterior->siguiente = padre;
//        }
//        if (padre->anterior) {
//            padre->anterior->siguiente = hijo;
//        }
//        if (hijo->siguiente) {
//            hijo->siguiente->anterior = padre;
//        }
//        if (padre->siguiente) {
//            padre->siguiente->anterior = hijo;
//        }
//        std::swap(hijo->anterior,padre->anterior);
//        std::swap(hijo->siguiente,padre->siguiente);
//        std::swap(hijo->indice,padre->indice);
//    }


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
