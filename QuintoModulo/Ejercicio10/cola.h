

typedef char TEC;

typedef struct nodo
{
    TEC dato;
    struct nodo *sig;
} nodo;

typedef struct
{
    nodo *pri;
    nodo *ult;
} cola;

void poneC(cola *C, TEC e);
void sacaC(cola *C, TEC *e);
void iniciaC(cola *C);
int vaciaC(cola C);
TEC consultaC(cola C);