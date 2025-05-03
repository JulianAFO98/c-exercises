/*
Dada una lista doblemente enlazada que contiene los inscriptos a un curso, en la que en cada
nodo se tiene:
• Apellido (ordenada por este campo)
• Nombre (los inscriptos con el mismo apellido, se ordenan por este campo)
• Categoría (docente, alumno, externo)
a) listarlos en orden alfabético, indicando el importe total recaudado. El valor del curso es un
dato leído por teclado, los docentes tienen un 30% de descuento, y los alumnos un 10%.
b) listar los inscriptos externos en orden alfabético descendente.
c) verificar si existe una persona con apellido X (dato) y nombre Y (dato) dentro de la lista de
inscriptos
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
void llenarLista(TListaD *L);
void mostrarLista(TListaD L);
void listarIndicandoImporte(TListaD L, float valorCurso);
void listarEnFormaInversa(TListaD L);
int existe(TListaD L, char nombre[100], char apellido[100]);
int main(void)
{
    TListaD lista;
    float valorCurso;
    lista.pri = lista.ult = NULL;
    llenarLista(&lista);
    mostrarLista(lista);
    // printf("Ingrese el valor del curso\n");
    // scanf("%f", &valorCurso);
    // listarIndicandoImporte(lista, valorCurso);
    // listarEnFormaInversa(lista);
    printf(existe(lista, "Martinez", "Joaquin") ? "Existe\n" : "No existe\n");
    return 0;
}
int existe(TListaD L, char apellido[100], char nombre[100])
{
    int encontrada = 0;
    nodo *aux = L.pri;
    while (aux != NULL && strcmp(aux->apellido, apellido) < 0)
        aux = aux->sig;

    while (aux != NULL && strcmp(aux->apellido, apellido) == 0)
    {
        if (strcmp(aux->nombre, nombre) == 0)
            encontrada = 1;
        aux = aux->sig;
    }

    return encontrada;
}

void listarEnFormaInversa(TListaD L)
{
    nodo *aux = L.ult;
    while (aux != NULL)
    {
        if (aux->categoria == 'E')
            printf("%s %s %c\n", aux->apellido, aux->nombre, aux->categoria);
        aux = aux->ant;
    }
}

void listarIndicandoImporte(TListaD L, float valorCurso)
{
    nodo *aux = L.pri;
    float valorRecaudado = 0;
    while (aux != NULL)
    {
        printf("%s %s %c\n", aux->apellido, aux->nombre, aux->categoria);
        if (aux->categoria == 'D')
        {
            valorRecaudado += valorCurso * 0.7;
        }
        else
        {
            if (aux->categoria == 'A')
                valorRecaudado += valorCurso * 0.9;
            else
                valorRecaudado += valorCurso;
        }
        aux = aux->sig;
    }
    printf("Valor recaudado total %.2f\n", valorRecaudado);
}

void mostrarLista(TListaD L)
{
    nodo *aux = L.pri;

    while (aux != NULL)
    {
        printf("%s %s %c\n", aux->apellido, aux->nombre, aux->categoria);
        aux = aux->sig;
    }
}

void llenarLista(TListaD *L)
{
    nodo *nuevo;
    FILE *arch;
    arch = fopen("archivo.txt", "r");
    char apellido[100];
    char nombre[100];
    char categoria;
    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf(arch, "%s %s %c\n", apellido, nombre, &categoria) == 3)
        {
            nuevo = (nodo *)malloc(sizeof(nodo));
            strcpy(nuevo->apellido, apellido);
            strcpy(nuevo->nombre, nombre);
            nuevo->categoria = categoria;
            if ((*L).pri == NULL)
            {
                nuevo->sig = NULL;
                nuevo->ant = NULL;
                (*L).pri = (*L).ult = nuevo;
            }
            else
            {
                nuevo->ant = (*L).ult;
                nuevo->sig = NULL;
                (*L).ult->sig = nuevo;
                (*L).ult = nuevo;
            }
        }
    }
}
