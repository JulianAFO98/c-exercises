

typedef struct
{
    char nombre[30];
    char apellido[30];
} Maratonista;

typedef struct nodo
{
    Maratonista dato;
    struct nodo *sig;
} nodo;

typedef nodo *Pila;

void poneP(Pila *P, Maratonista e);
void sacaP(Pila *P, Maratonista *e);
Maratonista consultaP(Pila P);
void iniciaP(Pila *P);
int vaciaP(Pila P);