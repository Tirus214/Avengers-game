#ifndef CONSULTAS_H
#define CONSULTAS_H
#include "mundo.h"
#include <QPlainTextEdit>

struct Consultas {
    Mundo* mundo;

    Consultas(Mundo* _mundo) {
        mundo = _mundo;
    }

    // Metodos
    void consultarPersona(int _id,QPlainTextEdit*);
    void consultarFamilia(int _id,QPlainTextEdit*);
    void consultarAmigos(int _id,QPlainTextEdit*);
    void consultarDeporte(QString _deporte,QPlainTextEdit*);
    void consultarHumanosVivos(QPlainTextEdit*);
    void consultarHumanosMuertos(QPlainTextEdit*);
    void consultarHumanosSalvados(QPlainTextEdit*);
    void imprimirArbol(QPlainTextEdit*);
};

#endif // CONSULTAS_H
