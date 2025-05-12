/*
Desarrollar funciones para:
a) devolver la suma de los elementos múltiplos de 3 de un árbol binario.
b)  retornar la cantidad de hojas de un árbol binario.
c) informar si un valor recibido como parámetro se encuentra en un árbol binario.
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
int sumaMultiplos(arbol a, TElememtoA e);
int cantHojas(arbol a);
int existe(arbol a, TElememtoA e);

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
    printf("La suma de  los multiplos de 3 es: %d\n", sumaMultiplos(a, 3));
    printf("Cantidad de hojas del arbol:%d\n", cantHojas(a));
    printf(existe(a, 22) ? "Existe\n" : "No Existe\n");
    return 0;
}

int existe(arbol a, TElememtoA e)
{
    if (a != NULL)
        if (a->dato == e)
            return 1;
        else
            return existe(a->izq, e) || existe(a->der, e);
    else
        return 0;
}

int cantHojas(arbol a)
{
    if (a != NULL)
        if (a->der == NULL && a->izq == NULL)
            return 1;
        else
            return cantHojas(a->izq) + cantHojas(a->der);
    else
        return 0;
}

int sumaMultiplos(arbol a, TElememtoA e)
{
    if (a != NULL)
        if (a->dato % e == 0) // Podria agregarse caso de hoja
            return a->dato + sumaMultiplos(a->izq, e) + sumaMultiplos(a->der, e);
        else
            return sumaMultiplos(a->izq, e) + sumaMultiplos(a->der, e);
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