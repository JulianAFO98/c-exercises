#include "cola.h"

void poneC(TCola *C, TEC e)
{

    if (!((*C).ult == MAX - 1 && (*C).pri == 0 || (*C).ult + 1 == (*C).pri))
    {
        if (C->pri == -1)
            C->pri = C->ult = 0;
        else if (C->ult == MAX - 1)
            C->ult = 0;
        else
            C->ult += 1;
        C->dato[C->ult] = e;
    }
}
void sacaC(TCola *C, TEC *e)
{
    if ((*C).pri != -1)
    {
        *e = (*C).dato[(*C).pri];
        if ((*C).pri == (*C).ult)
        {
            iniciaC(C);
        }
        else
        {
            if ((*C).pri == MAX - 1)
                (*C).pri == 0;
            else
                (*C).pri += 1;
        }
    }
}
void iniciaC(TCola *C)
{
    (*C).pri = (*C).ult = -1;
}
TEC consultaC(TCola C)
{
    if (C.pri != -1)
        return C.dato[C.pri];
}
int vaciaC(TCola C)
{
    return C.pri == -1;
}
