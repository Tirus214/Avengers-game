#include "arbol.h"


void Arbol::insertar(NodoDoble* nodo)
{
     raiz = insertar(nodo, raiz);
}

//  INSERTA RECURSIVAMENTE
NodoArbol* Arbol::insertar(NodoDoble* nodo, NodoArbol* nodoArbol){
    // cuando el NodoArbol es nulo, raiz o hijos de hojas
    //quiere decir que allí debe
   // ubicar el valor, en un nuevo NodoArbol

      if (nodoArbol == NULL){
          return new NodoArbol(nodo);
      }
      // si el valor es mayor,
      //llama recursivamente a insertar en el hijo
      // derecho
      else if (nodoArbol->nodoPersona->persona->id < nodo->persona->id)
      {
        nodoArbol->hijoIzquierdo = insertar(nodo, nodoArbol->hijoDerecho);
      }
      // en caso contrario, va al lado izquierdo
      else if (nodoArbol->nodoPersona->persona->id >= nodo->persona->id)
      {
         nodoArbol->hijoIzquierdo = insertar(nodo, nodoArbol->hijoIzquierdo);
      }

      return nodoArbol;
}




int Arbol::contadorNodos(NodoArbol* NodoArbol)
{
     if (NodoArbol == NULL)
        return 0;
     else
         return 1+ contadorNodos(NodoArbol->hijoDerecho)+contadorNodos(NodoArbol->hijoIzquierdo);
}




// BUSCA UN VALOR EN EL ARBOL ORDENADO
NodoDoble* Arbol::buscar(int id, NodoArbol* nodoArbol){
     // cuando el NodoArbol es nulo, quiere decir que allí debe
     // ubicar el valor, en un nuevo NodoArbol
     if (nodoArbol == NULL)
     {
         return NULL;
     }
     else if (nodoArbol->nodoPersona->persona->id == id)
     {
        return nodoArbol->nodoPersona;
     }
     // si el valor es mayor, llama recursivamente a insertar en el hijo
     // derecho
     else if (nodoArbol->nodoPersona->persona->id < id)
     {
         return buscar(id, nodoArbol->hijoDerecho);
     }
     // en caso contrario, va al lado izquierdo
     else if (nodoArbol->nodoPersona->persona->id > id)
     {
        return buscar(id, nodoArbol->hijoIzquierdo);
     }
 }



 // cantidad de elementos de un arbol binario
 int Arbol::obtenerNumeroElementos(NodoArbol* NodoArbol)
 {
     int num_elems = 0;

     if(NodoArbol != NULL)
     {
        num_elems += obtenerNumeroElementos(NodoArbol->hijoizquierdo);
        num_elems++; // contabilizar el NodoArbol visitado
        num_elems += obtenerNumeroElementos(NodoArbol->hijoderecho);
    }
    return num_elems;
 }


 // obtiene la altura
//Altura. La altura de un árbol se define como el
//nivel del NodoArbol de mayor nivel. Como cada NodoArbol de un árbol
//puede considerarse a su vez como la raíz de un árbol, también
//podemos hablar de altura de ramas; el máximo número de NodoArbols
//que hay que recorrer para llegar de la raíz a una de las hojas.

  int Arbol::obtenerAltura(NodoArbol* NodoArbol) {

      // resultado
    int altura    = 0;

    // referencias hi e hd
    NodoArbol* ref_h_izq;
    NodoArbol* ref_h_der;

    // resultado de alturas de hi e hd
    int altura_r_izq = 0;
    int altura_r_der = 0;

    //
    if(NodoArbol != NULL) {
        // incia en 1 para contar la raiz
        altura = 1;

        // inicialiaza las referencias
        ref_h_izq = NodoArbol->hijoizquierdo;
        ref_h_der = NodoArbol->hijoderecho;

        // si ninguno de los hijos es nulo
        if( (ref_h_izq != NULL) && (ref_h_der != NULL) ) {
            // obtiene las alturas de cada arbol izq y der
            altura_r_izq = obtenerAltura(ref_h_izq);
            altura_r_der = obtenerAltura(ref_h_der);

            // suma la altura mayor, para determinar el mayor nivel
            if(altura_r_izq >= altura_r_der)
            {
                altura += altura_r_izq;
            }
            else
            {
                altura += altura_r_der;
            }
        // hizq no es nulo, suma altura de hijo izquierdo
        }
        else if( (ref_h_izq != NULL) && (ref_h_der == NULL) )
        {
            altura += obtenerAltura(ref_h_izq);
        }
        // hder no es nulo, suma altura de hijo derecho
        else if( (ref_h_izq == NULL) && (ref_h_der != NULL) )
        {
            altura += obtenerAltura(ref_h_der);
        }
        // cuando ambos son nulos, resta el uno con el que empezó
        else if( (ref_h_izq == NULL) && (ref_h_der == NULL) )
        {
            altura -= 1;
        }
    }
    // retorna el resultado
    return altura;

}

int maximo (int a, int b)
{
    if (a>b)
       return a;
       else return b;
}

int Arbol::altura (NodoArbol* NodoArbol)
{
    if (NodoArbol == NULL)
        return -1;
    else
         return 1 + maximo(altura(NodoArbol->hijoizquierdo),altura(NodoArbol->hijoderecho));
}

int Arbol::cantNodoArbols2 (NodoArbol* NodoArbol)
{
    if (NodoArbol == NULL)
        return 0;
    else
         return 1 + cantNodoArbols2(NodoArbol->hijoizquierdo)+cantNodoArbols2(NodoArbol->hijoderecho);
}



int Arbol::cantHojas(NodoArbol* raiz)
{
    if (raiz == NULL)
       return 0;
    else if (raiz->hijoderecho == NULL && raiz->hijoizquierdo==NULL)
         return 1;
    else
        return cantHojas(raiz->hijoderecho)+cantHojas(raiz->hijoizquierdo);

}






// borrar
 NodoArbol* Arbol::mayor (NodoArbol* arbol)
  {
    if (arbol == NULL)
        return NULL;
    else if (arbol->hijoderecho == NULL)
        return arbol;
    else
        return mayor (arbol->hijoderecho);
  }


NodoArbol* Arbol::borrarElemento(int ele)
{
      raiz = borrarElemento(ele, raiz);
      return raiz;
}

NodoArbol* Arbol::borrarElemento(int ele, NodoArbol* arbol)
    {
        if (arbol == NULL)
        {
            return NULL;
        }
        else if (ele < arbol->dato)
            arbol->hijoizquierdo = borrarElemento(ele, arbol->hijoizquierdo);
        else if (ele > arbol->dato)
            arbol->hijoderecho = borrarElemento(ele, arbol->hijoderecho);
        else if (arbol->hijoizquierdo == NULL && arbol->hijoderecho == NULL)
            arbol = NULL;
        else if (arbol->hijoizquierdo == NULL)
            arbol = arbol->hijoderecho;
        else if (arbol->hijoderecho == NULL)
            arbol = arbol->hijoizquierdo;
        else{
            NodoArbol* max = mayor(arbol->hijoizquierdo); // mayor de los menores
            arbol->hijoizquierdo = borrarElemento(max->dato, arbol->hijoizquierdo);
            arbol->dato = max->dato;
        }
        return arbol;
    }
