#ifndef PERSONA_H
#define PERSONA_H
#include <QApplication>
#include <QDebug>
#include "listadoble.h"


struct Persona {
    int id;
    QString nombre;
    QString apellido;
    bool genero;
    QString creencia;
    QString profesion;
    QString fechaNacimiento[3];
    int accionesBuenas[7];
    int accionesMalas[7];
    int longevidad;
    QString estadoMarital;
    int salud;
    QStringList deportes;
    ListaDoble * amigos;
    ListaDoble * hijos;
    Persona * papa;
    Persona * mama;
    Persona * conyugue;

    Persona(int _id){
        id = _id;
        nombre = "";
        apellido = "";
        creencia = "";
        profesion = "";
        longevidad = 0;


    }

    QString ranNombre();
    QString ranApellido();
    bool ranGenero();
    QString ranCreencia();
    QString ranProfesion();
    QString ranFechaNacimiento();
};

#endif // PERSONA_H
