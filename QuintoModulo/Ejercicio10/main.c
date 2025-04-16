/*
Ingresar una secuencia de caracteres terminada en punto que representa una expresión
aritmética.
a. Comprobar que los paréntesis estén balanceados, de no ser así informar si falta
izquierdo o derecho. Los paréntesis son los únicos símbolos a controlar.
b. Agregar a la expresión la presencia y comprobación de corchetes y llaves.
*/

#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
void verificarParentesis(cola *C);
void limpiarCola(cola *C);
int main(void)
{
    cola C;
    iniciaC(&C);
    verificarParentesis(&C);
}

void verificarParentesis(cola *C)
{
    TEC e;
    unsigned int contIzq = 0, contDere = 0;
    while (consultaC(*C) != '.')
    {
        sacaC(C, &e);
        if (e == '(')
            contIzq++;
        if (e == ')')
            contIzq++;
        poneC(C, e);
    }

    if (contIzq == contDere)
        printf("We good");
    else
    {
        if (contDere > contIzq)
            printf("Falta parentesis Izquierdo");
        else
            printf("Falta parentesis derecho");
    }
}

void limpiarCola(cola *C)
{
    TEC e;
    while (!vaciaC(*C))
    {
        sacaC(C, &e);
    }
}
void llenarCola(cola *C)
{

    FILE *file;
    TEC e;

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