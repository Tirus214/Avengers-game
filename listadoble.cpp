#include "listadoble.h"


int Persona::aleatorio(int min, int max){
   std::uniform_int_distribution<int> distribution(min, max);
   return distribution(*QRandomGenerator::global());
}


void Persona::ranFechaNacimiento(){
    fechaNacimiento[2] = aleatorio(1,28);
    fechaNacimiento[1] = aleatorio(1,12);
    fechaNacimiento[0] = aleatorio(1950,2020);
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

void Persona::setCantPecados() {
    for (int i = 0; i < 7; i++) {
        cantPecados += accionesMalas[i];
    }
}

void Persona::setCantAccionesBuenas() {
    for (int i = 0; i < 7; i++) {
        cantAccionesBuenas += accionesBuenas[i];
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
        salud[i] = aleatorio(0,7);
    }
}



void ListaDoble::insertarAlFinal(Persona * persona){
        if(primerNodo == NULL){
            primerNodo = new NodoDoble(persona);
            primerNodo->siguiente = primerNodo->anterior = primerNodo;
        }
        else if (primerNodo->anterior == NULL){
            primerNodo->anterior = primerNodo->siguiente = new NodoDoble(persona);
            primerNodo->anterior->anterior = primerNodo->anterior->siguiente = primerNodo;
        }
        else{
            NodoDoble * nuevo = new NodoDoble(persona);
            primerNodo->anterior->siguiente = nuevo;
            nuevo->anterior = primerNodo->anterior;
            nuevo->siguiente = primerNodo;
            primerNodo->anterior = nuevo;

            //nuevo->siguiente = primerNodo;
            //nuevo->anterior = primerNodo->anterior;
            //primerNodo->anterior->siguiente = primerNodo->anterior = nuevo;
        }
        index++;
}


void ListaDoble::insertarAlInicio(Persona * persona){
    if(primerNodo == NULL){
        primerNodo = new NodoDoble(persona);
    }
    else if (primerNodo->siguiente == NULL){
        primerNodo->anterior = primerNodo->siguiente = new NodoDoble(persona);
        primerNodo->anterior->anterior = primerNodo->anterior->siguiente = primerNodo;
        primerNodo = primerNodo->anterior;
    }
    else{
        NodoDoble * nuevo = new NodoDoble(persona);
        nuevo->siguiente = primerNodo;
        nuevo->anterior = primerNodo->anterior;
        primerNodo->anterior->siguiente = primerNodo->anterior = nuevo;
        primerNodo = nuevo;
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
            qDebug() << tmp->persona->id << tmp->persona->nombre;
            tmp = tmp->siguiente;
        } while(tmp != primerNodo);
    }
}


bool ListaDoble::esta(int num){
    if(primerNodo != NULL){
        NodoDoble * tmp = primerNodo;
        do{
            if (tmp->persona->id == num) {
                return true;
            }
            tmp = tmp->siguiente;
        } while(tmp != primerNodo);
    }
    return false;
}


int ListaDoble::largo(){
    return index;
}

NodoDoble * ListaDoble::buscarPorId(int id){
    if(primerNodo != NULL){
        NodoDoble * tmp = primerNodo;
        do{
            if (tmp->persona->id == id) {
                return tmp;
            }
            tmp = tmp->siguiente;
        } while(tmp != primerNodo);
    }
    return NULL;
}



NodoDoble* ListaDoble::buscarEnPosicion(int posicion){
    if (!isEmpty()){
        NodoDoble* tmp = primerNodo;
        do{
            if(posicion == 0) return tmp;
            posicion--;
            tmp = tmp->siguiente;
        } while(tmp != primerNodo);
    }
    return NULL;
}



void NodoDoble::imprimir(){
    qDebug() << "ID: " << persona->id;
    qDebug() << "Nombre: " + persona->nombre;
    qDebug() << "Apellido: " + persona->apellido;
    qDebug() << "Creencia: " + persona->creencia;
    qDebug() << "Hijos: ";
    NodoDoble* hijo = persona->hijos->primerNodo;
    for (int i=0; i < persona->hijos->largo(); i++) {
        qDebug() << "    ID: " << hijo->persona->id;
        qDebug() << "    Nombre: " << hijo->persona->nombre;
    }
    // Imprimir los pecados (temporal)
    for (int i = 0; i < 7; i++) {
        qDebug() << "Pecado [" << i << "] = " << persona->accionesMalas[i];
    }
    // Imprimir nuevo atributo 'cantPecados'
    qDebug() << "Cantidad de pecados : [ " << persona->cantPecados << " ]";
    qDebug() << "";
}
