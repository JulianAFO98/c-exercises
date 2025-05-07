

unsigned int calcularCantNodos(TListaC L)
{
    nodoS *auxSimple = L;
    unsigned int cantNodos = 0;
    if (auxSimple != NULL)
    {
        do
        {
            cantNodos++;
            auxSimple = auxSimple->sig;

        } while (auxSimple != L);
    }
    return cantNodos;
}

void agregarAListaCircular(TListaS LS, TListaC *L, TPila *P)
{
    FILE *archb;
    TregCancion cancion;
    TElementoP elementoP;
    nodoC *auxCircular, *ant;
    nodoS *auxSimple;
    nodito *auxSimpleSub, *nuevo;

    unsigned int i, cantNodosC;
    cantNodosC = calcularCantNodos(*L);
    archb = fopen("nuevas.dat", "rb");
    if (archb == NULL)
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {

        fread(&cancion, sizeof(TregCancion), 1, archb);
        while (!feof(archb))
        {
            if (*L != NULL)
            {
                auxCircular = *L->sig;
                while (auxCircular != *L && (strcmp(auxCircular->idInterprete, cancion.idInterprete) != 0 || strcmp(auxCircular->idCancion, cancion.idCancion) != 0))
                    auxCircular = auxCircular->sig;
                if (strcmp(auxCircular->idInterprete, cancion.idInterprete) == 0 && strcmp(auxCircular->idCancion, cancion.idCancion) == 0)
                {
                    auxSimple = LS;
                    while (auxSimple != NULL && strcmp(auxSimple->idIterprete, cancion.idInterprete) < 0)
                        auxSimple = auxSimple->sig;
                    if (auxSimple != NULL && strcmp(auxSimple->idIterprete, cancion.idInterprete) == 0)
                    {
                        auxSimpleSub = auxSimple->sub;
                        while (auxSimpleSub != NULL && strcmp(auxSimpleSub->idCancion, cancion.idCancion) != 0)
                        {
                            auxSimpleSub = auxSimpleSub->sig;
                        }
                        if (auxSimpleSub != NULL)
                        {
                            elementoP.duracion = auxSimpleSub->duracion;
                            strcpy(elementoP.idCompuesto, strcat(cancion.idInterprete, cancion.idCancion));
                            poneP(P, elementoP);
                        }
                    }
                }
                else
                {
                    nuevo = (nodito *)malloc(sizeof(nodito));
                    strcpy(nuevo->idInterprete, cancion.idInterprete);
                    strcpy(nuevo->idCancion, cancion.idCancion);
                    if (cantNodosC > cancion.pos)
                    {
                        nuevo->sig = (*L)->sig;
                        (*L)->sig = nuevo;
                        *L = nuevo;
                    }
                    else
                    {
                        i = 1;
                        ant = *L;
                        auxCircular = (*L)->sig;
                        while (auxCircular != *L && i < cancion.pos)
                        {
                            auxCircular = auxCircular->sig;
                            i++;
                        }
                        ant->sig = nuevo;
                        nuevo->sig = auxCircular;
                    }
                }
            }
            else
            {
                nuevo = (nodito *)malloc(sizeof(nodito));
                strcpy(nuevo->idInterprete, cancion.idInterprete);
                strcpy(nuevo->idCancion, cancion.idCancion);
                nuevo->sig = nuevo;
                *L = nuevo;
            }
            fread(&cancion, sizeof(TregCancion), 1, archb);
        }
        fclose(archb);
    }
}

void listarEliminando(TListaS L, TListaC *LR, char idInterprete[11])
{

    TListaS auxListaSimple = L;
    nodito *auxCanciones;
    nodoC *ant, *act, *elim;
    unsigned int cantEliminadas = 0, cantMinutos = 0;

    while (auxListaSimple != NULL && strcmp(auxListaSimple->idInterprete, idInterprete) < 0)
        auxListaSimple = auxListaSimple->sig;
    if (auxListaSimple != NULL && strcmp(auxListaSimple->idInterprete, idInterprete) == 0)
    {
        printf("Interprete:%s\n", auxListaSimple->idInterprete);
        printf("Id Cancion          Titulo Cancion         Eliminada\n");
        auxCanciones = auxListaSimple->sub;

        while (auxCanciones != NULL)
        {
            if (*LR != NULL)
            {
                ant = *LR;
                act = (*LR)->sig;

                while ((strcmp(auxCanciones->idCancion, act->idCancion) != 0 || strcmp(auxListaSimple->idInterprete, act->idInterprete) != 0) && act != *LR)
                {
                    ant = act;
                    act = act->sig;
                }
                if (strcmp(auxCanciones->idCancion, act->idCancion) == 0 && strcmp(auxListaSimple->idInterprete, act->idInterprete) == 0)
                {
                    elim = act;
                    if (act == *LR)
                    {
                        if (act == act->sig)
                            *LR = NULL;
                        else
                        {
                            ant->sig = act->sig;
                            *LR = ant;
                        }
                    }
                    else
                        ant->sig = act->sig;
                    cantEliminadas += 1;
                    cantMinutos += auxCanciones->duracion;
                    printf("%s %s %c" auxCanciones->idCancion, auxCanciones->titulo, 'S');
                    free(elim);
                }
            }
            else
                printf("%s %s %c" auxCanciones->idCancion, auxCanciones->titulo, 'N');

            auxCanciones = auxCanciones->sig;
        }

        if (cantEliminadas == 0)
            printf("No se eliminaron canciones");
        else
            printf("%u canciones eliminadas (%u minutos)\n", cantEliminadas, cantMinutos);
    }

    void dejarSoloK(TPila * P, char idInterprete[11])
    {
        TElementoP elem;
        unsigned int longInterprete, cont = 0;
        if (!vaciaP(*P))
        {
            sacaP(P, &elem);
            dejarSoloK(P, idInterprete);
            // Analizo
            longInterprete = strlen(idInterprete);
            for (int i = 0; i < longInterprete; i++)
            {
                if (idInterprete[i] == elem.dobleId[i])
                    cont++;
            }
            // Si son del interpreta k las devuelvo
            if (cont == longInterprete)
                poneP(P, elem);
        }
    }
}

int main(void)
{
    TListaS L = NULL;
    TListaC LR = NULL;
    TPila P;
    char idInterprete[10];
    iniciaP(&P);
    cargarListaSimple(&L);
    cargarListaCircular(&LR);
    printf("Ingrese un id de interprete");
    scanf("%s", idInterprete);
    listarEliminando(L, &LR, idInterprete);
    agregarAListaCircular(L, &LR, &P);
    printf("Ingrese un id de interprete");
    scanf("%s", idInterprete);
    dejarSoloK(&P, idInterprete);
    return 0;
}