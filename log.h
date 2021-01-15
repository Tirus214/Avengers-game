#ifndef LOG_H
#define LOG_H
#include "filemanager.h"
#include "listadoble.h"
#include <QTime>
#include <QDate>

struct Log {
    QStringList historico;
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
    int segundos;
    QString fecha;
    QString tiempo;

    Log(){
        dia = 0;
        mes = 0;
        ano = 0;
        hora = 0;
        minutos = 0;
        segundos = 0;
        fecha = "";
        tiempo = "";
    }

    void getFechaYHora();
    void insertarMuerte(Persona* , QString);
    void insertarSalvacion(Persona* , QString);
    QString getAmigos(Persona* persona);
    QString getFamilia(Persona* persona);
    QString getExperiencia(Persona* persona);
};

#endif // LOG_H
