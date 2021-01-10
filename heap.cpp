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

//    void Heap::swap(NodoHeap* padre,NodoHeap* hijo) {
//        // nuevos hijos padres
//        NodoHeap copiaHijo = *hijo;
//        NodoHeap copiaPadre = *padre;
//        //aislar nodos
//        copiaHijo.anterior = NULL;
//        copiaHijo.siguiente = NULL;
//        copiaPadre.anterior = NULL;
//        copiaPadre.siguiente = NULL;
//        // AISLO PADRE
//        if (padre->indice == 1) {
//            qDebug() << "Padre : " << padre->indice << " ID: " << padre->nodoDoble->persona->id;
//            qDebug() << " Siguiente -> : " << padre->siguiente->indice << " ID: " << padre->siguiente->nodoDoble->persona->id;
//        } else {
//            qDebug() << "Padre : " << padre->indice << " ID: " << padre->nodoDoble->persona->id;
//            qDebug() << " Siguiente -> : " << padre->siguiente->indice << " ID: " << padre->siguiente->nodoDoble->persona->id;
//            qDebug() << " Anterior <- : " << padre->siguiente->indice << " ID: " << padre->anterior->nodoDoble->persona->id;
//        }
//        qDebug() << "Hijo : " << hijo->indice << " ID: " << hijo->nodoDoble->persona->id;
//        qDebug() << " Siguiente -> : " << hijo->siguiente->indice << " ID: " << hijo->siguiente->nodoDoble->persona->id;
//        // enlazo los siguientes para cada copia (futuro padre/hijo)
//        copiaHijo.siguiente = padre->siguiente;
//        copiaPadre.siguiente = hijo->siguiente;
//        // desenlazo primero el hijo
//        NodoHeap* anteriorHijoOrg = hijo->anterior;
//        anteriorHijoOrg->siguiente = NULL;
//        // inserto el nuevo hijo
//        copiaPadre.imprimir();
//        NodoHeap* ptoCopiaPadre = &copiaPadre;
//        ptoCopiaPadre->imprimir();
//        anteriorHijoOrg->siguiente = ptoCopiaPadre;
//        return;
//    }

//    void Heap::swap(NodoHeap* raiz,int indicePadre,int indiceHijo) {
//        if (indicePadre == indiceHijo) {
//            return;
//        } else {
//            if ( indicePadre <= contador && indiceHijo <= contador) {
//                NodoHeap* tempPadre = raiz, *anteriorTempPadre = NULL;
//                while (anteriorTempPadre && tempPadre->indice != indicePadre) {
//                    anteriorTempPadre = tempPadre;
//                    tempPadre = tempPadre->siguiente;
//                }
//                NodoHeap* tempHijo = raiz, *anteriorTempHijo = NULL;
//                while (anteriorTempHijo && tempHijo->indice != indiceHijo) {
//                    anteriorTempHijo = tempHijo;
//                    tempHijo = tempHijo->siguiente;
//                }
//                if (tempHijo == NULL || tempPadre == NULL) {
//                    return;
//                } else {
//                    if (anteriorTempPadre != NULL) {
//                        anteriorTempPadre->siguiente = tempHijo;
//                    } else {
//                        raiz = tempHijo;
//                    }
//                    if (anteriorTempHijo != NULL) {
//                        anteriorTempHijo->siguiente = tempPadre;
//                    } else {
//                        raiz = tempPadre;
//                    }
//                    // Intercambiar punteros
//                    NodoHeap* temp = tempHijo->siguiente;
//                    tempHijo->siguiente = tempPadre->siguiente;
//                    tempPadre->siguiente = temp;
//                }
//            } else {
//                qDebug() << "Index Out Of Bound";
//            }
//        }
//    }

    void Heap::swap(NodoHeap* hijo,NodoHeap* padre) {
        if (padre == primerNodo) {
            // Coloco el nuevoHijo donde estaba el Padre
            NodoHeap* nuevoHijo = new NodoHeap(hijo->nodoDoble);
            nuevoHijo->setIndice(1);
            nuevoHijo->siguiente = padre->siguiente;
            padre->siguiente = padre->anterior = NULL;
            //padre = NULL; // esto es para evitar usar mucha memoria entonces me vuelo todo lo anterior
            primerNodo = nuevoHijo;
            // Coloco el Padre donde estaba el hijo
            NodoHeap* nuevoPadre = new NodoHeap(padre->nodoDoble);
            nuevoPadre->setIndice(hijo->indice);
            nuevoPadre->siguiente = hijo->siguiente;
            nuevoPadre->anterior = hijo->anterior;
            hijo->anterior = hijo->siguiente = NULL;
            //hijo = NULL; // PROBANDO
            if (nuevoPadre->siguiente != NULL) {
                NodoHeap* refSiguienteHijo = nuevoPadre->siguiente;
                refSiguienteHijo->anterior = nuevoPadre;
            }
            if (nuevoPadre->siguiente != NULL) {
                NodoHeap* refAnteriorHijo = nuevoPadre->anterior;
                refAnteriorHijo->siguiente = nuevoPadre;
            }
            return;
        } else {
            // Coloco el nuevoHijo donde estaba el Padre
            NodoHeap* nuevoHijo = new NodoHeap(hijo->nodoDoble);
            nuevoHijo->setIndice(padre->indice);
            nuevoHijo->siguiente = padre->siguiente;
            nuevoHijo->anterior = padre->anterior;
            padre->siguiente = padre->anterior = NULL;
            //padre = NULL; // PROBANDO
            nuevoHijo->anterior = nuevoHijo;
            nuevoHijo->siguiente->anterior = nuevoHijo;
            // Coloco el Padre donde estaba el hijo
            NodoHeap* nuevoPadre = new NodoHeap(padre->nodoDoble);
            nuevoPadre->setIndice(hijo->indice);
            nuevoPadre->siguiente = hijo->siguiente;
            nuevoPadre->anterior = hijo->anterior;
            hijo->anterior = hijo->siguiente = NULL;
            //hijo = NULL; // PROBANDO
            if (nuevoPadre->siguiente != NULL) {
                NodoHeap* refSiguienteHijo = nuevoPadre->siguiente;
                refSiguienteHijo->anterior = nuevoPadre;
            }
            if (nuevoPadre->siguiente != NULL) {
                NodoHeap* refAnteriorHijo = nuevoPadre->anterior;
                refAnteriorHijo->siguiente = nuevoPadre;
            }
            return;
        }
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
