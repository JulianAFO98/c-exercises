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
void generarBinario(FILE **);
void mostrarBinario(FILE **);

int main()
{

    FILE * archBin;

    generarBinario(&archBin);
    mostrarBinario(&archBin);


    fclose(archBin);
    return 0;
}



void mostrarBinario(FILE **pArchBin) {

  Treg registro;

  *pArchBin = fopen("datosBinario.dat","r");

   if(*pArchBin == NULL) {
        printf("Error al abrir algun archivo.\n");
        return;
   }

  fread(&registro,sizeof(Treg),1,*pArchBin);
  while(!feof(*pArchBin)) {
      printf("%s %s %s %d %d\n",registro.patente,registro.fecha,registro.hora,registro.velPermitida,registro.velReg);
      fread(&registro,sizeof(Treg),1,*pArchBin);
  }


  fclose(*pArchBin);
}


void generarBinario(FILE **pArchBin) { // PREGUNTAR

  char aux;
  Treg registro;
  unsigned int totalMed=0,infracciones=0;

  FILE * archRadar = fopen("datosRadar.txt","r");
  *pArchBin = fopen("datosBinario.dat","wb");

   if(archRadar == NULL || *pArchBin == NULL) {
        printf("Error al abrir algun archivo.\n");
        return;
   }

  while(fscanf(archRadar,"%s%d%d%c%s%c%s",registro.patente,&registro.velReg,&registro.velPermitida,&aux,registro.fecha,&aux,registro.hora)== 7) {
    if((registro.velPermitida-registro.velReg)>registro.velPermitida*0.2) {
         fwrite(&registro,sizeof(Treg),1,*pArchBin);
         infracciones+=1;

    }
    totalMed+=1;
  }
   printf("Total mediciones: %d\n",totalMed);
   printf("Infracciones: %d\n",infracciones);

  fclose(archRadar);
  fclose(*pArchBin);
}
