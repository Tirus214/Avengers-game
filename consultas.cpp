#include "consultas.h"

void Consultas::consultarPersona(int _id) {
    NodoDoble* persona = mundo->listaPersonas->buscarPorId(_id);
    if (persona) {
        persona->imprimirEspecial();
    }
    return;
}

void Consultas::consultarFamilia(int _id) {
    NodoDoble* persona = mundo->listaPersonas->buscarPorId(_id);
    if (persona) {
        persona->imprimirFamilia();
    }
    return;
}

void Consultas::consultarAmigos(int _id) {
    return;
}

void Consultas::consultarEstadisticas() {
    return;
}

void Consultas::consultarDeporte(QString _deporte) {
    return;
}
