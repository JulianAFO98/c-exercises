

typedef struct
{
    char car;
} TEC; // tipo elemento cola

typedef struct nodoC
{
    TEC dato;
    struct nodoC *sig;
} nodoC;

typedef struct
{
    nodoC *pri;
    nodoC *ult;
} TC; // tipo cola

void poneC(TC *C, TEC e);
void sacaC(TC *C, TEC *e);
TEC consultaC(TC C);
int vaciaC(TC C);
void iniciaC(TC *C);
