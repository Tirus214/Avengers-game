#include "mundo.h"

void Mundo::crearPersonas(int num){
    for(int i=0; i<num; i++) {
        lista->insertarAlFinal(new Persona(index));
        index++;
    }
}
