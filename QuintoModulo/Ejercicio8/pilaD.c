
#include "pilaD.h"
#include <stdio.h>
#include <stdlib.h>

void sacaP(TipoP *P, TEP *e)
{
    if (*P != NULL)
    {
        TipoP aux;
        aux = (*P)->sig;
        *e = (*P)->e;
        free(*P);
        *P = aux;
    }
}
void poneP(TipoP *P, TEP e)
{
    TipoP aux;
    aux = (TipoP)malloc(sizeof(nodo));
    aux->e = e;
    aux->sig = *P;
    *P = aux;
}
void iniciaP(TipoP *P)
{
    *P = NULL;
}

TEP consultaP(TipoP P)
{
    if (P != NULL)
        return P->e;
}
int vaciaP(TipoP P)
{
    return P == NULL;
}
