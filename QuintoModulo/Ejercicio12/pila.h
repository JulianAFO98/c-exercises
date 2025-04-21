

typedef struct nodo
{
    char dato;
    struct nodo *sig;
} nodo;

typedef nodo *TipoPila;

void poneP(TipoPila *P, char c);
void sacaP(TipoPila *P, char *c);
void iniciaP(TipoPila *P);
char consultaP(TipoPila P);
int vaciaP(TipoPila P);
