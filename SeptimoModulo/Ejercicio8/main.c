/*
El draw de un torneo de tenis se representa mediante un árbol binario invertido. Desarrollar
subprogramas que muestren:
a) el nombre del ganador.
b) los nombres de los 2 finalistas.
c) los nombres de los 4 semifinalistas.
d) los nombres de todos los competidores y la cantidad.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char cad[255];
} TElememtoA;
typedef struct nodo
{
    TElememtoA dato;
    struct nodo *izq;
    struct nodo *der;
} NODO;
typedef NODO *arbol;

void addnodo(arbol *a, TElememtoA e);
void mostrarCampeon(arbol a);
void mostrarFinalistas(arbol a);
void mostrarPorNivel(arbol a, int nivel, int nivAct);
void mostrarCompetidores(arbol a, int nivel, int *cantComp);
int main()
{
    arbol a;
    TElememtoA elem;
    int cantComp = 0;
    strcpy(elem.cad, "Pedro");
    addnodo(&a, elem);
    strcpy(elem.cad, "Pedro");
    addnodo(&a->izq, elem);
    strcpy(elem.cad, "Pedro");
    addnodo(&a->izq->izq, elem);
    strcpy(elem.cad, "Juan");
    addnodo(&a->izq->der, elem);
    strcpy(elem.cad, "Leandro");
    addnodo(&a->der, elem);
    strcpy(elem.cad, "Leandro");
    addnodo(&a->der->izq, elem);
    strcpy(elem.cad, "Ramiro");
    addnodo(&a->der->izq->der, elem);
    strcpy(elem.cad, "Pedro");
    addnodo(&a->izq->izq->izq, elem);
    strcpy(elem.cad, "Felipe");
    addnodo(&a->izq->izq->der, elem);
    strcpy(elem.cad, "Juan");
    addnodo(&a->izq->der->der, elem);
    strcpy(elem.cad, "Julian");
    addnodo(&a->izq->der->izq, elem);
    strcpy(elem.cad, "Leandro");
    addnodo(&a->der->izq->izq, elem);
    strcpy(elem.cad, "Axel");
    addnodo(&a->der->der, elem);
    strcpy(elem.cad, "Axel");
    addnodo(&a->der->der->der, elem);
    strcpy(elem.cad, "Alejo");
    addnodo(&a->der->der->izq, elem);
    // a)
    mostrarCampeon(a);

    // b)
    mostrarFinalistas(a);

    // c)
    mostrarPorNivel(a, 3, 1);

    // d)
    mostrarCompetidores(a, 1, &cantComp);
    return 0;
}

void mostrarCompetidores(arbol a, int nivel, int *cantComp)
{
    if (a != NULL)
    {
        if (a->der == NULL && a->izq == NULL)
        {
            printf("Competidor:%s\n", (a->dato).cad);
            (*cantComp)++;
        }
        else
        {
            mostrarCompetidores(a->der, nivel + 1, cantComp);
            mostrarCompetidores(a->izq, nivel + 1, cantComp);

            if (nivel == 1)
                printf("Cantidad competidores:%d\n", *cantComp);
        }
    }
}

void mostrarPorNivel(arbol a, int nivel, int nivAct)
{
    if (a != NULL)
    {
        if (nivel == nivAct)
        {
            if (nivel == 3)
            {
                printf("Competidor de semifinal:%s\n", (a->dato).cad);
            }
            else
                printf("Competidor:%s\n", (a->dato).cad);
        }
        else
        {
            mostrarPorNivel(a->der, nivel, nivAct + 1);
            mostrarPorNivel(a->izq, nivel, nivAct + 1);
        }
    }
}

void mostrarFinalistas(arbol a)
{
    if (a != NULL)
        if (a->der != NULL && a->izq != NULL)
            printf("Finalistas: %s || %s\n", (a->der->dato).cad, (a->izq->dato).cad);
}

void mostrarCampeon(arbol a)
{
    if (a != NULL)
        printf("Ganador:%s\n", (a->dato).cad);
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}