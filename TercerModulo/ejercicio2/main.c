/*Recodificar en el lenguaje C los siguientes ejercicios de Programación I desarrollados en Pascal:
a) Sea V un arreglo de enteros, se pide:
I. Calcular e informar la suma de sus elementos.
II. Mostrar sus elementos.
III. Mostrar sus elementos en orden inverso.
b) Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
que posición se encuentra la primera ocurrencia de X o -1 en caso de no encontrarlo.
Implementar:
I. Considerando el arreglo desordenado, una búsqueda lineal recursiva.
II. Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva.
c) Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada.
d) Desarrollar un procedimiento recursivo que devuelva en un arreglo los máximos de cada fila
de una matriz de MxN.
e) Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
otro C manteniendo el orden pero sin pasar los elementos repetidos.  */

#include <stdlib.h>
#include <stdio.h>
#define SIZE 3
#define SIZE2 256

int sumaV(int[], int);
void mostrarV(int[], int);
void mostrarVInverso(int[], int);
int buscarPosX(float[], int, float);
int busquedaBinariaRec(float[], int, int, float);
void fusionarVectores(int[], int[], int[], int, int, int, int, int *);
void fusionarVectoresPro(int[], int[], int[], int *, int *, int *);
int buscarMinMat(int[SIZE][SIZE], int, int, int);
void llenarMatriz(int[SIZE2][SIZE2], int, int);
void generarVector(int[SIZE2][SIZE2], int, int, int, int[SIZE2], int *);
void mostrarVector(int[], int);

int main()
{
    // a)
    /*
    int v[] = {2, 5, 1, 10, 4, 5, -4, -5, -1};
    printf("El vector es: ");
    mostrarV(v, 8);
    printf("\nEl vector inverso es: ");
    mostrarVInverso(v, 8);
    printf("\nLa suma del vector da: %d", sumaV(v, 8));
    */

    // b)
    /*
    float desornado[] = {1, 4, 3, 6.6, 4.4, 1.45, 3, 10, 6, 1.1};
    float x;
    printf("\nIngrese X\n");
    scanf("%f", &x);
    int pos = buscarPosX(desornado, 9, x);
    if (pos == -1)
        printf("No se encontro el valor");
    else
    {
        printf("Se encontro en la posicion: %d", pos);
    }

    float ordenado[] = {1, 2, 5, 7, 15.5, 17, 20.6, 75.6, 100, 156.3, 170, 200};
    printf("\nIngrese X\n");
    scanf("%f", &x);
    pos = busquedaBinariaRec(ordenado, 0, 11, x);
    if (pos == -1)
        printf("No se encontro el valor");
    else
    {
        printf("Se encontro en la posicion: %d", pos);
    }
    */

    // c)
    /*
    int mat[SIZE][SIZE] = {{3, 2, -8}, {2, 4, -15}, {12, 3, -2}};
    printf("El min de la matriz es :%d", buscarMinMat(mat, 2, 2, 2));
    */

    // d)
    /*
    int mat[SIZE2][SIZE2];
    int v[SIZE2], k = 0, n, m;
    printf("Ingrese n\n");
    scanf("%d", &n);
    printf("Ingrese m\n");
    scanf("%d", &m);
    llenarMatriz(mat, n, m);
    generarVector(mat, n - 1, m - 1, m - 1, v, &k);
    mostrarVector(v, n);
    */

    // e)

    int ordenado1[] = {2, 4, 6, 7, 8, 9, 123, 200};
    int ordenado2[] = {2, 5, 6, 8, 9, 34, 155, 200, 201, 400};
    int fusionados[30];
    int k = 0;
    fusionarVectores(ordenado1, ordenado2, fusionados, 0, 7, 0, 9, &k);

    // Esperado 2 4 5 6 7 8 9 34 123 155 200 201 400
    for (int i = 0; i < k; i++)
    {
        printf("%d ", fusionados[i]);
    }
}

void mostrarVector(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

void generarVector(int mat[][SIZE2], int i, int j, int m, int v[], int *pK) // preguntar
{
    if (i > -1)
    {
        if (j == 0)
        {
            v[i] = mat[i][j];
            (*pK)++;
            generarVector(mat, i - 1, m, m, v, pK);
        }
        else
            generarVector(mat, i, j - 1, m, v, pK);

        if (mat[i][j] > v[i])
            v[i] = mat[i][j];
    }
}

void llenarMatriz(int mat[][SIZE2], int n, int m)
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

int buscarMinMat(int mat[][SIZE], int i, int j, int m)
{
    int min;
    if (i == 0 && j == 0)
        return mat[i][j];
    else
    {
        min = j == 0 ? buscarMinMat(mat, i - 1, m, m) : buscarMinMat(mat, i, j - 1, m);
        return min < mat[i][j] ? min : mat[i][j];
    }
}

void fusionarVectores(int ord1[], int ord2[], int fusion[], int i, int n, int j, int m, int *pK) // PREGUNTAR
{
    if (i <= n && j <= m)
    {
        if (ord1[i] == ord2[j])
        {
            fusion[*pK] = ord1[i];
            (*pK)++;
            fusionarVectores(ord1, ord2, fusion, ++i, n, ++j, m, pK);
        }
        else
        {
            if (ord1[i] < ord2[j])
            {
                fusion[*pK] = ord1[i];
                (*pK)++;
                fusionarVectores(ord1, ord2, fusion, ++i, n, j, m, pK);
            }
            else
            {
                fusion[*pK] = ord2[j];
                (*pK)++;
                fusionarVectores(ord1, ord2, fusion, i, n, ++j, m, pK);
            }
        }
    }
    else
    {
        if (i <= n)
        {
            fusion[*pK] = ord1[i];
            (*pK)++;
            fusionarVectores(ord1, ord2, fusion, ++i, n, j, m, pK);
        }

        if (j <= m)
        {
            fusion[*pK] = ord2[j];
            (*pK)++;
            fusionarVectores(ord1, ord2, fusion, i, n, ++j, m, pK);
        }
    }
}

// Se supone que el main controla que limite inferior (limInf) sera siempre inferior al limite superior(limSup)
int busquedaBinariaRec(float v[], int limInf, int limSup, float x)
{
    int medio = (limSup + limInf) / 2;
    if (v[medio] == x)
        return medio;
    else if (limInf == limSup)
        return -1;
    else
        return v[medio] > x ? busquedaBinariaRec(v, limInf, medio - 1, x) : busquedaBinariaRec(v, medio + 1, limSup, x);
}

int buscarPosX(float v[], int n, float x)
{
    if (n < 0)
        return -1;
    else
    {
        return v[n] == x ? n : buscarPosX(v, n - 1, x);
    }
}

int sumaV(int v[], int n)
{
    if (n == 0)
        return v[n];
    else
        return v[n] + sumaV(v, n - 1);
}

void mostrarV(int v[], int n)
{
    if (n >= 0)
    {
        mostrarV(v, n - 1);
        printf("%d ", v[n]);
    }
}

void mostrarVInverso(int v[], int n)
{
    if (n >= 0)
    {
        printf("%d ", v[n]);
        mostrarV(v, n - 1);
    }
}