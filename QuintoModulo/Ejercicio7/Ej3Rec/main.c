
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

TElementoP generarElem();
void mostrarRecursivo(TipoP *P, int N);
int main()
{
    TipoP pila;
    int N;

    iniciaP(&pila);
    poneP(&pila, generarElem("11111111"));
    poneP(&pila, generarElem("22222222"));
    poneP(&pila, generarElem("33333333"));
    poneP(&pila, generarElem("44444444"));

    printf("Ingrese N\n");
    scanf("%d", &N);
    printf("Mostrar Recursivo\n");
    mostrarRecursivo(&pila, N);

    return 0;
}

TElementoP generarElem(char nombre[20])
{
    TElementoP elemento;
    strcpy(elemento.DNI, nombre);
    return elemento;
}

void mostrarRecursivo(TipoP *P, int N)
{
    TElementoP e;
    if (!vaciaP(*P) && N > 0)
    {
        sacaP(P, &e);
        printf("%s\n", e.DNI);
        mostrarRecursivo(P, N - 1);
        poneP(P, e);
    }
}