/*
Retornar el valor mínimo de un ABB

*/

#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo
{
    TElememtoA dato;
    struct nodo *izq;
    struct nodo *der;
} NODO;
typedef NODO *arbol;

void addnodo(arbol *a, TElememtoA e);
int buscarMinimoABB(arbol a);

int main()
{
    arbol a;
    /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, 15);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 10);

    addnodo(&a->der, 20);
    addnodo(&a->der->izq, 18);
    addnodo(&a->der->izq->der, 19);
    printf("El minimo del arbol binario de busqueda es:%d\n", buscarMinimoABB(a));
    return 0;
}

int buscarMinimoABB(arbol a)
{
    arbol aux;
    if (a != NULL)
    {
        aux = a;
        while (aux->izq != NULL)
            aux = aux->izq;
        return aux->dato;
    }
    return -1;
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}