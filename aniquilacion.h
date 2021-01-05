#ifndef ANIQUILACION_H
#define ANIQUILACION_H
#include "heap.h"
#include "mundo.h"


struct CorvusGlaive {
    Heap * heap;
    Mundo * mundo;

    CorvusGlaive (Mundo * _mundo) {
        heap = new Heap();
        mundo = _mundo;
    }


};

#endif // ANIQUILACION_H
