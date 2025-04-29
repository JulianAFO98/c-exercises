/*
Una lista contiene en cada nodo una cola de números enteros. Desarrollar un programa que
genere una pila con los elementos máximos de cada cola de la lista. (Utilizar TDA pila dinámica
y TDA cola circular).
*/

#include "pila.h"
#include "cola.h"
#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#define cantNodoLista 2

void crearLista(TLista *L);
void generarPila(TLista L, TPila *P);
void mostrarPila(TPila *P);
int main(void)
{
    TLista lista = NULL;
    TPila pila;
    iniciaP(&pila);
    crearLista(&lista);
    generarPila(lista, &pila);
    mostrarPila(&pila);
    return 0;
}

void mostrarPila(TPila *P)
{
    TEP dato;
    printf("Maximos:\n");
    while (!vaciaP(*P))
    {
        sacaP(P, &dato);
        printf("%d\n", dato);
    }
}

void generarPila(TLista L, TPila *P)
{
    TLista aux = L;
    TCola colaAux;
    TEC dato, max;
    while (aux != NULL)
    {
        colaAux = aux->cola;
        if (!vaciaC(colaAux))
        {
            sacaC(&colaAux, &dato);
            max = dato;
        }
        while (!vaciaC(colaAux))
        {
            sacaC(&colaAux, &dato);
            if (dato > max)
                max = dato;
        }
        poneP(P, (TEP)max);
        aux = aux->sig;
    }
}

void crearLista(TLista *L)
{
    TLista aux;
    TEC dato;
    int cantCola;
    for (int i = 0; i < cantNodoLista; i++)
    {
        aux = (TLista)malloc(sizeof(nodoL));
        iniciaC(&aux->cola);
        printf("Ingrese cuantos valores desea agregar a la cola\n");
        scanf("%d", &cantCola);
        for (int j = 0; j < cantCola; j++)
        {
            printf("Ingrese el dato %d\n", j + 1);
            scanf("%d", &dato);
            poneC(&aux->cola, dato);
        }
        aux->sig = *L;
        *L = aux;
    }
}