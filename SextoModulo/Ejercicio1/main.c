/*
Dada una lista simplemente enlazada de caracteres, escribir una función void que:
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
} nodo;

typedef nodo *TLista;

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
    mostrarContenido(lista);
    eliminarEnP(&lista, 2);
    mostrarContenido(lista);
    printf("La cantidad de vocales en la lista es: %d\n", cantVocales(lista));
    printf(estaOrdenada(lista) ? "Esta ordenada\n" : "No esta ordenada\n");
}

void eliminarEnP(TLista *lista, int p)
{
    int i = 0;
    TLista anterior, actual;

    if (*lista != NULL)
    {
        actual = *lista;
        if (p == 0)
        {
            *lista = actual->sig;
            free(actual);
        }
        else
        {
            while (i < p && actual != NULL)
            {
                anterior = actual;
                actual = actual->sig;
                i++;
            }
            if (actual != NULL)
            {
                anterior->sig = actual->sig;
                free(actual);
            }
        }
    }
}

int estaOrdenada(TLista lista)
{
    TLista act = lista, sig;
    if (act != NULL)
    {
        sig = act->sig;
        while (sig != NULL && act->dato < sig->dato)
        {
            act = act->sig;
            sig = sig->sig;
        }
    }
    return sig == NULL;
}

int cantVocales(TLista lista)
{

    int vocales = 0;
    TLista aux = lista;
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
    TLista aux = (TLista)malloc(sizeof(nodo));
    aux->dato = c;
    aux->sig = *lista;
    *lista = aux;
}
void mostrarContenido(TLista lista)
{
    TLista aux = lista;
    while (aux != NULL)
    {
        printf("%c\n", aux->dato);
        aux = aux->sig;
    }
}

void iniciarLista(TLista *lista)
{
    *lista = NULL;
}