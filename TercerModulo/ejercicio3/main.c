/*Dado un vector A de N elementos, obtener el promedio de sus elementos. */

#include <stdio.h>
#include <stdlib.h>

float calcularProm(int[], int, int);

int main()
{
    int v[] = {2, 4, 6, 8, 9, 4, 3, 5, 7, 9, 6};
    int n = 11;
    printf("El promedio del vector es: %.2f", calcularProm(v, n - 1, n));
}

float calcularProm(int v[], int i, int n)
{
    /*
    if (i > 0)
    {
        return (float)v[i] / n + calcularProm(v, i - 1, n);
    }
    else
    {
        return (float)v[i] / n;
    }
    */

    return i > 0 ? (float)v[i] / n + calcularProm(v, i - 1, n) : (float)v[i] / n;
}