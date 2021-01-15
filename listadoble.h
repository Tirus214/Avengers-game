#ifndef ListaPersonas_H
#define ListaPersonas_H
#include <QApplication>
#include <QDebug>
#include "QRandomGenerator64"

struct Persona;
struct NodoDoble;
struct ListaDoble;


struct ListaDoble{
    NodoDoble * primerNodo;
    int index;

    ListaDoble(){
        primerNodo = NULL;
        index = 0;
    }

    void insertarAlFinal(Persona * persona);
    void insertarAlInicio(Persona * persona);
    bool isEmpty();
    void imprimir();
    bool esta(int index);
    NodoDoble * buscarPorId(int);
    int largo();
    NodoDoble* buscarEnPosicion(int posicion);
};


struct NodoDoble{
    Persona * persona;
    NodoDoble * siguiente;
    NodoDoble * anterior;

    NodoDoble(Persona * _persona){
        persona = _persona;
        siguiente = anterior = NULL;
    }

    // metodos
    void imprimir();
};



struct Persona {
    int id;
    QString nombre;
    QString apellido;
    QString genero;
    QString creencia;
    QString profesion;
    QString pais;
    QString estadoActual;
    int fechaNacimiento[3];
    int accionesBuenas[7];
    int accionesMalas[7];
    int longevidad;
    QString estadoMarital;
    int salud;
    QStringList paises;
    QString deportes;
    Persona * papa;
    Persona * mama;
    Persona * conyugue;
    ListaDoble * hijos;
    int categoria;
    int cantPecados = 0;
    int cantAccionesBuenas = 0;
    ListaDoble * amigos;

    Persona(int _id, QString _nombre, QString _apellido, QString _creencia, QString _profesion, QString _pais, QStringList _paises, QString gender){
        id = _id;
        hijos = new ListaDoble();
        amigos = new ListaDoble();
        salud = aleatorio(0,7);
        nombre = _nombre;
        apellido = _apellido;
        creencia = _creencia;
        profesion = _profesion;
        pais = _pais;
        genero = gender;
        ranFechaNacimiento();
        ranAccionesBuenas();
        ranAccionesMalas();
        setLongevidad();
        setEstadoMarital();
        setCantPecados();
        setCantAccionesBuenas();
        estadoActual = "Vivo";
        paises = _paises;
        categoria = 0;
    }

    void ranFechaNacimiento();
    void ranAccionesBuenas();
    void ranAccionesMalas();
    void setLongevidad();
    void setEstadoMarital();
    void setFrecuencia();
    void setCantPecados();
    void setCantAccionesBuenas();

    int aleatorio(int min, int max);
};

#endif // ListaPersonas_H
