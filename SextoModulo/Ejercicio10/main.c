/*
. Dada una lista doblemente enlazada de caracteres que representa una palabra, verificar si es
palíndroma.
*/

#include <stdlib.h>
#include <stdio.h>

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
int esPalindroma(TLista lista);

int main(void)
{
    TLista lista;
    iniciarLista(&lista);
    insertarEnLista(&lista, 'a');
    insertarEnLista(&lista, 'n');
    insertarEnLista(&lista, 'e');
    // mostrarContenido(lista);
    printf(esPalindroma(lista) ? "Es palindroma\n" : "No es palindroma\n");
    return 0;
}

int esPalindroma(TLista lista)
{
    TLista aux = lista;

    while ((aux.pri != aux.ult && aux.pri->sig != aux.ult) && aux.pri->dato == aux.ult->dato)
    {
        aux.pri = aux.pri->sig;
        aux.ult = aux.ult->ant;
    }
    return aux.pri == aux.ult || (aux.pri->sig == aux.ult && aux.pri->sig->dato == aux.ult->dato);
}

void insertarEnLista(TLista *lista, char c)
{
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    aux->dato = c;
    aux->sig = NULL;
    if ((*lista).pri == NULL)
    {
        aux->ant = NULL;
        (*lista).pri = aux;
    }
    else
    {
        (*lista).ult->sig = aux;
        aux->ant = (*lista).ult;
    }
    (*lista).ult = aux;
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