#include "pila.h"

void poneP(TPila *P, TElementoP E)
{
    if ((*P).tope != MAX - 1)
    {
        (*P).tope += 1;
        (*P).datos[(*P).tope] = E;
    }
}