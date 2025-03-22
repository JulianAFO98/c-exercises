
/*
Desarrollar un programa que lea una matriz de enteros de NxM y:
a) busque la posición de un valor x (puede no existir)
b) muestre el promedio de cada columna de la matriz.
c) muestre para cada fila que tenga al menos un cero la cantidad de elementos que superan el
promedio de la matriz

*/

#include <stdio.h>
#include <stdlib.h>
#define SYZE 3

void llenarMatriz(int [][SYZE],int,int);
void mostrarMatriz(int [][SYZE],int,int);
void buscarPosX(int [][SYZE],int,int,int);
void mostrarPromedioColumna(int [][SYZE],int,int);
void superanPromedio(int [][SYZE],int,int);
float calcularPromedio(int [][SYZE],int,int);
int tieneCero(int [][SYZE],int,int);

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
    printf("%p %d %p %d",&mat[0][5],mat[0][5],&mat[1][2],mat[1][2]); // una locura
    //b)
    //mostrarPromedioColumna(mat,n,m);
    //c)
    //superanPromedio(mat,n,m);

    return 0;
}


int tieneCero(int mat[][SYZE],int fila,int cantCol) {
    int j=0;
    while (j<cantCol && mat[fila][j]!=0) {
        j++;
    }

    return j<cantCol ? 1 : 0;
}


float calcularPromedio(int mat[][SYZE],int n,int m) { // declarar suma como float para retornar un float??
    float suma=0;

    for(int i = 0; i< n; i++) {
        for(int j = 0; j< m; j++) {
            suma+=mat[i][j];
        }
    }

    return suma/(n*m);
}


void superanPromedio(int mat[][SYZE],int n,int m) {
    float prom;
    int cantElem0;
    prom=calcularPromedio(mat,n,m);

    for( int i=0; i<n; i++) {
        cantElem0=0;
        if(tieneCero(mat,i,m)) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]>prom) {
                    cantElem0++;
                }
            }
            printf("Cantidad de numeros de la fila %d que superan el promedio es: %d",i,cantElem0);
        }
    }
}


void mostrarPromedioColumna(int mat[][SYZE],int n,int m) { // FLOAT SUMA??
    float suma;
    for (int j=0; j<m; j++) {
        suma=0;
        for (int i=0; i<n; i++) {
            suma+=mat[i][j];
        }
        printf("El promedio de la columna %d es %.2f\n",j,suma/n);
    }
}
void buscarPosX(int mat[][SYZE],int n,int m,int x) {  // Probando con SIZE=3 N=3 M=3 // matriz = {{1,2,3},{4,5,6},{7,8,9}} => buscamos 7
    int i=0,j=0;
    /*CONCLUSION:LEER ESTE COMENTARIO CUANDO SE VEA TODO LO DE ABAJO, EN LA CONDICION DEL PRIMER BUCLE
     i<n es igual a 2<3 ,todo bien con eso pero mat[i,j]!=x no esta de acuerdo,ya que compara mat[1,3]!=7 pero
     como c gestiona los vectores mat[1,3] es igual a [2,0] por lo que en la tercera iteracion resulta i<n TRUE pero mat[i][j] FALSE
    saliendo del bucle*/

    while(i<n && mat[i][j]!=x) { //N Y M VALEN 3 PERO LA MATRIZ TIENE SIZE = 3 ENTONCES LA MATRIZ QUEDA DE ESTA FORMA(POSICIONES NO VALORES)
        /*[
        [0:0,0:1,0:2]
        [1:0,1:1,1:2]
        [2:0,1:1,2:2]
        ]*/

        //Primera Iteracion 0<3 TRUE Mat!=x TRUE
        //Segunda Iteracion 1<3 TRUE Mat!=x TRUE
        //TERCERA ITERACION 2<3 NO ENTRA
        while(j<m && mat[i][j]!=x) {
            j++;
            // Primera Iteracion 0<3 TRUE mat!=x TRUE //j++ =>1
            // Primera Iteracion 1<3 TRUE mat!=x TRUE //j++ =>2
            // Primera Iteracion 2<3 TRUE mat!=x TRUE //j++ =>3
            // Primera Iteracion 3<3 FALSE mat!=x TRUE => ROMPE CICLO CON i=0 y j=3

            // Segunda Iteracion 0<3 TRUE Mat!=x TRUE //j++ => 1
            // Segunda Iteracion 1<3 TRUE Mat!=x TRUE //j++ => 2
            // Segunda Iteracion 2<3 TRUE Mat!=x TRUE //j++ => 3
            // Segunda Iteracion 3<3 FALSE Mat!=x TRUE => ROMPE CICLO CON i=1 y j=3 PERO QUIEN VIVE EN [1][3]??? Mirar ARRIBA

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
