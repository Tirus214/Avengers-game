#ifndef MUNDO_H
#define MUNDO_H
#include "heap.h"
#include "filemanager.h"
#include "arbol.h"


struct Mundo{
    ListaDoble * listaPersonas;
    FileManager * fileManager;
    QString listaNombresHombre[500];
    QString listaNombresMujer[500];
    QString listaApellidos[20];
    QString listaCreencias[10];
    QString listaProfesiones[50];
    QString listaPaises[100];
    QString listaDeportes[7] = {"Futbol", "Tenis", "Natacion", "Beisbol", "Basketball", "Atletismo", "Karate"};

    int index;
    Heap * arbolHeap;

    Mundo(){
        listaPersonas = new ListaDoble();
        index = 0;
        fileManager = new FileManager();
        obtenerArray("Apellidos", listaApellidos);
        obtenerArray("NombresHombre", listaNombresHombre);
        obtenerArray("NombresMujer", listaNombresMujer);
        obtenerArray("Creencias", listaCreencias);
        obtenerArray("Profesiones", listaProfesiones);
        obtenerArray("Paises", listaPaises);

        arbolHeap = new Heap();
    }

    void crearPersonas(int num);
    int getId(void); //retorna un id unico
    int getNumPaises(); //retorna el numero de paises segun probabilidades
    void getPaises(int num, QStringList paises);  //retorna lista de paises aleatorios segun la cantidad ingresada
    bool ranGenero();   //obtiene un genero random
    int aleatorio(int min, int max);  //crea un aleatorio
    void obtenerArray(QString nombre, QString array[]); //obtiene un array de un archivo
    void clasificarRango(); //clasifica a las personas por rango etario
    void putHijos();    //coloca hijos segun apellido a todas las personas
    void insertHijos(NodoDoble*, int);
    bool validarHijo(Persona* papa, Persona* hijo);
    void crearArbol();
    int getCantNodosArbol();
    void sumarAcciones();
    void imprimir();
};

#endif // MUNDO_H
