/*
Una lista doble contiene en cada nodo un rango de números enteros [A,B] y una sublista de
enteros. Generar una lista simple paralela a la lista doble donde cada nodo contenga el
promedio de los valores de la sublista y la cantidad de elementos de la misma que no
pertenecen al rango [A,B].
*/

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

void llenarListaDoble(TListaD *L);
void mostrarListaDoble(TListaD L);
void generarListaSimple(TListaD L, TListaS *LS);

int main(void)
{
    TListaD lista;
    TListaS listaSimple;
    lista.pri = lista.ult = NULL;
    llenarListaDoble(&lista);
    mostrarListaDoble(lista);
    generarListaSimple(lista, &listaSimple);
    return 0;
}

void mostrarListaDoble(TListaD L)
{
    nodoD *aux = L.pri;
    nodoSub *subAux;
    int i = 0;
    while (aux != NULL)
    {
        printf("----Nodo numero %d de la lista doble----\n", i + 1);
        subAux = aux->sub;
        while (subAux != NULL)
        {
            printf("%d ", subAux->dato);
            subAux = subAux->sig;
        }
        printf("\n");
        aux = aux->sig;
        i++;
    }
}

void llenarListaDoble(TListaD *L)
{
    int inicio, fin, n, valor;
    nodoD *nuevo;
    nodoSub *nuevoSub;
    FILE *arch = fopen("archivo.txt", "r");
    if (arch == NULL)
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {
        while (fscanf(arch, "%d %d\n", &inicio, &fin) == 2)
        {
            nuevo = (nodoD *)malloc(sizeof(nodoD));
            nuevo->A = inicio;
            nuevo->B = fin;
            nuevo->sub = NULL;
            printf("Ingrese cuantos valores quiere que tenga la sublista\n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Ingrese el valor %d de la sublista\n", i + 1);
                scanf("%d", &valor);
                nuevoSub = (nodoSub *)malloc(sizeof(nodoSub));
                nuevoSub->dato = valor;
                nuevoSub->sig = nuevo->sub;
                nuevo->sub = nuevoSub;
            }
            nuevo->sig = NULL;
            if ((*L).pri == NULL)
            {
                nuevo->ant = NULL;
                (*L).pri = nuevo;
            }
            else
            {
                (*L).ult->sig = nuevo;
                nuevo->ant = (*L).ult;
            }
            (*L).ult = nuevo;
        }
        fclose(arch);
    }
}
