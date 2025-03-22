/*
 1- Desarrollar un programa que cree dinámicamente un arreglo de números reales que contenga N elementos
 (N es ingresado por teclado).
 2- Ingresar sus elementos y mostrar aquellos que sean positivos utilizando aritmética de punteros.
 3- Al finalizar, liberar la memoria solicitada en tiempo de ejecución.

*/
#include <stdio.h>
#include <stdlib.h>
//Primera Forma
/*
void mostrarVector(float [],int);
void llenarVector(float [],int);
*/

//Segunda forma con aritmeta de punteros
void mostrarVector(float *,int);
void llenarVector(float *,int);
void mostrarPositivos(float *,int);

int main() {
    //1
    int n;
    float *pv;
    printf("Ingrese n\n");
    scanf("%d",&n);
    pv = (float *) malloc(n*sizeof(float)); // es igual a float v[]
    llenarVector(pv,n);
    mostrarVector(pv,n);
    printf("\n");
    mostrarPositivos(pv,n);

    //printf("%f\n",pv[2]); // FUNCIONA
    free(pv);
    return 0;
}
//Primera Forma => llenado normal de un vector (mismo comportamiento)
/*
void mostrarVector(float v[],int n){
  for(int i=0;i<n;i++) {
      printf("%.2f ",v[i]);
    }
}

void llenarVector(float v[],int n){
  for(int i=0;i<n;i++) {
    scanf("%f",&v[i]);
  }
}
*/
//Segunda forma con aritmetica y pasando *pv
void mostrarVector(float *pv,int n) {

    for(int i=0; i<n; i++) {
        printf("%.2f ",*(pv+i));
    }
}

void llenarVector(float *pv,int n) {
    for(int i=0; i<n; i++) {
        scanf("%f",(pv+i));
    }
}

void mostrarPositivos(float *pv,int n) {

    for(int i=0; i<n; i++) {
        if(*(pv+i)>0) {
            printf("%.2f ",*(pv+i));
        }

    }

}

