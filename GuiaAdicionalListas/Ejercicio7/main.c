
/*
A partir de la lista de equipos de fútbol con sublista de jugadores del ejercicio 6 de la práctica 6
de Listas, crear una lista doblemente enlazada con los equipos que tengan algún jugador mayor
de 30 años. Para cada equipo registrar cantidad de jugadores y edad promedio. La estructura
de cada nodo de la lista doble es la siguiente:
• Nombre del equipo (ordenada por este campo)
• Cantidad de jugadores
• Edad promedio
*/

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void llenarLista(TLista *L);
void mostrarLista(TLista L);
void generarListaDoble(TLista L, TListaD *LD);
void mostrarListaDoble(TListaD LD);
int main(void)
{
    TLista lista = NULL;
    TListaD listaDoble;
    listaDoble.pri = listaDoble.ult = NULL;
    llenarLista(&lista);
    mostrarLista(lista);
    generarListaDoble(lista, &listaDoble);
    mostrarListaDoble(listaDoble);
    return 0;
}

void mostrarListaDoble(TListaD LD)
{
    nodoD *aux = LD.pri;
    printf("\n-------------------\n");
    while (aux != NULL)
    {
        printf("Equipo %s de %u jugadores con promedio de edad %.2f\n", aux->nombre, aux->cantJugadores, aux->edadProm);
        aux = aux->sig;
    }
}

void generarListaDoble(TLista L, TListaD *LD)
{
    TLista aux = L;
    nodito *auxJugador;
    nodoD *nuevo, *act;
    unsigned int bandera, cantJugadores, sumEdad;

    while (aux != NULL)
    {
        sumEdad = 0;
        cantJugadores = 0;
        bandera = 0;
        auxJugador = aux->sub;
        while (auxJugador != NULL)
        {
            if (auxJugador->dato.edad > 30)
                bandera = 1;
            cantJugadores++;
            sumEdad += auxJugador->dato.edad;
            auxJugador = auxJugador->sig;
        }
        if (bandera)
        {
            nuevo = (nodoD *)malloc(sizeof(nodoD));
            nuevo->cantJugadores = cantJugadores;
            nuevo->edadProm = (float)sumEdad / cantJugadores;
            strcpy(nuevo->nombre, aux->dato.nombre);

            if ((*LD).pri == NULL || strcmp(nuevo->nombre, (*LD).pri->nombre) < 0)
            {
                nuevo->sig = (*LD).pri;
                nuevo->ant = NULL;
                if ((*LD).pri == NULL)
                    (*LD).ult = nuevo;
                else
                    (*LD).pri->ant = nuevo;
                (*LD).pri = nuevo;
            }
            else
            {
                if (strcmp((*LD).ult->nombre, nuevo->nombre) < 0)
                {
                    nuevo->sig = NULL;
                    (*LD).ult->sig = nuevo;
                    nuevo->ant = (*LD).ult;
                    (*LD).ult = nuevo;
                }
                else
                {
                    act = (*LD).pri;
                    while (strcmp(act->nombre, nuevo->nombre) < 0)
                        act = act->sig;

                    nuevo->sig = act;
                    nuevo->ant = act->ant;
                    act->ant->sig = nuevo;
                    act->ant = nuevo;
                }
            }
        }
        aux = aux->sig;
    }
}

void llenarLista(TLista *L)
{
    char nombreEquipo[50], nombreJugador[50], activo;
    unsigned int edad, puntaje;
    TLista aux;
    subLista subAux, nuevo;
    FILE *arch, *arch2;

    arch = fopen("equipos.txt", "r");

    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf(arch, "%s %d", nombreEquipo, &puntaje) == 2)
        {
            aux = (TLista)malloc(sizeof(nodo));
            strcpy(aux->dato.nombre, nombreEquipo);
            aux->dato.puntaje = puntaje;
            aux->sub = NULL;
            aux->sig = *L;
            *L = aux;
        }
        fclose(arch);
    }

    arch2 = fopen("jugadores.txt", "r");

    if (arch2 == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        aux = *L;
        while (aux != NULL)
        {
            subAux = aux->sub;
            while (fscanf(arch2, "%s %d %c", nombreJugador, &edad, &activo) == 3)
            {
                nuevo = (subLista)malloc(sizeof(nodito));
                strcpy(nuevo->dato.nombre, nombreJugador);
                nuevo->dato.edad = edad;
                nuevo->dato.estaActivo = activo;
                nuevo->sig = subAux;
                subAux = nuevo;
            }
            aux->sub = subAux;
            aux = aux->sig;
        }
        fclose(arch2);
    }
}

void mostrarLista(TLista L)
{
    TLista aux = L;
    subLista subAux;
    while (aux != NULL)
    {
        printf("Equipo:%s Puntaje:%d\n", aux->dato.nombre, aux->dato.puntaje);
        subAux = aux->sub;
        while (subAux != NULL)
        {
            printf("Nombre jugador:%s Edad%d Estado:%c\n", subAux->dato.nombre, subAux->dato.edad, subAux->dato.estaActivo);
            subAux = subAux->sig;
        }
        aux = aux->sig;
    }
}