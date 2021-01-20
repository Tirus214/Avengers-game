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


int Persona::sumaPecados(){
    int resul = 0;
    for (int i=0; i<7; i++) {
        resul += accionesMalas[i];
    }
    return resul;
}

int Persona::sumaAccionesBuenas(){
    int resul = 0;
    for (int i=0; i<7; i++) {
        resul += accionesBuenas[i];
    }
    return resul;
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



NodoDoble * ListaDoble::insertarSorted(NodoDoble *& head ,Persona * nuevaPersona){
        NodoDoble * ins = new NodoDoble(nuevaPersona);
        NodoDoble * itr = head;
        if (head == NULL) {
            ins->siguiente = ins;
            ins->anterior = ins;
            head = ins;
            index++;
            return head;
        }
        //case: at begining
        else if (head->persona->id < nuevaPersona->id){
            head->anterior->siguiente = ins;
            ins->anterior = head->anterior;
            ins->siguiente = head;
            head->anterior = ins;
            head = ins;
            index++;
            return ins;
        }
        else {
            while (itr->persona->id > nuevaPersona->id) {
                // case: at end of list
                if (itr->siguiente == head) {
                    ins->siguiente = head;
                    ins->anterior = itr;
                    itr->siguiente = ins;
                    head->anterior = ins;
                    index++;
                    return ins;
                }
                else {
                    itr = itr->siguiente;
                }
            }
            // case: middle
            itr->anterior->siguiente = ins;
            ins->anterior = itr->anterior;
            itr->anterior = ins;
            ins->siguiente = itr;
            index++;
            return ins;
        }
    }


void ListaDoble::sort(NodoDoble * start, int largoLista){
    struct NodoDoble *t, *s;
    int i;

    if (start == NULL) return;

    s = start;
    for(i = 0;i < largoLista; i++){
        t = s->siguiente;
        while(t != start){
            if (s->persona->id < t->persona->id){
                std::swap(s->persona, t->persona);
            }
            t = t->siguiente;
        }
        s = s->siguiente;
    }
}

void ListaDoble::ordenaLista(NodoDoble *nodo)
{
    int n;
    NodoDoble *actual, *siguienteNodo;

    if(nodo != NULL)
    {
        actual = nodo;
        do
        {
            siguienteNodo = actual->siguiente;
            while(siguienteNodo != nodo)
            {
                if(actual->persona->id < siguienteNodo->persona->id)
                {
                    n = siguienteNodo->persona->id;
                    siguienteNodo->persona->id = actual->persona->id;
                    actual->persona->id = n;
                }
                siguienteNodo = siguienteNodo->siguiente;
            }
            actual = actual->siguiente;
            siguienteNodo = actual->siguiente;
        }
        while(siguienteNodo != nodo);
    }
}

bool ListaDoble::isEmpty(){
    return primerNodo == NULL;
}

void ListaDoble::imprimir(){
    if(!isEmpty()){
        NodoDoble * tmp = primerNodo;
        do{
            tmp = tmp->siguiente;
        } while(tmp != primerNodo);
    }
}

bool ListaDoble::esta(int num){
    if(primerNodo != NULL){   
        NodoDoble * tmp = NULL;
        tmp = primerNodo;
        do{
            if (tmp->persona->id == num) {
                return true;
            }
            if (primerNodo == tmp) return false;
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
//    qDebug() << "Creencia: " + persona->creencia;
//    qDebug() << "Hijos: ";
//    NodoDoble* hijo = persona->hijos->primerNodo;
//    for (int i=0; i < persona->hijos->largo(); i++) {
//        qDebug() << "    ID: " << hijo->persona->id;
//        qDebug() << "    Nombre: " << hijo->persona->nombre;
//    }
//    // Imprimir los pecados (temporal)
//    for (int i = 0; i < 7; i++) {
//        qDebug() << "Pecado [" << i << "] = " << persona->accionesMalas[i];
//    }
//    // Imprimir nuevo atributo 'cantPecados'
//    qDebug() << "Cantidad de pecados : [ " << persona->cantPecados << " ]";
//    qDebug() << "";
}

void NodoDoble::imprimirEspecial(QPlainTextEdit* refPantalla) {
    refPantalla->appendPlainText("\nID [ " + QString::number(persona->id)+ " ]");
    refPantalla->appendPlainText("Nombre: " + persona->nombre);
    refPantalla->appendPlainText("Apellido: " + persona->apellido);
    refPantalla->appendPlainText("Edad: " + QString::number(persona->longevidad));
    if (persona->vivo) {
        refPantalla->appendPlainText("Estado: Vivo");
    } else {
        refPantalla->appendPlainText("Estado: Muerto");
    }
    refPantalla->appendPlainText("Situacion actual: " + persona->situacion);
    refPantalla->appendPlainText("Cantidad de veces eliminad@: " + QString::number(persona->cantEliminaciones));
    refPantalla->appendPlainText("Cantidad de veces salvad@: " + QString::number(persona->cantSalvaciones));
    refPantalla->appendPlainText("Papa: ");
    persona->papa->imprimir(refPantalla);
    refPantalla->appendPlainText("Madre: ");
    persona->mama->imprimir(refPantalla);
    refPantalla->appendPlainText("Hijos: ");
    NodoDoble* hijo = persona->hijos->primerNodo;
    while (hijo != NULL) {
        refPantalla->appendPlainText("  ID: " + QString::number(hijo->persona->id) + " Nombre: " + hijo->persona->nombre);
        hijo = hijo->siguiente;
    }
    for (int i = 0; i < 7; i++) {
        refPantalla->appendPlainText("Pecado [" + QString::number(i) + "] = " + QString::number(persona->accionesMalas[i]));
    }
    refPantalla->appendPlainText("Cantidad de pecados: " + QString::number(persona->cantPecados) + " Cantidad de acciones buenas: " + QString::number(persona->cantAccionesBuenas) );
    refPantalla->moveCursor(QTextCursor::End);

//    qDebug() << "ID [ " << persona->id << " ]";
//    qDebug() << "Nombre: " << persona->nombre;
//    qDebug() << "Apellido: " << persona->apellido;
//    qDebug() << "Edad: " << persona->longevidad;
//    qDebug() << "Vivo: " << persona->vivo;

//    qDebug() << "Situacion actual: " << persona->situacion;
//    qDebug() << "Cantidad de veces eliminad@: " << persona->cantEliminaciones;
//    qDebug() << "Cantidad de veces salvad@: " << persona->cantSalvaciones;
//    qDebug() << "Creencia: " << persona->creencia;
//    qDebug() << "Papa: ";
//    persona->papa->imprimir();
//    qDebug() << "Madre: ";
//    persona->mama->imprimir();
//    qDebug() << "Hijos: { ";
//    NodoDoble* hijo = persona->hijos->primerNodo;
//    for (int i=0; i < persona->hijos->largo(); i++) {
//        qDebug() << "    ID: " << hijo->persona->id;
//        qDebug() << "    Nombre: " << hijo->persona->nombre;
//        hijo = hijo->siguiente;
//    }
    // Imprimir los pecados (temporal)
//    for (int i = 0; i < 7; i++) {
//        qDebug() << "Pecado [" << i << "] = " << persona->accionesMalas[i];
//    }
//    // Imprimir nuevo atributo 'cantPecados'
//    qDebug() << "Cantidad de pecados : [ " << persona->cantPecados << " ]";
//    qDebug() << "";

}

void NodoDoble::imprimirFamilia(QPlainTextEdit* refPantalla) {

    refPantalla->appendPlainText("\nID [ " + QString::number(persona->id)+ " ]");
    refPantalla->appendPlainText("Nombre: " + persona->nombre);
    refPantalla->appendPlainText("Apellido: " + persona->apellido);
    refPantalla->appendPlainText("Edad: " + QString::number(persona->longevidad));
    if (persona->vivo) {
        refPantalla->appendPlainText("Estado: Vivo");
    } else {
        refPantalla->appendPlainText("Estado: Muerto");
    }
    refPantalla->appendPlainText("Situacion actual: " + persona->situacion);
    refPantalla->appendPlainText("Cantidad de veces eliminad@: " + QString::number(persona->cantEliminaciones));
    refPantalla->appendPlainText("Cantidad de veces salvad@: " + QString::number(persona->cantSalvaciones));
    refPantalla->appendPlainText("  Padre:\n");
    persona->papa->imprimir2(refPantalla);
    refPantalla->appendPlainText("  Madre:\n");
    persona->mama->imprimir2(refPantalla);
    refPantalla->appendPlainText("  Hijos:\n");
    NodoDoble* hijo = persona->hijos->primerNodo;
    while (hijo != NULL) {
        hijo->persona->imprimir2(refPantalla);
        hijo = hijo->siguiente;
    }
    refPantalla->moveCursor(QTextCursor::End);

//    qDebug() << "ID [ " << persona->id << " ]";
//    qDebug() << "Nombre: " << persona->nombre;
//    qDebug() << "Apellido: " << persona->apellido;
//    qDebug() << "Edad: " << persona->longevidad;
//    qDebug() << "vivo: " << persona->vivo;
//    qDebug() << "Situacion actual: " << persona->situacion;
//    qDebug() << "Cantidad de veces eliminad@: " << persona->cantEliminaciones;
//    qDebug() << "Cantidad de veces salvad@: " << persona->cantSalvaciones;
//    // Padre
//    qDebug() << " Padre: ";
//    persona->papa->imprimir2();
//    qDebug() << " Madre: ";
//    persona->mama->imprimir2();
//    qDebug() << " Hijos: ";
//    NodoDoble* hijo = persona->hijos->primerNodo;
//    while (hijo != NULL) {
//        hijo->persona->imprimir2();
//    }

}

void Persona::imprimir(QPlainTextEdit* refPantalla) {
//    qDebug() << "ID [ " << id << " ]";
//    qDebug() << "Nombre: " << nombre << " Apellido: " << apellido;
    refPantalla->appendPlainText("\nID [" + QString::number(id) + "] Nombre: " + nombre + " Apellido: " + apellido);
    refPantalla->moveCursor(QTextCursor::End);
}

void Persona::imprimir2(QPlainTextEdit* refPantalla) {
    refPantalla->appendPlainText("\nID [ " + QString::number(id) + " ]");
    refPantalla->appendPlainText("Nombre: " + nombre + " Apellido: " + apellido + " Edad: " + QString::number(longevidad));
    if (vivo) {
        refPantalla->appendPlainText("Estado: Vivo");
    } else {
        refPantalla->appendPlainText("Estado: Muerto");
    }
    refPantalla->appendPlainText("Cantidad de veces eliminad@: " + QString::number(cantEliminaciones) + " Cantidad de veces salvad@: " + QString::number(cantSalvaciones));
    refPantalla->moveCursor(QTextCursor::End);

//    qDebug() << "ID [ " << id << " ]";
//    qDebug() << "Nombre: " << nombre << " Apellido: " << apellido;
//    qDebug() << "Edad: " << longevidad;
//    qDebug() << "Vivo: " << vivo;
//    qDebug() << "Situacion actual: " << situacion;
//    qDebug() << "Cantidad de veces eliminad@: " << cantEliminaciones;
//    qDebug() << "Cantidad de veces salvad@: " << cantSalvaciones;
}

void NodoDoble::imprimirAmigos(QPlainTextEdit* refPantalla) {
    refPantalla->appendPlainText("\nID [ " + QString::number(persona->id)+ " ]");
    refPantalla->appendPlainText("Nombre: " + persona->nombre);
    refPantalla->appendPlainText("Apellido: " + persona->apellido);
    refPantalla->appendPlainText("Edad: " + QString::number(persona->longevidad));
    if (persona->vivo) {
        refPantalla->appendPlainText("Estado: Vivo");
    } else {
        refPantalla->appendPlainText("Estado: Muerto");
    }
    refPantalla->appendPlainText("Situacion actual: " + persona->situacion);
    refPantalla->appendPlainText("Cantidad de veces eliminad@: " + QString::number(persona->cantEliminaciones));
    refPantalla->appendPlainText("Cantidad de veces salvad@: " + QString::number(persona->cantSalvaciones));
    refPantalla->appendPlainText("  Amigos:\n");
    NodoDoble* amigo = persona->amigos->primerNodo;
    while (amigo != NULL) {
        amigo->persona->imprimir2(refPantalla);
        amigo = amigo->siguiente;
    }
    refPantalla->moveCursor(QTextCursor::End);
    return;
}
