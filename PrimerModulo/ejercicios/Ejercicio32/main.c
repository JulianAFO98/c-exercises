/*
En un archivo binario se registran temperaturas diarias m�xima y m�nima para algunas ciudades
del pa�s en un mes determinado. Cada registro tiene los siguientes campos: ciudad (cadena de
20, archivo ordenado por este campo), d�a del mes (1..30), temperatura m�xima (float),
temperatura m�nima (float). Listar para cada ciudad sus temperaturas m�ximas y m�nimas en el
mes; y al final del listado la ciudad que tuvo la menor temperatura en el mes, indicando el d�a.
*/


#include <stdio.h>
#include <stdlib.h>
#define CANTCIUDADES 2

typedef struct {
    char ciudad[21];
    unsigned short int dia;
    float tempMax;
    float tempMin;
}  regClima;

void llenarBinario(FILE **);
void corteDeControl(FILE **);

int main() {
    FILE * arch;
    llenarBinario(&arch);
    corteDeControl(&arch);
    return 0;
}


void corteDeControl(FILE **arch){
    regClima registro;
    char ciudadActual[21],ciudadMinima[21];
    float minima=200;
    unsigned short int diaMinima;


    *arch = fopen("datos.dat","rb");

    if(*arch == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

    fread(&registro,sizeof(regClima),1,*arch);
    while(!feof(*arch)) {

     strcpy(ciudadActual,registro.ciudad);
     printf("Temperaturas de la ciudad %s\n",ciudadActual);

     while(!feof(*arch) && strcmp(ciudadActual,registro.ciudad)==0) {
        if(registro.tempMin<minima) {
            minima=registro.tempMin;
            diaMinima=registro.dia;
            strcpy(ciudadMinima,registro.ciudad);
        }
        printf("Dia %d Max:%.2f Min:%.2f\n",registro.dia,registro.tempMax,registro.tempMin);
        fread(&registro,sizeof(regClima),1,*arch);
     }
    }


   printf("La ciudad mas fria fue: %s en el dia %d",ciudadMinima,diaMinima);


    fclose(*arch);

}


void llenarBinario(FILE ** arch) {
    regClima registro;

    *arch = fopen("datos.dat","wb");

    if(*arch == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

    for (int i=0; i<CANTCIUDADES; i++) {
        printf("Ingrese nombre ciudad\n");
        gets(registro.ciudad);
        printf("Ingrese dia\n");
        scanf("%d",&registro.dia);
        printf("Ingrese temp max\n");
        scanf("%f",&registro.tempMax);
        printf("Ingrese  temp minima\n");
        scanf("%f",&registro.tempMin);
        getchar();
        fwrite(&registro,sizeof(regClima),1,*arch);
    }



    fclose(*arch);
}
