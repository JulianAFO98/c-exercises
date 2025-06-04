/*
Dada la matriz de alcance correspondiente a un digrafo, realizar una función recursiva para
hallar el vértice alcanzado por la mayor cantidad de vértices. En el caso de que existan más de
uno, devolver el primero encontrado
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void llenarMatriz(int mat[MAX][MAX], int *n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void verticeMasAlcanzado(int mat[MAX][MAX],int i, int j,int n,int acum,int * max,int * vertice);
int main()
{
    int mat[MAX][MAX], n = 0,vertice=0,max=0;
    llenarMatriz(mat, &n);
    mostrarMatriz(mat, n);
    verticeMasAlcanzado(mat,n-1,n-1,n-1,0,&max,&vertice);
    printf("Vertice mas alcanzado:%c\n",vertice+'A');
    return 0;
}

void verticeMasAlcanzado(int mat[MAX][MAX],int i, int j,int n,int acum,int * max,int * vertice){
    if(j>-1){    
        acum+=mat[i][j]==1;
        if(i>0){
            verticeMasAlcanzado(mat,i-1,j,n,acum,max,vertice);
        }else {
            if(acum>*max){
                *max=acum;
                *vertice=j;  
            }
            verticeMasAlcanzado(mat,n,j-1,n,0,max,vertice);    
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
        for (int i = 1; i <= *n; i++)
            for (int j = 1; j <= *n; j++)
                fscanf(arch, "%d", &mat[i][j]);
        fclose(arch);
    }
}

void mostrarMatriz(int mat[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}
