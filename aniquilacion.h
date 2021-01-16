#ifndef ANIQUILACION_H
#define ANIQUILACION_H
#include "heap.h"
#include "mundo.h"
#include "arbol.h"

// Cada estructura de aniquilacion tiene un heap exclusivo pero comparten el mismo mundo
// Cada Heap de cada
struct CorvusGlaive {
    // atributos
    Heap * heap;
    Mundo * mundo;
    int contador;


    // constructor
    CorvusGlaive (Mundo * _mundo) {
        heap = new Heap();
        mundo = _mundo;
        insertarAHeap();
        contador = 0;
    }

    // metodos
    void imprimir();
    void insertarAHeap();
    void insertarAHeap_aux(NodoDoble*);
    void acomodarHeap(NodoHeap*);
    void matarPersonas();
};

struct Thanos {
    //atributos
    Mundo * mundo;
    ListaDoble * listaPersona;
    ListaDoble * matrizDispersion[70][10];
    int eliminados;

    Thanos(Mundo * _mundo){
        mundo = _mundo;
        eliminados = 0;
    }

    void insertar (int, int, NodoDoble *);
    int hashFunction(NodoDoble *);
    void recorrerLista();
    void imprimir();
    void comandoThanos(int, int);
    void eliminarCasilla(ListaDoble *, int, int);
};

struct Midnight {
    // atributos
    Heap * heap;
    Mundo * mundo;
    ListaDoble * listaPersona;
    int contador;

    // constructor
    Midnight (Mundo * _mundo) {
        heap = new Heap();
        mundo = _mundo;
        mundo->llenarHeap(heap);
        listaPersona = mundo->listaPersonas;
        recorrerHeap();
        imprimir();
        contador = 0;
    }

    // metodos
    void acomodarHeap(NodoHeap *);
    void imprimir();
    void recorrerHeap();
    void matarPersonas();
};

struct Nebula{
    // atributos
    Mundo * mundo;
    ListaDoble * listaPersona;
    Heap * arbolEntrada;
    int tamanoArbol;
    NodoDoble * nodoSeleccionado;
    int contador;

    Nebula (Mundo * _mundo) {
        mundo = _mundo;
        listaPersona = mundo->listaPersonas;
        arbolEntrada = mundo->arbolHeap;
        tamanoArbol = arbolEntrada->contarNodos();
        nodoSeleccionado = randNodoArbol();
        contador = 0;
    }


    void matarPersonas(NodoDoble *, NodoDoble *);
    bool revisarLista(ListaDoble *);
    NodoDoble * randNodoArbol();

};

struct Dwarf{
    ListaDoble * listaPersona;
    QString deporteSeleccionado;
    int deporteRepeticiones;
    Mundo * mundo;
    int contador;

    Dwarf (Mundo * _mundo) {
        mundo = _mundo;
        listaPersona = mundo->listaPersonas;
        deporteSeleccionado = "";
        deporteRepeticiones = 0;
        contador = 0;
    }

    void matarPersonas();
};



#endif // ANIQUILACION_H
