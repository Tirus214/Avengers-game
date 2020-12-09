#ifndef PERSONA_H
#define PERSONA_H
#include <QApplication>


struct Persona {
    int id;
    QString nombre;
    QString apellido;
    bool genero;
    QString creencia;
    QString profesion;
    QString fechaNacimiento;

    Persona(){

    }
};

#endif // PERSONA_H
