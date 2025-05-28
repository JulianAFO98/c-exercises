
typedef int TElementoC;

typedef struct nodo {
    TElementoC dato;
    struct nodo * sig;
} nodo;

typedef struct {
    nodo * pri;
    nodo * ult;
} TCola;

int vaciaC(TCola C);
void iniciaC(TCola * C);
void sacaC(TCola * C, TElementoC * e);
void poneC(TCola * C, TElementoC e);
TElementoC consultaC(TCola C);
