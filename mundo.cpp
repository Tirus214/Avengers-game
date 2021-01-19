#include "mundo.h"
#include "QRandomGenerator64"
#include <QPlainTextDocumentLayout>
#include <QPlainTextEdit>

void Mundo::crearPersonas(int num){
    for(int i=0; i<num; i++) { 
        int id = getId();
        QString _gender = "";
        QString _nombre = "";
        if(ranGenero()){
            _gender = "Mujer";
            _nombre = listaNombresMujer[aleatorio(0, 500)];
        }
        else{
            _gender = "Hombre";
            _nombre = listaNombresHombre[aleatorio(0, 500)];
        }
        QString _apellido = listaApellidos[aleatorio(0,listaApellidos->length()-1)];
        QString _creencia = listaCreencias[aleatorio(0, listaCreencias->length()-1)];
        QString _profesion = listaProfesiones[aleatorio(0,listaProfesiones->length()-1)];
        QString _pais = listaPaises[aleatorio(0, listaPaises->length()-1)];

        int rand = getNumPaises();
        QStringList arrayPaises;
        getPaises(rand, arrayPaises);
        NodoDoble * nodoCreado = listaPersonas->insertarSorted(listaPersonas->primerNodo,new Persona(id, _nombre, _apellido, _creencia, _profesion, _pais, arrayPaises, _gender));
        insertDeportes(nodoCreado);
    }
    index += num;
    clasificarRango();
    putHijos();
    putConyugue();
    putPadres();
    putAmigos();
    crearHeap();
}


int Mundo::getId(){
    int id = aleatorio(0,99999999);
    if(!listaPersonas->isEmpty()){
        while(listaPersonas->esta(id)){
            id = aleatorio(0,99999999);
        }
    }
    return id;
}


int Mundo::getNumPaises(){
    int rand = aleatorio(0,99);
    if(rand <= 30) rand = aleatorio(0,2);
    else if(rand <= 55) rand = aleatorio(2,10);
    else if(rand <= 75) rand = aleatorio(10,15);
    else if(rand <= 90) rand = aleatorio(16,25);
    else rand = aleatorio(25,100);
    return rand;
}


void Mundo::getPaises(int num, QStringList paises){
    for(int i=0; i<num; i++){
        paises.append(listaPaises[aleatorio(0, listaPaises->length()-1)]);
    }
}


bool Mundo::ranGenero(){
    int num = aleatorio(0,1);
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
                int cantHijos = aleatorio(0,4);
                insertHijos(tmp, cantHijos);
            }
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}


void Mundo::insertHijos(NodoDoble* papa, int num){
    NodoDoble * hijo = listaPersonas->primerNodo;
    do{
        if(hijo->persona->apellido == papa->persona->apellido && hijo->persona->id != papa->persona->id)
            if(hijo->persona->pais == papa->persona->pais)
                if(validarHijo(papa->persona, hijo->persona)){
                    papa->persona->hijos->insertarAlFinal(hijo->persona);
                    num--;
                }
        hijo = hijo->siguiente;
    } while(hijo != listaPersonas->primerNodo && num > 0);
}


bool Mundo::validarHijo(Persona* papa, Persona* hijo){
    if(papa->categoria == 5 && hijo->categoria <= 1) return true;
    else if(papa->categoria == 6 && hijo->categoria <= 3) return true;
    else if(papa->categoria == 7 && hijo->categoria >= 4 & hijo->categoria <= 6) return true;
    else if(papa->categoria == 8 && hijo->categoria >= 6 & hijo->categoria <= 7) return true;
    return false;
}


void Mundo::insertDeportes(NodoDoble * nodoCreado){
    int numDeportes = aleatorio(0,6);
    nodoCreado->persona->deportes = listaDeportes[numDeportes];
}


void Mundo::crearHeap(){
    int multiplo = 0;
    int cantNodos = getCantNodosArbol();
    if (cantNodos > 0) {
        multiplo = (int) listaPersonas->largo() / cantNodos;
    }
    else{
        cantNodos = 1;
        multiplo = 1;
    }
    for(int i=0; i<cantNodos; i++) {
        NodoDoble * tmp = listaPersonas->buscarEnPosicion(multiplo*i);
        arbolHeap->insertarAlInicio(tmp);
        arbolOrdenado->insertarPorNivel(arbolOrdenado->raiz,tmp);
    }
    return;
}


