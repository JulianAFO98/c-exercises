/*
Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo, velocidad registrada, velocidad máxima permitida,
fecha y hora de la medición. Cada dato está separado por un espacio. El programa debe
generar un archivo binario con los registros donde la velocidad registrada supere en más de un
20% a la velocidad máxima. Cada registro del archivo binario contiene los mismos datos que el
archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones procesadas y la
cantidad de registros generados en el archivo binario
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char patente[7];
    char hora[6];
    char fecha[11];
    int velReg;
    int velPermitida;
}  Treg;
void generarBinario();
void mostrarBinario();

int main() {
    generarBinario();
    mostrarBinario();
    return 0;
}



void mostrarBinario() {

    Treg registro;

    FILE * archBin = fopen("datosBinario.dat","r");

    if(archBin == NULL) {
        printf("Error al abrir algun archivo.\n");
        return;
    } else {

        fread(&registro,sizeof(Treg),1,archBin);
        while(!feof(archBin)) {
            printf("%s %s %s %d %d\n",registro.patente,registro.fecha,registro.hora,registro.velPermitida,registro.velReg);
            fread(&registro,sizeof(Treg),1,archBin);
        }


        fclose(archBin);

    }

}


void generarBinario() { // PREGUNTAR

    char aux;
    Treg registro;
    unsigned int totalMed=0,infracciones=0;

    FILE * archRadar = fopen("datosRadar.txt","r");
    FILE * archBin = fopen("datosBinario.dat","wb");

    if(archRadar == NULL || archBin == NULL) {
        printf("Error al abrir algun archivo.\n");
    } else {
        while(fscanf(archRadar,"%s%d%d%c%s%c%s",registro.patente,&registro.velReg,&registro.velPermitida,&aux,registro.fecha,&aux,registro.hora)== 7) {
            if((registro.velPermitida-registro.velReg)>registro.velPermitida*0.2) {
                fwrite(&registro,sizeof(Treg),1,archBin);
                infracciones+=1;

            }
            totalMed+=1;
        }
        printf("Total mediciones: %d\n",totalMed);
        printf("Infracciones: %d\n",infracciones);

        fclose(archRadar);
        fclose(archBin);


    }

}
