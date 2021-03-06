#ifndef MUNDO_H
#define MUNDO_H
#include "heap.h"
#include "arbol.h"
#include "log.h"
#include <QPlainTextEdit>

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
    Arbol * arbolOrdenado;
    Log * logMuertes;
    Log * logSalvacion;

    int totalMatados;
    int totalSalvados;

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
        arbolOrdenado = new Arbol();
        logMuertes = new Log();
        logSalvacion = new Log();
        llenarHeap(arbolHeap);

        totalMatados = 0;
        totalSalvados = 0;
    }

    void crearPersonas(int num);
    int getId(void); //retorna un id unico
    int getNumPaises(); //retorna el numero de paises segun probabilidades
    QStringList getPaises(int num);  //retorna lista de paises aleatorios segun la cantidad ingresada
    bool ranGenero();   //obtiene un genero random
    int aleatorio(int min, int max);  //crea un aleatorio
    void obtenerArray(QString nombre, QString array[]); //obtiene un array de un archivo
    void clasificarRango(); //clasifica a las personas por rango etario
    void putHijos();    //coloca hijos segun apellido a todas las personas
    void insertHijos(NodoDoble*, int);
    bool validarHijo(Persona* papa, Persona* hijo);
    void insertDeportes(NodoDoble *);
    void crearHeap();
    int getCantNodosArbol();
    int getIndex(int exponente);
    void sumarAcciones();
    void putConyugue();
    void putPadres();
    void randomPareja(Persona * actual, QString gender);
    bool validarPadre(Persona* tmp, Persona* cuestionable);
    bool isHijo(Persona* tmp, Persona* cuestionable);
    void randomPadre(Persona* actual, QString gender);
    bool validarConyugue(Persona* actual, Persona* tmp);
    void imprimir();
    void imprimirMasPecador();
    // crear primer heap con las personas del mundo
    void llenarHeap();
    // llenar un Heap con los nodos del mundo para poder llenar varios heaps con las mismas personas
    void llenarHeap(Heap*);
    void putAmigos();
    void searchAmigos(NodoDoble * actual, int numAmigos);
    bool searchAmigosComun(ListaDoble * amigos, ListaDoble * amigosPosibles);
    void crearArbol();
    int contarVivos();
    int contarMuertos();
    NodoDoble* conseguirNodoAleatorio();

    void getLogs();
    // pantalla
    QString getStringArbol();
    QString printElementos(QString salida, QString nombre, NodoArbol * raiz, int num);
    QString getHumanoString(QString salida, Persona* persona, int num);
    void imprimirPantalla(QPlainTextEdit*);
    // estadisticas
    void imprimirHumanosVivos(QPlainTextEdit*);
    void imprimirHumanosMuertos(QPlainTextEdit*);
    void imprimirHumanosSalvados(QPlainTextEdit*);
    void imprimirPorDeporte(QString,QPlainTextEdit*);
};

#endif // MUNDO_H