int Mundo::getCantNodosArbol(){
    int cantNodos = (int) listaPersonas->largo()/100;    //obtengo el 1%
    int exponente = 0;
    int index = getIndex(exponente);
    while(cantNodos > index){
        exponente++;
        index = getIndex(exponente);
    }
    return index;
}


int Mundo::getIndex(int exponente){
   return pow(2,exponente)-1;
}


void Mundo::sumarAcciones(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            for (int i=0; i<7; i++){
                int num1 = aleatorio(0,99);
                tmp->persona->accionesBuenas[i] = num1;
                int num2 = aleatorio(0,99);
                tmp->persona->accionesMalas[i] = num2;
            }
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}


void Mundo::putConyugue(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            if(tmp->persona->estadoMarital != "Soltero"){
                if(tmp->persona->genero == "Hombre")
                    randomPareja(tmp->persona, "Mujer");
                else randomPareja(tmp->persona, "Hombre");
            }
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}


void Mundo::randomPareja(Persona * actual, QString gender){
    int index = aleatorio(0, listaPersonas->largo()-1);
    NodoDoble * tmp = listaPersonas->buscarEnPosicion(index);
    while(tmp->persona->genero != gender | validarPadre(actual, tmp->persona) | isHijo(actual, tmp->persona)){
        index = aleatorio(0, listaPersonas->largo()-1);
        tmp = listaPersonas->buscarEnPosicion(index);
    }
    actual->conyugue = tmp->persona;
}


bool Mundo::validarPadre(Persona* tmp, Persona* cuestionable){
    if(tmp->papa == cuestionable) return true;
    else if(tmp->mama == cuestionable) return true;
    else return false;
}


bool Mundo::isHijo(Persona* tmp, Persona* cuestionable){
    if(!tmp->hijos->isEmpty()){
        NodoDoble* hijo = tmp->hijos->primerNodo;
        do{
            if(hijo->persona == cuestionable) return true;
            else if(isHijo(tmp->hijos->primerNodo->persona, cuestionable)) return true;
            hijo = hijo->siguiente;
        } while(hijo != tmp->hijos->primerNodo);
    }
    return false;
}


void Mundo::putPadres(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            randomPadre(tmp->persona, "Hombre");
            randomPadre(tmp->persona, "Mujer");
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}


void Mundo::randomPadre(Persona* actual, QString gender){
    int index = aleatorio(0, listaPersonas->largo()-1);
    Persona * tmp = listaPersonas->buscarEnPosicion(index)->persona;
    while(tmp->genero != gender | validarConyugue(actual, tmp) | isHijo(actual, tmp)){
        index = aleatorio(0, listaPersonas->largo()-1);
        tmp = listaPersonas->buscarEnPosicion(index)->persona;
    }
    if(gender == "Hombre") actual->papa = tmp;
    else if(gender == "Mujer") actual->mama = tmp;
}


bool Mundo::validarConyugue(Persona* actual, Persona* tmp){
    return actual->conyugue == tmp;
}


void Mundo::putAmigos(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            int numAmigos = aleatorio(0,50);
            searchAmigos(tmp, numAmigos);
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}


void Mundo::searchAmigos(NodoDoble * actual, int numAmigos){
    if(!listaPersonas->isEmpty() || numAmigos != 0){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
                if(actual->persona->amigos->esta(tmp->persona->id)){
                    tmp = tmp->siguiente;
                    continue;
                }
                if(tmp->persona->pais == actual->persona->pais){
                    actual->persona->amigos->insertarAlFinal(tmp->persona);
                    numAmigos--;
                }
                else if(aleatorio(0,100) <= 40){
                    actual->persona->amigos->insertarAlFinal(tmp->persona);
                    numAmigos--;
                }
                else if(searchAmigosComun(actual->persona->amigos, tmp->persona->amigos)){
                    actual->persona->amigos->insertarAlFinal(tmp->persona);
                    numAmigos--;
                }
            tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo && numAmigos > 0);
    }
}


