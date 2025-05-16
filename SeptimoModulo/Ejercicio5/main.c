/*
Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b)  retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario
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
int calcularProf(arbol a);
int maxLong(arbol a);
int contarDerechos(arbol a);
int main()
{
    arbol a;
    TElememtoA elem;
    int prof = 0;
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
    strcpy(elem.cad, "programa");
    addnodo(&a->der->izq, elem);
    strcpy(elem.cad, "C");
    addnodo(&a->der->izq->der, elem);
    printf("Profundidad:%d\n",calcularProf(a));
    printf("Longitud de la cadena mas larga del arbol:%d\n", maxLong(a));
    printf("Cantidad de hijos derechos:%d\n", contarDerechos(a));
    return 0;
}
// Version 1
/*
int contarDerechos(arbol a)
{
    if (a != NULL)
        if (a->der != NULL)
            return 1 + contarDerechos(a->der) + contarDerechos(a->izq);
        else
            return contarDerechos(a->der) + contarDerechos(a->izq);
    else
        return 0;
}
*/
// Version 2
int contarDerechos(arbol a)
{
    int cuenta = 0;
    if (a != NULL)
    {
        if (a->der != NULL)
            cuenta = 1;
        return cuenta + contarDerechos(a->der) + contarDerechos(a->izq);
    }
    else
        return 0;
}

int maxLong(arbol a)
{
    int izq, dere, len;
    if (a != NULL)
    {
        izq = maxLong(a->izq);
        dere = maxLong(a->der);
        len = strlen((a->dato).cad);
        if (izq >= len && izq >= dere)
            return izq;
        else if (dere >= len && dere >= izq)
            return dere;
        else
            return len;
    }
    else
        return 0;
}
/*
void calcularProf(arbol a, int niv, int *prof)
{
    if (a != NULL)
    {
        if (niv > *prof)
            *prof = niv;
        calcularProf(a->izq, niv + 1, prof);
        calcularProf(a->der, niv + 1, prof);
    }
}
*/

int calcularProf(arbol a){
    int izq,der;
    if(a!=NULL){
      izq=calcularProf(a->izq);
      der=calcularProf(a->der);
      if(izq>der) {
        return 1+izq;
      }else 
        return 1+der;
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