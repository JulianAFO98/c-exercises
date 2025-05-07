

#include "cola.h"
#include <stdlib.h>
void sacaC(TCola *C, TElementoC *X)
{
    nodo *aux;
    if ((*C).pri != NULL)
    {
        *X = (*C).pri->dato;
        aux = (*C).pri;
        (*C).pri = (*C).pri->sig;
        if ((*C).pri == NULL)
            (*C).ult = NULL;
        free(aux);
    }
}