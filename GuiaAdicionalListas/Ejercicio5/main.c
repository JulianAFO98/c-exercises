/*
Resolver mediante subprogramas las siguientes operaciones sobre una lista doblemente
enlazada:
a) insertar un elemento en la posición media. Si la cantidad de elementos de la lista es impar
insertar en la posición media más uno. Considerar la inserción en una lista vacía (único
nodo)
b) eliminar un elemento conociendo la posición (puntero) del anterior, nulo para eliminar el
primer elemento.
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro)
*/

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

void llenarLista(TLista *L);
void mostrarLista(TLista L);
void insertaEnLista(TLista *L, int num);
void insertarEnMedio(TLista *L, TElementoL elem);
int calcularCantNodos(TLista L);
void eliminarX(TLista *L, TElementoL x);
void eliminarSabiendoAnterior(TLista *L, int pos);

int main(void)
{
    TLista lista;
    lista.pri = lista.ult = NULL;
    llenarLista(&lista);
    mostrarLista(lista);
    insertarEnMedio(&lista, 30);
    insertarEnMedio(&lista, 40);
    insertarEnMedio(&lista, 40);
    mostrarLista(lista);
    eliminarX(&lista, 40);
    mostrarLista(lista);

    return 0;
}

void mostrarLista(TLista L)
{
    nodo *aux = L.pri;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void llenarLista(TLista *L)
{
    FILE *arch = fopen("archivo.txt", "r");
    int num;
    if (arch == NULL)
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {
        while (fscanf(arch, "%d", &num) == 1)
            insertaEnLista(L, num);
    }
}

void insertaEnLista(TLista *L, int num)
{
    nodo *nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->dato = num;
    nuevo->sig = NULL;
    if ((*L).pri == NULL)
    {
        (*L).pri = (*L).ult = nuevo;
        nuevo->ant = NULL;
    }
    else
    {
        (*L).ult->sig = nuevo;
        nuevo->ant = (*L).ult;
        (*L).ult = nuevo;
    }
}

int calcularCantNodos(TLista L)
{
    int cont = 0;
    nodo *aux = L.pri;
    while (aux != NULL)
    {
        cont++;
        aux = aux->sig;
    }
    return cont;
}

void insertarEnMedio(TLista *L, TElementoL elem) // PREGUNTAR POR INSERCION
{
    int cantNodos, pos, i = 0;
    nodo *nuevo = (nodo *)malloc(sizeof(nodo)), *act;
    nuevo->dato = elem;
    cantNodos = calcularCantNodos(*L);
    pos = cantNodos / 2;
    if ((*L).pri == NULL)
    {
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        (*L).pri = nuevo;
        (*L).ult = nuevo;
    }
    else
    {
        act = (*L).pri;
        while (act != NULL && i < pos)
        {
            act = act->sig;
            i++;
        }
        if (act == (*L).pri)
        {
            nuevo->ant = NULL;
            nuevo->sig = (*L).pri;
            (*L).pri->ant = nuevo;
            (*L).pri = nuevo;
        }
        else
        {
            nuevo->ant = act->ant;
            nuevo->sig = act;
            act->ant->sig = nuevo;
            act->ant = nuevo;
        }
    }
}

void eliminarX(TLista *L, TElementoL x)
{
    nodo *aux = (*L).pri, *elim;
    int banderaElim;
    while (aux != NULL)
    {
        banderaElim = 0;
        if (aux->dato == x)
        {
            if (aux == (*L).pri)
            {
                if ((*L).pri == (*L).ult)
                    (*L).pri = (*L).ult = NULL;
                else
                    (*L).pri = (*L).pri->sig;
            }
            else
            {
                if (aux == (*L).ult)
                {
                    (*L).ult = aux->ant;
                    (*L).ult->sig = NULL;
                }
                else
                {
                    aux->ant->sig = aux->sig;
                    aux->sig->ant = aux->ant;
                }
            }
            banderaElim = 1;
        }
        if (banderaElim)
        {
            elim = aux;
            aux = aux->sig;
            free(elim);
        }
        else
            aux = aux->sig;
    }
}

void eliminarSabiendoAnterior(TLista *L, int pos)
{
}