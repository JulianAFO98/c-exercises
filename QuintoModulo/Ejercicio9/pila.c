#include "pila.h"
#include <stdlib.h>

void poneP(TP *P, TEP e)
{
    TP aux = (TP)malloc(sizeof(nodo));
    aux->dato = e;
    aux->sig = *P;
    *P = aux;
}

void sacaP(TP *P, TEP *e)
{
    if (*P != NULL)
    {
        TP aux = *P;
        *P = (*P)->sig;
        *e = aux->dato;
        free(aux);
    }
}

TEP consultaP(TP P)
{
    return P->dato;
}
void iniciaP(TP *P)
{
    *P = NULL;
}
int vaciaP(TP P)
{
    return P == NULL;
}