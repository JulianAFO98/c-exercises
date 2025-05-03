/*
Desarrollar un programa que gestione las reservas de pasajes para los vuelos de una aerolínea.
Para ello se cuenta con una lista de destinos con la siguiente estructura:
• Destino
• Sublista ordenada de Vuelos (a dicho destino)
o Código de vuelo
o Fecha y horario de salida
o Capacidad de pasajeros
o Sublista de pasajes vendidos (para dicho vuelo)
 Documento del pasajero
Tanto para la reserva como para su cancelación se solicita: destino, código de vuelo y
documento del pasajero. El programa debe además permitir agregar destinos y vuelos. Cada
vuelo tiene una fecha y horario de salida y capacidad de pasajeros. El programa debe también
listar el estado (cantidad de reservas, lugares disponibles, etc.) de todos los vuelos de un
destino solicitado al operador.
NOTA: Dado que no se requieren cálculos con las fechas y horarios de salida, se sugiere almacenar dicho campo
como una cadena.
*/

#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include <string.h>
void llenarListaDestinos(TLista *L);
void mostrarDestinos(TLista L);
void reservarAsiento(TLista L, char destino[100], char codigo[25], char DNI[10]); // VALIDAR CANTIDAD DE ASIENTOS OCUPADOS? DNI NO REPETIBLES(OPCIONAL)
void eliminarAsiento(TLista L, char destino[100], char codigo[25], char DNI[10]);
void agregarVuelo(TLista L, char destino[100], char codigo[25], char fechaHora[25], unsigned int capacidadP);
void mostrarDestinoEspecifico(TLista L, char destino[100]);

void agregarDestino(TLista *L, char destino[100]);

int main(void)
{
    TLista listaDestinos = NULL;
    llenarListaDestinos(&listaDestinos);
    // mostrarDestinos(listaDestinos);
    //  reservarAsiento(listaDestinos, "NuevaYork", "NY1001", "41431184");
    //  mostrarDestinos(listaDestinos);
    //  eliminarAsiento(listaDestinos, "NuevaYork", "NY1001", "41431184");
    //  mostrarDestinos(listaDestinos);
    agregarDestino(&listaDestinos, "Nueva Zelanda");
    // mostrarDestinos(listaDestinos);
    agregarVuelo(listaDestinos, "Nueva Zelanda", "NZ1067", "2025-12-12-00:00", 225);
    // mostrarDestinos(listaDestinos);
    mostrarDestinoEspecifico(listaDestinos, "Tokio");

    return 0;
}

void mostrarDestinoEspecifico(TLista L, char destino[100])
{
    TLista aux = L;
    nodoViaje *auxViaje;
    nodoPasaje *auxPasaje;
    while (aux != NULL && strcmp(aux->destino, destino) != 0)
    {
        aux = aux->sig;
    }
    if (aux != NULL)
    {
        printf("----------Destino:%s----------\n", aux->destino);
        auxViaje = aux->viajes;
        while (auxViaje != NULL)
        {
            printf("Vuelo:%s %s %u\n", auxViaje->codigoVuelo, auxViaje->fechaHoraSalida, auxViaje->capPasajeros);
            printf("Pasajeros:\n");
            auxPasaje = auxViaje->pasajeros;
            while (auxPasaje != NULL)
            {
                printf("----%s\n", auxPasaje->DNI);
                auxPasaje = auxPasaje->sig;
            }
            auxViaje = auxViaje->sig;
        }
    }
}

void agregarVuelo(TLista L, char destino[100], char codigo[25], char fechaHora[25], unsigned int capacidadP)
{
    TLista aux = L;
    nodoViaje *nuevoViaje, *ant, *act;

    while (aux != NULL && strcmp(aux->destino, destino) != 0)
        aux = aux->sig;

    if (aux != NULL)
    {

        nuevoViaje = (nodoViaje *)malloc(sizeof(nodoViaje));
        nuevoViaje->pasajeros = NULL;
        strcpy(nuevoViaje->codigoVuelo, codigo);
        strcpy(nuevoViaje->fechaHoraSalida, fechaHora);
        nuevoViaje->capPasajeros = capacidadP;
        if (aux->viajes == NULL || strcmp(nuevoViaje->codigoVuelo, aux->viajes->codigoVuelo) < 0)
        {
            nuevoViaje->sig = aux->viajes;
            aux->viajes = nuevoViaje;
        }
        else
        {
            ant = NULL;
            act = aux->viajes;
            while (act != NULL && strcmp(nuevoViaje->codigoVuelo, act->codigoVuelo) > 0)
            {
                ant = act;
                act = act->sig;
            }
            ant->sig = nuevoViaje;
            nuevoViaje->sig = act;
        }
    }
}

