/*Determinar mediante una función “lógica” si una matriz cuadrada de dimensión NxN es
simétrica (aij = aji) con respecto a su diagonal.*/

#include <stdlib.h>
#include <stdio.h>
#define SIZE 3

int isSimetric(int[SIZE][SIZE], int, int, int);

int main()
{
    int mat[SIZE][SIZE] = {{3, 2, -8}, {2, 4, -15}, {-8, -15, -2}}, n;
    n = SIZE;
    printf(isSimetric(mat, n - 2, n - 1, n - 1) ? "Es simetrica" : "No es simetrica");
}

int isSimetric(int mat[][SIZE], int i, int j, int m)
{
    if (i == -1) // Si me caigo es true
        return 1;
    else
    {
        if (mat[i][j] == mat[j][i])
        {
            return (j == i) // Hacia donde me desplazo en caso de que sea simetrica
                       ? isSimetric(mat, i - 1, m, m)
                       : isSimetric(mat, i, j - 1, m);
        }
        else
            return 0; // Si encontro algun valor que no es simetrico salgo  con false
    }
}