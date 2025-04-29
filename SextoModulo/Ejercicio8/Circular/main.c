/*
Dada una lista  enlazada circularmente de caracteres, escribir una función void que:
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
    insertarEnLista(&lista, 'a');
    insertarEnLista(&lista, 'z');
    mostrarContenido(lista);
    eliminarEnP(&lista, 1);
    mostrarContenido(lista);

    printf("La cantidad de vocales en la lista es: %d\n", cantVocales(lista));
    printf(estaOrdenada(lista) ? "Esta ordenada\n" : "No esta ordenada\n");
    return 0;
}

void eliminarEnP(TLista *lista, int p)
{
    int i = 0;
    TLista anterior, actual;

    if (*lista != NULL)
    {
        anterior = (*lista);
        actual = (*lista)->sig;
        while (i < p && actual != NULL)
        {
            anterior = actual;
            actual = actual->sig;
            i++;
        }

        if (actual == (*lista)->sig)
        {
            if (actual == anterior)
                *lista = NULL;
            else
                (*lista)->sig = actual->sig;
            free(actual);
        }
        else
        {
            if (actual == *lista)
                *lista = anterior;
            anterior->sig = actual->sig;
            free(actual);
        }
    }
}

int estaOrdenada(TLista lista)
{
    TLista act = lista, sig;
    if (lista != NULL)
    {
        act = lista->sig;
        sig = act->sig;
        while (sig != lista->sig && act->dato < sig->dato)
        {
            act = act->sig;
            sig = sig->sig;
        }
    }
    return sig == lista->sig;
}

int cantVocales(TLista lista)
{

    int vocales = 0;
    if (lista != NULL)
    {

        TLista aux = lista->sig;
        do
        {
            if (esVocal(aux->dato))
                vocales++;
            aux = aux->sig;
        } while (aux != lista->sig);
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
    if (*lista == NULL)
    {
        aux->sig = aux;
        *lista = aux;
    }
    else
    {
        aux->sig = (*lista)->sig;
        (*lista)->sig = aux;
    }
}
void mostrarContenido(TLista lista)
{
    if (lista != NULL)
    {
        TLista aux = lista->sig;
        do
        {
            printf("%c\n", aux->dato);
            aux = aux->sig;
        } while (aux != lista->sig);
    }
}

void iniciarLista(TLista *lista)
{
    *lista = NULL;
}