/*Un sensor de temperatura realiza mediciones peri�dicas (una cada 5 seg.). Las mismas son
registradas en un archivo binario, donde cada elemento es de tipo float. Implementar un
programa que genere dicho archivo y, otro programa que lo lea y muestre por pantalla
temperatura promedio, m�xima y m�nima.*/

#include <stdio.h>
#include <stdlib.h>

void llenarArchivo(FILE **);
void leerArchivo(FILE **);

int main()
{
    FILE * arch;

    llenarArchivo(&arch);
    leerArchivo(&arch);
    return 0;
}


void leerArchivo(FILE **pArch) {

    float temp,suma=0,max=-300,min=300,n=0;

    *pArch = fopen("datos.dat","r");

    fread(&temp,sizeof(float),1,*pArch);
    while(!feof(*pArch)) {
        suma+=temp;
        n+=1;
        if(temp>max) {
            max=temp;
        }
        if(temp<min) {
            min=temp;
        }
        fread(&temp,sizeof(float),1,*pArch);
    }

    printf("Temperatura maxima %.2f\n",max);
    printf("Temperatura minima %.2f\n",min);
    printf("Temperatura promedio %.2f\n",suma/n);

    fclose(*pArch);

}





void llenarArchivo(FILE **pArch) {
    unsigned int n;
    float medicion;

    *pArch = fopen("datos.dat","wb");

    printf("Ingrese cuantas mediciones desea generar\n");
    scanf("%d",&n);
    for (int i = 0;i<n;i++) {
        printf("Ingrese medicion numero %d\n",i+1);
        scanf("%f",&medicion);
        fwrite(&medicion,sizeof(float),1,*pArch);
    }

    fclose(*pArch);

}
