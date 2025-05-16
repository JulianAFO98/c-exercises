/*
Desarrollar  una  función  que  retorne  la  suma  del  contenido  de  aquellos  nodos  de  un  árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato.
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
int sumaX(arbol a, int nivAct, int nivel);
int main()
{
    arbol a;
    int X;
    addnodo(&a, 5);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 6);
    addnodo(&a->der, 4);
    addnodo(&a->der->izq, 1);
    addnodo(&a->der->izq->der, 2);
    printf("Ingrese grado X\n");
    scanf("%d", &X);
    printf("La suma es:%d\n", sumaX(a, 1, X));
    return 0;
}

int sumaX(arbol a, int nivAct, int nivel)//este
{
    int suma = 0;
    if (a != NULL)
    {
        if (nivAct == nivel && ((a->der == NULL && a->izq) || (a->der && a->izq == NULL)))
            suma = a->dato;
        return suma + sumaX(a->izq, nivAct + 1, nivel) + sumaX(a->der, nivAct + 1, nivel);
    }
    else
        return 0;
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}