/*
A partir de una lista simplemente enlazada ordenada de enteros, generar dos listas
simplemente enlazadas de salida: una conteniendo los valores impares ordenados
descendentemente, y la segunda con los valores pares ordenados de manera ascendente. No
se deberá crear nuevos nodos, sino utilizar los de la lista original generando nuevos enlaces.
*/
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

void llenarLista(TLista *L);
void insertaOrdenado(TLista *L, int num);
void mostrarLista(TLista L);
void generarListasParImpar(TLista *lista, TLista *impares, TLista *pares);
int main(void)
{

    TLista lista = NULL, listaPar = NULL, listaImpar = NULL;

    llenarLista(&lista);
    // mostrarLista(lista);
    generarListasParImpar(&lista, &listaImpar, &listaPar);
    mostrarLista(listaImpar);
    mostrarLista(listaPar);
    return 0;
}

void generarListasParImpar(TLista *lista, TLista *impares, TLista *pares) // Preguntar por el puntero ultimo de par
{
    TLista aux, act, ant;
    while (*lista != NULL)
    {
        // Extraigo el nodo de lista
        aux = *lista;
        *lista = (*lista)->sig;
        // Analizo Si es par o impar
        if (aux->dato % 2 == 0)
        {
            // Inserto
            if (*pares == NULL)
            {
                aux->sig = NULL;
                *pares = aux;
            }
            else
            {
                ant = NULL;
                act = *pares;
                while (act != NULL)
                {
                    ant = act;
                    act = act->sig;
                }
                ant->sig = aux;
                aux->sig = act;
            }
        }
        else
        {
            // Inserto
            aux->sig = *impares;
            *impares = aux;
        }
    }
}

void mostrarLista(TLista L)
{
    while (L != NULL)
    {
        printf("%d ", L->dato);
        L = L->sig;
    }
    printf("\n");
}

void llenarLista(TLista *L)
{
    FILE *arch;
    int num;
    arch = fopen("archivo.txt", "r");
    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf(arch, "%d ", &num) == 1)
            insertaOrdenado(L, num);
        fclose(arch);
    }
}

void insertaOrdenado(TLista *L, int num)
{
    TLista nuevo = (TLista)malloc(sizeof(nodo)), ant, act;
    nuevo->dato = num;
    if (*L == NULL || num < (*L)->dato)
    {
        nuevo->sig = (*L);
        *L = nuevo;
    }
    else
    {
        ant = NULL;
        act = *L;
        while (act != NULL && num > act->dato)
        {
            ant = act;
            act = act->sig;
        }
        ant->sig = nuevo;
        nuevo->sig = act;
    }
}
