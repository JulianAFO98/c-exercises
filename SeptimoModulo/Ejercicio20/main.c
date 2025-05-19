/*
Dado un árbol binario proveniente de la conversión de un árbol general: 
a)  hallar la cantidad de nodos que habia en niveles impares.  
b) obtener el promedio de las claves cuyo grado era K (dato de entrada). 
c)  obtener la altura del árbol original 
d) determinar el grado del árbol original. 
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
int hallarImpares(arbol a);

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
    printf("Cantidad de nodos impares %d\n",hallarImpares(a));
    return 0;
}

int hallarImpares(arbol a){
  
}


void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}