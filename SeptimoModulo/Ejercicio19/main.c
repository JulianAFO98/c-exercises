/*
Dado  un  árbol  binario  que  proviene  de  la  transformación  de  un  bosque,  determinar  qué 
cantidad de árboles lo componían. 

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
int cuantosLoComponen(arbol a);

int main()
{
    arbol a;
    addnodo(&a, 5);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 6);

    addnodo(&a->der, 4);
    addnodo(&a->der->izq, 1);
    addnodo(&a->der->izq->der, 2);
    printf("Cantidad de nodos %d\n",cuantosLoComponen(a));
    return 0;
}

int cuantosLoComponen(arbol a){
    int cont=0;
    if(a!=NULL) {
      while(a!=NULL) {
        cont++;
        a=a->der;
      }
      return cont;
    }else 
     return 0;
}


void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}