
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
//ESTATICOS
/*
void sacaP(TipoP *P,char * c) {
    if(P->tope != -1) {
        *c = P->texto[(P->tope)--];
    }

}
void poneP(TipoP *P,char c) {
    if(P->tope != SIZE-1) {
        P->texto[++(P->tope)] = c;
    }
}
void iniciaP(TipoP *P) {
    P->tope = -1;
}

char consultaP(TipoP P) {
    if(P.tope != -1)
        return P.texto[P.tope];

}
int vaciaP(TipoP P) {
    return P.tope == -1;

}

*/

void sacaP(TipoP *P,char * c) {
    if (*P != NULL) {
        TipoP aux;
        aux= (*P)->sig;
        *c = (*P)->c;
        free(*P);
        *P=aux;
    }
}
void poneP(TipoP *P,char c) {
    TipoP aux;
    aux = (TipoP) malloc(sizeof(nodo));
    aux->c=c;
    aux->sig = *P;
    *P=aux;
}
void iniciaP(TipoP *P) {
    *P = NULL;
}

char consultaP(TipoP P) {
    if(P!= NULL)
        return P->c;
}
int vaciaP(TipoP P) {
    return P == NULL;
}
