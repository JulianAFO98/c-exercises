/*
Dado un árbol binario de cadenas de caracteres retornar el nivel en el que se encuentra la
cadena más larga que comienza con A
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char cad[25];
} TElememtoA;
typedef struct nodo
{
    TElememtoA dato;
    struct nodo *izq;
    struct nodo *der;
} NODO;

typedef NODO *arbol;

void addnodo(arbol *a, TElememtoA e);
void calcularProfA(arbol a, int niv, int *prof, int *maxLen);
int main()
{
    arbol a;
    int niv = 1, prof = 0, maxLen = 0;

    TElememtoA elem;
    strcpy(elem.cad, "hola");
    addnodo(&a, elem);
    strcpy(elem.cad, "mundo");
    addnodo(&a->izq, elem);
    strcpy(elem.cad, "estoy");
    addnodo(&a->izq->izq, elem);
    strcpy(elem.cad, "haciendo");
    addnodo(&a->izq->der, elem);
    strcpy(elem.cad, "un");
    addnodo(&a->der, elem);
    strcpy(elem.cad, "Arograma");
    addnodo(&a->der->izq, elem);
    strcpy(elem.cad, "C");
    addnodo(&a->der->izq->der, elem);
    calcularProfA(a, niv, &prof, &maxLen);
    printf("Max profundidad con A %d\n", prof);
    return 0;
}

void calcularProfA(arbol a, int niv, int *prof, int *maxLen)
{
    int lenCad;
    if (a != NULL)
    {
        lenCad = strlen((a->dato).cad);
        if (niv > *prof && lenCad > (*maxLen) && (a->dato).cad[0] == 'A')
        {
            *prof = niv;
            *maxLen = lenCad;
        }
        calcularProfA(a->izq, niv + 1, prof, maxLen);
        calcularProfA(a->der, niv + 1, prof, maxLen);
    }
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}