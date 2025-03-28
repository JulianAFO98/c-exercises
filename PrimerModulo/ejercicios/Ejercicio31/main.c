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

void llenarBinario(FILE **);
void mostrarDatosJugador(FILE **,unsigned int);

int main() {
    FILE * arch;
    unsigned int n;

    llenarBinario(&arch);
    printf("Ingrese una posicion a buscar\n");
    scanf("%d",&n);
    mostrarDatosJugador(&arch,n);

    return 0;
}


void mostrarDatosJugador(FILE **pArch,unsigned int pos) {

    TipoTenista tenista;

    *pArch = fopen("datos.dat","r");

    if(*pArch == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

    fseek(*pArch,pos*sizeof(TipoTenista),SEEK_CUR); // Preguntar
    fread(&tenista,sizeof(TipoTenista),1,*pArch);

    printf("nombre tenista %s\n",tenista.nombre);
    printf("apellido tenista %s\n",tenista.apellido);
    printf("nacionalidad tenista %s\n",tenista.nacionalidad);
    printf("puntaje tenista %f\n",tenista.puntaje);


}



void llenarBinario(FILE **pArch) {

    TipoTenista tenista;


    *pArch = fopen("datos.dat","wb");

    if(*pArch == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

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
        fwrite(&tenista,sizeof(TipoTenista),1,*pArch);
    }


    fclose(*pArch);

}
