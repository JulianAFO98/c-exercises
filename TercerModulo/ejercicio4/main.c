/*Dada una matriz A de NxM float, retornar la cantidad de veces que un valor X aparece en A
(realizar una versión void y otra int)  */

#include <stdlib.h>
#include <stdio.h>
#define SIZE2 256

void llenarMatriz(float[SIZE2][SIZE2], int, int);
void contarXVoid(float[SIZE2][SIZE2], int, int, int, float, int *);
int contarXInt(float[SIZE2][SIZE2], int, int, int, float);
int main()
{
    float mat[SIZE2][SIZE2], x;
    int n, m, count = 0;
    printf("Ingrese n\n");
    scanf("%d", &n);
    getchar();
    printf("Ingrese m\n");
    scanf("%d", &m);
    getchar();
    llenarMatriz(mat, n, m);

    printf("Ingrese x\n");
    scanf("%f", &x);
    contarXVoid(mat, n - 1, m - 1, m - 1, x, &count);
    printf("\nCantidad de veces que aparece x: %d", count);
    printf("\nCantidad de veces que aparece x: %d", contarXInt(mat, n - 1, m - 1, m - 1, x));
}

int contarXInt(float mat[][SIZE2], int i, int j, int m, float x)
{
    if (i == 0 && j == 0)
    {
        return x == mat[i][j]; // Retorna 0 o 1
    }
    else
    {
        int count = mat[i][j] == x; // Mismo concepto de arriba => count = 0 || 1
        return j == 0 ? count + contarXInt(mat, i - 1, m, m, x) : count + contarXInt(mat, i, j - 1, m, x);
    }
}

void contarXVoid(float mat[][SIZE2], int i, int j, int m, float x, int *count)
{
    if (i > -1)
    {
        if (x == mat[i][j])
            (*count)++;

        j == 0 ? contarXVoid(mat, i - 1, m, m, x, count) : contarXVoid(mat, i, j - 1, m, x, count);
    }
}

void llenarMatriz(float mat[][SIZE2], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Ingrese el valor [%d][%d]:", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
}
