#include "consultas.h"

void Consultas::consultarPersona(int _id,QPlainTextEdit* refPantalla) {
    NodoDoble* persona = mundo->listaPersonas->buscarPorId(_id);
    if (persona) {
        persona->imprimirEspecial();
    }
    return;
}

void Consultas::consultarFamilia(int _id,QPlainTextEdit* refPantalla) {
    NodoDoble* persona = mundo->listaPersonas->buscarPorId(_id);
    if (persona) {
        persona->imprimirFamilia();
    }
    return;
}

void Consultas::consultarAmigos(int _id,QPlainTextEdit* refPantalla) {
    // Falta arreglar amigos
    return;
}

void Consultas::consultarHumanosVivos(QPlainTextEdit* refPantalla) {
    return;
}

void Consultas::consultarHumanosMuertos(QPlainTextEdit* refPantalla) {
    return;
}

void Consultas::consultarHumanosSalvados(QPlainTextEdit* refPantalla) {
    return;
}

void Consultas::consultarDeporte(QString _deporte,QPlainTextEdit* refPantalla) {
    return;
}
