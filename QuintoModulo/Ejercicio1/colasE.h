
#define SIZE 100


typedef int TElementoC;

typedef struct {
    TElementoC elementos[SIZE];
    int primero,ultimo;
} TCola;


void IniciaC (TCola * C);
int VaciaC (TCola C);
TElementoC consultaC (TCola C);
void sacaC (TCola *C, TElementoC* x);
void poneC (TCola *C, TElementoC x);
