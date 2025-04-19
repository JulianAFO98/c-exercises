
#include "cola.h"

void poneC(Cola *c, MaratonistaC m)
{
    if (!(c->ult == MAX - 1 && c->pri == 0 || c->ult + 1 == c->pri))
    {
        if (c->pri == -1)
        {
            c->pri = c->ult = 0;
        }
        else
        {
            if (c->ult == MAX - 1)
                c->ult = 0;
            else
                c->ult += 1;
        }
        c->v[c->ult] = m;
    }
}
void sacaC(Cola *c, MaratonistaC *m)
{
    if (c->pri != -1)
    {
        *m = c->v[c->pri];
        if (c->pri == c->ult)
            iniciaC(c);
        else
        {
            if (c->pri == MAX - 1)
                c->pri = 0;
            else
                c->pri += 1;
        }
    }
}
MaratonistaC consultaC(Cola c)
{
    if (c.pri != -1)
        return c.v[c.pri];
}
int vaciaC(Cola c)
{
    return c.pri == -1;
}
void iniciaC(Cola *c)
{
    c->pri = c->ult = -1;
}
