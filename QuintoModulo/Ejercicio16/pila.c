#include "pila.h"
#include <stdlib.h>

void poneP(Pila *P, Carta c)
{
    Pila aux = (Pila)malloc(sizeof(nodo));
    aux->dato = c;
    aux->sig = *P;
    *P = aux;
}

void sacaP(Pila *P, Carta *c)
{
    if (*P != NULL)
    {
        Pila aux = *P;
        *P = (*P)->sig;
        *c = aux->dato;
        free(aux);
    }
}

Carta consultaP(Pila P)
{
    return P->dato;
}
void iniciaP(Pila *P)
{
    *P = NULL;
}
int vaciaP(Pila P)
{
    return P == NULL;
}