/*
Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una matriz de adyacencia
c) media matriz (triángulo superior) 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void llenarMatriz(int mat[MAX][MAX],int * n);
void mostrarMatriz(int mat[MAX][MAX],int  n);
int gradoVer(int mat[MAX][MAX],int n,int vertice);
int gradoVerMediaMatriz(int mat[MAX][MAX],int n,int vertice);

int main(){
    int mat[MAX][MAX],n=0;
    llenarMatriz(mat,&n);
    mostrarMatriz(mat,n);
    printf("Grado del vertice B(1):%d\n",gradoVer(mat,n,1));
    printf("Grado del vertice B(1):%d\n",gradoVerMediaMatriz(mat,n,1));

    return 0;
}

int gradoVer(int mat[MAX][MAX],int n,int vertice){
   int suma =0;
   for(int i=0;i<n;i++) {
        if (i == vertice) {
            suma += 2 * mat[vertice][i]; // el bucle cuenta doble
        } else {
            suma += mat[vertice][i];
        }
   }
   return suma;
}

int gradoVerMediaMatriz(int mat[MAX][MAX],int n,int vertice){
  int grado=0,i=0,j;
  while(i<=vertice){
    if(i==vertice && mat[i][i]!=0)
      grado+=mat[i][i]*2;
    else {
      grado+=(mat[i][vertice]==1);  
    }  
    i++;
  }
  j=i;
  while(j<n){
    grado+=(mat[vertice][j]==1); 
    j++;
  }
  
  return grado;
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