/*
A partir de una lista circular no ordenada con los DNI (cadena de 8), sexo (carácter F-M), emitió
voto? (S-N) de los votantes en el padrón de una mesa, resolver mediante una función para
cada item:
a) listar los votantes femeninos que han emitido el voto
b) contar los votantes de cada sexo (hayan o no votado).
c) buscar un DNI, que es dato, en la lista de votantes y mostrar si votó o no.
d) eliminar los votantes que no han emitido el voto y almacenar sus DNI en un archivo binario
(almacenando DNI y sexo).
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
void llenarLista(TLista *L);
void mostrarLista(TLista L);
void mostrarFVotantes(TLista L);
void contarVotantes(TLista L, int *F, int *M);
int indicarSiVoto(TLista L, char DNI[10]);
void eliminarNoVotantes(TLista *L);
void mostrarArchivo();
int main(void)
{
    TLista lista = NULL;
    int fem = 0, masc = 0;
    llenarLista(&lista);
    mostrarFVotantes(lista);
    contarVotantes(lista, &fem, &masc);
    printf("Cantidad de votantes  => Femeninos: %d  Masculinos: %d\n", fem, masc);
    printf(indicarSiVoto(lista, "43720198") ? "Voto\n" : "No voto\n");
    eliminarNoVotantes(&lista);
    mostrarLista(lista);
    mostrarArchivo();
    return 0;
}

void mostrarArchivo()
{
    FILE *archB;
    archB = fopen("archivo.dat", "rb");

    if (archB == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
    }
    else
    {

        char DNI[10];

        printf("Contenido del archivo:\n");
        fread(DNI, sizeof(char), 10, archB);
        while (!feof(archB))
        {
            printf("%s\n", DNI);
            fread(DNI, sizeof(char), 10, archB);
        }
        fclose(archB);
    }
}

void eliminarNoVotantes(TLista *L)
{
    TLista aux, ant, elim;
    FILE *archB;
    archB = fopen("archivo.dat", "wb");

    if (*L != NULL)
    {
        ant = *L;
        aux = (*L)->sig;
        do
        {
            elim = NULL;
            if (aux->voto == 'N')
            {
                elim = aux;
                if (aux == *L)
                {
                    if (aux->sig == aux)
                        *L = NULL;
                    else
                    {
                        ant->sig = aux->sig;
                        *L = ant;
                    }
                }
                else
                    ant->sig = aux->sig;
            }
            if (elim != NULL)
            {
                if (*L != NULL)
                    aux = aux->sig;
                else
                    aux = NULL;
                fwrite(elim->DNI, sizeof(char), 10, archB);
                free(elim);
            }
            else
            {
                ant = aux;
                aux = aux->sig;
            }

        } while (aux != NULL && aux != (*L)->sig);
    }

    fclose(archB);
}

int indicarSiVoto(TLista L, char DNI[10])
{
    TLista aux = L->sig;
    int voto = 0;
    if (aux != NULL)
    {
        while (aux != L && strcmp(aux->DNI, DNI) != 0)
        {
            if (strcmp(aux->DNI, DNI) == 0 && aux->voto == 'S')
                voto = 1;

            aux = aux->sig;
        }
        if (strcmp(aux->DNI, DNI) == 0 && aux->voto == 'S')
            voto = 1;
    }
    return voto;
}

void contarVotantes(TLista L, int *F, int *M)
{
    TLista aux = L;
    if (aux != NULL)
    {
        do
        {
            if (aux->sexo == 'F')
                (*F)++;
            else
                (*M)++;
            aux = aux->sig;
        } while (aux != L);
    }
}

void mostrarFVotantes(TLista L)
{
    TLista aux = L;
    printf("Lista de votantes femininas\n");
    if (aux != NULL)
    {
        do
        {
            if (aux->sexo == 'F' && aux->voto == 'S')
                printf("%s\n", aux->DNI);
            aux = aux->sig;
        } while (aux != L);
    }
}

void mostrarLista(TLista L)
{
    TLista aux = L;
    do
    {
        printf("%s %c %c\n", aux->DNI, aux->sexo, aux->voto);
        aux = aux->sig;
    } while (aux != L);
}

void llenarLista(TLista *L)
{
    FILE *arch;
    nodo *nuevo;
    char DNI[10], sexo, voto;
    arch = fopen("archivo.txt", "r");
    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf(arch, "%s %c %c", DNI, &sexo, &voto) == 3)
        {
            nuevo = (nodo *)malloc(sizeof(nodo));
            nuevo->sexo = sexo;
            nuevo->voto = voto;
            strcpy(nuevo->DNI, DNI);
            if (*L == NULL)
                nuevo->sig = nuevo;
            else
            {
                nuevo->sig = (*L)->sig;
                (*L)->sig = nuevo;
            }
            *L = nuevo;
        }
        fclose(arch);
    }
}