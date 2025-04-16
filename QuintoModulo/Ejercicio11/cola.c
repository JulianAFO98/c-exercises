#include "cola.h"
#include <stdlib.h>

void poneC(cola *C, empleado e)
{
    nodo *N = (nodo *)malloc(sizeof(nodo));
    N->dato = e;
    N->sig = NULL;
    if ((*C).pri == NULL)
        (*C).pri = N;
    else
        (*C).ult->sig = N;
    (*C).ult = N;
}
void sacaC(cola *C, empleado *e)
{
    nodo *aux;
    if ((*C).pri != NULL)
    {
        aux = (*C).pri;
        *e = aux->dato;
        (*C).pri = (*C).pri->sig;
        if ((*C).pri == NULL)
            (*C).ult == NULL;
        free(aux);
    }
}
void iniciaC(cola *C)
{
    (*C).pri = (*C).ult = NULL;
}
int vaciaC(cola C)
{
    return C.pri == NULL;
}
empleado consultaC(cola C)
{
    if (C.pri != NULL)
        return C.pri->dato;
}