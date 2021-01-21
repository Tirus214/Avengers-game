#include "consultas.h"

void Consultas::consultarPersona(int _id,QPlainTextEdit* refPantalla) {
    NodoDoble* persona = mundo->listaPersonas->buscarPorId(_id);
    if (persona) {
        persona->imprimirEspecial(refPantalla);
    }
    return;
}

void Consultas::consultarFamilia(int _id,QPlainTextEdit* refPantalla) {
    NodoDoble* persona = mundo->listaPersonas->buscarPorId(_id);
    if (persona) {
        persona->imprimirFamilia(refPantalla);
    }
    return;
}

void Consultas::consultarAmigos(int _id, QPlainTextEdit* refPantalla) {
    // Falta arreglar amigos
    NodoDoble* tmp = mundo->listaPersonas->buscarPorId(_id);
    if (tmp != NULL) {
        tmp->imprimirAmigos(refPantalla);
    }
    return;
}

void Consultas::consultarHumanosVivos(QPlainTextEdit* refPantalla) {
    mundo->imprimirHumanosVivos(refPantalla);
    return;
}

void Consultas::consultarHumanosMuertos(QPlainTextEdit* refPantalla) {
    mundo->imprimirHumanosMuertos(refPantalla);
    return;
}

void Consultas::consultarHumanosSalvados(QPlainTextEdit* refPantalla) {
    mundo->imprimirHumanosSalvados(refPantalla);
    return;
}

void Consultas::consultarDeporte(QString _deporte,QPlainTextEdit* refPantalla) {
    mundo->imprimirPorDeporte(_deporte,refPantalla);
    return;
}
