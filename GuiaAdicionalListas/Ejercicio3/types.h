#include <stdio.h>

typedef struct nodoArch
{
    char texto[255];
    struct nodoArch *sig;
} nodoArch;

typedef nodoArch *subArch;

typedef struct nodoCarpeta
{
    char nombreCarpeta[100];
    subArch archivos;
    struct nodoCarpeta *carpetas;
    struct nodoCarpeta *sig;
} nodoCarpeta;

typedef nodoCarpeta *TListaCarpeta;
