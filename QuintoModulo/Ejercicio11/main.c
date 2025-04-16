/*Simular una fila de empleados para usar un horno microondas en el comedor de una empresa.
Para cada empleado se tiene: su número de legajo, el momento de arribo (en segundos a partir
de las 12:00) y la cantidad de segundos que piensa usar el horno. El programa debe mostrar
para cada empleado el tiempo en que empieza y termina el uso del horno. Al finalizar mostrar
tiempo promedio de espera y legajo con mayor tiempo de espera.  */

#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#define DOCE_HORAS 43200

void llenarCola(cola *C);
void limpiarCola(cola *C);
void procesarInfoHorno(cola *C);
void convertirAFormatoHora(int segundos);
int main(void)
{
    cola C;
    iniciaC(&C);
    llenarCola(&C);
    procesarInfoHorno(&C);
    limpiarCola(&C);
    printf("Presione enter para continuar...");
    getchar();
}

void convertirAFormatoHora(int segundos)
{
    int horas = segundos / 3600;
    int minutos = (segundos % 3600) / 60;
    int seg = segundos % 60;

    printf("%02d:%02d:%02d\n", horas, minutos, seg);
}

void procesarInfoHorno(cola *C)
{
    empleado e;
    int llegada, empieza, salida = 0;
    unsigned int contEmp = 0, esperaTotal = 0, maxLegajo, maxTiempoEspera = 0, tiempoEspera;
    while (!vaciaC(*C))
    {
        sacaC(C, &e);
        contEmp++;
        llegada = e.tiempoSegundosArribo;
        empieza = salida;
        tiempoEspera = (empieza - llegada) < 0 ? 0 : (empieza - llegada);
        esperaTotal += tiempoEspera;
        salida = empieza + e.tiempoSegundosHorno;
        if (tiempoEspera > maxTiempoEspera)
        {
            maxTiempoEspera = tiempoEspera;
            maxLegajo = e.legajo;
        }
        // Mostrar datos y calcular
        printf("Datos empleado-> Legajo: %d\n", e.legajo);
        printf("Llegada ");
        convertirAFormatoHora(DOCE_HORAS + llegada);
        printf("Salida ");
        convertirAFormatoHora(DOCE_HORAS + salida);
    }

    if (contEmp != 0)
        printf("El tiempo de espera promedio en segundos fue %.2f\n", (float)esperaTotal / contEmp);
    else
        printf("No habia empleados\n");

    if (maxTiempoEspera != 0)
        printf("El legajo con mas tiempo de espera fue: %d con un tiempo de espera de %d\n", maxLegajo, maxTiempoEspera);
    else
        printf("No habia empleados o no hubo tiempo de espera\n");
}

void limpiarCola(cola *C)
{
    empleado e;
    while (!vaciaC(*C))
    {
        sacaC(C, &e);
        printf("Datos empleado-> Legajo: %d Llegada:%d Tiempo Horno:%d\n", e.legajo, e.tiempoSegundosArribo, e.tiempoSegundosHorno);
    }
}
void llenarCola(cola *C)
{

    FILE *file;
    empleado e;

    file = fopen("archivo.txt", "r");

    if (file == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf(file, "%d %d %d", &e.legajo, &e.tiempoSegundosArribo, &e.tiempoSegundosHorno) == 3)
            poneC(C, e);
        fclose(file);
    }
}