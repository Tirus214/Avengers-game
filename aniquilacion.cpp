#include "aniquilacion.h"


//===============================CORVUS GLAIVE=====================================================

void CorvusGlaive::imprimir(){
    if (heap->isEmpty()) {
        return;
    } else {
        NodoHeap* tmp = heap->primerNodo;
        while (tmp != NULL) {
            qDebug() << " [ #" << tmp->indice << " ID: " << tmp->nodoDoble->persona->id << " C.Pecados: " << tmp->nodoDoble->persona->cantPecados << " ] ->";
            tmp = tmp->siguiente;
        }
        qDebug() << "\n";
        return;
    }
}


void CorvusGlaive::acomodarHeap(NodoHeap* hijo) {
    if (hijo == heap->primerNodo) {
        return;
    } else {
        // Averiguar el padre
        NodoHeap* padre = heap->getPadre(hijo);
        // Comparamos hijo con padre
        if (hijo->nodoDoble->persona->cantPecados > padre->nodoDoble->persona->cantPecados) {
//            int siguienteIndice = padre->indice;
//            heap->swap(hijo,padre);
//            acomodarHeap(heap->buscarIndice(siguienteIndice));
            acomodarHeap(heap->swapConReturnNodos(hijo,padre));
        }
        return;
    }
}

void CorvusGlaive::insertarAHeap_aux(NodoDoble* nodo) {
    NodoHeap* nuevo = new NodoHeap(nodo);
    if (heap->isEmpty()) {
        nuevo->indice = heap->contador + 1;
        heap->primerNodo = heap->ultimoNodo = nuevo;
        heap->contador++;
        return;
    } else {
        NodoHeap* temp = heap->primerNodo;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        nuevo->indice = heap->contador + 1;
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
        heap->contador++;
        acomodarHeap(nuevo);
        return;
    }
}

void CorvusGlaive::matarPersonas(){
    if (heap->isEmpty()) {
        return;
    }
    else {
        contadorUltimaCorrida = 0;
        int cantidadAEliminar = (heap->contador/2)*0.05;
        NodoHeap* tmp = heap->primerNodo;
        for (int i = 0; i < cantidadAEliminar; i++){
            if(tmp->nodoDoble->persona->estadoActual == "Vivo"){
                contadorUltimaCorrida++;
                tmp->nodoDoble->persona->estadoActual = "Muerto";
                // Hago un record de quien lo mato
                tmp->nodoDoble->persona->situacion = "Eliminado por Corvus Glaive";
                tmp->nodoDoble->persona->cantEliminaciones = tmp->nodoDoble->persona->cantEliminaciones+1;
                contador++;
                mundo->logMuertes->insertarMuerte(tmp->nodoDoble->persona, "Corvus Glaive por ser del 5% mas pecador con una suma de: " +
                                                  QString::number(tmp->nodoDoble->persona->sumaPecados()) );
            }
            tmp = tmp->siguiente;
        }
        return;
    }
}

void CorvusGlaive::insertarAHeap() {
    if (!mundo->listaPersonas->isEmpty()) {
        NodoDoble* tmp = mundo->listaPersonas->primerNodo;
        do {
            insertarAHeap_aux(tmp);
            tmp = tmp->siguiente;
        } while (tmp != mundo->listaPersonas->primerNodo);
    }
    return;
}


//================================MIDNIGHT=====================================================

void Midnight::acomodarHeap(NodoHeap * hijo){
    if (heap->isEmpty()) {
        return;
    } else {
        NodoHeap* padre = NULL;
        padre = heap->getPadre(hijo);
        while (hijo->nodoDoble->persona->cantAccionesBuenas < padre->nodoDoble->persona->cantAccionesBuenas){
            heap->swapConReturnNodos(hijo,padre);
            hijo = padre;
            padre = heap->getPadre(hijo);
            if (padre == NULL) break;
        }
    }
}

void Midnight::recorrerHeap(){
    if (heap->isEmpty()) {
        return;
    } else {
        NodoHeap * tmp = heap->primerNodo;
        if (tmp->anterior == NULL && tmp->siguiente == NULL) return;
        while (tmp != NULL) {
            if (heap->getPadre(tmp) != NULL)
            acomodarHeap(tmp);
            tmp = tmp->siguiente;
        }
    }
}


