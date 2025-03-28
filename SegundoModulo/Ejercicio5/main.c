/*
Desarrollar un programa que cree un arreglo estático de punteros a enteros, y luego cargue en
él una cantidad desconocida de enteros (se encuentran en un archivo de texto). Posteriormente
a la carga, mostrar aquellos que sean positivos. Luego, para finalizar, liberar la memoria
solicitada en tiempo de ejecución.

*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vp[20],n;

    printf("Ingrese n\n");
    scanf("%d",&n);

    //Crear variables dinamicas en cada valor del vector
    for(int i=0; i<n; i++) {
        vp[i] = (int *) malloc(sizeof(int));
        scanf("%d",vp[i]);

    }

    //Mostrar
    printf("Todos\n");
    for(int i=0; i<n; i++) {
        printf("%d\n",*vp[i]);
    }

    //Mostrar Positivos
    printf("Positivos\n");
    for(int i=0; i<n; i++) {
        if(*vp[i]>0) {
          printf("%d\n",*vp[i]);
        }
    }

    //Liberar memoria dinamica
    for(int i=0; i<n; i++) {
        free(vp[i]);
    }


    return 0;
}
