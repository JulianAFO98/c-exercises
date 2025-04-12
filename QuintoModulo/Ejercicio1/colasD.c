

#include <stdio.h>
#include <stdlib.h>

#include "colasD.h"

void IniciaC (TCola * C){
   C->primero = NULL;
   C->ultimo = NULL;
}

int VaciaC (TCola C){
   return C.primero == NULL;
}
TElementoC consultaC (TCola C){
    if(C.primero!=NULL)
        return C.primero->dato;

}
void sacaC (TCola *C, TElementoC* x){
   nodo * aux;
   if((*C).primero!=NULL){
     aux = C->primero;
     *x = aux->dato;
     C->primero = (*C).primero->sig;
     if(C->primero == NULL) {
        C->ultimo =NULL;
     }
     free(aux);
   }


}

void poneC (TCola *C, TElementoC x){
   nodo * N;
   N = (nodo *) malloc(sizeof(nodo));
   N->dato=x;
   N->sig=NULL;
   if(C->primero=NULL) {
     C->primero = N;
   }else {
     (*C).ultimo->sig = N;
   }
   (*C).ultimo = N;

}
