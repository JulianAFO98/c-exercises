/*
Leer el nombre y la edad de N personas, calcular e imprimir:
a) el listado de nombres de las personas de más de X años (X es dato).
b) el porcentaje de las personas mayores de edad (sobre el total).

*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE 256
typedef struct {
    char nombre[100];
    int edad;
} TPersona;

void llenarVector(TPersona [],int);
void mostrarVector(TPersona [], unsigned int);
float porcentajeMayoresDeEdad(TPersona [], unsigned int);
void mostrarMayoresQueX(TPersona [], unsigned int, unsigned int);


int main() {
    unsigned int  n,x;
    TPersona personas[SIZE];

    printf("Ingrese cuantas personas quiere ingresar\n");
    scanf("%d",&n);
    getchar();
    llenarVector(personas,n);
    mostrarVector(personas,n);
    printf("Ingrese x\n");
    scanf("%d",&x);
    getchar();
    mostrarMayoresQueX(personas,n,x);
    printf("Porcentaje de personas mayores de edad: %.2f",porcentajeMayoresDeEdad(personas,n));
    return 0;
}


void llenarVector(TPersona personas[],int cantPersonas) {
    TPersona persona;
    for (int i=0; i<cantPersonas; i++) {
        printf("Ingrese el nombre de la persona %d\n",i);
        gets(persona.nombre);
        printf("Ingrese la edad de la persona %d\n",i);
        scanf("%d",&persona.edad);
        getchar();
        personas[i]=persona;
    }

}

void mostrarVector(TPersona personas[],unsigned int cantPersonas) {

    for (int i=0; i<cantPersonas; i++) {
        printf("Nombre de la persona %d\n",i);
        puts(personas[i].nombre);
        printf("Edad de la persona %d es %d\n",i,personas[i].edad);

    }
    printf("\n");

}

void mostrarMayoresQueX(TPersona personas[], unsigned int cantPersonas,unsigned int x) {
    printf("Nombre de aquellos con mas de %d anios \n", x);

    for (int i=0; i<cantPersonas; i++) {
        if(personas[i].edad > x) {
            puts(personas[i].nombre);
            printf("\n");
        }


    }

}
float porcentajeMayoresDeEdad(TPersona personas[], unsigned int cantPersonas) {
    unsigned int cont = 0;
    for (int i=0; i<cantPersonas; i++) {
        if(personas[i].edad >=18) {
            cont++;
        }


    }
   return (float) cont / cantPersonas;
}

