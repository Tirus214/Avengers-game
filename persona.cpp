#include "persona.h"


int Persona::aleatorio(int min, int max){
   std::uniform_int_distribution<int> distribution(min, max);
   return distribution(*QRandomGenerator::global());
}


void Persona::ranFechaNacimiento(){
    fechaNacimiento[2] = aleatorio(1,28);
    fechaNacimiento[1] = aleatorio(1,13);
    fechaNacimiento[0] = aleatorio(1950,2021);
}


void Persona::ranAccionesBuenas(){
    for(int i=0; i<7; i++){
        accionesBuenas[i] = aleatorio(0,500);
    }
}


void Persona::ranAccionesMalas(){
    for(int i=0; i<7; i++){
        accionesMalas[i] = aleatorio(0,500);
    }
}


void Persona::setLongevidad(){
    longevidad = 2021 - fechaNacimiento[0];
}


void Persona::setEstadoMarital(){
    int num = aleatorio(0,100);
    if (num < 10) estadoMarital = "Soltero";
    else if(num < 80) estadoMarital = "Casado";
    else estadoMarital = "Divorciado";
}


void Persona::setFrecuencia(){
    for(int i=0; i<7; i++){
        salud[i] = aleatorio(0,8);
    }
}


void Persona::setPaises(QString _paises[]){
    for(int i=0; i<_paises->length(); i++){
        paises.append(_paises[i]);
    }
}

