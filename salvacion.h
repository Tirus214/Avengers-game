#ifndef SALVACION_H
#define SALVACION_H
#include "heap.h"
#include "mundo.h"
#include "arbol.h"

struct Antman{
    int cantidadHormigas;
    ListaDoble * listaPersonas;
    Mundo * mundo;
    int contador;
    NodoArbol * inicio;
    NodoArbol * final;
    Arbol * arbolEntrada;
    int contadorUltimaCorrida;
    QStringList hormigas;

    //constructor
    Antman (Mundo * _mundo) {
        cantidadHormigas = 0;
        mundo = _mundo;
        arbolEntrada = mundo->arbolOrdenado;
        listaPersonas = mundo->listaPersonas;
        contador = 0;
        contadorUltimaCorrida = 0;
        inicio = NULL;
        final = NULL;
        getHormigas();
    }


    //métodos
    void getHormigas();
    void setHormigas(int num);
    void dejarFeromonas();
    int maximo(int, int);
    NodoArbol * escogerNodo(NodoArbol *);
    void salvarPersonas();
    void clearFeromonas(NodoArbol *);
    NodoArbol * desempate(NodoArbol *,NodoArbol *);
};


struct Ironman{
    int contador;
    Heap * heapEntrada;
    Mundo * mundo;
    int contadorUltimaCorrida;

    //constructor
    Ironman (Mundo * _mundo){
        mundo = _mundo;
        heapEntrada = mundo->arbolHeap;
        contador = 0;
        contadorUltimaCorrida = 0;
    }

    void detonarBombas();
    void salvarPersonas(NodoHeap *);
    void salvarAscendientes(Persona*);
    void salvarDescendientes(Persona*);
};

struct Thor{

    int contador;
    int contadorUltimaCorrida;
    Arbol * arbolEntrada;
    Mundo * mundo;
    int nivelEscogido;

    Thor (Mundo * _mundo){
        mundo = _mundo;
        arbolEntrada = mundo->arbolOrdenado;
        contador = 0;
        contadorUltimaCorrida = 0;
    }

    void obtenerNodoPorNivel(NodoArbol *, int, int);
    void salvarPersonas(Persona*);
};

struct Spiderman{
    int contador;
    Heap * heapEntrada;
    Mundo * mundo;
    ListaDoble * listaPersonas;
    int contadorTelas;
    int contadorUltimaCorrida;

    Spiderman (Mundo * _mundo){
        mundo = _mundo;
        heapEntrada = mundo->arbolHeap;
        contador = 0;
        listaPersonas = mundo->listaPersonas;
        contadorTelas = 0;
        contadorUltimaCorrida = 0;
    }

    void crearTela();
    void salvarPersonas(NodoHeap *);
};

#endif // SALVACION_H
