

typedef int TEP;

typedef struct nodoP
{
    TEP dato;
    struct nodoP *sig;
} nodoP;

typedef nodoP *TPila;

void poneP(TPila *P, TEP e);
void sacaP(TPila *P, TEP *e);
void iniciaP(TPila *P);
TEP consultaP(TPila P);
int vaciaP(TPila P);
