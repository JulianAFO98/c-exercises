#include "pila.h"
#include <stdlib.h>

void poneP(TipoPila *P, char c)
{
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    aux->dato = c;
    aux->sig = *P;
    *P = aux;
}
void sacaP(TipoPila *P, char *c)
{
    nodo *aux = *P;
    if (*P != NULL)
    {
        *c = aux->dato;
        *P = aux->sig;
        free(aux);
    }
}
void iniciaP(TipoPila *P)
{
    *P = NULL;
}
char consultaP(TipoPila P)
{
    if (P != NULL)
        return P->dato;
}
int vaciaP(TipoPila P)
{
    return P == NULL;
}
