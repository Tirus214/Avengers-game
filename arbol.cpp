#include "arbol.h"
#include <queue>

NodoArbol * Arbol::crearNodo(NodoDoble * nodo){
    NodoArbol * nuevoNodo = new NodoArbol(nodo);
    nuevoNodo->hijoDerecho = nuevoNodo->hijoIzquierdo = NULL;
    return nuevoNodo;
}

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
        nodoArbol->hijoDerecho = insertar(nodo, nodoArbol->hijoDerecho);
      }
      // en caso contrario, va al lado izquierdo
      else if (nodoArbol->nodoPersona->persona->id >= nodo->persona->id)
      {
         nodoArbol->hijoIzquierdo = insertar(nodo, nodoArbol->hijoIzquierdo);
      }

      return nodoArbol;
}

NodoArbol * Arbol::insertarPorNivel(NodoArbol *&raiz, NodoDoble * valor){
    if (raiz == NULL) {
            raiz = crearNodo(valor);
            return raiz;
        }

        std::queue <NodoArbol *> q;
        q.push(raiz);

        while (!q.empty()) {
            NodoArbol* temp = q.front();
            q.pop();

            if (temp->hijoIzquierdo != NULL)
                q.push(temp->hijoIzquierdo);
            else {
                temp->hijoIzquierdo = crearNodo(valor);
                return raiz;
            }

            if (temp->hijoDerecho != NULL)
                q.push(temp->hijoDerecho);
            else {
                temp->hijoDerecho = crearNodo(valor);
                return raiz;
            }
        }
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
 int Arbol::obtenerNumeroElementos(NodoArbol* nodoArbol)
 {
     int num_elems = 0;

     if(nodoArbol != NULL)
     {
        num_elems += obtenerNumeroElementos(nodoArbol->hijoIzquierdo);
        num_elems++; // contabilizar el NodoArbol visitado
        num_elems += obtenerNumeroElementos(nodoArbol->hijoDerecho);
    }
    return num_elems;
 }


 // obtiene la altura
//Altura. La altura de un árbol se define como el
//nivel del NodoArbol de mayor nivel. Como cada NodoArbol de un árbol
//puede considerarse a su vez como la raíz de un árbol, también
//podemos hablar de altura de ramas; el máximo número de NodoArbols
//que hay que recorrer para llegar de la raíz a una de las hojas.

  int Arbol::obtenerAltura(NodoArbol* nodoArbol) {

      // resultado
    int altura    = 0;

    // referencias hi e hd
    NodoArbol* ref_h_izq;
    NodoArbol* ref_h_der;

    // resultado de alturas de hi e hd
    int altura_r_izq = 0;
    int altura_r_der = 0;

    //
    if(nodoArbol != NULL) {
        // incia en 1 para contar la raiz
        altura = 1;

        // inicialiaza las referencias
        ref_h_izq = nodoArbol->hijoIzquierdo;
        ref_h_der = nodoArbol->hijoDerecho;

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

int Arbol::altura (NodoArbol* nodoArbol)
{
    if (nodoArbol == NULL)
        return -1;
    else
         return 1 + maximo(altura(nodoArbol->hijoIzquierdo),altura(nodoArbol->hijoDerecho));
}

int Arbol::cantNodos2 (NodoArbol* nodoArbol)
{
    if (nodoArbol == NULL)
        return 0;
    else
         return 1 + cantNodos2(nodoArbol->hijoIzquierdo)+cantNodos2(nodoArbol->hijoDerecho);
}



int Arbol::cantHojas(NodoArbol* raiz)
{
    if (raiz == NULL)
       return 0;
    else if (raiz->hijoDerecho == NULL && raiz->hijoIzquierdo==NULL)
         return 1;
    else
        return cantHojas(raiz->hijoDerecho)+cantHojas(raiz->hijoIzquierdo);

}


bool Arbol::isEmpty(NodoArbol * raiz){
    if (raiz == NULL) return true;
    return false;
}


// borrar
 NodoArbol* Arbol::mayor (NodoArbol* arbol)
  {
    if (arbol == NULL)
        return NULL;
    else if (arbol->hijoDerecho == NULL)
        return arbol;
    else
        return mayor (arbol->hijoDerecho);
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
        else if (ele < arbol->nodoPersona->persona->id)
            arbol->hijoIzquierdo = borrarElemento(ele, arbol->hijoIzquierdo);
        else if (ele > arbol->nodoPersona->persona->id)
            arbol->hijoDerecho = borrarElemento(ele, arbol->hijoDerecho);
        else if (arbol->hijoIzquierdo == NULL && arbol->hijoDerecho == NULL)
            arbol = NULL;
        else if (arbol->hijoIzquierdo == NULL)
            arbol = arbol->hijoDerecho;
        else if (arbol->hijoDerecho == NULL)
            arbol = arbol->hijoIzquierdo;
        else{
            NodoArbol* max = mayor(arbol->hijoIzquierdo); // mayor de los menores
            arbol->hijoIzquierdo = borrarElemento(max->nodoPersona->persona->id, arbol->hijoIzquierdo);
            arbol->nodoPersona->persona->id = max->nodoPersona->persona->id;
        }
        return arbol;
    }
