/*
Desarrollar un programa que reciba una expresión aritmética que contemple las cuatro
operaciones básicos (+, -, * y /) en notación postfija (polaca invertida) y devuelva su valor, a
menos que ocurra un error porque la expresión no sea válida. Las expresiones postfijas no
necesitan paréntesis para especificar el orden de las operaciones. Ej: 5 *(1+3) en notación
posfija es 5 1 3 + *. Los operandos se limitan a números de un solo dígito y son leídos como
caracteres, de la misma manera que los operacion.
 */

#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

void llenarDatos(TipoPila *operacion);
void eliminarPila(TipoPila *pila);
void mostrarResultado(TipoPila *operacion);

int main(void)
{
    TipoPila operacion;
    iniciaP(&operacion);
    llenarDatos(&operacion);
    mostrarResultado(&operacion);
    eliminarPila(&operacion);
}

void mostrarResultado(TipoPila *operacion)
{
    char car;
    if (!vaciaP(*operacion))
    {
        sacaP(operacion, &car);
        if (!vaciaP(*operacion))
            printf("Algo fallo\n");
        else
            printf("%d\n", car - '0');
    }
}

void eliminarPila(TipoPila *pila)
{
    char car;

    while (!vaciaP(*pila))
    {
        sacaP(pila, &car);
        printf("%c", car);
    }
    printf("\n");
}

void llenarDatos(TipoPila *operacion)
{
    char car, num1, num2, result;
    int num1Int, num2Int, r;
    FILE *arch;
    arch = fopen("archivo.txt", "r");
    if (arch == NULL)
    {
        printf("El archivo no existe o no se encontro");
    }
    else
    {
        while (fscanf(arch, "%c", &car) == 1)
        {
            if (car == '+' || car == '*' || car == '-' || car == '/')
            {
                if (!vaciaP(*operacion))
                {
                    sacaP(operacion, &num1);
                    if (!vaciaP(*operacion))
                    {
                        sacaP(operacion, &num2);
                        num1Int = num1 - '0';
                        num2Int = num2 - '0';

                        switch (car)
                        {
                        case '+':
                            r = num2Int + num1Int;
                            break;
                        case '-':
                            r = num2Int - num1Int;
                            break;
                        case '*':
                            r = num2Int * num1Int;
                            break;
                        case '/':
                            if (num1Int != 0)
                                r = num2Int / num1Int;
                            else
                                printf("Error: división por cero\n");
                            break;
                        }
                        poneP(operacion, r + '0');
                    }
                }
            }
            else
                poneP(operacion, car);
        }

        fclose(arch);
    }
}