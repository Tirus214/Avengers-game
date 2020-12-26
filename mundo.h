#ifndef MUNDO_H
#define MUNDO_H
#include "listadoble.h"
#include "filemanager.h"


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
    ListaDoble * rangoInfantil;
    ListaDoble * rangoPreescolar;
    ListaDoble * rangoEscolar;
    ListaDoble * rangoPubertad;
    ListaDoble * rangoAdolecencia;
    ListaDoble * rangoJoven;
    ListaDoble * rangoAdultoJoven;
    ListaDoble * rangoAdultoMaduro;
    ListaDoble * rangoAdultoMayor;

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

        rangoInfantil = new ListaDoble();
        rangoPreescolar = new ListaDoble();
        rangoEscolar = new ListaDoble();
        rangoPubertad = new ListaDoble();
        rangoAdolecencia = new ListaDoble();
        rangoJoven = new ListaDoble();
        rangoAdultoJoven = new ListaDoble();
        rangoAdultoMaduro = new ListaDoble();
        rangoAdultoMayor = new ListaDoble();
    }

    void crearPersonas(int num);
    int getId(int num); //retorna un id unico
    int getNumPaises(); //retorna el numero de paises segun probabilidades
    void getPaises(int num, QString paises[]);  //retorna lista de paises aleatorios segun la cantidad ingresada
    bool ranGenero();   //obtiene un genero random
    int aleatorio(int min, int max);  //crea un aleatorio
    void obtenerArray(QString nombre, QString array[]); //obtiene un array de un archivo
    void clasificarRango(); //clasifica a las personas por rango etario
    void putHijos();
    void insertHijos(int num, int id, ListaDoble * hijos, QString apellido);
    void imprimir();
};

#endif // MUNDO_H
