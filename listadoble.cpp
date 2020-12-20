#include "listadoble.h"


void ListaDoble::insertarAlFinal(Persona * persona){
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
        index++;
}


bool ListaDoble::isEmpty(){
    return primerNodo == NULL;
}

void ListaDoble::imprimir(){
    if(!isEmpty()){
        NodoDoble * tmp = primerNodo;
        do{
            qDebug() << tmp->persona->id;
            tmp = tmp->siguiente;
        } while(tmp != primerNodo);
    }
}


bool ListaDoble::esta(int num){
    if(!isEmpty()){
        NodoDoble * tmp = primerNodo;
        do{
            if(tmp->persona->id == num)
                return true;
            tmp = tmp->siguiente;
        } while(tmp != primerNodo);
    }
    return false;
}


int ListaDoble::largo(){
    return index;
}




