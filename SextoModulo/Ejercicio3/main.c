/*
Escribir un programa que lea desde un archivo un texto que contiene una cantidad desconocida
de palabras (una en cada línea) y genere una lista ordenada de todas las palabras existentes en
el texto con su frecuencia de aparición.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

void iniciaL(TLista *L);
void mostrarLista(TLista L);
void generarListaOrdenada(TLista *L);
void insertaOrdenado(TLista *L, Palabra p);
void modificarApariciones(TLista *L, int pos);
int buscarPos(TLista L, char palabra[]);

int main(void)
{
    TLista lista;
    iniciaL(&lista);
    generarListaOrdenada(&lista);
    mostrarLista(lista);
}

void iniciaL(TLista *L)
{
    *L = NULL;
}

void insertaOrdenado(TLista *L, Palabra p)
{
    TLista aux, ant, act;
    aux = (TLista)malloc(sizeof(nodo));
    aux->pal = p;
    if (*L == NULL || strcmp(p.cadena, (*L)->pal.cadena) < 0)
    {
        aux->sig = *L;
        *L = aux;
    }
    else
    {
        ant = NULL;
        act = *L;
        while (act != NULL && strcmp(p.cadena, act->pal.cadena) > 0)
        {
            ant = act;
            act = act->sig;
        }
        ant->sig = aux;
        aux->sig = act;
    }
}

void modificarApariciones(TLista *L, int pos)
{
    TLista aux = *L;
    int i = 0;
    while (i < pos)
    {
        aux = aux->sig;
        i++;
    }
    aux->pal.apariciones += 1;
}

int buscarPos(TLista L, char palabra[])
{
    int i = 0;
    TLista aux = L;
    while (aux != NULL && strcmp(palabra, aux->pal.cadena) != 0)
    {
        aux = aux->sig;
        i++;
    }
    return aux != NULL ? i : -1;
}

void generarListaOrdenada(TLista *L)
{
    Palabra pal;
    int pos;
    FILE *arch = fopen("archivo.txt", "r");
    if (arch == NULL)
        printf("No se encontro el archivo");
    else
    {
        while (fscanf(arch, "%s\n", pal.cadena) == 1)
        {
            pos = buscarPos(*L, pal.cadena);
            if (pos == -1)
            {
                pal.apariciones = 1;
                insertaOrdenado(L, pal);
            }
            else
                modificarApariciones(L, pos);
        }
    }
}

void mostrarLista(TLista L)
{
    TLista aux = L;
    while (aux != NULL)
    {
        printf("palabra: %s => apariciones: %d\n", aux->pal.cadena, aux->pal.apariciones);
        aux = aux->sig;
    }
}