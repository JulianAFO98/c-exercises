/*
Copiar el contenido completo de una lista simplemente enlazada en una lista doblemente
enlazada y en una lista circular, ambas inicialmente vacías. Ambas copias deben realizarse en la
misma función. En ambos casos se debe mantener el orden de la lista original, siendo el último
elemento de la lista simple el último de la circular. La lista original no debe ser modificada.
*/

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

void llenarListaSimple(TListaS *L);
void insertarEnLista(TListaS *L, int numero);
void mostrarListaSimple(TListaS L);
void llenarListasRestantes(TListaS simple, TListaS *circular, TListaD *doble);
void mostrarLCircular(TListaS L);
void mostrarLDoble(TListaD L);

int main(void)
{
    TListaS listaSimple = NULL;
    TListaS listaCircular = NULL;
    TListaD listaDoble;
    listaDoble.pri = listaDoble.ult = NULL;
    llenarListaSimple(&listaSimple);
    mostrarListaSimple(listaSimple);
    llenarListasRestantes(listaSimple, &listaCircular, &listaDoble);
    mostrarLCircular(listaCircular);
    mostrarLDoble(listaDoble);
}
void llenarListaSimple(TListaS *L)
{
    int numero;
    FILE *arch;
    arch = fopen("archivo.txt", "r");

    if (arch == NULL)
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {

        while (fscanf(arch, "%d", &numero) == 1)
        {
            insertarEnLista(L, numero);
        }
    }
}

void insertarEnLista(TListaS *L, int numero)
{
    TListaS aux = (TListaS)malloc(sizeof(nodoS));
    aux->dato = numero;
    aux->sig = *L;
    *L = aux;
}

void mostrarListaSimple(TListaS L)
{

    TListaS aux = L;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void llenarListasRestantes(TListaS simple, TListaS *circular, TListaD *doble)
{
    TListaS auxCircu, auxSimple;
    nodoD *auxDoble;
    auxSimple = simple;
    if (auxSimple != NULL)
    {
        while (auxSimple != NULL)
        {
            auxCircu = (TListaS)malloc(sizeof(nodoS));
            auxDoble = (nodoD *)malloc(sizeof(nodoD));
            auxCircu->dato = auxSimple->dato;
            auxDoble->dato = auxSimple->dato;
            if (auxSimple == simple)
            {
                auxCircu->sig = auxCircu;
                *circular = auxCircu;
                auxDoble->ant = NULL;
                auxDoble->sig = NULL;
                (*doble).pri = auxDoble;
                (*doble).ult = auxDoble;
            }
            else
            {
                auxDoble->sig = NULL;
                auxDoble->ant = (*doble).ult;
                (*doble).ult->sig = auxDoble;
                (*doble).ult = auxDoble;
                auxCircu->sig = (*circular)->sig;
                (*circular)->sig = auxCircu;
                *circular = auxCircu;
            }
            auxSimple = auxSimple->sig;
        }
    }
}

void mostrarLCircular(TListaS L)
{
    TListaS aux = L->sig;

    do
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    } while (aux != L->sig);
    printf("\n");
}
void mostrarLDoble(TListaD L)
{

    nodoD *aux = L.pri;

    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}