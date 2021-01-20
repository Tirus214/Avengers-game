#include "salvacion.h"

void Antman::getHormigas(){
    mundo->fileManager->leer2("Hormigas", hormigas);
}

void Antman::setHormigas(int num){
    cantidadHormigas = num;
}

void Antman::dejarFeromonas(){
    if (arbolEntrada->isEmpty(arbolEntrada->raiz)) return;
    else {
        clearFeromonas(arbolEntrada->raiz);
        getHormigas();
        NodoArbol * tmp = NULL;
        for(int i = 0;i < 2; i++){
            int aleatorio = 0;
            if (i == 0) tmp = arbolEntrada->raiz->hijoIzquierdo;
            else if (i == 1) tmp = arbolEntrada->raiz->hijoDerecho;
            for (int i = 0; i <= cantidadHormigas; i++){
                while(tmp != NULL){
                    aleatorio = mundo->aleatorio(0,100);
                    tmp->feromonas = tmp->feromonas + 1;
                    if (0 <= aleatorio && aleatorio > 50 && tmp->hijoIzquierdo != NULL) tmp = tmp->hijoIzquierdo;
                    else tmp = tmp->hijoDerecho;
                    hormigas.append("Humano" + QString::number(tmp->nodoPersona->persona->id) + " " +
                                    tmp->nodoPersona->persona->nombre + tmp->nodoPersona->persona->apellido +
                                    " alcanzado por la hormiga: " + QString::number(i));
                }
            }
        }
        hormigas.append("=========================================================================================");
        mundo->fileManager->escribir("Hormigas", hormigas);
        inicio = escogerNodo(arbolEntrada->raiz->hijoIzquierdo);
        final = escogerNodo(arbolEntrada->raiz->hijoDerecho);
        salvarPersonas();
    }
    return;
}

void Antman::clearFeromonas(NodoArbol * raiz){
    if (raiz->feromonas == 0 || raiz == NULL) return;
    else{
        raiz->feromonas = 0;
        clearFeromonas(raiz->hijoDerecho);
        clearFeromonas(raiz->hijoIzquierdo);
    }
}

NodoArbol * Antman::escogerNodo(NodoArbol * raiz){
    if(raiz->hijoDerecho == NULL) return raiz;
    else if (raiz->hijoDerecho->feromonas > raiz->hijoIzquierdo->feromonas){
        return escogerNodo(raiz->hijoDerecho);
    }
    else if (raiz->hijoDerecho->feromonas < raiz->hijoIzquierdo->feromonas){
        return escogerNodo(raiz->hijoIzquierdo);
    }
    else if (raiz->hijoDerecho->feromonas == raiz->hijoIzquierdo->feromonas){
        return escogerNodo(desempate(raiz->hijoIzquierdo, raiz->hijoDerecho));
    }
}


void Antman::salvarPersonas(){
    contadorUltimaCorrida = 0;
    NodoDoble * inicioDoble = listaPersonas->buscarPorId(inicio->nodoPersona->persona->id);
    NodoDoble * finalDoble = listaPersonas->buscarPorId(final->nodoPersona->persona->id);
    do{
        if(inicioDoble->persona->vivo == false){
            mundo->totalSalvados++;
            contadorUltimaCorrida++;
            contador++;
            inicioDoble->persona->vivo = true;
            inicioDoble->persona->salvado = true;
            inicioDoble->persona->situacion = "Salvado por Antman";
            inicioDoble->persona->cantSalvaciones = inicioDoble->persona->cantSalvaciones+1;
            mundo->logSalvacion->insertarSalvacion(inicioDoble->persona, "Antman por estar en una de las ramas con mayor rastro de hormigas");
        }
        inicioDoble = inicioDoble->siguiente;
    }while (inicioDoble != finalDoble);
    return;
}



int getMaximo (int a, int b){
    if (a>b)
       return a;
    else if (a==b)
        return a;
       else return b;
}


NodoArbol * Antman::desempate(NodoArbol * izquierdo, NodoArbol * derecho){
    if (izquierdo->hijoIzquierdo == NULL) return izquierdo;
    else if(getMaximo(izquierdo->hijoIzquierdo->feromonas,izquierdo->hijoDerecho->feromonas) > getMaximo(derecho->hijoIzquierdo->feromonas,derecho->hijoDerecho->feromonas)) return izquierdo;
   else return derecho;
}



void Ironman::detonarBombas(){
    if (heapEntrada->isEmpty()) return;
    else {
        contadorUltimaCorrida = 0;
        NodoHeap * tmp = heapEntrada->primerNodo;
        int probabilidadDetonacion = mundo->aleatorio(40,60);
        while (tmp != NULL) {
            int aleatorioBomba = mundo->aleatorio(0,100);
            if (aleatorioBomba <= probabilidadDetonacion){
                salvarAscendientes(tmp->nodoDoble->persona);
                salvarDescendientes(tmp->nodoDoble->persona);
            }
            tmp = tmp->siguiente;
        }
    }
}

