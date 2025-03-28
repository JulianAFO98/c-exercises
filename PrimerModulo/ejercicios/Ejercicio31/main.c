/*
El ranking de una asociación de tenistas es registrada en un archivo binario. Para cada jugador
se registra apellido y nombre, nacionalidad y puntaje. Realizar un subprograma que muestre los
datos del jugador ubicado en una posición recibida como parámetro.
*/


#include <stdio.h>
#include <stdlib.h>
#define CANTTENISTAS 2
typedef struct {
    char apellido[30];
    char nombre[30];
    char nacionalidad[30];
    float puntaje;
} TipoTenista;

void llenarBinario();
void mostrarDatosJugador(unsigned int);

int main() {

    unsigned int n;

    llenarBinario();
    printf("Ingrese una posicion a buscar\n");
    scanf("%d",&n);
    mostrarDatosJugador(n);

    return 0;
}


void mostrarDatosJugador(unsigned int pos) {

    TipoTenista tenista;

    FILE * arch = fopen("datos.dat","r");

    if(arch  == NULL) {
        printf("No se pudo abrir el archivo");
    } else {
        fseek(arch,pos*sizeof(TipoTenista),SEEK_CUR); // Preguntar
        fread(&tenista,sizeof(TipoTenista),1,arch);

        printf("nombre tenista %s\n",tenista.nombre);
        printf("apellido tenista %s\n",tenista.apellido);
        printf("nacionalidad tenista %s\n",tenista.nacionalidad);
        printf("puntaje tenista %f\n",tenista.puntaje);

    }

   fclose(arch);

}



void llenarBinario() {

    TipoTenista tenista;


    FILE * arch = fopen("datos.dat","wb");

    if(arch  == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }else {
        for (int i=0; i<CANTTENISTAS; i++) {
            printf("Ingrese nombre tenista\n");
            gets(tenista.nombre);
            printf("Ingrese apellido tenista\n");
            gets(tenista.apellido);
            printf("Ingrese nacionalidad tenista\n");
            gets(tenista.nacionalidad);
            printf("Ingrese puntaje tenista\n");
            scanf(" %f",&tenista.puntaje);
            getchar();
            fwrite(&tenista,sizeof(TipoTenista),1,arch);
        }
        fclose(arch);
    }



}
