
#include "pilaD.h"
#include <stdio.h>
#include <stdlib.h>

void sacaP(TipoP *P, char *c)
{
    if (*P != NULL)
    {
        TipoP aux;
        aux = (*P)->sig;
        *c = (*P)->c;
        free(*P);
        *P = aux;
    }
}
void poneP(TipoP *P, char c)
{
    TipoP aux;
    aux = (TipoP)malloc(sizeof(nodo));
    aux->c = c;
    aux->sig = *P;
    *P = aux;
}
void iniciaP(TipoP *P)
{
    *P = NULL;
}

char consultaP(TipoP P)
{
    if (P != NULL)
        return P->c;
}
int vaciaP(TipoP P)
{
    return P == NULL;
}
