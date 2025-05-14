/*
Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente
*/

#include <stdio.h>
#include <stdlib.h>
typedef char TElememtoA;
typedef struct nodo
{
    TElememtoA dato;
    struct nodo *izq;
    struct nodo *der;
} NODO;
typedef NODO *arbol;

void addnodo(arbol *a, TElememtoA e);
void llenarVectorDesc(arbol a, char vec[], int *dimv);
int main()
{
    arbol a;
    char vec[25];
    int dimv = 0;
    addnodo(&a, 'k');
    addnodo(&a->izq, 'c');
    addnodo(&a->izq->izq, 'a');
    addnodo(&a->izq->der, 'd');

    addnodo(&a->der, 'w');
    addnodo(&a->der->izq, 'r');
    addnodo(&a->der->izq->der, 's');
    llenarVectorDesc(a, vec, &dimv);
    for (int i = 0; i < dimv; i++)
        printf("%c ", vec[i]);
    printf("\n");
    return 0;
}

void llenarVectorDesc(arbol a, char vec[], int *dimv)
{
    if (a != NULL)
    {
        llenarVectorDesc(a->der, vec, dimv);
        vec[(*dimv)++] = a->dato;
        llenarVectorDesc(a->izq, vec, dimv);
    }
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}