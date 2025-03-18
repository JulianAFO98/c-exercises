
/*
Desarrollar un programa que lea una matriz de enteros de NxM y:
a) busque la posición de un valor x (puede no existir)
b) muestre el promedio de cada columna de la matriz.
c) muestre para cada fila que tenga al menos un cero la cantidad de elementos que superan el
promedio de la matriz

*/

#include <stdio.h>
#include <stdlib.h>
#define SYZE 256

void llenarMatriz(int [][SYZE],int,int);
void mostrarMatriz(int [][SYZE],int,int);
void buscarPosX(int [][SYZE],int,int,int);
void mostrarPromedioColumna(int [][SYZE],int,int);

int main() {
    int mat[SYZE][SYZE],n,m,x;
    printf("Ingrese n y m\n");
    scanf("%d %d",&n,&m);
    llenarMatriz(mat,n,m);
    mostrarMatriz(mat,n,m);
    //a)
    //printf("Ingrese X\n");
    //scanf("%d",&x);
    //buscarPosX(mat,n,m,x);
    //b)
    mostrarPromedioColumna(mat,n,m);
    return 0;
}


void mostrarPromedioColumna(int mat[][SYZE],int n,int m) { // FLOAT SUMA??
    float suma;
    for (int j=0;j<m;j++) {
        suma=0;
        for (int i=0; i<n; i++) {
            suma+=mat[i][j];
        }
      printf("El promedio de la columna %d es %.2f\n",j,suma/n);
    }
}
void buscarPosX(int mat[][SYZE],int n,int m,int x) { // PREGUNTAR
    int i=0,j=0; // PREGUNTAR SOBRE LOS INTS
    while(i<n && mat[i][j]!=x) {
        while(j<m && mat[i][j]!=x) {
            j++;
        }
        if(mat[i][j]!=x) {
            j=0;
            i++;

        }

    }

    if(i<n) {
        printf("Encontrado en i=%d j=%d",i,j);
    } else {
        printf("No existe el numero buscado");
    }

}



void llenarMatriz(int mat[][SYZE],int n,int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d",&mat[i][j]);
        }
    }
}


void mostrarMatriz(int mat[][SYZE],int n,int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
