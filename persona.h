#ifndef PERSONA_H
#define PERSONA_H
#include <QApplication>
#include <QDebug>


struct Persona {
    int id;
    QString nombre;
    QString apellido;
    bool genero;
    QString creencia;
    QString profesion;
    QString fechaNacimiento;

    Persona(int _id){
        id = _id;
    }

    QString ranNombre();
    QString ranApellido();
    bool ranGenero();
    QString ranCreencia();
    QString ranProfesion();
    QString ranFechaNacimiento();
};

#endif // PERSONA_H
