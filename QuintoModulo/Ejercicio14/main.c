/*
Utilizar las estructuras que considere adecuadas para determinar si una palabra almacenada en
una cola es palíndroma. Se conoce de antemano la cantidad de letras de la palabra (N).
*/

#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include "pila.h"
void llenarCola(TC *C);
void limpiarCola(TC *C);
void verificarPalindromo(TC *C, unsigned int n, int *result);

int main(void)
{
    TC C;
    unsigned int n;
    int result;
    iniciaC(&C);
    llenarCola(&C);
    printf("Cuantas letras tenia la palabra ingresada?\n");
    scanf("%u", &n);
    verificarPalindromo(&C, n, &result); // Void, si se modifica la cola(parametro de salida) no puede ser int(booleano -> isPalindrome())
    printf(result ? "Es palindroma\n" : "No es palindroma\n");
}

void limpiarCola(TC *C)
{
    TEC e;
    while (!vaciaC(*C))
    {
        sacaC(C, &e);
        printf("%c", e.car);
    }
    printf("\n");
}
void llenarCola(TC *C)
{

    FILE *file;
    TEC e;

    file = fopen("archivo.txt", "r");

    if (file == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf(file, "%c", &e.car) == 1)
            poneC(C, e);
        fclose(file);
    }
}

void verificarPalindromo(TC *C, unsigned int n, int *result)
{
    unsigned int limite = n / 2, i = 0, contIguales = 0;
    TEC elemCola;
    TEP elemPila;
    TP pila;
    iniciaP(&pila);
    while (!vaciaC(*C))
    {
        if (i < limite)
        { // Al inicio de la palabra saco de cola y lo pongo en la pila aux
            sacaC(C, &elemCola);
            elemPila.c = elemCola.car; // ambos son caracteres pero tenia ganas de ponerle distinto nombre
            poneP(&pila, elemPila);
            i++;
        }
        else
        {
            if (i == limite && n % 2 == 1)
            { // Si estoy en la letra del medio y es una palabra de tamaño impar elimino la letra del medio
                sacaC(C, &elemCola);
                i++;
            }
            else
            { // Sigo con el resto de la palabra
                sacaC(C, &elemCola);
                sacaP(&pila, &elemPila);
                if (elemCola.car == elemPila.c)
                    contIguales++;
            }
        }
    }
    printf("%d %d\n", contIguales, limite);
    *result = contIguales == limite;
}