void Ironman::salvarAscendientes(Persona * personaAnalizada){
    if (personaAnalizada == NULL) return;
    if (personaAnalizada->vivo == false){
        mundo->totalSalvados++;
        contadorUltimaCorrida++;
        contador++;
        personaAnalizada->vivo = true;
        personaAnalizada->salvado = true;
        personaAnalizada->situacion = "Salvado por Ironman";
        personaAnalizada->cantSalvaciones = personaAnalizada->cantSalvaciones+1;
        mundo->logSalvacion->insertarSalvacion(personaAnalizada, "Ironman por ser pariente de la persona: " + QString::number(personaAnalizada->id)
                                               + " a la que le detono la bomba");
    }
    if (personaAnalizada->papa != nullptr) salvarAscendientes(personaAnalizada->papa);
    if (personaAnalizada->mama != nullptr) salvarAscendientes(personaAnalizada->mama);
    return;
}

void Ironman::salvarDescendientes(Persona * raiz){
    if(raiz == NULL) return;
    else{
        if (raiz->vivo == false){
            mundo->totalSalvados++;
            contadorUltimaCorrida++;
            contador++;
            raiz->vivo = true;
            raiz->salvado = true;
            raiz->situacion = "Salvado por Ironman";
            raiz->cantSalvaciones = raiz->cantSalvaciones+1;
            mundo->logSalvacion->insertarSalvacion(raiz, "Ironman por ser pariente de la persona: " + QString::number(raiz->id)
                                                   + " a la que le detono la bomba");
        }
        NodoDoble * tmp = raiz->amigos->primerNodo;
        for(int i = 0; i < raiz->amigos->largo(); i++){
            salvarDescendientes(tmp->persona);
            tmp = tmp->siguiente;
        }
    }
}



void Thor::obtenerNodoPorNivel(NodoArbol *raiz, int nivelActual, int nivelBuscado){
    if(raiz == NULL) {
          return;
      }
      if(nivelActual == nivelBuscado) {
        salvarPersonas(raiz->nodoPersona->persona->papa);
        salvarPersonas(raiz->nodoPersona->persona->mama);
        NodoDoble * tmp = raiz->nodoPersona->persona->hijos->primerNodo;
        do{
            if (tmp == NULL) break;
            salvarPersonas(tmp->persona);
            tmp = tmp->siguiente;
        }while(tmp != raiz->nodoPersona->persona->hijos->primerNodo);
      }
      obtenerNodoPorNivel(raiz->hijoIzquierdo, nivelActual+1, nivelBuscado);
      obtenerNodoPorNivel(raiz->hijoDerecho, nivelActual+1, nivelBuscado);
}

void Thor::salvarPersonas(Persona * personaSalvada){
    if (personaSalvada == nullptr) return;
    else{
        contadorUltimaCorrida = 0;
        NodoDoble * amigoTmp = personaSalvada->amigos->primerNodo;
        if (amigoTmp == nullptr) return;
        else{
            do{
                if (amigoTmp->persona->vivo == false){
                    mundo->totalSalvados++;
                    contadorUltimaCorrida++;
                    amigoTmp->persona->vivo = true;
                    amigoTmp->persona->salvado = true;
                    amigoTmp->persona->situacion = "Salvado por Thor";
                    amigoTmp->persona->cantSalvaciones = amigoTmp->persona->cantSalvaciones+1;
                    contador++;
                    mundo->logSalvacion->insertarSalvacion(amigoTmp->persona, "Thor por ser amigo de un familiar del humano con ID: " +
                                                           QString::number(personaSalvada->id));
                }
                amigoTmp = amigoTmp->siguiente;
            }while (amigoTmp != personaSalvada->amigos->primerNodo);
        }
    }
    return;
}

void Spiderman::crearTela(){
    if (heapEntrada->primerNodo == nullptr) return;
    else{
        NodoHeap * tmp = heapEntrada->primerNodo;
        int aleatorio = 0;
        contadorTelas = 0;
        NodoHeap * hojaEncontrada = nullptr;
        while(tmp != nullptr){
            aleatorio = mundo->aleatorio(0,100);
            if (aleatorio >= 50){
                contadorTelas++;
                if (heapEntrada->getHijoDerecho(tmp) == nullptr && heapEntrada->getHijoIzquierdo(tmp) == nullptr && hojaEncontrada == nullptr){
                    hojaEncontrada = tmp;
                }
            }
            tmp = tmp->siguiente;
        }
        salvarPersonas(hojaEncontrada);
    }
}

void Spiderman::salvarPersonas(NodoHeap * hoja){
    if (hoja == nullptr) return;
    else{
        contadorUltimaCorrida = 0;
        NodoDoble * inicio = mundo->listaPersonas->buscarPorId(hoja->nodoDoble->persona->id);
        for(int i = 0; i <= contadorTelas; i++){
            if (inicio == nullptr) return;
            if(inicio->persona->vivo == false){
                mundo->totalSalvados++;
                contadorUltimaCorrida++;
                inicio->persona->vivo = true;
                inicio->persona->salvado = true;
                inicio->persona->situacion = "Salvado por Spiderman";
                inicio->persona->cantSalvaciones = inicio->persona->cantSalvaciones+1;
                contador ++;
                mundo->logSalvacion->insertarSalvacion(inicio->persona, "Spiderman por estar a la derecha del humano con ID: " +
                                                       QString::number(hoja->nodoDoble->persona->id));
            }
            inicio = inicio->siguiente;
        }
    }
}

