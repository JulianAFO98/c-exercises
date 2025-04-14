/*Rehacer los ejercicios 2 y de 3 de pilas mediante subprogramas recursivos. Las pilas no deben
perder su información.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilaD.h"

void llenarPila(TipoP *);
void limpiarPila(TipoP *);
void mantenerInfoRec(TipoP *);
int main()
{
    TipoP pila;
    iniciaP(&pila);
    llenarPila(&pila);
    mantenerInfoRec(&pila);
    limpiarPila(&pila);
    return 0;
}

void llenarPila(TipoP *P)
{
    FILE *arch;
    char c;
    arch = fopen("archivo.txt", "r");

    if (arch == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        while (fscanf(arch, "%c", &c) == 1)
        {
            poneP(P, c);
        }
        fclose(arch);
    }
}

void limpiarPila(TipoP *p)
{
    char aux;
    while (!vaciaP(*p))
    {
        sacaP(p, &aux);
        printf("Elemento extraido %c\n", aux);
    }
}

void mantenerInfoRec(TipoP *p)
{
    char c;
    if (!vaciaP(*p))
    {
        sacaP(p, &c);
        printf("Elemento extraido %c\n", c);
        mantenerInfoRec(p);
        poneP(p, c);
    }
}