/*
Generar una lista simplemente enlazada a partir del contenido de un arreglo de N enteros no
ordenados:
a) invirtiendo el orden de sus elementos (no se permite recorrer el arreglo comenzando por el
último elemento)
b) manteniendo el orden de sus elementos.
c) de forma ordenada
*/

#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#define N 10

void iniciaL(TLista *L);
void llenarListaInvertida(int vec[], TLista *L);
void llenarListaEnOrdenOriginal(int vec[], TLista *L);
void llenarOrdenado(int vec[], TLista *L);
void insertarAlPrincipio(TLista *L, int x);
void insertarAlFinal(TLista *L, int x);
void insertarOrdenado(TLista *L, int x);
void mostrarLista(TLista L);
void limpiarLista(TLista *L);

int main(void)
{
    int vecEnteros[N] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};
    TLista lista;
    iniciaL(&lista);
    llenarListaInvertida(vecEnteros, &lista);
    mostrarLista(lista);
    limpiarLista(&lista);
    llenarListaEnOrdenOriginal(vecEnteros, &lista);
    mostrarLista(lista);
    limpiarLista(&lista);
    llenarOrdenado(vecEnteros, &lista);
    mostrarLista(lista);
    limpiarLista(&lista);
    return 0;
}

void insertarOrdenado(TLista *L, int x)
{
    TLista ant, act, aux;
    aux = (TLista)malloc(sizeof(nodo));
    aux->dato = x;
    if (*L == NULL || x < (*L)->dato)
    {
        aux->sig = *L;
        *L = aux;
    }
    else
    {
        ant = NULL;
        act = *L;
        while (act != NULL && x > act->dato)
        {
            ant = act;
            act = act->sig;
        }
        ant->sig = aux;
        aux->sig = act;
    }
}

void llenarOrdenado(int vec[], TLista *L)
{
    for (int i = 0; i < N; i++)
    {
        insertarOrdenado(L, vec[i]);
    }
}

void insertarAlFinal(TLista *L, int x)
{
    TLista ant, act, aux;
    aux = (TLista)malloc(sizeof(nodo));
    aux->dato = x;
    if (*L == NULL)
    {
        aux->sig = *L;
        *L = aux;
    }
    else
    {
        act = *L;
        while (act != NULL)
        {
            ant = act;
            act = act->sig;
        }
        ant->sig = aux;
        aux->sig = NULL;
    }
}

void llenarListaEnOrdenOriginal(int vec[], TLista *L)
{
    for (int i = 0; i < N; i++)
    {
        insertarAlFinal(L, vec[i]);
    }
}

void llenarListaInvertida(int vec[], TLista *L)
{
    for (int i = 0; i < N; i++)
    {
        insertarAlPrincipio(L, vec[i]);
    }
}

void insertarAlPrincipio(TLista *L, int x)
{
    TLista aux = (TLista)malloc(sizeof(nodo));
    aux->dato = x;
    aux->sig = *L;
    *L = aux;
}

void iniciaL(TLista *L)
{
    *L = NULL;
}

void mostrarLista(TLista L)
{
    TLista aux = L;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void limpiarLista(TLista *L)
{
    TLista aux;
    while (*L != NULL)
    {
        aux = *L;
        *L = (*L)->sig;
        free(aux);
    }
}