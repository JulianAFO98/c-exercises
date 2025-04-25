#include "pila.h"
#include <stdlib.h>

void poneP(TPila *P, TEP e)
{
    TPila aux = (TPila)malloc(sizeof(nodoP));
    aux->dato = e;
    aux->sig = *P;
    *P = aux;
}
void sacaP(TPila *P, TEP *e)
{
    TPila aux;
    if (*P != NULL)
    {
        aux = *P;
        *e = aux->dato;
        *P = (*P)->sig;
        free(aux);
    }
}
void iniciaP(TPila *P)
{
    *P = NULL;
}
TEP consultaP(TPila P)
{
    if (P != NULL)
        return P->dato;
}
int vaciaP(TPila P)
{
    return P == NULL;
}
