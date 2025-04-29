/*
Se tiene una lista con equipos de fútbol (nombre y puntaje en el torneo), la cual está ordenada
descendentemente por puntaje (los equipos con el mismo puntaje están ordenados
alfabéticamente). Cada equipo cuenta con una sublista de jugadores (nombre y edad, estado
([A]ctivo, [S]uspendido)).
a) Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al
finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que
cumplan el criterio solicitado.
b) Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
mostrando edad promedio de cada equipo.
c) Verificar si el equipo E (dato) tiene P (dato) puntos.
d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos.
*/

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void llenarLista(TLista *L);
void mostrarLista(TLista L);
void listarNombreK(TLista L, char K);
void mostrarMinimoX(TLista L, unsigned int X);
int verificarPunt(TLista L, char[50], unsigned int);
void eliminarSuspendidos(TLista L);
int main(void)
{
    TLista lista = NULL;
    char K;
    unsigned int X, punt;
    char equipo[50];
    llenarLista(&lista);
    /*printf("Ingrese una letra para buscar nombres en equipos\n");
    scanf("%c", &K);
    getchar();
    listarNombreK(lista, K);
    printf("Ingrese una cantidad de puntos\n");
    scanf("%d", &X);
    mostrarMinimoX(lista, X);
    printf("Ingrese un equipo para verificar su puntuacion\n");
    scanf("%s", equipo);
    printf("Ingrese la puntuacion\n");
    scanf("%d", &punt);
    printf(verificarPunt(lista, equipo, punt) ? "Si tiene esa puntuacion\n" : "No tiene esa puntuacion");
    */
    eliminarSuspendidos(lista);
    mostrarLista(lista);
    return 0;
}

void eliminarSuspendidos(TLista L) // Preguntar
{
    TLista aux = L;
    subLista act, ant, subaux;
    while (aux != NULL)
    {
        subaux = aux->sub;
        while (subaux != NULL)
        {
            act = subaux;
            while (act != NULL && act->dato.estaActivo != 'S')
            {
                ant = act;
                act = act->sig;
            }
            if (act != NULL)
            {
                if (act == aux->sub) // Si es el primero
                {
                    aux->sub = aux->sub->sig; // adelanto la sub lista una posicion e igualo sub aux a ese puntero
                    subaux = aux->sub;
                }
                else
                {
                    ant->sig = act->sig; // uno el ant con el siguiente al actual
                    subaux = act->sig;   // me paro en el siguiente al que voy a eliminar
                }
                free(act);
            }
            else
                subaux = subaux->sig;
        }
        aux = aux->sig;
    }
}

int verificarPunt(TLista L, char equipo[50], unsigned int punt)
{

    TLista aux = L;
    subLista subAux;
    while (aux != NULL && strcmp(aux->dato.nombre, equipo) != 0)
        aux = aux->sig;

    return aux != NULL && aux->dato.puntaje == punt;
}

void mostrarMinimoX(TLista L, unsigned int X)
{
    unsigned int cont, suma;
    TLista aux = L;
    subLista subAux;
    while (aux != NULL)
    {
        if ((aux->dato.puntaje) >= X)
        {
            printf("Equipo:%s Puntaje:%d\n", aux->dato.nombre, aux->dato.puntaje);
            cont = 0;
            suma = 0;
            subAux = aux->sub;
            while (subAux != NULL)
            {
                printf("Nombre jugador:%s Edad%d Estado:%c\n", subAux->dato.nombre, subAux->dato.edad, subAux->dato.estaActivo);
                cont++;
                suma += subAux->dato.edad;
                subAux = subAux->sig;
            }
            if (cont != 0)
                printf("Promedio de edad del equipo:%.2f \n", (float)suma / cont);
            else
                printf("El equipo no tiene jugadores\n");
        }
        aux = aux->sig;
    }
}

void listarNombreK(TLista L, char K)
{
    TLista aux = L;
    subLista subAux;
    unsigned int cantList = 0;
    unsigned int contNombConKPorEquipo, maxNombConKPorEquipo = 0;
    char nombreEquipoMax[50];
    while (aux != NULL)
    {
        printf("Equipo:%s\n", aux->dato.nombre, aux->dato.puntaje);
        subAux = aux->sub;
        contNombConKPorEquipo = 0;
        while (subAux != NULL)
        {
            if (subAux->dato.nombre[0] == toupper(K))
            {
                printf("%s\n", subAux->dato.nombre);
                contNombConKPorEquipo++;
                cantList++;
            }
            subAux = subAux->sig;
        }
        if (contNombConKPorEquipo > maxNombConKPorEquipo)
        {
            maxNombConKPorEquipo = contNombConKPorEquipo;
            strcpy(nombreEquipoMax, aux->dato.nombre);
        }
        aux = aux->sig;
    }

    printf("El equipo con mas jugadores con la letra %c es %s\n", K, nombreEquipoMax);
    printf("Cantidad de listados:%d\n", cantList);
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