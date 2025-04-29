/*
Corregir los errores de la siguiente función, que elimina el nodo de una lista circular que
contiene un valor pasado como parámetro (elem)
void lc_eliminaelem(TLISTAC *pult, TELEMENTOLC elem, int *eliminado) {
 TLISTAC ant, act = *pult->sig;
 eliminado = 0;
 if (pult = NULL) {
 do{
 ant = act;
 act->sig = act;
 }while ( *pult != act && elem < act.dato);
 if (elem = act->dato){
 if (*pult != (*pult)->sig)
 *pult= NULL;
 else {
 act->sig = ant->sig;
 if (act == *pult)
 pult = *ant;
 }
 free (ant);
 eliminado = 1;
 }
 }
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef int TELEMENTOLC;

typedef struct nodo
{
    TELEMENTOLC dato;
    struct nodo *sig;
} nodo;

typedef nodo *TLISTAC;

void lc_insertar(TLISTAC *pult, TELEMENTOLC elem)
{
    TLISTAC nuevo = (TLISTAC)malloc(sizeof(nodo));
    nuevo->dato = elem;
    if (*pult == NULL)
    {
        nuevo->sig = nuevo;
    }
    else
    {
        nuevo->sig = (*pult)->sig;
        (*pult)->sig = nuevo;
    }
    *pult = nuevo;
}

void lc_imprimir(TLISTAC pult)
{
    if (pult == NULL)
        printf("Lista vacía\n");
    else
    {
        TLISTAC act = pult->sig;
        do
        {
            printf("%d -> ", act->dato);
            act = act->sig;
        } while (act != pult->sig);
        printf("(inicio)\n");
    }
}

void lc_eliminaelem(TLISTAC *pult, TELEMENTOLC elem, int *eliminado)
{
    TLISTAC ant, act = *pult;
    *eliminado = 0;
    if (*pult != NULL)
    {
        do
        {
            ant = act;
            act = act->sig;
            printf("%d", elem == act->dato);
        } while (*pult != act && elem != act->dato);

        if (elem == act->dato)
        {
            if (*pult == (*pult)->sig)
                *pult = NULL;
            else
            {
                ant->sig = act->sig;
                if (act == *pult)
                    *pult = ant;
            }
            free(act);
            *eliminado = 1;
        }
    }
}

int main()
{
    TLISTAC lista = NULL;
    int eliminado;

    // Insertar elementos
    lc_insertar(&lista, 10);
    lc_insertar(&lista, 20);
    lc_insertar(&lista, 30);
    lc_insertar(&lista, 40);

    printf("Lista original:\n");
    lc_imprimir(lista);

    // Intentar eliminar un valor
    int valor = 20;
    lc_eliminaelem(&lista, valor, &eliminado);

    if (eliminado)
        printf("\nElemento %d eliminado.\n", valor);
    else
        printf("\nElemento %d no encontrado.\n", valor);

    printf("Lista resultante:\n");
    lc_imprimir(lista);

    return 0;
}