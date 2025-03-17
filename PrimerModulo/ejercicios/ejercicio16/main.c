/*
Desarrollar un subprograma que reciba una cantidad de segundos y devuelva su equivalente en
el formato horas:minutos:segundos
*/


#include <stdio.h>
#include <stdlib.h>

void convertirAHoraFormateada(int);


int main() {
    convertirAHoraFormateada(7641);
    return 0;
}


void convertirAHoraFormateada(int tiempoEnSegundos) {
    int horas,segundos,minutos;

    horas = tiempoEnSegundos / 3600;
    tiempoEnSegundos -= horas*3600;
    minutos = tiempoEnSegundos / 60;
    tiempoEnSegundos -= minutos*60;
    segundos=tiempoEnSegundos;

    printf("%d:%d:%d",horas,minutos,segundos);
}
