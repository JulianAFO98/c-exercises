/*
Para un digrafo dado, desarrollar un programa que genere la matriz de alcance R a partir de la
matriz A resultante del algoritmo de Floyd.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void llenarMatriz(int mat[MAX][MAX], int *n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void floydAWarShall(int mat[MAX][MAX], int n);

int main()
{
    int mat[MAX][MAX], n = 0;
    llenarMatriz(mat, &n);
    mostrarMatriz(mat, n);
    floydAWarShall(mat, n);
    mostrarMatriz(mat, n);

    return 0;
}

void floydAWarShall(int mat[MAX][MAX], int n)
{
    int infinito = 999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i][j] != infinito;
        }
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
