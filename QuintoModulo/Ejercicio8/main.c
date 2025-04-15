/*Transformar, mediante un subprograma recursivo, una pila de manera que tenga los mismos
datos pero cambiados de signo.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilaD.h"

TEP generarElem(int n);
void convertirANegativos(TipoP *P);
void mostrarNormal(TipoP *P);

int main()
{
    TipoP pila;
    iniciaP(&pila);
    poneP(&pila, generarElem(1));
    poneP(&pila, generarElem(2));
    poneP(&pila, generarElem(3));
    poneP(&pila, generarElem(4));
    convertirANegativos(&pila);
    mostrarNormal(&pila);
    // Deberia imprimir -1 -2 -3 -4

    return 0;
}

void convertirANegativos(TipoP *P)
{
    TEP e;
    if (!vaciaP(*P))
    {
        sacaP(P, &e);
        convertirANegativos(P);
        e = e * -1;
        poneP(P, e);
    }
}

TEP generarElem(int n)
{
    TEP elemento;
    elemento = n;
    return elemento;
}

void mostrarNormal(TipoP *P)
{
    TipoP pilaAux;
    TEP e;
    iniciaP(&pilaAux);
    while (!vaciaP(*P))
    {
        sacaP(P, &e);
        poneP(&pilaAux, e);
    }
    while (!vaciaP(pilaAux))
    {
        sacaP(&pilaAux, &e);
        printf(" %d\n", e);
        poneP(P, e);
    }
}
