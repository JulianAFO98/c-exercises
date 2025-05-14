/*
 Determinar  cuántos  elementos  de  un  ABB  son mayores  que A  y  menores  que  B.  A  y  B  son
parámetros de entrada.

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
int entreAyB(arbol a, int x, int k);
int main()
{
    arbol a;
    addnodo(&a, 15);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 10);

    addnodo(&a->der, 20);
    addnodo(&a->der->izq, 18);
    addnodo(&a->der->izq->der, 19);
    printf("La cantidad de elementos entre los elementos x y k es:%d\n", entreAyB(a, 5, 10));
    return 0;
}

int entreAyB(arbol a, int x, int k)
{
    if (a != NULL)
    {
        if (a->dato <= x)
            return entreAyB(a->der, x, k);
        else if (a->dato >= k)
            return entreAyB(a->izq, x, k);
        else
            return 1 + entreAyB(a->izq, x, k) + entreAyB(a->der, x, k);
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