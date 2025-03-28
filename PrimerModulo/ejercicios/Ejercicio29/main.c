/*Un sensor de temperatura realiza mediciones periódicas (una cada 5 seg.). Las mismas son
registradas en un archivo binario, donde cada elemento es de tipo float. Implementar un
programa que genere dicho archivo y, otro programa que lo lea y muestre por pantalla
temperatura promedio, máxima y mínima.*/

#include <stdio.h>
#include <stdlib.h>

void llenarArchivo();
void leerArchivo();

int main()
{

    llenarArchivo();
    leerArchivo();
    return 0;
}


void leerArchivo() {
    float temp,suma=0,max=-300,min=300,n=0;

    FILE * arch=fopen("datos.dat","r");

    if(arch == NULL) {
        printf("Error al intentar leer el archivo");
    }else {
        fread(&temp,sizeof(float),1,arch);
        while(!feof(arch)) {
            suma+=temp;
            n+=1;
            if(temp>max) {
                max=temp;
            }
            if(temp<min) {
                min=temp;
            }
            fread(&temp,sizeof(float),1,arch);
        }

        printf("Temperatura maxima %.2f\n",max);
        printf("Temperatura minima %.2f\n",min);
        printf("Temperatura promedio %.2f\n",suma/n);

        fclose(arch);
    }

}





void llenarArchivo() {
    unsigned int n;
    float medicion;

    FILE * arch = fopen("datos.dat","wb");

    if(arch == NULL) {
        printf("Error al crear el archivo");
    }else {
        printf("Ingrese cuantas mediciones desea generar\n");
        scanf("%d",&n);
        for (int i = 0; i<n; i++) {
            printf("Ingrese medicion numero %d\n",i+1);
            scanf("%f",&medicion);
            fwrite(&medicion,sizeof(float),1,arch);
        }

        fclose(arch);
    }

}
