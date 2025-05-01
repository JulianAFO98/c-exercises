/*
Dadas dos listas simplemente enlazadas de enteros L1 y L2:
a) verificar si son iguales. Considerar que están ordenadas.
b) añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de
L1. En otro caso, añadir L1 al final de L2.
c) eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada.
*/

#include "types.h"
#include <stdlib.h>
#include <stdio.h>
void llenarLista(TLista *L);
void insertarOrdenado(TLista *L, int num);
void mostrarLista(TLista L);
int sonIguales(TLista L1, TLista L2);
void fusionarListas(TLista L1, TLista L2);
void eliminarDeLista(TLista *L1, TLista L2);
int main(void)
{

    TLista L1 = NULL, L2 = NULL;
    llenarLista(&L1);
    llenarLista(&L2);
    mostrarLista(L1);
    mostrarLista(L2);
    /*printf(sonIguales(L1, L2) ? "Son Iguales\n" : "No son iguales\n");
    fusionarListas(L1, L2);
    */
    eliminarDeLista(&L1, L2);
    mostrarLista(L1);
    return 0;
}

void eliminarDeLista(TLista *L1, TLista L2)
{

    TLista aux = L2, act, ant;
    int i, cantElim = 0; // Uso indexacion 0 => Ej : 0 -> 1 -> 3 -> 6 -> 10  => siendo 0 la primer posicion posible en L2
    while (aux != NULL)
    {
        act = *L1;
        i = 0;
        while (i < (aux->dato - cantElim)) // aux->dato me da la posicion
        {
            if (act != NULL)
            {
                ant = act;
                act = act->sig;
            }
            i++;
        }
        if (act != NULL)
        {
            if (act == *L1)
            {
                *L1 = act->sig;
                i++;
            }
            else
                ant->sig = act->sig;

            cantElim++;
            free(act);
        }
        aux = aux->sig;
    }
}

void fusionarListas(TLista L1, TLista L2)
{
    TLista aux, listaAAgregar, listaFinal, nuevo;
    // Veo que lista tiene el ultimo mas grande
    if (L1 != NULL)
    {
        aux = L1;
        while (aux->sig != NULL)
            aux = aux->sig;
        if (L2 != NULL)
        {
            if (L2->dato > aux->dato)
            {
                listaFinal = L1;
                listaAAgregar = L2;
            }
            else
            {
                listaFinal = L2;
                listaAAgregar = L1;
            }
            while (listaFinal->sig != NULL)
                listaFinal = listaFinal->sig;
            while (listaAAgregar != NULL)
            {
                nuevo = (TLista)malloc(sizeof(nodo));
                nuevo->dato = listaAAgregar->dato;
                nuevo->sig = listaFinal->sig;
                listaFinal->sig = nuevo;
                listaFinal = nuevo;
                listaAAgregar = listaAAgregar->sig;
            }
        }
    }
}

int sonIguales(TLista L1, TLista L2)
{

    while ((L1 != NULL && L2 != NULL) && (L1->dato == L2->dato))
    {
        L1 = L1->sig;
        L2 = L2->sig;
    }
    return L1 == NULL && L2 == NULL;
}

void llenarLista(TLista *L)
{
    unsigned int n;
    int num;
    printf("Ingrese cuantos nodos quiere que tenga la lista\n");
    scanf("%u", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el valor a insertar(%d/%u)\n", i + 1, n);
        scanf("%d", &num);
        insertarOrdenado(L, num);
    }
}

void insertarOrdenado(TLista *L, int num) // Preguntar
{
    TLista ant, act, nuevo = (TLista)malloc(sizeof(nodo));
    nuevo->dato = num;
    if (*L == NULL || num < (*L)->dato)
    {
        nuevo->sig = *L;
        *L = nuevo;
    }
    else
    {
        ant = NULL;
        act = *L;
        while (act != NULL && num >= act->dato) // Para repetidos
        {
            ant = act;
            act = act->sig;
        }
        ant->sig = nuevo;
        nuevo->sig = act;
    }
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