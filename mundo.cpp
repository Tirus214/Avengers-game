#include "mundo.h"
#include "QRandomGenerator64"


void Mundo::crearPersonas(int num){
    for(int i=0; i<num; i++) { 
        int id = getId();
        QString _nombre = "";
        if(ranGenero()){
            QString _gender = "Mujer";
            _nombre = listaNombresMujer[aleatorio(0, listaNombresMujer->length())];
        }
        else{
            QString _gender = "Hombre";
            _nombre = listaNombresHombre[aleatorio(0, listaNombresHombre->length())];
        }
        QString _apellido = listaApellidos[aleatorio(0,listaCreencias->length())];
        QString _creencia = listaCreencias[aleatorio(0, listaCreencias->length())];
        QString _profesion = listaProfesiones[aleatorio(0,listaProfesiones->length())];

        int rand = getNumPaises();
        QString paises[rand];
        getPaises(rand, paises);
        qDebug() << "hi";
        listaPersonas->insertarAlFinal(new Persona(id, _nombre, _apellido, _creencia, _profesion, paises));
    }
    index += num;
    clasificarRango();
    putHijos();
}


int Mundo::getId(){
    int id = aleatorio(0,10000000);
    while(listaPersonas->esta(id)){
        id = aleatorio(0,10000000);
    }
    return id;
}


int Mundo::getNumPaises(){
    int rand = aleatorio(0,100);
    if(rand <= 30) rand = aleatorio(0,3);
    else if(rand <= 55) rand = aleatorio(2,11);
    else if(rand <= 75) rand = aleatorio(10,16);
    else if(rand <= 90) rand = aleatorio(16,26);
    else rand = aleatorio(25,101);
    return rand;
}


void Mundo::getPaises(int num, QString paises[]){
    for(int i=0; i<num; i++){
        paises[i] = listaPaises[aleatorio(0, listaPaises->length())];
    }
}


bool Mundo::ranGenero(){
    int num = aleatorio(0,2);
    return num == 0;
}


int Mundo::aleatorio(int min, int max){
   std::uniform_int_distribution<int> distribution(min, max);
   return distribution(*QRandomGenerator::global());
}


void Mundo::obtenerArray(QString nombre, QString array[]){
    fileManager->leer(nombre, array);
}


void Mundo::clasificarRango(){
    NodoDoble * tmp = listaPersonas->primerNodo;
    do{
        if(tmp->persona->longevidad <= 1) rangoInfantil->insertarAlFinal(tmp->persona);
        else if(tmp->persona->longevidad <= 4) rangoPreescolar->insertarAlFinal(tmp->persona);
        else if(tmp->persona->longevidad <= 10) rangoEscolar->insertarAlFinal(tmp->persona);
        else if(tmp->persona->longevidad <= 14) rangoPubertad->insertarAlFinal(tmp->persona);
        else if(tmp->persona->longevidad <= 19) rangoAdolecencia->insertarAlFinal(tmp->persona);
        else if(tmp->persona->longevidad <= 24) rangoJoven->insertarAlFinal(tmp->persona);
        else if(tmp->persona->longevidad <= 34) rangoAdultoJoven->insertarAlFinal(tmp->persona);
        else if(tmp->persona->longevidad <= 64) rangoAdultoMaduro->insertarAlFinal(tmp->persona);
        else rangoAdultoMayor->insertarAlFinal(tmp->persona);
        tmp = tmp->siguiente;
    }while(tmp != listaPersonas->primerNodo);
}


void Mundo::putHijos(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            int cantHijos = aleatorio(0,5);
            insertHijos(cantHijos, tmp->persona->id, tmp->persona->hijos, tmp->persona->apellido);
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}


void Mundo::insertHijos(int num, int id, ListaDoble * hijos, QString apellido){
    NodoDoble * tmp = listaPersonas->primerNodo;
    do{
        if(tmp->persona->apellido == apellido && tmp->persona->id != id){
            hijos->insertarAlFinal(tmp->persona);
            num--;
        }
        tmp = tmp->siguiente;
    } while(tmp != listaPersonas->primerNodo || num < 0);
}
