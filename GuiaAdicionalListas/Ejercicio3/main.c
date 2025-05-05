/*
Simular un gestor de archivos simplificado mediante listas de carpetas que contengan sublistas
de carpetas y archivos. Implementar el listado del contenido de una carpeta ingresada como
dato. No es necesario listar el contenido de las subcarpetas de dicha carpeta.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
void llenarCarpetas(TListaCarpeta *L);
void mostrarCarpetas(TListaCarpeta L);
void agregarTextoCarpeta(TListaCarpeta L, char nombreCarpeta[100]);
void mostrarCarpetaEspecifica(TListaCarpeta L, char nombreCarpeta[100]);
int main(void)
{
        TListaCarpeta lista = NULL;
        llenarCarpetas(&lista);
        llenarCarpetas(&lista->carpetas);      // Esto lo hago porque confio en que ingrese correctamente los datos en la creacion de arriba
        llenarCarpetas(&lista->sig->carpetas); // Mismo aca
        agregarTextoCarpeta(lista, "carpeta1");
        // mostrarCarpetas(lista);
        mostrarCarpetaEspecifica(lista, "carpeta1");
        return 0;
}

void mostrarCarpetaEspecifica(TListaCarpeta L, char nombreCarpeta[100])
{
        TListaCarpeta aux = L;
        nodoCarpeta *auxCarpetas;
        nodoArch *auxArch;
        printf("\n-------------\n");
        while (aux != NULL && strcmp(aux->nombreCarpeta, nombreCarpeta) != 0)
                aux = aux->sig;
        if (aux != NULL)
        {
                printf("-%s\n", aux->nombreCarpeta);
                auxCarpetas = aux->carpetas;
                while (auxCarpetas != NULL)
                {
                        printf("-C-%s\n", auxCarpetas->nombreCarpeta);
                        auxCarpetas = auxCarpetas->sig;
                }
                auxArch = aux->archivos;
                while (auxArch != NULL)
                {
                        printf("-A-%s\n", auxArch->texto);
                        auxArch = auxArch->sig;
                }
                aux = aux->sig;
        }
}

void agregarTextoCarpeta(TListaCarpeta L, char nombreCarpeta[100])
{
        TListaCarpeta aux = L;
        nodoArch *auxArch;
        while (aux != NULL && strcmp(aux->nombreCarpeta, nombreCarpeta) != 0)
                aux = aux->sig;
        if (aux != NULL)
        {
                auxArch = (nodoArch *)malloc(sizeof(nodoArch));
                printf("Ingrese el texto a agregar\n");
                gets(auxArch->texto);
                auxArch->sig = aux->archivos;
                aux->archivos = auxArch;
        }
}

void mostrarCarpetas(TListaCarpeta L)
{
        TListaCarpeta aux = L;
        nodoCarpeta *auxCarpetas;
        nodoArch *auxArch;
        printf("\n-------------\n");
        while (aux != NULL)
        {
                printf("-%s\n", aux->nombreCarpeta);
                auxCarpetas = aux->carpetas;
                while (auxCarpetas != NULL)
                {
                        printf("-C-%s\n", auxCarpetas->nombreCarpeta);
                        auxCarpetas = auxCarpetas->sig;
                }
                auxArch = aux->archivos;
                while (auxArch != NULL)
                {
                        printf("-A-%s\n", auxArch->texto);
                        auxArch = auxArch->sig;
                }
                aux = aux->sig;
        }
}

void llenarCarpetas(TListaCarpeta *L)
{
        int n;
        TListaCarpeta aux;
        printf("Cuantas carpetas desea crear\n");
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++)
        {
                aux = (TListaCarpeta)malloc(sizeof(nodoCarpeta));
                printf("Ingrese nombre de la carpeta\n");
                gets(aux->nombreCarpeta);
                aux->archivos = NULL;
                aux->carpetas = NULL;
                aux->sig = *L;
                *L = aux;
        }
}
