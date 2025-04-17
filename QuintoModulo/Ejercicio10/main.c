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
void llenarCola(cola *C);

int main(void)
{
    cola C;
    iniciaC(&C);
    llenarCola(&C);
    verificarParentesis(&C);
    limpiarCola(&C);
}

void verificarParentesis(cola *C)
{
    TEC e;
    unsigned int contParentesisIzq = 0, contParentesisDere = 0, contLlaveIzq = 0, contLlaveDere = 0, contCorcheteIzq = 0, contCorcheteDere = 0;
    while (consultaC(*C) != '.')
    {
        sacaC(C, &e);
        switch (e)
        {
        case ')':
            contParentesisDere++;
            break;
        case '(':
            contParentesisIzq++;
            break;
        case '[':
            contCorcheteIzq++;
            break;
        case ']':
            contCorcheteDere++;
            break;
        case '{':
            contLlaveIzq++;
            break;
        case '}':
            contLlaveDere++;
            break;
        }
        poneC(C, e);
    }

    if (contParentesisIzq == contParentesisDere)
        printf("We good parentesis\n");
    else
    {
        if (contParentesisDere > contParentesisIzq)
            printf("Falta parentesis Izquierdo\n");
        else
            printf("Falta parentesis derecho\n");
    }

    if (contCorcheteDere == contCorcheteIzq)
        printf("We good corchetes\n");
    else
    {
        if (contCorcheteDere > contCorcheteIzq)
            printf("Falta corchete Izquierdo\n");
        else
            printf("Falta corchete derecho\n");
    }

    if (contLlaveDere == contLlaveIzq)
        printf("We good llaves\n");
    else
    {
        if (contCorcheteDere > contLlaveIzq)
            printf("Falta llave Izquierdo\n");
        else
            printf("Falta llave derecho\n");
    }

    sacaC(C, &e);
}

void limpiarCola(cola *C)
{
    TEC e;
    while (!vaciaC(*C))
    {
        sacaC(C, &e);
        printf("%c", e);
    }
    printf("\n");
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
        while (fscanf(file, "%c", &e) == 1)
            poneC(C, e);
        fclose(file);
    }
}