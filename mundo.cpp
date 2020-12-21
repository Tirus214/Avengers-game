#include "mundo.h"
#include "QRandomGenerator64"


void Mundo::crearPersonas(int num){
    for(int i=0; i<num; i++) {
        int id = aleatorio(0,10000000);
        while(listaPersonas->esta(num)){
            id = aleatorio(0,10000000);
        }
        listaPersonas->insertarAlFinal(new Persona(id));
    }
}


int Mundo::aleatorio(int min, int max){
   std::uniform_int_distribution<int> distribution(min, max);
   return distribution(*QRandomGenerator::global());
}


void Mundo::obtenerArray(QString nombre, QString *array){
    fileManager->leer(nombre);
    makeStaticArray(fileManager->array, array);
}


void Mundo::makeStaticArray(QStringList arrayList, QString *arreglo){
    for(int i=0; i<arrayList.length(); i++){
        arreglo[0] = arrayList[0];
    }
}


void Mundo::imprimir(){
    for(int i=0; i<listaApellidos->length(); i++){
        qDebug() << listaApellidos[i] + "\n";
    }
}
