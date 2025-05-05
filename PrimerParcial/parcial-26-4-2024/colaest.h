
#define DOM 8
typedef struct
{
    char dominio[DOM];
} TElementoC;

typedef struct
{
    TElementoC datos[255];
    unsigned int pri, ult;
} TCola;

void sacaC(TCola *C, TElementoC *e);
void poneC(TCola *C, TElementoC e);
int vaciaC(TCola C);
void iniciaC(TCola *C);
TElementoC consultaC(TCola C);