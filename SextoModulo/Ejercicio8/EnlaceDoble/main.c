/*
Dada una lista doblemente enlazada de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct nodo
{
    char dato;
    struct nodo *sig;
    struct nodo *ant;
} nodo;

typedef struct
{
    nodo *pri;
    nodo *ult;
} TLista;

void insertarEnLista(TLista *lista, char c);
void mostrarContenido(TLista lista);
void iniciarLista(TLista *lista);
int cantVocales(TLista lista);
int esVocal(char c);
int estaOrdenada(TLista lista);
void eliminarEnP(TLista *lista, int p);

int main(void)
{
    TLista lista;
    iniciarLista(&lista);
    insertarEnLista(&lista, 'c');
    insertarEnLista(&lista, 'z');
    insertarEnLista(&lista, 'a');
    insertarEnLista(&lista, 'k');
    mostrarContenido(lista);
    eliminarEnP(&lista, 1);
    mostrarContenido(lista);
    printf("La cantidad de vocales en la lista es: %d\n", cantVocales(lista));
    printf(estaOrdenada(lista) ? "Esta ordenada\n" : "No esta ordenada\n");
}

void eliminarEnP(TLista *lista, int p)
{
    int i = 0;
    nodo *actual;
    if ((*lista).pri != NULL)
    {
        actual = (*lista).pri;

        while (i < p && actual != NULL)
        {
            actual = actual->sig;
            i++;
        }
        if (actual != NULL)
        {
            if (actual == (*lista).pri)
            {
                if (actual == (*lista).ult)
                {
                    (*lista).pri = NULL;
                    (*lista).ult = NULL;
                }
                else
                {
                    (*lista).pri = actual->sig;
                    (*lista).pri->ant = NULL;
                }
            }
            else
            {
                if (actual == (*lista).ult)
                {
                    (*lista).ult = (*lista).ult->ant;
                    (*lista).ult->sig = NULL;
                }
                else
                {
                    actual->ant->sig = actual->sig;
                    actual->sig->ant = actual->ant;
                }
            }
            free(actual);
        }
    }
}

int estaOrdenada(TLista lista)
{
    nodo *act = lista.pri;
    if (act != NULL)
    {
        act = act->sig;
        while (act != NULL && act->ant->dato < act->dato)
            act = act->sig;
    }
    return act == NULL;
}

int cantVocales(TLista lista)
{

    int vocales = 0;
    nodo *aux = lista.pri;
    while (aux != NULL)
    {
        if (esVocal(aux->dato))
            vocales++;
        aux = aux->sig;
    }
    return vocales;
}

int esVocal(char c)
{
    char lowerChar = tolower(c);
    return lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u';
}

void insertarEnLista(TLista *lista, char c)
{
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    aux->dato = c;
    aux->ant = NULL;
    if ((*lista).pri == NULL)
    {
        aux->sig = NULL;
        (*lista).ult = aux;
    }
    else
    {
        (*lista).pri->ant = aux;
        aux->sig = (*lista).pri;
    }
    (*lista).pri = aux;
}
void mostrarContenido(TLista lista)
{
    nodo *aux = lista.pri;
    while (aux != NULL)
    {
        printf("%c\n", aux->dato);
        aux = aux->sig;
    }
}

void iniciarLista(TLista *lista)
{
    (*lista).pri = (*lista).ult = NULL;
}