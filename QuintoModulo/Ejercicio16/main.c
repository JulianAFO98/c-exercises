/*Simular un juego de naipes donde N jugadores van tomando un naipe del mazo por turno. El
juego finaliza cuando el mazo queda vacío. El puntaje de cada jugador consiste en la sumatoria
de los números de los naipes que fue tomando. Si el palo del naipe tomado coincide con el palo
del levantado en el turno anterior el número se duplica. Implementar utilizando las estructuras
(pilas y/o colas) que considere necesarias.  */

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
void llenarMazo(Pila *pila);
void limpiarCartas(Pila *pila);
void repartirCartas(Pila *pila, Pila *pv, int n);
void mostrarPuntuacionJugador(Pila *pv, int n);
int main(void)
{
    Pila pila, *pv;
    int n;
    iniciaP(&pila);
    llenarMazo(&pila);
    printf("Ingrese la cantidad de jugadores\n");
    scanf("%d", &n);
    pv = (Pila *)malloc(n * sizeof(Pila)); // hacer en funcion
    for (int i = 0; i < n; i++)
        iniciaP((pv + i));
    repartirCartas(&pila, pv, n);
    mostrarPuntuacionJugador(pv, n);
    free(pv);
    // limpiarCartas(&pila);
}

void mostrarPuntuacionJugador(Pila *pv, int n)
{
    Carta carta, cartaAnterior;
    int puntuacion;
    for (int i = 0; i < n; i++)
    {
        puntuacion = 0;
        cartaAnterior.palo = '\0';
        printf("------Jugador %d------\n", i + 1);
        while (!vaciaP(*(pv + i)))
        {
            sacaP((pv + i), &carta);
            puntuacion += cartaAnterior.palo == carta.palo ? carta.numero * 2 : carta.numero;
            cartaAnterior = carta;
            printf("Palo:%c Numero:%d\n", carta.palo, carta.numero);
        }
        printf("Puntuacion total: %d\n", puntuacion);
    }
}

void repartirCartas(Pila *pila, Pila *pv, int n)
{
    Carta carta;
    int i = 0;
    while (!vaciaP(*pila))
    {
        sacaP(pila, &carta);
        poneP((pv + i), carta);
        i++;
        i = i % n;
    }
}

void limpiarCartas(Pila *pila)
{
    Carta carta;
    while (!vaciaP(*pila))
    {
        sacaP(pila, &carta);
        printf("Palo:%c Numero:%d\n", carta.palo, carta.numero);
    }
}

void llenarMazo(Pila *pila)
{
    Carta carta;
    FILE *arch = fopen("cartas.txt", "r");

    if (arch == NULL)
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {
        while (fscanf(arch, "%c %d\n", &carta.palo, &carta.numero) == 2)
        {
            poneP(pila, carta);
        }
        fclose(arch);
    }
}
