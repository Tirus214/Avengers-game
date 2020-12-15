#include "listapersonas.h"


void ListaPersonas::insertarAlFinal(Persona * persona){
    if(persona != NULL){
        if(primerNodo == NULL){
            primerNodo = new NodoDoble(persona);
        }
        else if (primerNodo->anterior == NULL){
            primerNodo->anterior = primerNodo->siguiente = new NodoDoble(persona);
            primerNodo->anterior->anterior = primerNodo->anterior->siguiente = primerNodo;
        }
        else{
            NodoDoble * nuevo = new NodoDoble(persona);
            nuevo->siguiente = primerNodo;
            nuevo->anterior = primerNodo->anterior;
            primerNodo->anterior->siguiente = primerNodo->anterior = nuevo;
        }
    }
}



bool ListaPersonas::isEmpty(){
    return primerNodo == NULL;
}

void ListaPersonas::toString(){
    if(!isEmpty()){
        NodoDoble * tmp = primerNodo;
        do{
            qDebug() << tmp->persona;
            tmp = tmp->siguiente;
        } while(tmp != primerNodo);
    }
}
