

typedef struct
{
    char palo;
    int numero;
} Carta;

typedef struct nodo
{
    Carta dato;
    struct nodo *sig;
} nodo;

typedef nodo *Pila;

void poneP(Pila *P, Carta c);
void sacaP(Pila *P, Carta *c);
Carta consultaP(Pila P);
void iniciaP(Pila *P);
int vaciaP(Pila P);