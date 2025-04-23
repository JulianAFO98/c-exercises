/*
Corregir los errores en el siguiente programa, el cual incorpora en una lista ordenada de
números los elementos de un arreglo de N números ordenados, respetando el orden de la lista.
*/

#define N 2
... void main()
{
    int i, arr[N] = {4, 8, 9, 60}; // SE SALE DEL RANGO 0 1 2 3 y se espera 0 1
    TLISTA lista = NULL, pult = NULL, act, ant, nuevo;
    cargarLista(&lista);
    printf("\nLista Original\n");
    muestra(&lista);         // NO HACE FALTA &
    act = lista;             // deberia estar en el for
    ant = NULL;              // deberia estar en el for
    for (i = 0; i <= N; i++) // cuidado con el rango
    {
        while (act != NULL && arr[i] <= act->n)
        {
            act = ant;     // esta alrevez la asignacion
            act = act.sig; // ->
        }
        *nuevo = (TLISTA)malloc(sizeof(NODO)); // sin *
        nuevo->n = arr[i - 1];                 // i
        if (ant = NULL)                        // falta = y ant ya es NULL, deberia ser act
        {
            nuevo->sig = lista;
            *lista = &nuevo; // sin & y sin *
        }
        else
        {
            nuevo->sig = ant;  // act no ant
            ant->sig = &nuevo; // sin &
        }
        act = nuevo->sig;
    }
    printf("\nLista Resultado\n");
    muestra(&lista); // sin &
}

// Version Corregida

#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct nodo
{
    int n;
    struct nodo *sig;
} NODO, *TLISTA;

// Suponiendo que ya están implementadas correctamente
void cargarLista(TLISTA *lista);
void muestra(TLISTA lista);

int main()
{
    int i, arr[N] = {4, 8, 9, 60};
    TLISTA lista = NULL, act, ant, nuevo;

    cargarLista(&lista);

    printf("\nLista Original\n");
    muestra(lista);

    for (i = 0; i < N; i++)
    {
        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->n = arr[i];
        nuevo->sig = NULL;

        act = lista;
        ant = NULL;

        // Buscar posición donde insertar respetando orden
        while (act != NULL && arr[i] > act->n)
        {
            ant = act;
            act = act->sig;
        }

        if (ant == NULL)
        {
            // Insertar al principio
            nuevo->sig = lista;
            lista = nuevo;
        }
        else
        {
            // Insertar en medio o al final
            nuevo->sig = act;
            ant->sig = nuevo;
        }
    }

    printf("\nLista Resultado\n");
    muestra(lista);

    return 0;
}