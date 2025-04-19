#include "pila.h"
#include <stdlib.h>

void poneP(Pila *P, Maratonista m)
{
    Pila aux = (Pila)malloc(sizeof(nodo));
    aux->dato = m;
    aux->sig = *P;
    *P = aux;
}

void sacaP(Pila *P, Maratonista *m)
{
    if (*P != NULL)
    {
        Pila aux = *P;
        *P = (*P)->sig;
        *m = aux->dato;
        free(aux);
    }
}

Maratonista consultaP(Pila P)
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