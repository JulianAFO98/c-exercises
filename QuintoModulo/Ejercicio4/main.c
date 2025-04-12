/*Ingresar en una cola los números almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la cola.
a. Utilizar la implementación estática no circular.
b. Utilizar la implementación dinámica.
c. Mantener la información en la cola. 
*/
#include <stdlib.h>
#include <stdio.h>
// cambiar por D para usar dinamica y descomentar el codigo del colaD.c y colaD.h
#include "colaE.h" 


void ingresarTexto(TC *C);
void mostrarTexto(TC *C);
void mostrarManteniendo(TC*C);
int main(void){
    TC cola;
    iniciaC(&cola);
    ingresarTexto(&cola);
    mostrarManteniendo(&cola);
    mostrarTexto(&cola);
    return 0;
}

void ingresarTexto(TC *C){
    FILE * arch;
    TEC e;
    arch = fopen("archivo.txt","r");
    if(arch == NULL) {
        printf("No se pudo abrir el archivo");
    }else {
        while(fscanf(arch,"%c",&e.car) == 1) {
            poneC(C,e);
        }
        fclose(arch);
    }
}

void mostrarTexto(TC *C) {
    TEC e;
    while(!vaciaC(*C)) {
        sacaC(C,&e);
        printf("%c",e.car);
    }
    printf("\n");
}

void mostrarManteniendo(TC * C){
    TEC e,centinela;
    centinela.car='@';
    poneC(C,centinela);
    while(consultaC(*C).car!='@') {
        sacaC(C,&e);
        printf("%c",e.car);
        poneC(C,e);
    }
    printf("\n");
    sacaC(C,&centinela);
}