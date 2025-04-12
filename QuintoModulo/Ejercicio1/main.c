#include "pilasD.h" //cambiar por PilasE.h si se quiere utilizar  pilas estaticas
#include "colasE.h"
#include <stdio.h>
#include <stdlib.h>


void limpiarPila(TPila *);

int main() {
    // Con pilas
  /*
    TPila pila;
    ElementoPila elem,elem2;
    elem.num = 6;
    elem2.num = 5;
    iniciaP(&pila);
    poneP(&pila,elem);
    poneP(&pila,elem2);
    sacaP(&pila,&elem);
    ElementoPila elem3=consultaP(pila);
    printf("El ultimo elemento de la pila es %d\n",elem3.num);
    limpiarPila(&pila);
*/
    //Con Colas


    return 0;
}

//Este metodo saca y muestra, eliminando el contenido  de la pila -> Lo uso para mostrar
void limpiarPila(TPila *p){
   ElementoPila aux;
   while(!vaciaP(*p)) {
    sacaP(p,&aux);
    printf("Elemento extraido %d\n",aux.num);
   }
}
