/*
Desarrollar una función que a partir de una matriz de NxM elementos enteros, devuelva en un
arreglo de structs, fila, columna y valor de las componentes de la matriz divisibles por N+M

*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef int Tmatriz[SIZE][SIZE];
typedef struct {
    int posI;
    int posJ;
    int valorPos;
} componenteMatriz;

void llenarMatriz(Tmatriz mat,int n, int m);
void mostrarMatriz(Tmatriz mat,int n, int m);
void llenarVectorNM(Tmatriz mat,int n, int m,componenteMatriz [],int *);
void mostrarVector(componenteMatriz [],int k);

int main() {

    Tmatriz mat;
    componenteMatriz componentes[SIZE];

    int n,m,k;
    printf("Ingrese n\n");
    scanf("%d",&n);
    printf("Ingrese m\n");
    scanf("%d",&m);
    llenarMatriz(mat,n,m);
    mostrarMatriz(mat,n,m);
    llenarVectorNM(mat,n,m,componentes,&k);
    mostrarVector(componentes,k);
    return 0;
}


void mostrarVector(componenteMatriz componentes[],int k) {
    for(int i=0; i<k; i++) {
        printf("Valores de pos %d ,i=%d j=%d valor=%d\n",i,componentes[i].posI,componentes[i].posJ,componentes[i].valorPos);
    }

}


void llenarVectorNM(Tmatriz mat,int n, int m,componenteMatriz componentes[],int *pk) {
    *pk = 0;
    componenteMatriz componenteAux;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] % (n+m) == 0) {
                // forma 1 de llenar una componente del vector
                /*
                componenteAux.posI = i;
                componenteAux.posJ = j;
                componenteAux.valorPos = mat[i][j];
                componentes[*pk] = componenteAux;
                */
                // forma 2
                componentes[*pk].posI = i;
                componentes[*pk].posJ = j;
                componentes[*pk].valorPos = mat[i][j];

                //Esto va en ambos casos
                (*pk)++;
            }
        }
    }

}



void llenarMatriz(Tmatriz mat,int n, int m) {

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("Ingrese el valor de la posicion [%d][%d]\n",i,j);
            scanf("%d",&mat[i][j]);
            getchar();
        }
    }

}

void mostrarMatriz(Tmatriz mat,int n, int m) {

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

}

