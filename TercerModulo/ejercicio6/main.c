/*Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par. */

#include <stdlib.h>
#include <stdio.h>
#define SIZE 256

void llenarMatriz(int[SIZE][SIZE], int, int);
void cumple(int[SIZE][SIZE], int, int, int, int, int, int);
int main()
{
    int mat[SIZE][SIZE];
    int n, m, anterior = 0, actual = 0;
    printf("Ingrese n\n");
    scanf("%d", &n);
    printf("Ingrese m\n");
    scanf("%d", &m);
    llenarMatriz(mat, n, m);
    cumple(mat, 0, 0, n - 1, m - 1, anterior, actual);
}

void cumple(int mat[SIZE][SIZE], int i, int j, int n, int m, int anterior, int actual)
{

    actual += mat[i][j];

    if (i <= n) // Mientras no me caiga de la matriz
    {
        if (i == 0 && j == m) // Si estoy en la ultima columna de la primera fila y es par sigo
        {
            if (actual % 2 == 0)
            {

                anterior = actual;
                actual = 0;
                cumple(mat, i + 1, 0, n, m, anterior, actual);
            }
            else
            {
                printf("No cumple");
            }
        }
        else if (i == n && j == m && actual > anterior) // Si estoy en el ultimo valor y  se cumple la condicion entonces cumple la condicion final
        {
            printf("Cumple");
        }
        else
        {
            if (j == m && actual > anterior) // Si llego al final de una columna y esta cumple sigo
            {
                anterior = actual;
                actual = 0;
                cumple(mat, i + 1, 0, n, m, anterior, actual);
            }
            else
            {
                if (j < m) // En camino al j==m
                {
                    cumple(mat, i, j + 1, n, m, anterior, actual);
                }
                else // Por descarte si no cumple ninguna anterior, no cumple condicion final
                {
                    printf("No cumple");
                }
            }
        }
    }
}

void llenarMatriz(int mat[][SIZE], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Ingrese el valor [%d][%d]:", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}