
int esMesPar(unsigned int fecha)
{
    switch (fecha)
    {
    case (fecha > 31 && fecha < 61):
        return 1;
        break;
    case (fecha > 90 && fecha < 120):
        return 1;
        break;
    case 1:
        break;
    case 1:
        break;
    case 1:
        break;
    case 1:
        break;
    default:
        return 0;
    }
}

void generarBinario(TListaD LD, char codigoAG[6], unsigned int K)
{
    unsigned int cantMult = 0;
    TRegM multa;
    nodoD *auxListaDoble = LD.pri;
    nodito *auxLista;
    FILE *archb;
    archb = fopen("archivo.dat", "wb");
    if (arch == NULL)
        printf("No hay memoria suficiente");
    else
    {
        while (auxListaDoble != NULL && strcmp(auxListaDoble->codigoAG, codigoAG) > 0)
            auxListaDoble = auxListaDoble->sig;
        if (auxListaDoble != NULL && strcmp(auxListaDoble->codigoAG, codigoAG) == 0)
        {
            auxLista = auxListaDoble->sub;
            while (auxLista != NULL)
            {
                if ((strcmp(auxLista->hora, "12:00") < 0 || strcmp(auxLista->hora, "18:00") > 0) && esMesPar(auxLista->fecha))
                {
                    cantMult++;
                    strcpy(multa.patente, auxLista->patente);
                    multa.fecha = auxLista->fecha;
                    multa.tiempoAbonado = auxLista->tiempoAbonado;
                    multa.tiempoReal = auxLista->tiempoReal;
                    strcpy(multa.hora, auxLista->hora);
                    fwrite(&multa, sizeof(TRegM), 1, archb);
                }

                auxLista = auxLista->sig;
            }
            printf((cantMult > K && auxListaDoble->esEstudiant == 'S') ? "Le corresponde la bonificacion" : "No le corresponde la bonificacion");
        }
    }
}

void multasSeptiembre(TCola *C, TListaD LD)
{
    TElementoC elem;
    nodoD *auxListaDoble;
    nodito *auxSubLista, *nuevo, *act, *ant;
    elem.codigoAge = 'zzzzz';
    if (!vaciaC(C))
    {
        poneC(C, elem);
        sacaC(C, &elem);
        while (elem.codigo != 'zzzzz')
        {
            if ((elem.fecha > 243 && elem.fecha < 273) && (elem.tiempoReal > elem.tiempoPagado))
            {
                auxListaDoble = (LD).pri;
                while (auxListaDoble != NULL && strcmp(auxListaDoble->codigo, elem.codigo) > 0)
                    auxListaDoble = auxListaDoble->sig;
                if (auxListaDoble != NULL && strcmp(auxListaDoble->codigo, elem.codigo) == 0)
                {
                    auxSubLista = auxListaDoble->sub;
                    nuevo = (nodito *)malloc(sizeof(nodito));
                    strcpy(nuevo->patente, elem.patente);
                    nuevo->fecha = elem.fecha;
                    strcpy(nuevo->hora, elem.hora);
                    nuevo->tiempoReal.hora = elem.tiempoReal / 60;
                    nuevo->tiempoReal.minutos = elem.tiempoReal % 60;
                    nuevo->tiempoPagado.hora = elem.tiempoPagado / 60;
                    nuevo->tiempoPagado.minutos = elem.tiempoPagado % 60;
                    if (auxSubLista == NULL || strcmp(elem.patente, auxSubLista->patente) < 0)
                    {
                        nuevo->sig = auxSubLista;
                        auxSubLista = nuevo;
                    }
                    else
                    {
                        ant = NULL;
                        act = auxSubLista;
                        while (act != NULL && strcmp(act->patente, elem.patente) > 0)
                        {
                            ant = act;
                            act = act->sig;
                        }
                        ant->sig = nuevo;
                        nuevo->sig = act;
                    }
                }
            }
            sacaC(C, &elem);
        }
    }
    sacaC(C, &elem);
}

#include "cola.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // inicializas
    TListaD LD;
    TCola C;
    unsigned int K;
    char codigoAG[6];
    LD.pri = LD.ult = NULL;
    iniciaC(&C);
    cargaListaDoble(&LD);
    cargarCola(&C);
    multasSeptiembre(&C, LD);
    printf("Ingrese K\n");
    scanf("%d", &K);
    printf("Ingrese el codigo AG");
    scanf("%s", codigoAG);
    generarBinario(LD, codigoAG, K);
    return 0;
}