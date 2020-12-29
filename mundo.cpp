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
        QString _apellido = listaApellidos[aleatorio(0,listaApellidos->length())];
        QString _creencia = listaCreencias[aleatorio(0, listaCreencias->length())];
        QString _profesion = listaProfesiones[aleatorio(0,listaProfesiones->length())];

        int rand = getNumPaises();
        QStringList paises;
        getPaises(rand, paises);
        listaPersonas->insertarAlFinal(new Persona(id, _nombre, _apellido, _creencia, _profesion, paises));
    }
    index += num;
    clasificarRango();
    putHijos();
    //crearArbol();
}


int Mundo::getId(){
    int id = aleatorio(0,10000000);
    if(!listaPersonas->isEmpty()){
        while(listaPersonas->esta(id)){
            id = aleatorio(0,10000000);
        }
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


void Mundo::getPaises(int num, QStringList paises){
    for(int i=0; i<num; i++){
        paises.append(listaPaises[aleatorio(0, listaPaises->length())]);
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
        if(tmp->persona->longevidad <= 1) tmp->persona->categoria = 0;
        else if(tmp->persona->longevidad <= 4) tmp->persona->categoria = 1;
        else if(tmp->persona->longevidad <= 10) tmp->persona->categoria = 2;
        else if(tmp->persona->longevidad <= 14) tmp->persona->categoria = 3;
        else if(tmp->persona->longevidad <= 19) tmp->persona->categoria = 4;
        else if(tmp->persona->longevidad <= 24) tmp->persona->categoria = 5;
        else if(tmp->persona->longevidad <= 34) tmp->persona->categoria = 6;
        else if(tmp->persona->longevidad <= 64) tmp->persona->categoria = 7;
        else tmp->persona->categoria = 8;
        tmp = tmp->siguiente;
    }while(tmp != listaPersonas->primerNodo);
}


void Mundo::putHijos(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            if(tmp->persona->categoria >= 5){
                int cantHijos = aleatorio(0,5);
                insertHijos(tmp, cantHijos);
            }
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}


void Mundo::insertHijos(NodoDoble* papa, int num){
    NodoDoble * hijo = listaPersonas->primerNodo;
    do{
        if(hijo->persona->apellido == papa->persona->apellido && hijo->persona->id != papa->persona->id){
            if(validarHijo(papa->persona, hijo->persona)){
                papa->persona->hijos->insertarAlFinal(hijo->persona);
                num--;
            }
        }
        hijo = hijo->siguiente;
    } while(hijo != listaPersonas->primerNodo || num < 0);
}


bool Mundo::validarHijo(Persona* papa, Persona* hijo){
    if(papa->categoria == 5 && hijo->categoria <= 1) return true;
    else if(papa->categoria == 6 && hijo->categoria <= 3) return true;
    else if(papa->categoria == 7 && hijo->categoria >= 4 & hijo->categoria <= 6) return true;
    else if(papa->categoria == 8 && hijo->categoria >= 6 & hijo->categoria <= 7) return true;
    return false;
}


void Mundo::crearArbol(){
    int cantNodos = getCantNodosArbol();
    int multiplo = (int) listaPersonas->largo() / cantNodos;
    for(int i=0; i<cantNodos; i++) {
        arbolHeap->insertarAlInicio(listaPersonas->buscarEnPosicion(multiplo*i));
    }
}


int Mundo::getCantNodosArbol(){
    int cantNodos = (int) listaPersonas->largo()/100;    //obtengo el 1%
    int exponente = 0;
    int index = 2;
    while(cantNodos <= (int) pow(index,exponente)-1){
        exponente++;
    }
    cantNodos = (int) pow(index,exponente-1);
    return cantNodos;
}


void Mundo::sumarAcciones(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            for (int i=0; i<7; i++){
                int num1 = aleatorio(0,100);
                tmp->persona->accionesBuenas[i] = num1;
                int num2 = aleatorio(0,100);
                tmp->persona->accionesMalas[i] = num2;
            }
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}


void Mundo::imprimir(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            qDebug() << "ID: " << tmp->persona->id;
            qDebug() << "Nombre: " + tmp->persona->nombre;
            qDebug() << "Apellido: " + tmp->persona->apellido;
            qDebug() << "Creencia: " + tmp->persona->creencia;
            qDebug() << "Hijos: ";
            NodoDoble* hijo = tmp->persona->hijos->primerNodo;
            for (int i=0; i<tmp->persona->hijos->largo(); i++) {
                qDebug() << "    ID: " << hijo->persona->id;
                qDebug() << "    Nombre: " << hijo->persona->nombre;
            }
        } while(tmp != listaPersonas->primerNodo);
    }
}


