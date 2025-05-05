/*
Resolver mediante subprogramas las siguientes operaciones sobre una lista circular:
a) insertar un elemento conociendo la posición (puntero) del anterior. Tomar el último como
anterior del primero, y nulo para insertar en una lista vacía.
b) insertar un elemento conociendo la posición (puntero) del siguiente. Tomar el primero
como siguiente del último, nulo para insertar en una lista vacía.
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro)
*/

#include <stdlib.h>
#include <stdio.h>
#include "types.h"
void crearListaCircular(TLista *L);
void mostrarListaCircular(TLista L);
void insertarConociendoAnterior(TLista *L, nodo *anterior, TElementoL e);
void insertarConociendoSiguiente(TLista *L, nodo *sig, TElementoL e);
void eliminarOcurrenciasX(TLista *L, TElementoL e);

int main(void)
{
    TLista lista = NULL;
    TElementoL e = 999;
    crearListaCircular(&lista);
    mostrarListaCircular(lista);
    insertarConociendoAnterior(&lista, lista->sig->sig, e);
    mostrarListaCircular(lista);
    insertarConociendoSiguiente(&lista, lista, 500);
    eliminarOcurrenciasX(&lista, -22);
    eliminarOcurrenciasX(&lista, 344);
    eliminarOcurrenciasX(&lista, 999);
    eliminarOcurrenciasX(&lista, -6);
    eliminarOcurrenciasX(&lista, 4);
    eliminarOcurrenciasX(&lista, 500);
    eliminarOcurrenciasX(&lista, 222);

    mostrarListaCircular(lista);

    return 0;
}

void eliminarOcurrenciasX(TLista *L, TElementoL e)
{
    TLista ant, act, elim;
    if (*L != NULL)
    {
        ant = *L;
        act = (*L)->sig;
        do
        {
            elim = NULL;
            if (act->dato == e)
            {
                elim = act;
                if (*L == act) // Si estoy en el puntero
                {
                    if (act == act->sig) // si es el unico nodo
                        *L = NULL;
                    else
                    {
                        *L = ant;
                        (*L)->sig = act->sig;
                    }
                }
                else // estoy en cualquier otra posicion
                    ant->sig = act->sig;
            }
            if (elim != NULL)
            {
                if (*L != NULL)
                    act = act->sig;
                free(elim);
            }
            else
            {
                ant = act;
                act = act->sig;
            }
        } while (*L != NULL && act != (*L)->sig);
    }
}

void insertarConociendoSiguiente(TLista *L, nodo *sig, TElementoL e)
{
    nodo *nuevo = (nodo *)malloc(sizeof(nodo)), *aux;

    nuevo->dato = e;

    if (sig == NULL)
    {
        if (*L == NULL)
        {
            nuevo->sig = nuevo;
            *L = nuevo;
        }
    }
    else
    {
        aux = *L;
        while (aux->sig != sig && aux->sig != *L)
            aux = aux->sig;
        if (aux->sig != sig)
            free(nuevo);
        else
        {
            aux->sig = nuevo;
            nuevo->sig = sig;
            if (aux == *L)
                *L = nuevo;
        }
    }
}

void insertarConociendoAnterior(TLista *L, nodo *anterior, TElementoL e)
{
    nodo *nuevo = (nodo *)malloc(sizeof(nodo));

    nuevo->dato = e;

    if (*L == NULL)
    {
        nuevo->sig = nuevo;
        *L = nuevo;
    }
    else
    {
        // Lista no vacía
        nuevo->sig = anterior->sig;
        anterior->sig = nuevo;

        // Si se insertó después del último nodo, actualizamos el puntero a último
        if (anterior == *L)
            *L = nuevo;
    }
}

void mostrarListaCircular(TLista L)
{
    TLista aux = L->sig;

    if (aux != NULL)
    {
        do
        {
            printf("%d ", aux->dato);
            aux = aux->sig;
        } while (aux != L->sig);
        printf("\n");
    }
}

void crearListaCircular(TLista *L)
{
    nodo *nuevo, *act, *ant;
    FILE *arch;
    int num;
    arch = fopen("archivo.txt", "r");
    if (arch == NULL)
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {
        while (fscanf(arch, "%d ", &num) == 1)
        {
            nuevo = (nodo *)malloc(sizeof(nodo));
            nuevo->dato = num;
            if (*L == NULL)
            {
                nuevo->sig = nuevo;
                *L = nuevo;
            }
            else
            {
                if (nuevo->dato > (*L)->dato)
                {
                    nuevo->sig = (*L)->sig;
                    (*L)->sig = nuevo;
                    *L = nuevo;
                }
                else
                {

                    ant = *L;
                    act = (*L)->sig;
                    while (nuevo->dato > act->dato)
                    {
                        ant = act;
                        act = act->sig;
                    }
                    nuevo->sig = act;
                    ant->sig = nuevo;
                }
            }
        }
        fclose(arch);
    }
}
