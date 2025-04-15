/*Desarrollar un programa que sume dos números enteros positivos, permitiendo una cantidad
de dígitos mayor a la que soportan los tipos numéricos. Los números pueden tener diferente
magnitud y deben ser ingresados comenzando desde su dígito más significativo (en orden).
Utilizar pilas de caracteres. */
#include <stdlib.h>
#include <stdio.h>
#include "pila.h"

void llenarNumero(TP *P, int N);
void mostrarPila(TP *P);
void mostrarPilaInversa(TP *P);
void sumarAmbosNumeros(TP *P1, TP *P2, TP *result);

int main(void)
{
    TP P1, P2, result;
    int N;

    iniciaP(&P1);
    iniciaP(&P2);
    iniciaP(&result);
    printf("Ingrese cuantos digitos quiere que tenga el primer numero\n");
    scanf("%d", &N);
    getchar();
    llenarNumero(&P1, N);
    printf("Ingrese cuantos digitos quiere que tenga el segundo numero\n");
    scanf("%d", &N);
    getchar();
    llenarNumero(&P2, N);
    mostrarPilaInversa(&P1);
    printf("\n+\n");
    mostrarPilaInversa(&P2);
    printf("\n------------------------------------------------------\n");
    sumarAmbosNumeros(&P1, &P2, &result);
    mostrarPila(&result);
    printf("\n");
}

void llenarNumero(TP *P, int N)
{
    TEP e;
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el digito numero %d\n", i + 1);
        scanf("%c", &e.c);
        getchar();
        poneP(P, e);
    }
}

void mostrarPilaInversa(TP *P)
{
    TEP e;
    if (!vaciaP(*P))
    {
        sacaP(P, &e);
        mostrarPilaInversa(P);
        printf("%d ", (e.c - '0'));
        poneP(P, e);
    }
}
void mostrarPila(TP *P)
{
    TEP e;
    if (!vaciaP(*P))
    {
        sacaP(P, &e);
        printf("%d ", (e.c - '0'));
        mostrarPila(P);
        poneP(P, e);
    }
}

void sumarAmbosNumeros(TP *P1, TP *P2, TP *result)
{
    TEP e, z, x;
    int resto, suma, div = 0;
    while (!vaciaP(*P1) || !vaciaP(*P2))
    {
        if (!vaciaP(*P1))
            sacaP(P1, &e);
        else
            e.c = '0';

        if (!vaciaP(*P2))
            sacaP(P2, &z);
        else
            z.c = '0';

        suma = (e.c - '0') + (z.c - '0') + div;
        resto = suma % 10;
        div = suma / 10;
        x.c = resto + '0';
        poneP(result, x);
    }
    if (div != 0)
    {
        x.c = div + '0';
        poneP(result, x);
    }
}