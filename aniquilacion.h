#ifndef ANIQUILACION_H
#define ANIQUILACION_H
#include "heap.h"
#include "mundo.h"

//struct NodoHeap {
//    int dato;
//    int indice;
//    NodoHeap* siguiente;
//    NodoHeap* anterior;

//    NodoHeap(int _dato) {
//        dato = _dato;
//        indice = 0;
//        siguiente = anterior = NULL;
//    }

//};

//struct Heap {
//    NodoHeap* raiz;
//    int contador;

//    Heap() {
//        raiz = NULL;
//        contador = 0;
//    }

//    // metodos
//    bool isEmpty() {
//        return (raiz == NULL);
//    }

//    void insertar(int _dato) {
//        NodoHeap* nuevo = new NodoHeap(_dato);
//        if (isEmpty()) {
//            raiz = nuevo;
//            nuevo->indice = contador + 1;
//            contador++;
//            return;
//        }
//        else {
//            NodoHeap* tmp = raiz;
//            while (tmp->siguiente != NULL) {
//                tmp = tmp->siguiente;
//            }
//            nuevo->indice = contador + 1;
//            tmp->siguiente = nuevo;
//            contador++;
//            //acomodar(tmp);
//            return;
//        }
//    }

//    bool paridad(unsigned int numero) {
//        bool paridad = 0;
//        if (numero == 0) {
//            return true;
//        }
//        else if (numero == 1) {
//            return true;
//        }
//        else {
//            while (numero) {
//                paridad = !paridad;
//                numero = numero & (numero - 1);
//            }
//            return paridad;
//        }
//    }

//    bool paridad2(int numero) {
//        if (numero == 0) {
//            return true;
//        }
//        else if (numero == 1) {
//            return false;
//        }
//        else {
//            if (numero % 2 == 0) {
//                return true;
//            }
//            return false;
//        }
//    }

//    NodoHeap* buscarIndice(int _indice) {
//        NodoHeap* temp = raiz;
//        while (temp != NULL) {
//            if (temp->indice == _indice) {
//                return temp;
//            }
//            temp = temp->siguiente;
//        }
//        return NULL;
//    }

//    void acomodar(NodoHeap* hijo) {
//        NodoHeap* padre;
//        if (paridad2(hijo->indice)) {
//            return;
//        }
//    }

//    void imprimir() {
//        if (isEmpty()) {
//            return;
//        }
//        else {
//            NodoHeap* tmp = raiz;
//            while (tmp != NULL) {
//                std::cout << "[ #" << tmp->indice << " : " << tmp->dato << " ] ->";
//                tmp = tmp->siguiente;
//            }
//            std::cout << "\n";
//        }
//    }
//};

struct CorvusGlaive {
    Heap * heap;
    Mundo * mundo;

    CorvusGlaive (Mundo * _mundo) {
        heap = new Heap();
        mundo = _mundo;
    }


};

#endif // ANIQUILACION_H
