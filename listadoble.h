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
};



struct Persona {
    int id;
    QString nombre;
    QString apellido;
    bool genero;
    QString creencia;
    QString profesion;
    int fechaNacimiento[3];
    int accionesBuenas[7];
    int accionesMalas[7];
    int longevidad;
    QString estadoMarital;
    int salud[7];
    QStringList paises;
    Persona * papa;
    Persona * mama;
    Persona * conyugue;
    ListaDoble * hijos;

    Persona(int _id, QString _nombre, QString _apellido, QString _creencia, QString _profesion, QString* _paises){
        id = _id;
        hijos = new ListaDoble();
        nombre = _nombre;
        apellido = _apellido;
        creencia = _creencia;
        profesion = _profesion;
        ranFechaNacimiento();
        ranAccionesBuenas();
        ranAccionesMalas();
        setLongevidad();
        setEstadoMarital();
        setFrecuencia();
        setPaises(_paises);
    }

    void ranFechaNacimiento();
    void ranAccionesBuenas();
    void ranAccionesMalas();
    void setLongevidad();
    void setEstadoMarital();
    void setFrecuencia();
    void setPaises(QString* _paises);

    int aleatorio(int min, int max);
};

#endif // ListaPersonas_H
