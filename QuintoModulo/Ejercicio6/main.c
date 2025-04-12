/*Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de
enteros:
a. cuente la cantidad de ceros que contiene.
b. obtenga el valor promedio (sin perder la información de la pila)
c. calcule los valores máximo y mínimo de la pila (sin perder la información de la pila)
d. quite todos los valores mayores al último. */

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void llenarPila(TP *P);
void mostrarPila(TP *P);
void contarCeros(TP *P, int *pcont);
void promedioSinPerderPila(TP *P, float *prom);
void calcularMaxyMin(TP *P, int *max, int *min);
void quitarMayoresMax(TP *P);

int main(void)
{
    TP P;
    int cont = 0;
    int max = -9999, min = 9999;
    float prom;
    iniciaP(&P);
    llenarPila(&P);
    // contarCeros(&P, &cont);
    // printf("La cantidad de 0 es %d\n", cont);
    promedioSinPerderPila(&P, &prom);
    printf("El promedio es %.2f\n", prom);
    calcularMaxyMin(&P, &max, &min);
    printf("Max:%d Min:%d\n", max, min);
    quitarMayoresMax(&P);
    mostrarPila(&P);

    return 0;
}

void llenarPila(TP *P)
{
    TEP e;
    int N;

    printf("Ingrese N\n");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &e);
        poneP(P, e);
    }
}

void contarCeros(TP *P, int *pcont)
{
    TEP e;
    while (!vaciaP(*P))
    {
        sacaP(P, &e);
        if (e == 0)
            (*pcont)++;
    }
}

void mostrarPila(TP *P)
{
    TEP e;
    while (!vaciaP(*P))
    {
        sacaP(P, &e);
        printf("%d ", e);
    }
    printf("\n");
}

void promedioSinPerderPila(TP *P, float *prom)
{
    TEP e;
    TP pilaAux;
    int suma = 0, cont = 0;

    iniciaP(&pilaAux);
    while (!vaciaP(*P))
    {
        sacaP(P, &e);
        poneP(&pilaAux, e);
        suma += e;
        cont++;
    }
    while (!vaciaP(pilaAux))
    {
        sacaP(&pilaAux, &e);
        poneP(P, e);
    }
    *prom = (float)suma / cont;
}

void calcularMaxyMin(TP *P, int *max, int *min)
{
    TEP e;
    TP pilaAux;

    iniciaP(&pilaAux);
    while (!vaciaP(*P))
    {
        sacaP(P, &e);
        poneP(&pilaAux, e);
        if (e > *max)
        {
            *max = e;
        }
        if (e < *min)
        {
            *min = e;
        }
    }

    while (!vaciaP(pilaAux))
    {
        sacaP(&pilaAux, &e);
        poneP(P, e);
    }
}

void quitarMayoresMax(TP *P)
{
    TEP e, max;
    TP pilaAux;

    iniciaP(&pilaAux);
    max = consultaP(*P);
    while (!vaciaP(*P))
    {
        sacaP(P, &e);
        if (e <= max)
        {
            poneP(&pilaAux, e);
        }
    }

    while (!vaciaP(pilaAux))
    {
        sacaP(&pilaAux, &e);
        poneP(P, e);
    }
}