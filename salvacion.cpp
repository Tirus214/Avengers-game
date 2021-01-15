#include "salvacion.h"

void Antman::dejarFeromonas(){
    if (arbolEntrada->isEmpty(arbolEntrada->raiz)) return;
    else {
        clearFeromonas(arbolEntrada->raiz);
        NodoArbol * tmp = NULL;
        for(int i = 0;i > 2; i++){
            int aleatorio = 0;
            for (int i = 0; i <= cantidadHormigas; i++){
                if (i == 0) tmp = arbolEntrada->raiz->hijoIzquierdo;
                if (i == 1) tmp = arbolEntrada->raiz->hijoDerecho;
                while(tmp != NULL){
                    aleatorio = mundo->aleatorio(0,100);
                    tmp->feromonas++;
                    if (0 <= aleatorio && aleatorio > 50 and tmp->hijoIzquierdo != NULL) tmp = tmp->hijoIzquierdo;
                    else tmp = tmp->hijoDerecho;
                }
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

void Antman::escogerNodo(){
    for(int i = 0; i < 0; i++){
        NodoArbol * tmp = NULL;
        if (i == 0) tmp = arbolEntrada->raiz->hijoIzquierdo;
        if (i == 1) tmp = arbolEntrada->raiz->hijoDerecho;
        while (tmp != NULL) {
            if(tmp->hijoDerecho == tmp->hijoIzquierdo == NULL) break;
            else if (tmp->hijoDerecho == NULL){
                tmp = tmp->hijoIzquierdo;
            }
            else if (tmp->hijoIzquierdo == NULL){
                tmp = tmp->hijoDerecho;
            }
            else if (tmp->hijoDerecho->feromonas > tmp->hijoIzquierdo->feromonas){
                tmp = tmp->hijoDerecho;
            }
            else if (tmp->hijoDerecho->feromonas < tmp->hijoIzquierdo->feromonas){
                tmp = tmp->hijoIzquierdo;
            }
            else if (tmp->hijoDerecho->feromonas == tmp->hijoIzquierdo->feromonas){
                tmp = desempate(tmp->hijoIzquierdo, tmp->hijoDerecho);
            }
        }
        if (i == 0) inicio = tmp;
        if (i == 1) final = tmp;
    }
    return;
}


void Antman::salvarPersonas(){
    NodoDoble * inicioDoble = listaPersonas->buscarPorId(inicio->nodoPersona->persona->id);
    NodoDoble * finalDoble = listaPersonas->buscarPorId(final->nodoPersona->persona->id);
    do{
        if(inicioDoble->persona->estadoActual == "Muerto"){
            contador++;
            inicioDoble->persona->estadoActual = "Vivo";
        }
        inicioDoble = inicioDoble->siguiente;
    }while (inicioDoble != finalDoble);
    return;
}

int maximo (int a, int b)
{
    if (a>b)
       return a;
    else if (a==b)
        return a;
       else return b;
}


NodoArbol * Antman::desempate(NodoArbol * izquierdo, NodoArbol * derecho){
    if (izquierdo->hijoIzquierdo == NULL) return izquierdo;
    else if(maximo(izquierdo->hijoIzquierdo->feromonas,izquierdo->hijoDerecho->feromonas) > maximo(derecho->hijoIzquierdo->feromonas,derecho->hijoDerecho->feromonas)) return izquierdo;
    else return derecho;
}

void Ironman::detonarBombas(){
    if (heapEntrada->isEmpty()) return;
    else {
        NodoHeap * tmp = heapEntrada->primerNodo;
        int probabilidadDetonacion = mundo->aleatorio(40,60);
        while (tmp != NULL) {
            int aleatorioBomba = mundo->aleatorio(0,100);
            if (aleatorioBomba <= probabilidadDetonacion){
                salvarAscendientes(tmp->nodoDoble->persona);
                salvarDescendientes(tmp->nodoDoble->persona);
            }
            tmp = tmp->siguiente;
        }
    }
}

void Ironman::salvarAscendientes(Persona * personaAnalizada){
    if (personaAnalizada == NULL) return;
    if (personaAnalizada->estadoActual == "Muerto"){
        contador++;
        personaAnalizada->estadoActual = "Vivo";
    }
    salvarAscendientes(personaAnalizada->papa);
    salvarAscendientes(personaAnalizada->mama);
}

void Ironman::salvarDescendientes(Persona * raiz){
    if(raiz == NULL) return;
    else{
        if (raiz->estadoActual == "Muerto"){
            contador++;
            raiz->estadoActual = "Vivo";
        }
        NodoDoble * tmp = raiz->amigos->primerNodo;
        if (tmp == NULL) return;
        else{
            do{
                salvarAscendientes(tmp->persona);
            }while(tmp != NULL);
        }
    }
}
