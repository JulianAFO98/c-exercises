
typedef struct
{
    // DATOS
} TElementoC;

typedef struct nodo
{
    TElementoC dato;
    struct nodo *sig;
} nodo;

typedef struct
{
    nodo *pri;
    nodo *ult;
} TCola;

void poneC(TCola *C, TElementoC X);
void sacaC(TCola *C, TElementoC *X);
void iniciaC(TCola *C);
TElementoC consultaC(TCola C);
int vaciaC(TCola C);