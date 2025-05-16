/*
Desarrollar una función que compruebe que si un árbol binario es un ABB.
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
int esABB(arbol a,int min,int max);
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
    printf(esABB(a,-9999,9999) ? "Es ABB\n" : "No es ABB\n");
    return 0;
}
int esABB(arbol a,int min,int max)
{
    if(a != NULL) {
        if(a->dato<max && a->dato>min) {
            return esABB(a->izq,min,a->dato) && esABB(a->der,a->dato,max);
        }else 
           return 0;
    }else
     return 1;
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}