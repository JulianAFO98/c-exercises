/*
Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas
*/

#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#define MAX 20

void llenarMatriz(int mat[MAX][MAX], int *n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void mostrarEnAmplitud(int mat[MAX][MAX], int n);
void inicializarVector(int vec[],int n);
int hayaCeros(int vec[],int n){
    int i=0;
    while(i<n && vec[i]!=0)
     i++;
    return i<n;
}
int main()
{
    int mat[MAX][MAX], n = 0;
    llenarMatriz(mat, &n);
    mostrarMatriz(mat, n);
    mostrarEnAmplitud(mat,n);
    return 0;
}

void inicializarVector(int vec[],int n){
    for(int i=0;i<n;i++){
        vec[i]=0;
    }
}

void mostrarEnAmplitud(int mat[MAX][MAX], int n){
   TCola C;
   int vecVisitados[n],nodoActual;
   iniciaC(&C);
   inicializarVector(vecVisitados,n);
   poneC(&C,vecVisitados[0]);//Mi primer nodo es A(0)
   while(hayaCeros(vecVisitados,n)){
      nodoActual = consultaC(C);
      if(vecVisitados[nodoActual]) {// nodo actual es indice y tambien valor del nodo

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
                fscanf(arch,"%d", &mat[i][j]);
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