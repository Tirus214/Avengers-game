#include "nodoheap.h"

void NodoHeap::imprimir(){
    qDebug() << "Nodo Heap = { \n" << "Indice: " << indice << " } \n";
    qDebug() << "Nodo Doble = { \n";
    nodoDoble->imprimir();
    qDebug() << " }";
    qDebug() << " Siguiente -> : " << siguiente->indice;
    siguiente->nodoDoble->imprimir();
}
