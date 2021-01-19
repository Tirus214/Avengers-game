#ifndef CONSULTAS_H
#define CONSULTAS_H
#include "mundo.h"

struct Consultas {
    Mundo* mundo;

    Consultas(Mundo* _mundo) {
        mundo = _mundo;
    }

    // Metodos
    void consultarPersona(int _id);
    void consultarFamilia(int _id);
    void consultarAmigos(int _id);
    void consultarDeporte(QString _deporte);
    void consultarEstadisticas();
    void imprimirArbol();
};

#endif // CONSULTAS_H
