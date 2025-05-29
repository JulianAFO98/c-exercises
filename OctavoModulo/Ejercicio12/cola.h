
typedef int TElementoC;

typedef struct nodoC {
    TElementoC dato;
    struct nodoC * sig;
} nodoC;

typedef struct {
    nodoC * pri;
    nodoC * ult;
} TCola;

int vaciaC(TCola C);
void iniciaC(TCola * C);
void sacaC(TCola * C, TElementoC * e);
void poneC(TCola * C, TElementoC e);
TElementoC consultaC(TCola C);
