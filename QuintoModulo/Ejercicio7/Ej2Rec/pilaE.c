
#include "pilaE.h"
#include <stdio.h>
#include <stdlib.h>

void sacaP(TipoP *P, char *c)
{
    if (P->tope != -1)
    {
        *c = P->texto[(P->tope)--];
    }
}
void poneP(TipoP *P, char c)
{
    if (P->tope != SIZE - 1)
    {
        P->texto[++(P->tope)] = c;
    }
}
void iniciaP(TipoP *P)
{
    P->tope = -1;
}

char consultaP(TipoP P)
{
    if (P.tope != -1)
        return P.texto[P.tope];
}
int vaciaP(TipoP P)
{
    return P.tope == -1;
}
