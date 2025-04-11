#include <stdio.h>
#include <stdlib.h>
#include "pilasD.h"


void iniciaP(TPila *P) {
    *P=NULL;
}

void sacaP(TPila *P,ElementoPila * pelem){
     TPila aux;
     if(*P) {
        *pelem =(*P)->elem;
        aux = (*P)->sig;
        free(*P);
        *P=aux;
     }

}
void poneP(TPila *P,ElementoPila elem) {
    TPila N;
    N = (TPila) malloc(sizeof(nodop));
    N->elem=elem;
    N->sig = *P;
    *P=N;
}
int vaciaP(TPila P){
  return P == NULL;
}

ElementoPila consultaP(TPila P){
  if(P!=NULL)
   return P->elem;
}

