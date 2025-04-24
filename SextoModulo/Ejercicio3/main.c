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
        aux->pal.apariciones=1;
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
        //si son iguales 
        
        if(act != NULL && strcmp(p.cadena, act->pal.cadena) == 0){
            act->pal.apariciones+=1;
        }else {
            aux->pal.apariciones=1;
            ant->sig = aux;
            aux->sig = act;
        }
    }
}



void generarListaOrdenada(TLista *L)
{
    Palabra pal;
    FILE *arch = fopen("archivo.txt", "r");
    if (arch == NULL)
        printf("No se encontro el archivo");
    else
    {
        while (fscanf(arch, "%s\n", pal.cadena) == 1)
        {
             insertaOrdenado(L, pal);
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