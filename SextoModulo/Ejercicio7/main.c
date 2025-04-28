/*
Implementar un programa de biblioteca que administre la siguiente estructura: un arreglo de
listas simples ordenadas alfabéticamente con los autores que comiencen con la misma letra, o
sea que habrá un elemento del arreglo por cada letra del abecedario, aunque no existan
autores que comiencen con dicha letra. Para cada autor existe una sublista, ordenada por
título, con los libros disponibles para ser prestados de cada autor:
• Autor
• Sublista de libros de dicho autor
o Titulo
o Autor
o Año de edición
Se debe poder agregar libros a esta estructura.
Además, gestionar una lista de socios con una sublista de libros prestados. Permitir las
operaciones de registrar préstamos (mover el nodo de la sublista del autor al final de la sublista
de libros prestados para el socio) y devoluciones (mover nodo del libro prestado de dicha
sublista a la sublista del autor de acuerdo al orden indicado). Dicha lista posee la siguiente
estructura:
• Socio
• Sublista de libros prestados
o Titulo
o Autor
o Año de edición
*/

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LETRAS_ABECEDARIO 26

void llenarListasDeAutores(TLista vecListas[]);
void insertarOrdenadoAlf(TLista *L, char nombre[100]);
void mostrarVector(TLista vecListas[]);
void mostrarListaAutores(TLista L);
void agregarLibro(TLista vecListas[]);
void insertarLibroEnListaCorrespondiente(TLista L, Libro libro);
void llenarListaDeSocios(TListaS *L);
void mostrarListaSocios(TListaS L);
void reservarLibro(TLista vecListas[], TListaS socios);
void devolverLibro(TLista vecListas[], TListaS socios);
Libro extraerLibro(TLista L, char nombreLibro[100], char nombreAutor[100]);
Libro extraerLibroDelSocio(TListaS socios, char nombreLibro[100], char nombreSocio[100]);
void insertarEnSocios(TListaS socios, char nombreSocio[100], Libro lib);

int main(void)
{
    TLista vectorListas[26];
    TListaS socios = NULL;
    for (int i = 0; i < LETRAS_ABECEDARIO; i++)
        vectorListas[i] = NULL;

    llenarListasDeAutores(vectorListas);
    agregarLibro(vectorListas);
    mostrarVector(vectorListas);
    llenarListaDeSocios(&socios);
    reservarLibro(vectorListas, socios);
    mostrarListaSocios(socios);
    mostrarVector(vectorListas);
    devolverLibro(vectorListas, socios);
    mostrarListaSocios(socios);
    mostrarVector(vectorListas);
}

void devolverLibro(TLista vecListas[], TListaS socios)
{
    char nombreLibro[100], nombreAutor[100], nombreSocio[100];
    Libro libroAux;
    int index;
    printf("Ingrese el nombre del libro\n");
    gets(nombreLibro);
    printf("Ingrese nombre del autor\n");
    gets(nombreAutor);
    printf("Ingrese nombre del socio\n");
    gets(nombreSocio);
    index = (int)tolower(nombreAutor[0]) - 97;
    libroAux = extraerLibroDelSocio(socios, nombreLibro, nombreSocio);
    printf("\nLibro extraido de socio %s %d\n", libroAux.titulo, libroAux.anioEdicion);
    if (libroAux.anioEdicion != 0)
        insertarLibroEnListaCorrespondiente(vecListas[index], libroAux);
}

Libro extraerLibroDelSocio(TListaS socios, char nombreLibro[100], char nombreSocio[100])
{
    Libro libroAux;
    TListaS aux = socios;
    subLista act, ant;

    libroAux.anioEdicion = 0;
    libroAux.autor[0] = '\0'; // esto
    libroAux.titulo[0] = '\0';

    aux = socios;
    while (aux != NULL && strcmp(nombreSocio, aux->socio) != 0) // Busco el socio
        aux = aux->sig;

    if (aux != NULL) // Si existe el socio
    {
        ant = NULL;
        act = aux->sub;

        while (act != NULL && strcmp(nombreLibro, act->libro.titulo) != 0) // Busco el libro
        {
            ant = act;
            act = act->sig;
        }

        if (act != NULL && strcmp(nombreLibro, act->libro.titulo) == 0) // Preguntar por esta forma de buscar
        {
            if (ant == NULL) // Es el primero
                aux->sub = act->sig;
            else
                ant->sig = act->sig;

            libroAux = act->libro;
            free(act);
        }
        else
            printf("El libro no existe\n");
    }
    else
        printf("El socio no existe\n");

    return libroAux;
}

void reservarLibro(TLista vecListas[], TListaS socios)
{
    char nombreLibro[100], nombreAutor[100], nombreSocio[100];
    Libro libroAux;
    int index;
    // Pedir datos
    printf("Ingrese el nombre del libro\n");
    gets(nombreLibro);
    printf("Ingrese nombre del autor\n");
    gets(nombreAutor);
    printf("Ingrese nombre del socio\n");
    gets(nombreSocio);
    // Buscar el libro en vecListas(puede no existir) y si lo encuentro quitarlo y devolverlo
    index = (int)tolower(nombreAutor[0]) - 97;
    libroAux = extraerLibro(vecListas[index], nombreLibro, nombreAutor);
    if (libroAux.anioEdicion != 0)
        insertarEnSocios(socios, nombreSocio, libroAux);
}

void insertarEnSocios(TListaS socios, char nombreSocio[100], Libro lib) // Preguntar
{
    TListaS aux = socios;
    subLista nuevo;
    while (aux != NULL && strcmp(nombreSocio, aux->socio) != 0) // Busco el socio
        aux = aux->sig;

    if (aux != NULL)
    {
        nuevo = (subLista)malloc(sizeof(nodito));
        nuevo->libro = lib;
        nuevo->sig = aux->sub;
        aux->sub = nuevo;
    }
    else
    {
        printf("No se encontro el socio");
    }
}

