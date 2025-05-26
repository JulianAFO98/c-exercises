/*
Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice 
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void llenarMatriz(int mat[MAX][MAX],int * n);
void mostrarMatriz(int mat[MAX][MAX],int  n);
int gradoEntrada(int mat[MAX][MAX],int n,int  vertice);
int gradoSalida(int mat[MAX][MAX],int n,int  vertice);
int gradoVer(int mat[MAX][MAX],int n,int  vertice);
int main(){
    int mat[MAX][MAX],n=0;
    llenarMatriz(mat,&n);
    mostrarMatriz(mat,n);
    printf("Grado de entrada del vertice A(0):%d\n",gradoEntrada(mat,n,0));
    printf("Grado de salida del vertice A(0):%d\n",gradoSalida(mat,n,0));
    printf("Grado del vertice A(0):%d\n",gradoVer(mat,n,0));

    return 0;
}

int gradoVer(int mat[MAX][MAX],int n,int  vertice){ // preguntar
    return gradoEntrada(mat,n,vertice)+gradoSalida(mat,n,vertice) - ((mat[vertice][vertice]!=0) ? mat[vertice][vertice] : 0);
}


int gradoEntrada(int mat[MAX][MAX],int n,int  vertice){
    int suma=0;
    for(int i=0;i<n;i++){
        suma+=mat[i][vertice];
    }
    return suma;

}
int gradoSalida(int mat[MAX][MAX],int n,int  vertice){
    int suma=0;
    for(int i=0;i<n;i++){
        suma+=mat[vertice][i];
    }
    return suma;

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
