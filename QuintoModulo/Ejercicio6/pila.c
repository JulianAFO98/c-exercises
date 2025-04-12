#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

void poneP(TP *P,TEP e){
  TP N;
  N = (TP) malloc(sizeof(nodo));
  N->dato=e;
  N->sig=*P;
  *P=N;
}

void sacaP(TP *P,TEP * e);
TEP consultaP(TP P){
    if(P!= NULL) 
     return P->dato;
}
void iniciaP(TP* P){
    (*P) = NULL;
}
int vaciaP(TP P){
    return P == NULL;
}

