/*
Rehacer el ejercicio 12 suponiendo que los números se encuentran en un archivo de texto,
todos en la misma línea. ¿Como modificaría la lectura, si hubiera un valor por línea?
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
