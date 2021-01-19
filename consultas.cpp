#include "consultas.h"

void Consultas::consultarPersona(int _id) {
    NodoDoble* persona = mundo->listaPersonas->buscarPorId(_id);
    if (persona) {
        persona->imprimirEspecial();
    }
}

void Consultas::consultarFamilia(int _id) {

}