void agregarDestino(TLista *L, char destino[100])
{
    TLista nuevo = (TLista)malloc(sizeof(nodo));
    strcpy(nuevo->destino, destino);
    nuevo->viajes = NULL;
    nuevo->sig = *L;
    *L = nuevo;
}

void reservarAsiento(TLista L, char destino[100], char codigo[25], char DNI[10])
{

    TLista aux = L;
    nodoViaje *auxViaje;
    nodoPasaje *nuevo;
    while (aux != NULL && strcmp(aux->destino, destino) != 0)
        aux = aux->sig;

    if (aux != NULL) // PREGUNTAR por doble validacion
    {
        auxViaje = aux->viajes;
        while (auxViaje != NULL && strcmp(auxViaje->codigoVuelo, codigo) < 0)
            auxViaje = auxViaje->sig;
        if (auxViaje != NULL && strcmp(auxViaje->codigoVuelo, codigo) == 0)
        {
            nuevo = (nodoPasaje *)malloc(sizeof(nodoPasaje));
            strcpy(nuevo->DNI, DNI);
            nuevo->sig = auxViaje->pasajeros;
            auxViaje->pasajeros = nuevo;
        }
    }
}

void eliminarAsiento(TLista L, char destino[100], char codigo[25], char DNI[10])
{

    TLista aux = L;
    nodoViaje *auxViaje;
    nodoPasaje *act, *ant;
    while (aux != NULL && strcmp(aux->destino, destino) != 0)
        aux = aux->sig;

    if (aux != NULL)
    {
        auxViaje = aux->viajes;
        while (auxViaje != NULL && strcmp(auxViaje->codigoVuelo, codigo) < 0)
            auxViaje = auxViaje->sig;
        if (auxViaje != NULL && strcmp(auxViaje->codigoVuelo, codigo) == 0)
        {
            ant = NULL;
            act = auxViaje->pasajeros;
            while (act != NULL && strcmp(act->DNI, DNI) != 0)
            {
                ant = act;
                act = act->sig;
            }
            if (act != NULL)
            {
                if (act == auxViaje->pasajeros) // es el primero
                    auxViaje->pasajeros = act->sig;
                else
                    ant->sig = act->sig;
                free(act);
            }
        }
    }
}

void mostrarDestinos(TLista L)
{
    TLista aux = L;
    nodoViaje *auxViaje;
    nodoPasaje *auxPasaje;
    while (aux != NULL)
    {
        printf("----------Destino:%s----------\n", aux->destino);
        auxViaje = aux->viajes;
        while (auxViaje != NULL)
        {
            printf("Vuelo:%s %s %u\n", auxViaje->codigoVuelo, auxViaje->fechaHoraSalida, auxViaje->capPasajeros);
            printf("Pasajeros:\n");
            auxPasaje = auxViaje->pasajeros;
            while (auxPasaje != NULL)
            {
                printf("----%s\n", auxPasaje->DNI);
                auxPasaje = auxPasaje->sig;
            }
            auxViaje = auxViaje->sig;
        }
        aux = aux->sig;
    }
}

void llenarListaDestinos(TLista *L)
{
    TLista nuevo;
    nodoViaje *nuevoViaje, *act, *ant;
    FILE *arch;
    unsigned int cantVuelos;
    char dest[100];

    arch = fopen("archivo.txt", "r");

    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf(arch, "%s %u\n", dest, &cantVuelos) == 2)
        {
            nuevo = (TLista)malloc(sizeof(nodo));
            strcpy(nuevo->destino, dest);
            nuevo->viajes = NULL;
            for (int i = 0; i < cantVuelos; i++)
            {
                nuevoViaje = (nodoViaje *)malloc(sizeof(nodoViaje));
                nuevoViaje->pasajeros = NULL;

                fscanf(arch, "%s %s %u\n", nuevoViaje->codigoVuelo, nuevoViaje->fechaHoraSalida, &nuevoViaje->capPasajeros);
                if (nuevo->viajes == NULL || strcmp(nuevoViaje->codigoVuelo, nuevo->viajes->codigoVuelo) < 0)
                {
                    nuevoViaje->sig = nuevo->viajes;
                    nuevo->viajes = nuevoViaje;
                }
                else
                {
                    ant = NULL;
                    act = nuevo->viajes;
                    while (act != NULL && strcmp(nuevoViaje->codigoVuelo, act->codigoVuelo) > 0)
                    {
                        ant = act;
                        act = act->sig;
                    }
                    ant->sig = nuevoViaje;
                    nuevoViaje->sig = act;
                }
            }
            nuevo->sig = *L;
            *L = nuevo;
        }
        fclose(arch);
    }
}
