#include "mundo.h"
#include "QRandomGenerator64"


void Mundo::crearPersonas(int num){
    for(int i=0; i<num; i++) {
        int id = aleatorio(0,10000000);
        while(listaPersonas->esta(num)){
            id = aleatorio(0,10000000);
        }
        listaPersonas->insertarAlFinal(new Persona(id));
    }
}


int Mundo::aleatorio(int min, int max){
   std::uniform_int_distribution<int> distribution(min, max);
   return distribution(*QRandomGenerator::global());
}
