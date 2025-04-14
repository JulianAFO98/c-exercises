#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


void poneP(TipoP *P,TElementoP x){
  TipoP N;
  N = (TipoP) malloc (sizeof(nodo));
  N->dato = x;
  N->sig=*P;
  *P=N;
}

void sacaP(TipoP *P,TElementoP *e){
   if(*P != NULL) {
    TipoP aux;
    aux = *P;
    *e=aux->dato;
    *P = (*P)->sig;
    free(aux);
   }

}
void iniciaP(TipoP *P) {
    *P = NULL;
}
int vaciaP(TipoP P) {
    return P == NULL;
}

TElementoP consultaP(TipoP P) {
    if(P!=NULL)
      return P->dato;
}
