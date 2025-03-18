
/*Desarrollar un programa que lea un vector y, mediante opciones de un menú, calcule e imprima
lo siguiente:
a) los elementos en posiciones impares 1,3,5 o sea segundo, cuarto, sexto...
b) genere otro vector con los elementos divisibles por k (k dato). Muestre el nuevo vector con
otra función
c) busca la posición de un valor x (puede no existir)

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 256


void llenarVector(int [],int);
void mostrarVector(int [],int);
void mostrarOpciones();
void mostrarElemEnPosImpares(int [],int);
void generarNuevoVector(int [],int [],int,int *pm,int);
int buscarX(int[],int,int);

int main() {
    int v[SIZE],v2[SIZE],k,n,m,opcion,x,posX;


    printf("Ingrese cuantos valores tendra el vector\n");
    scanf("%d",&n);
    llenarVector(v,n);
    mostrarVector(v,n);
    mostrarOpciones();
    printf("Ingrese su accion a realizar\n");
    scanf("%d",&opcion);
    switch(opcion) {
    case 1:
        mostrarElemEnPosImpares(v,n);
        break;
    case 2:
        printf("Ingrese k\n");
        scanf("%d",&k);
        generarNuevoVector(v,v2,n,&m,k);
        mostrarVector(v2,m);
        break;
    case 3:
        printf("Ingrese un valor x a buscar\n");
        scanf("%d",&x);
        posX=buscarX(v,n,x);
        if(posX) { // Pos X puede ser 0 o !=0
            printf("El valor se encuentra en la posicion %d\n",posX);
        } else {
            printf("No se encontro el valor\n");
        }
        break;
    default:
        printf("Ingrese una opcion erroneo\n");
    }
    return 0;
}

void generarNuevoVector(int v[],int v2[],int n,int *pm,int k) {
    *pm = 0;
    for (int i=0; i<n; i++) {
        if(v[i] % k == 0) {
            v2[*pm] = v[i];
            (*pm)++;

        }
    }
}


int buscarX(int v[],int n,int x) {
    unsigned int i=0;

    while (i<n && v[i]!=x) {
        i++;
    }

    return (i<n) ? i : 0;
}

void llenarVector(int v[],int n) {

    printf("Ingrese valores ENTEROS\n");

    for (int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }

}

void mostrarVector(int v[],int n) {
    for (int i=0; i<n; i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void mostrarOpciones() {
    printf("1- Mostrar elementos en posiciones impares\n");
    printf("2- Genere otro vector con los elementos divisibles por k\n");
    printf("3- Busca la posición de un valor x (puede no existir)\n");
}

void mostrarElemEnPosImpares(int v[],int n) {

    for (int i=1; i<n; i+=2) {
        printf("%d",v[i]);
    }
}