Libro extraerLibro(TLista L, char nombreLibro[100], char nombreAutor[100]) // Preguntar por esto y por el caso de que quede vacia
{
    Libro libroAux;
    TLista aux = L;
    subLista act, ant;

    libroAux.anioEdicion = 0;
    libroAux.autor[0] = '\0'; // esto
    libroAux.titulo[0] = '\0';

    aux = L;
    while (aux != NULL && strcmp(nombreAutor, aux->autor) > 0) // Busco el autor
        aux = aux->sig;

    if (aux != NULL) // Si existe el autor
    {
        act = aux->sub;
        ant = NULL;

        while (act != NULL && strcmp(nombreLibro, act->libro.titulo) > 0) // Busco el libro
        {
            ant = act;
            act = act->sig;
        }

        if (act != NULL && strcmp(nombreLibro, act->libro.titulo) == 0) // Preguntar por esta forma de buscar
        {
            if (ant == NULL) // Es el primero
                aux->sub = act->sig;
            else
                ant->sig = act->sig;

            libroAux = act->libro;
            free(act);
        }
        else
            printf("El libro no existe\n");
    }
    else
        printf("El autor no existe\n");

    return libroAux;
}

void llenarListaDeSocios(TListaS *L)
{
    char nombreSocio[100];
    TListaS nuevo;
    FILE *arch = fopen("socios.txt", "r");

    if (arch == NULL)
        printf("No se pudo crear el archivo");
    else
    {
        while (fscanf(arch, "%s\n", nombreSocio) == 1)
        { // Podria usar la funcion insertarEnListasSocios,lo hago aca para variar un poco
            nuevo = (TListaS)malloc(sizeof(nodoS));
            strcpy(nuevo->socio, nombreSocio);
            nuevo->sub = NULL;
            nuevo->sig = *L;
            *L = nuevo;
        }

        fclose(arch);
    }
}

void agregarLibro(TLista vecListas[])
{
    Libro libro;
    unsigned int index;
    printf("Ingrese titulo del libro\n");
    gets(libro.titulo);
    printf("Ingrese el autor del libro\n");
    gets(libro.autor);
    printf("Ingrese el anio de edicion del libro\n");
    scanf("%u", &libro.anioEdicion);
    getchar();
    index = (int)tolower(libro.autor[0]) - 97;
    insertarLibroEnListaCorrespondiente(vecListas[index], libro);
}

void insertarLibroEnListaCorrespondiente(TLista L, Libro libro)
{
    TLista aux = L;
    subLista act, ant;
    // Busco el nodo en el que debo insertar el libro
    while (aux != NULL && strcmp(libro.autor, aux->autor) > 0)
        aux = aux->sig;

    if (aux == NULL)
        printf("El autor no existe");
    else
    {
        subLista nuevo = (subLista)malloc(sizeof(nodito));
        nuevo->libro = libro;
        if (aux->sub == NULL || strcmp(libro.titulo, aux->sub->libro.titulo) < 0)
        {
            nuevo->sig = aux->sub;
            aux->sub = nuevo;
        }
        else
        {
            ant = NULL;
            act = aux->sub;
            while (act != NULL && strcmp(libro.titulo, act->libro.titulo) > 0)
            {
                ant = act;
                act = act->sig;
            }
            ant->sig = nuevo;
            nuevo->sig = act;
        }
    }
}
void mostrarListaSocios(TListaS L)
{
    TListaS aux = L;
    subLista subAux;
    printf("----------Socios----------\n");
    while (aux != NULL)
    {
        printf("%s\n", aux->socio);
        subAux = aux->sub;
        while (subAux != NULL)
        {
            printf("---%s\n", subAux->libro.titulo);
            subAux = subAux->sig;
        }
        aux = aux->sig;
    }
}

void mostrarListaAutores(TLista L)
{
    TLista aux = L;
    subLista subAux;
    while (aux != NULL)
    {
        printf("%s\n", aux->autor);
        subAux = aux->sub;
        while (subAux != NULL)
        {
            printf("---%s\n", subAux->libro.titulo);
            subAux = subAux->sig;
        }
        aux = aux->sig;
    }
}

void mostrarVector(TLista vecListas[])
{
    printf("-------Autores-------\n");
    for (int i = 0; i < LETRAS_ABECEDARIO; i++)
    {
        mostrarListaAutores(vecListas[i]);
    }
}

void llenarListasDeAutores(TLista vecListas[])
{
    char nombreAutor[100];
    unsigned int index;
    FILE *arch = fopen("autores.txt", "r");

    if (arch == NULL)
        printf("No se pudo crear el archivo");
    else
    {
        while (fscanf(arch, "%s\n", nombreAutor) == 1)
        {
            index = (int)tolower(nombreAutor[0]) - 97; // Usando codigo ascii busco una pos entre 0 25 -> posibles letras del abcdario
            insertarOrdenadoAlf(&vecListas[index], nombreAutor);
        }

        fclose(arch);
    }
}

void insertarOrdenadoAlf(TLista *L, char nombre[100])
{
    TLista ant, act;
    TLista nuevo = (TLista)malloc(sizeof(nodo));
    strcpy(nuevo->autor, nombre);
    nuevo->sub = NULL;

    if (*L == NULL || strcmp(nombre, (*L)->autor) < 0)
    {
        nuevo->sig = *L;
        *L = nuevo;
    }
    else
    {
        act = *L;
        while (act != NULL && strcmp(nombre, act->autor) > 0)
        {
            ant = act;
            act = act->sig;
        }
        ant->sig = nuevo;
        nuevo->sig = act;
    }
}