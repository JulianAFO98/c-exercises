#include "pila.h"
#include <stdlib.h>

int vaciaP(TPila P){
    return P == NULL;
}
void iniciaP(TPila * P){
    *P = NULL;
}
void sacaP(TPila * P, TElementoP * e){
    nodoP * aux;
    if(*P!=NULL){
       *e=(*P)->dato;
       aux=*P;
       *P=(*P)->sig;
       free(aux);
    }
}
void poneP(TPila * P, TElementoP e){
    nodoP * nuevo = (nodoP *) malloc(sizeof(nodoP));
    nuevo->dato=e;
    nuevo->sig = *P;
    *P=nuevo;
}
TElementoP consultaP(TPila P){
    if(P!=NULL)
      return P->dato;
}
