#define MAX 255

typedef int TEC;

typedef struct
{
    TEC dato[MAX];
    int pri, ult;
} TCola;

void poneC(TCola *C, TEC e);
void sacaC(TCola *C, TEC *e);
void iniciaC(TCola *C);
TEC consultaC(TCola C);
int vaciaC(TCola C);
