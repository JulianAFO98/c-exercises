/*
Rehacer el ejercicio 12 suponiendo que los n�meros se encuentran en un archivo de texto,
todos en la misma l�nea. �Como modificar�a la lectura, si hubiera un valor por l�nea?
*/



#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arch;
    int num,sum=0;

    arch = fopen("datos.txt","r");

    if(arch == NULL) {
        printf("Error al abrir el archivo");

    }else {
        while(fscanf(arch,"%d",&num) == 1) {
            sum+=num;
        };
        printf("%d",sum);
        fclose(arch);
    }



    return 0;
}
