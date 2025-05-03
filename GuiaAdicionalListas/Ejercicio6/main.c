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
void insertarConociendoAnterior(TLista *L, TElementoL e, int pos);
int main(void)
{
    TLista lista = NULL;
    TElementoL e = 999;
    crearListaCircular(&lista);
    mostrarListaCircular(lista);
    insertarConociendoAnterior(&lista, e, 3);
    return 0;
}

void insertarConociendoAnterior(TLista *L, TElementoL e, int pos)
{
    int i = 0;
    nodo *nuevo = (TLista)malloc(sizeof(nodo)), *act, *ant;
    nuevo->dato = e;
    if (pos == 0 && *L == NULL)
    {
        nuevo->sig = nuevo;
        *L = nuevo;
    }
    else
    {
        if (*L != NULL)
        {
            i = 1;
            ant = *L;
            act = (*L)->sig;
            while (i < pos && act != *L)
            {
                /* code */
            }
        }
        else
            free(nuevo);
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
