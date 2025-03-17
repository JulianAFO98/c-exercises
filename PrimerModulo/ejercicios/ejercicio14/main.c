/*
Desarrollar un subprograma que muestre un cuadrado con bordes de N numerales (N es
parámetro de entrada)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    generarCuadrado(16);
    return 0;
}


void generarCuadrado(int N) {
    unsigned int i,j;
    for(i=1; i<=N; i++) {
        for (j=1; j<=N; j++) {
            if(i==1 || i==N) {
                printf("# ");
            } else {
                if(j==1 || j==N) {
                    printf("# ");
                } else {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
}