void Midnight::matarPersonas(){
    if (heap->isEmpty()) {
        return;
    }
    else {
        contadorUltimaCorrida = 0;
        int cantidadAEliminar = (heap->contador/2)*0.05;
        NodoHeap* tmp = heap->primerNodo;
        for (int i = 0; i < cantidadAEliminar; i++){
            if(tmp->nodoDoble->persona->estadoActual == "Vivo"){
                tmp->nodoDoble->persona->estadoActual = "Muerto";
                tmp->nodoDoble->persona->situacion = "Eliminado por Midnight";
                tmp->nodoDoble->persona->cantEliminaciones = tmp->nodoDoble->persona->cantEliminaciones+1;
                contadorUltimaCorrida++;
                contador++;
                mundo->logMuertes->insertarMuerte(tmp->nodoDoble->persona, "Midnight por ser del 5% menos acciones buenas con una suma de: " +
                                                  QString::number(tmp->nodoDoble->persona->sumaAccionesBuenas()) );
            }
            tmp = tmp->siguiente;
        }
        return;
    }
}

void Midnight::imprimir(){
    if (heap->isEmpty()) {
        return;
    } else {
        NodoHeap* tmp = heap->primerNodo;
        while (tmp != NULL) {
            qDebug() << " [ #" << tmp->indice << " ID: " << tmp->nodoDoble->persona->id << " Acciones buenas: " << tmp->nodoDoble->persona->cantAccionesBuenas << "Estado:" << tmp->nodoDoble->persona->estadoActual << " ] ->";
            tmp = tmp->siguiente;
        }
        qDebug() << "\n";
        return;
    }
}



//===============================NEBULA=====================================================



NodoDoble* Nebula::randNodoArbol(){
    int random = mundo->aleatorio(0,tamanoArbol);
    if (arbolEntrada->isEmpty()) {
        return NULL;
    }
    else {
        if (random == 0) return arbolEntrada->primerNodo->nodoDoble;
        NodoHeap* tmp = arbolEntrada->primerNodo;
        for (int i = 0; i < random; i++){
            tmp = tmp->siguiente;
        }
        nodoSeleccionado = tmp->nodoDoble;
        contadorUltimaCorrida = 0;
        return tmp->nodoDoble;
    }
}


void Nebula::matarPersonas(NodoDoble * raiz, int idAnterior){
    if (raiz == NULL) return;
    if (raiz->persona->estadoActual == "Muerto" && revisarLista(raiz->persona->amigos) == false) return;
    else {
        idAnterior = raiz->persona->id;
        if (raiz->persona->estadoActual == "Vivo"){
            raiz->persona->estadoActual = "Muerto";
            raiz->persona->situacion = "Eliminado por Nebula";
            raiz->persona->cantEliminaciones = raiz->persona->cantEliminaciones+1;
            contadorUltimaCorrida++;
            contador++;
            mundo->logMuertes->insertarMuerte(raiz->persona, "Nebula por ser amigo del humano con ID: " +
                                              QString::number(idAnterior) );

        }
        NodoDoble * tmp = raiz->persona->amigos->primerNodo;
        for(int i = 0; i < raiz->persona->amigos->largo(); i++){
            matarPersonas(tmp, idAnterior);
            tmp = tmp->siguiente;
        }
        return;
    }
}

bool Nebula::revisarLista(ListaDoble * listaAmigos){
    if (listaAmigos->isEmpty()) return false;
    else{
        NodoDoble * tmp = listaAmigos->primerNodo;
        do{
            if (tmp->persona->estadoActual == "Vivo") return true;
        }while(tmp != listaAmigos->primerNodo);
        return false;
    }
}

void Dwarf::matarPersonas(){
    if (listaPersona->isEmpty()) {
        return;
    }
    else {
        contadorUltimaCorrida = 0;
        NodoDoble * tmp =  listaPersona->primerNodo;
        int contadorTotalDeportes = 0;
        do{
            if(tmp->persona->deportes == deporteSeleccionado && tmp->persona->salud > deporteRepeticiones) contadorTotalDeportes++;
            tmp = tmp->siguiente;
        }while(tmp != listaPersona->primerNodo);
        int eliminacionesPorRealizar = contadorTotalDeportes / 2;
        int contadorEliminados = 0;
        do{
            if(tmp->persona->deportes == deporteSeleccionado && tmp->persona->salud > deporteRepeticiones){
                contadorEliminados++;
                if (tmp->persona->estadoActual == "Vivo"){
                    contadorUltimaCorrida++;
                    tmp->persona->estadoActual = "Muerto";
                    tmp->persona->situacion = "Eliminado por Dwarf";
                    tmp->persona->cantEliminaciones = tmp->persona->cantEliminaciones+1;
                    contador++;
                    mundo->logMuertes->insertarMuerte(tmp->persona, "Dwarf por practicar el deporte" + deporteSeleccionado +"mas de " +
                                                      deporteRepeticiones + " veces por semana");
                }

                if (contadorEliminados >= eliminacionesPorRealizar) return;
            }
            tmp = tmp->siguiente;
        }while(tmp != listaPersona->primerNodo);
        return;
    }
}






