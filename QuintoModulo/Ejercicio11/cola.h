

typedef struct
{
    unsigned int legajo, tiempoSegundosArribo, tiempoSegundosHorno;
} empleado;

typedef struct nodo
{
    empleado dato;
    struct nodo *sig;
} nodo;

typedef struct
{
    nodo *pri;
    nodo *ult;
} cola;

void poneC(cola *C, empleado e);
void sacaC(cola *C, empleado *e);
void iniciaC(cola *C);
int vaciaC(cola C);
empleado consultaC(cola C);