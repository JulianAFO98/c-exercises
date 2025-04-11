/*
Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila.
a. Utilizar la implementación estática.
b. Utilizar la implementación dinámica.
c. Mantener la información en la pila.
*/


#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


void llenarPila(TipoP *);
void limpiarPila(TipoP *);
void mantenerInfo(TipoP *);
int main() {
    TipoP pila;
    iniciaP(&pila);
    llenarPila(&pila);
    mantenerInfo(&pila);
    //limpiarPila(&pila);
    return 0;
}

void llenarPila(TipoP *P) {
    FILE * arch;
    char c;
    arch = fopen("archivo.txt","r");

    if(arch == NULL) {
        printf("No se pudo abrir el archivo\n");
    } else {
        while(fscanf(arch,"%c",&c) == 1) {
            poneP(P,c);
        }
        fclose(arch);
    }
}


void limpiarPila(TipoP *p) {
    char aux;
    while(!vaciaP(*p)) {
        sacaP(p,&aux);
        printf("Elemento extraido %c\n",aux);
    }
}



void mantenerInfo(TipoP *p){
    TipoP pilaAux;
    char c;

    iniciaP(&pilaAux);
    while(!vaciaP(*p)) {
        sacaP(p,&c);
        poneP(&pilaAux,c);
        printf("Elemento extraido %c\n",c);
    }
    while(!vaciaP(pilaAux)) {
        sacaP(&pilaAux,&c);
        poneP(p,c);
    }
}

