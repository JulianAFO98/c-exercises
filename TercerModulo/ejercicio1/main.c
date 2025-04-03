/*Desarrollar funciones (algunas pueden ser void) para:
a) calcular el producto de dos números enteros positivos a partir de sumas sucesivas.
b) calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas
c) hallar el máximo elemento de un vector de enteros (realizar una versión void y otra int) */

#include <stdlib.h>
#include <stdio.h>

int multRecursiva(unsigned int, unsigned int);
void calcularRestYCoci(unsigned int, unsigned int, unsigned int *, unsigned int *);
void hallarMaxVoid(int[], int, int *);
int hallarMaxInt(int[], int);

int main()
{
    int v[] = {1, 5, 3, 15, -23, 4, 23}, cociente = 0, resto = 0;
    unsigned int resMult = multRecursiva(5, 3);
    printf("%d\n", resMult);
    calcularRestYCoci(10, 2, &cociente, &resto);
    printf("El cociente es %d y el resto es %d\n", cociente, resto);
    int max = hallarMaxInt(v, 6);
    printf("Maximo via int = %d\n", max);
    hallarMaxVoid(v, 6, &max);
    printf("Maximo via void = %d", max);
}

void hallarMaxVoid(int v[], int n, int *pmax)
{
    if (n == 0)
    {
        *pmax = v[n];
    }
    else
    {
        hallarMaxVoid(v, n - 1, pmax);
        if (v[n] > *pmax)
        {
            *pmax = v[n];
        }
    }
}

int hallarMaxInt(int v[], int n)
{
    int max;
    if (n == 0)
    {
        return v[n];
    }
    else
    {
        max = hallarMaxInt(v, n - 1);
        if (v[n] > max)
        {
            return v[n];
        }
        else
        {
            return max;
        }
    }
}

void calcularRestYCoci(unsigned int a, unsigned int b, unsigned int *pCociente, unsigned int *pResto)
{
    if (a < b)
    {
        if (*pCociente)
        {
            *pResto = a;
        }
    }
    else
    {
        (*pCociente)++;
        *pResto = a - b;
        calcularRestYCoci(*pResto, b, pCociente, pResto);
    }
}

int multRecursiva(unsigned int a, unsigned int b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return a + multRecursiva(a, b - 1);
    }
}