#include "salvacion.h"

void Antman::dejarFeromonas(){
    if (arbolEntrada->isEmpty(arbolEntrada->raiz)) return;
    else {
        clearFeromonas(arbolEntrada->raiz);
        int aleatorio = 0;
        for (int i = 0; i <= cantidadHormigas; i++){
            NodoArbol * tmp = arbolEntrada->raiz;
            while(tmp != NULL){
                aleatorio = mundo->aleatorio(0,100);
                tmp->feromonas++;
                if (0 <= aleatorio && aleatorio > 50) tmp = tmp->hijoIzquierdo;
                else tmp = tmp->hijoDerecho;
            }
        }
    }
}

void Antman::clearFeromonas(NodoArbol * raiz){
    if (raiz->feromonas == 0 || raiz == NULL) return;
    else{
        raiz->feromonas = 0;
        clearFeromonas(raiz->hijoDerecho);
        clearFeromonas(raiz->hijoIzquierdo);
    }
}

NodoArbol * Antman::escogerNodo(){
    NodoArbol * tmp = arbolEntrada->raiz;
    while (tmp != NULL) {
        if(tmp->hijoDerecho == tmp->hijoIzquierdo == NULL) break;
        else if (tmp->hijoDerecho == NULL) tmp = tmp->hijoIzquierdo;
        else if (tmp->hijoIzquierdo == NULL) tmp = tmp->hijoDerecho;
    }
}
