/*
Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas
*/

#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "pila.h"

#define MAX 20

void llenarMatriz(int mat[MAX][MAX], int *n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void mostrarEnAmplitud(int mat[MAX][MAX], int n);
void inicializarVector(int vec[], int n);
int hayaCeros(int vec[], int n);
void agregarAdyacentes(TCola *C, int mat[MAX][MAX], int n, int fila, int vecVisitados[]);
void mostrarEnProfundidad(int mat[MAX][MAX], int n);
int caminoDisponible(int mat[MAX][MAX], int n, int fila, int vecVisitados[]);
int cantConexas(int mat[MAX][MAX], int n);
int buscarNodoDisp(int vec[MAX], int n);

int main()
{
    int mat[MAX][MAX], n = 0;
    llenarMatriz(mat, &n);
    mostrarMatriz(mat, n);
    printf("Recorrido en Amplitud\n");
    mostrarEnAmplitud(mat, n);
    printf("\nRecorrido en Profundidad\n");
    mostrarEnProfundidad(mat, n);
    printf("\n");
    printf("Cantidad de componentes:%d\n", cantConexas(mat, n));
    return 0;
}

void mostrarEnProfundidad(int mat[MAX][MAX], int n)
{
    TPila P;
    int vecVisitados[MAX] = {0}, nodoActual, indice, cant = 0;
    iniciaP(&P);
    poneP(&P, 4); // Mi primer nodo es E(4)
    while (hayaCeros(vecVisitados, n))
    {
        if (vaciaP(P))
        {
            cant++;
            poneP(&P, buscarNodoDisp(vecVisitados, n));
        }

        while (!vaciaP(P))
        {
            nodoActual = consultaP(P);
            if (!vecVisitados[nodoActual])
            {
                printf("%c ", nodoActual + 65);
                vecVisitados[nodoActual] = 1;
            }
            indice = caminoDisponible(mat, n, nodoActual, vecVisitados);
            if (indice == -1)
                sacaP(&P, &nodoActual);
            else
                poneP(&P, indice);
        }
    }
}

int buscarNodoDisp(int vec[MAX], int n)
{
    int i = 0;
    while (i < n && vec[i] != 0)
        i++;
    return i;
}

int cantConexas(int mat[MAX][MAX], int n)
{
    TCola C;
    int vecVisitados[n], nodoActual, cant = 1;
    iniciaC(&C);
    inicializarVector(vecVisitados, n);
    poneC(&C, 4); // Mi primer nodo es E(4)
    while (hayaCeros(vecVisitados, n))
    {
        if (vaciaC(C))
        {
            cant++;
            poneC(&C, buscarNodoDisp(vecVisitados, n));
        }

        while (hayaCeros(vecVisitados, n) && !vaciaC(C))
        {
            sacaC(&C, &nodoActual);
            if (!vecVisitados[nodoActual])
            {
                vecVisitados[nodoActual] = 1;
                agregarAdyacentes(&C, mat, n, nodoActual, vecVisitados);
            }
        }
    }

    return cant;
}

int caminoDisponible(int mat[MAX][MAX], int n, int fila, int vecVisitados[])
{
    int camino = -1, i = 0;
    while (i < n && camino == -1)
    {
        if (mat[fila][i] == 1 && vecVisitados[i] != 1)
            camino = i;
        i++;
    }
    return camino;
}

int hayaCeros(int vec[], int n)
{
    int i = 0;
    while (i < n && vec[i] != 0)
        i++;
    return i < n;
}

void inicializarVector(int vec[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vec[i] = 0;
    }
}

void mostrarEnAmplitud(int mat[MAX][MAX], int n)
{
    TCola C;
    int vecVisitados[n], nodoActual, cant = 0;
    iniciaC(&C);
    inicializarVector(vecVisitados, n);
    poneC(&C, 4); // Mi primer nodo es E(4)
    while (hayaCeros(vecVisitados, n))
    {
        if (vaciaC(C))
        {
            poneC(&C, buscarNodoDisp(vecVisitados, n));
        }
        while (!vaciaC(C))
        {
            sacaC(&C, &nodoActual);
            if (!vecVisitados[nodoActual])
            {
                printf("%c ", nodoActual + 65);
                vecVisitados[nodoActual] = 1;
                agregarAdyacentes(&C, mat, n, nodoActual, vecVisitados);
            }
        }
    }
}

void agregarAdyacentes(TCola *C, int mat[MAX][MAX], int n, int fila, int vecVisitados[])
{
    for (int i = 0; i < n; i++)
    {
        if (mat[fila][i] == 1 && !vecVisitados[i])
            poneC(C, i);
    }
}

void llenarMatriz(int mat[MAX][MAX], int *n)
{
    FILE *arch;

    arch = fopen("datos.txt", "r");
    if (arch == NULL)
        printf("El archivo no existe\n");
    else
    {
        printf("Ingrese el valor de n\n");
        scanf("%d", n);
        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *n; j++)
                fscanf(arch, "%d", &mat[i][j]);
        fclose(arch);
    }
}

void mostrarMatriz(int mat[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}