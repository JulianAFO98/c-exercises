#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

TElementoP generarElem();
void mostrarInverso(TipoP *, int);
void mostrarNormal(TipoP *, int);

int main()
{
    TipoP pila;
    int N;

    iniciaP(&pila);
    poneP(&pila, generarElem("41431104"));
    poneP(&pila, generarElem("41431114"));
    poneP(&pila, generarElem("41434184"));
    poneP(&pila, generarElem("41433184"));

    printf("Ingrese N\n");
    scanf("%d", &N);
    printf("Orden normal\n");
    mostrarNormal(&pila, N);
    printf("Orden inverso\n");
    mostrarInverso(&pila, N);

    return 0;
}

void mostrarInverso(TipoP *P, int N)
{
    TElementoP e;
    int i = 0;
    while (!vaciaP(*P) && i < N)
    {
        sacaP(P, &e);
        printf("DNI numero %s\n", e.DNI);
        i++;
    }
}

void mostrarNormal(TipoP *P, int N)
{
    TipoP pilaAux;
    TElementoP e;
    iniciaP(&pilaAux);
    int i = 0;
    while (!vaciaP(*P) && i < N)
    {
        sacaP(P, &e);
        poneP(&pilaAux, e);
        i++;
    }
    while (!vaciaP(pilaAux))
    {
        sacaP(&pilaAux, &e);
        printf("DNI numero %s\n", e.DNI);
        poneP(P, e);
    }
}

TElementoP generarElem(char nombre[20])
{
    TElementoP elemento;
    strcpy(elemento.DNI, nombre);
    return elemento;
}