bool Mundo::searchAmigosComun(ListaDoble * amigos, ListaDoble * amigosPosibles){
    if(!amigos->isEmpty() && !amigosPosibles->isEmpty()){
        NodoDoble * tmp = amigos->primerNodo;
        do{
            if(amigosPosibles->esta(tmp->persona->id)){
                if(aleatorio(0,100) <= 70) return true;
            }
            tmp = tmp->siguiente;
        } while(tmp != amigos->primerNodo);
    }
    return false;
}


void Mundo::imprimir(){
    if(!listaPersonas->isEmpty()){
        NodoDoble * tmp = listaPersonas->primerNodo;
        do{
            qDebug() << "ID: " << tmp->persona->id;
            qDebug() << "Nombre: " + tmp->persona->nombre;
            qDebug() << "Apellido: " + tmp->persona->apellido;
            qDebug() << "Deporte: " + tmp->persona->deportes;
            qDebug() << "Creencia: " + tmp->persona->creencia;
            qDebug() << "Vivo: " << tmp->persona->vivo;
            qDebug() << "Hijos: ";
            NodoDoble* hijo = tmp->persona->hijos->primerNodo;
            for (int i=0; i<tmp->persona->hijos->largo(); i++) {
                qDebug() << "    ID: " << hijo->persona->id;
                qDebug() << "    Nombre: " << hijo->persona->nombre;
                hijo = hijo->siguiente;
            }
            qDebug() << "Amigos: ";
            NodoDoble* amigos = tmp->persona->amigos->primerNodo;
            for (int i=0; i<tmp->persona->amigos->largo(); i++) {
                qDebug() << "    ID: " << amigos->persona->id;
                qDebug() << "    Nombre: " << amigos->persona->nombre;
                qDebug() << "    Vivo: " << amigos->persona->vivo;
                amigos = amigos->siguiente;
            }
            // Imprimir los pecados (temporal)
            for (int i = 0; i < 7; i++) {
                qDebug() << "Pecado [" << i << "] = " << tmp->persona->accionesMalas[i];
            }
            // Imprimir nuevo atributo 'cantPecados'
            qDebug() << "Cantidad de pecados : [ " << tmp->persona->cantPecados << " ]";
            qDebug() << "";
              tmp = tmp->siguiente;
        } while(tmp != listaPersonas->primerNodo);
    }
}

// =====================================    PANTALLAS   =====================================================

void Mundo::imprimirPantalla() {
    if (!listaPersonas->isEmpty()) {
        NodoDoble* tmp = listaPersonas->primerNodo;
        do {

        }
    }
}

// ==========================================================================================================
int Mundo::contarMuertos(){
    NodoDoble * tmp = listaPersonas->primerNodo;
    int contador = 0;
    do{
        if (tmp->persona->vivo == false)contador++;
        tmp = tmp->siguiente;
    }while(tmp != listaPersonas->primerNodo);
    return contador;
}

int Mundo::contarVivos(){
    NodoDoble * tmp = listaPersonas->primerNodo;
    int contador = 0;
    do{
        if (tmp->persona->vivo == true)contador++;
        tmp = tmp->siguiente;
    }while(tmp != listaPersonas->primerNodo);
    return contador;
}

void Mundo::llenarHeap() {
    if (!listaPersonas->isEmpty()) {
        NodoDoble* tmp = listaPersonas->primerNodo;
        do {
            arbolHeap->insertar(tmp);
            tmp = tmp->siguiente;
        } while (tmp != listaPersonas->primerNodo);
    }
    return;
}

void Mundo::llenarHeap(Heap *heapNuevo) {
    if (!listaPersonas->isEmpty()) {
        NodoDoble* tmp = listaPersonas->primerNodo;
        do {
            heapNuevo->insertar(tmp);
            tmp = tmp->siguiente;
        } while (tmp != listaPersonas->primerNodo);
    }
    return;
}



