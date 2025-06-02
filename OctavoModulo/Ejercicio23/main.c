/*
Para un digrafo dado, desarrollar un programa que genere la matriz de alcance R a partir de la
matriz A resultante del algoritmo de Floyd.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void llenarMatriz(int mat[MAX][MAX], int *n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void mostrarCaminoPFloyd(int mat[MAX][MAX],int vertice,int destino);
int main()
{
    int mat[MAX][MAX], n = 0;
    llenarMatriz(mat, &n);
    mostrarMatriz(mat, n);
    mostrarCaminoPFloyd(mat,1,2);
    return 0;
}

void mostrarCaminoPFloyd(int mat[MAX][MAX],int vertice,int destino){ 
  int infinito = 999; // asumo que marque mis inf con 999
  if(mat[vertice][destino]==infinito){
     printf("Inalcanzable");
  }else {
      if(destino!=vertice) {
         if(mat[vertice][destino]!=0){
           mostrarCaminoPFloyd(mat,vertice,mat[vertice][destino]);
         }else {
           mostrarCaminoPFloyd(mat,vertice,vertice);
          }
      }
        printf("%c ",destino+64);
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