//===============================THANOS=====================================================


void Thanos::addListas(){
    for (int i = 0; i <= 70; i++){
        for(int j = 0; j <= 9; j++){
            matrizDispersion[i][j] = new ListaDoble();
        }
    }
}

void Thanos::recorrerLista(){
    if (listaPersona->isEmpty()) {
        return;
    }
    else{
        addListas();
        NodoDoble * tmp = listaPersona->primerNodo;
        do{
            int resultadoHash = hashFunction(tmp);
            insertar(2020-tmp->persona->fechaNacimiento[0], resultadoHash, tmp);
            tmp = tmp->siguiente;
        }while(tmp != listaPersona->primerNodo);
        return;
    }
}

int Thanos::hashFunction(NodoDoble * analizado){
    Persona * personaAnalizada = analizado->persona;
    int puntos = 9;
    if (personaAnalizada->cantPecados >= 1600) puntos = puntos - 4;
    if (personaAnalizada->hijos->largo() >= 2) puntos--;
    if (personaAnalizada->estadoMarital == "Soltero")puntos = puntos - 2;
    else if (personaAnalizada->estadoMarital == "Divorciado") puntos--;
    if (personaAnalizada->longevidad > 35) puntos--;
    else if (personaAnalizada->longevidad > 55) puntos = puntos - 2;
    return puntos;
}

void Thanos::insertar(int anioNacimiento, int resultadoHash, NodoDoble * personaInsertada){
    matrizDispersion[anioNacimiento][resultadoHash]->insertarAlFinal(personaInsertada->persona);
}

void Thanos::eliminarCasilla(ListaDoble * casillaEliminada, int ano, int nivel){
    if (casillaEliminada->isEmpty()) return;
    else{
        contadorUltimaCorrida = 0;
        NodoDoble * tmp = casillaEliminada->primerNodo;
        do {
            if (tmp->persona->estadoActual == "Vivo"){
                eliminados++;
                contadorUltimaCorrida++;
                tmp->persona->estadoActual = "Muerto";
                tmp->persona->situacion = "Eliminado por Thanos";
                tmp->persona->cantEliminaciones = tmp->persona->cantEliminaciones+1;
                tmp = tmp->siguiente;
                mundo->logMuertes->insertarMuerte(tmp->persona, "Thanos por estar en el nivel " + QString::number(nivel) +
                                                  " y nacer en el año " + QString::number(ano));
            }
        }while(tmp != casillaEliminada->primerNodo);
    }
}

void Thanos::comandoThanos(int anio, int nivelHash){
    if (anio == -1){
        for(int i = 0; i <= 70; i++){
            eliminarCasilla(matrizDispersion[i][nivelHash], i, nivelHash);
        }
    }
    else if (nivelHash == -1){
        for(int i = 0; i <= 9; i++){
            eliminarCasilla(matrizDispersion[anio][i], anio, i);
        }
    }
    else eliminarCasilla(matrizDispersion[anio][nivelHash], anio, nivelHash);
}

void Thanos::imprimir(){
    for(int i = 0; i <= 69; i++){
        for(int j = 0; j <= 9; j++){
            ListaDoble * listaImpresa = matrizDispersion[i][j];
            if (!listaImpresa->isEmpty()){
                NodoDoble * tmp = listaImpresa->primerNodo;
                do{
                    qDebug() << "Anio nacimiento: " << 2021 - i;
                    qDebug() << "Nivel de utilidad (Entre más alto, mejor): " << j;
                    qDebug() << "Edad: " << tmp->persona->longevidad;
                    qDebug() << "Estado actual " << tmp->persona->estadoActual;
                } while(tmp != listaImpresa->primerNodo);
            }
            else qDebug() << "La lista en los valores " << i <<", "<< j << " está vacía";
        }
    }
}

// =================================== Ebony Maw ===========================================
