#ifndef PERSONA_H
#define PERSONA_H
#include <QApplication>
#include <QDebug>
#include "QRandomGenerator64"


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
    int salud;
    QStringList deportes;
    QStringList paises;
    Persona * papa;
    Persona * mama;
    Persona * conyugue;

    Persona(int _id, QString _nombre, QString _apellido, QString _creencia, QString _profesion, QString paises[]){
        id = _id;
        nombre = _nombre;
        apellido = _apellido;
        creencia = _creencia;
        profesion = _profesion;
        ranFechaNacimiento();
        ranAccionesBuenas();
        ranAccionesMalas();
        setLongevidad();
        setEstadoMarital();
    }

    void ranFechaNacimiento();
    void ranAccionesBuenas();
    void ranAccionesMalas();
    void setLongevidad();
    void setEstadoMarital();

    int aleatorio(int min, int max);
};

#endif // PERSONA_H
