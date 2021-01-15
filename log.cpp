#include "log.h"

void Log::getFechaYHora(){
    dia = QDate::currentDate().day();
    mes = QDate::currentDate().month();
    ano = QDate::currentDate().year();
    fecha = QString::number(ano) + "-" + QString::number(mes) + "-" + QString::number(dia);

    hora = QTime::currentTime().hour();
    minutos = QTime::currentTime().minute();
    segundos = QTime::currentTime().second();
    tiempo = QString::number(hora) + "-" + QString::number(minutos) + "-" + QString::number(segundos);
}


void Log::insertarMuerte(Persona* persona, QString nota){
    historico.append(fecha + " " + tiempo + "   Humano " + QString::number(persona->id) + " " + persona->nombre +
                     " " + persona->apellido + " " + persona->pais + " " + "Amigos [ " + getAmigos(persona) + " ] " +
                     "Pareja ID: " +QString::number(persona->conyugue->id) + " " + persona->conyugue->nombre + " " +
                     persona->conyugue->apellido + " Familia [ " + getFamilia(persona) + " ] " + "Murio el " + fecha +
                     " aniquilidado por " + nota);
}


void Log::insertarSalvacion(Persona* persona, QString nota){
    historico.append(fecha + " " + tiempo + "   Humano " + QString::number(persona->id) + " " + persona->nombre +
                     " " + persona->apellido + " " + persona->pais + " " + "Amigos [ " + getAmigos(persona) + " ] " +
                     "Pareja ID: " +QString::number(persona->conyugue->id) + " " + persona->conyugue->nombre + " " +
                     persona->conyugue->apellido + " Familia [ " + getFamilia(persona) + " ] " + "Fue salvado el " + fecha +
                     " salvado por " + nota);
}


QString Log::getAmigos(Persona* persona){
    QString resul = " ";
    if(!persona->amigos->isEmpty()){
        NodoDoble * tmp = persona->amigos->primerNodo;
        do{
            resul = resul + "ID: " + QString::number(tmp->persona->id) + " " + tmp->persona->nombre + " " + tmp->persona->apellido + " ";
            tmp = tmp->siguiente;
        } while(tmp != persona->amigos->primerNodo);
    }
    return resul;
}

QString Log::getFamilia(Persona* persona){
    QString resul = " ";
    resul = resul + "Papa ID: " +QString::number(persona->papa->id) + " " + persona->papa->nombre + " " + persona->papa->apellido + " ";
    resul = resul + "Mama ID: " +QString::number(persona->mama->id) + " " + persona->mama->nombre + " " + persona->mama->apellido + " ";
    if(!persona->amigos->isEmpty()){
        NodoDoble * tmp = persona->hijos->primerNodo;
        do{
            resul = resul + "ID: " +QString::number(tmp->persona->id) + " " + tmp->persona->nombre + " " + tmp->persona->apellido;
            tmp = tmp->siguiente;
        } while(tmp != persona->hijos->primerNodo);
    }
    return resul;
}

QString Log::getExperiencia(Persona* persona){
    QString resul = " ";
    if(!persona->paises.isEmpty()){
        for (int i=0; i<persona->paises.length(); i++) {
            resul = resul + persona->paises[i] + " ";
        }
    }
    return resul;
}
