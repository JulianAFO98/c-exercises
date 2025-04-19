/*Un sistema de inscripción a una maratón toma los datos de una cola de competidores (apellido
y nombre) y genera las identificaciones apilándolas según la inicial de los apellidos. Mostrar los
datos de la pila de los apellidos que comienzan con una letra solicitada al operador. */

// POR CONFLICTOS DE TIPOS HAY 2 MARATONISTAS -> MARATONISTAC (COLA)  -> MARATONISTA (PILA)

#include "cola.h"
#include "pila.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void llenarCola(Cola *C);
void limpiarCola(Cola *C);
void generarPila(Pila[], Cola *C);
void mostrarPilaSeleccionada(Pila VP[], char c);
void limpiarPilasRestantes(Pila VP[], char seleccionada);
int main(void)

{
    Cola cola;
    Pila vecPilas[26];
    char c;
    for (int i = 0; i < 26; i++)
        iniciaP(&vecPilas[i]);
    iniciaC(&cola);
    llenarCola(&cola);
    generarPila(vecPilas, &cola);
    printf("Ingrese una letra a buscar\n");
    scanf("%c", &c);
    mostrarPilaSeleccionada(vecPilas, c);
    limpiarPilasRestantes(vecPilas, c);
    // limpiarCola(&cola);
}

void limpiarPilasRestantes(Pila VP[], char seleccionada)
{
    Maratonista m;
    seleccionada = tolower(seleccionada); // para comparar de forma uniforme

    for (int i = 0; i < 26; i++)
    {
        if (i != (seleccionada - 'a')) // si no es la pila seleccionada
        {
            printf("Pila de la letra %c:\n", i + 'a');
            while (!vaciaP(VP[i]))
            {
                sacaP(&VP[i], &m);
                printf("Maratonista %s %s\n", m.nombre, m.apellido);
            }
            printf("\n");
        }
    }
}

void mostrarPilaSeleccionada(Pila VP[], char c)
{
    Pila pilaSeleccionada = VP[(int)c - 97];
    Maratonista elemP;
    while (!vaciaP(pilaSeleccionada))
    {
        sacaP(&pilaSeleccionada, &elemP);
        printf("Maratonista %s %s\n", elemP.nombre, elemP.apellido);
    }
}

void generarPila(Pila VP[], Cola *C)
{
    MaratonistaC elemC;
    Maratonista elemP;
    char primeraLetraApellido;
    while (!vaciaC(*C))
    {
        sacaC(C, &elemC);
        primeraLetraApellido = tolower(elemC.apellido[0]);
        strcpy(elemP.nombre, elemC.nombre);
        strcpy(elemP.apellido, elemC.apellido);
        poneP(&VP[(int)primeraLetraApellido - 97], elemP);
    }
}

void limpiarCola(Cola *C)
{
    MaratonistaC m;
    while (!vaciaC(*C))
    {
        sacaC(C, &m);
        printf("Maratonista %s %s\n", m.nombre, m.apellido);
    }
    printf("\n");
}

void llenarCola(Cola *C)
{

    FILE *file;
    MaratonistaC m;

    file = fopen("archivo.txt", "r");

    if (file == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf(file, "%s %s ", m.nombre, m.apellido) == 2)
        {
            poneC(C, m);
        }
        fclose(file);
    }
}