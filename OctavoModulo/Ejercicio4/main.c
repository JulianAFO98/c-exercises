/*
Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente. 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void llenarMatriz(int mat[MAX][MAX],int * n);
void mostrarMatriz(int mat[MAX][MAX],int  n);
void modificarMatriz(int mat[MAX][MAX],int n);

int main(){
    int mat[MAX][MAX],n=0;
    llenarMatriz(mat,&n);
    mostrarMatriz(mat,n);
    printf("\n-------------------\n");
    modificarMatriz(mat,n);
    mostrarMatriz(mat,n);
    return 0;
}

void llenarMatriz(int mat[MAX][MAX],int * n){


    printf("Ingrese el valor de n\n");
    scanf("%d",n);
    for(int i=0;i<*n;i++)
       for(int j=0;j<*n;j++){
        printf("Ingrese [%d,%d]\n",i,j);
        scanf("%d",&mat[i][j]);
       }
}

void mostrarMatriz(int mat[MAX][MAX],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }
}

void modificarMatriz(int mat[MAX][MAX],int n){
    for(int i=0;i<n;i++)
      for(int j=i;j<n;j++){
        if(mat[i][j]==1 || mat [j][i]==1) {
            mat[j][i]=1; 
            mat[i][j]=1;
        } 
      }
     
    
}

