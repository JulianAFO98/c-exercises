

int calcularCantPuestos(TListaD PA)
{
    nodoDoble *aux = PA.pri;
    int cont = 0;
    while (aux != NULL)
        cont++;
    return cont;
}

void AtenderAutomoviles(TListaD PA, TListaS LT, TCola *C)
{
    TElementoC centinela = "zzzzzzz", elem;
    TListaS aux;
    nodoAuto *act, *nuevo, *ant;
    nodoDoble *auxDoble;
    unsigned int N, puestoAsignado, i;

    N = calcularCantPuestos(PA);
    poneC(C, centinela);
    while (!vaciaC(*C) && strcmp(consultaC(*C), centinela) != 0)
    {
        sacoC(C, &elem);
        aux = LT;
        while (aux != NULL && strcmp(elem, aux->dominio) > 0)
            aux = aux->sig;
        if (aux != NULL && strcmp(elem, aux->dominio) == 0)
        { // Si encontre el dominio
            if (aux->fecha[5] == '4')
            {
                i = 0;
                puestoAsignado = rand() % N + 1;
                auxDoble = PA;
                while (i < puestoAsignado - 1)
                { // Encontre el puesto ,jamas sera null, ya que tengo la cantidad de puestos
                    auxDoble = auxDoble->sig;
                    i++;
                }
                nuevo = (nodoAuto *)malloc(sizeof(nodoAuto));
                strcpy(nuevo->dominio, elem);
                nuevo->cantObs = 0;
                nuevo->sig = NULL;
                if (auxDoble->automoviles == NULL)
                    auxDoble->automoviles = nuevo;
                else
                {
                    act = auxDoble->automoviles;
                    while (act != NULL)
                    {
                        ant = act;
                        act = act->sig;
                    }
                    ant->sig = nuevo;
                }
            }
            else
                poneC(C, elem);
        }
        else
            // Si el dominio no esta lo listo
            printf("Turno rechazado para el dominio:%s\n", elem);
    }
    sacaC(C, centinela);
}

void eliminarAutomovilesRechazados(TListaD PA)
{

    nodoDoble *auxListaDoble;
    nodoSimple *act, *ant, *elim;
    FILE *arch;
    char puesto[4], dominio[8], estado;
    unsigned int observaciones;
    arch = fopen("TESTEOS.TXT", "r");
    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        while (fscanf("%s %s %u %c", puesto, dominio, &observaciones, &estado) == 4)
        {
            auxListaDoble = PA;
            while (auxListaDoble != NULL && strcmp(auxListaDoble->puesto, puesto) != 0)
                auxListaDoble = auxListaDoble->sig;
            if (auxListaDoble != NULL)
            {
                ant = NULL;
                act = auxListaDoble->automoviles;
                while (act != NULL && strcmp(act->dominio, dominio) != 0)
                {
                    ant = act;
                    act = act->sig;
                }
                if (act != NULL)
                {
                    if (estado == 'R')
                    {
                        elim = act;
                        if (act == auxListaDoble->automoviles)
                            auxListaDoble->automoviles = act->sig;
                        else
                            ant->sig = act->sig;
                        free(elim);
                    }
                    else
                        act->cantObs = observaciones;
                }
            }
        }
        fclose(arch);
    }
}

void eliminarTurnosIncorrectos(TListaS *LT)
{
    TListaS act = *LT, ant, elim;
    int cantIncorrectos = 0, cantTurnos = 0;
    while (act != NULL)
    {
        elim = NULL;
        if (!esCorrecto(act->domnio, act->fecha))
        {
            elim = act;
            if (act == *LT)
                *LT = (*LT)->sig;
            else
                ant->sig = act->sig;

            act = act->sig;
            cantIncorrectos++;
            free(elim);
        }
        else
        {
            ant = act;
            act = act->sig;
        }

        cantTurnos++;
    }

    if (cantTurnos != 0)
        printf("Cantidad de depurados:%.2f", (float)cantIncorrectos / cantTurnos);
    else
        printf("No hubieron turno");
}

int esCorrecto(char dominio[], char fecha[])
{
    int longDom;
    char ultNum;
    longDom = strlen(dominio);
    if (longDom == 6)
        ultNum = dominio[5];
    else
        ultNum = dominio[4];
    if (fecha[4] == '0')
        return ultNum == fecha[5];
    else
    {
        if (fecha[4] == '1' && fecha[5] == '0')
            return ultNum == '0';
        else
            return 1;
    }
}

int main(void)
{
    TCola C;
    TListaD PA;
    TListaS LT = NULL;
    iniciaC(&C);
    PA.pri = PA.ult = NULL;
    eliminarAutomovilesRechazados(&PA);
    AtenderAutomoviles(PA, LT, &C);
    eliminarTurnosIncorrectos(&LT);
    return 0;
}