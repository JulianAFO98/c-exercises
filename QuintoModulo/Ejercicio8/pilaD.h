
typedef int TEP;

typedef struct nodo
{
    TEP e;
    struct nodo *sig;
} nodo;
typedef nodo *TipoP;

void sacaP(TipoP *P, TEP *e);
void poneP(TipoP *P, TEP e);
void iniciaP(TipoP *P);
TEP consultaP(TipoP P);
int vaciaP(TipoP P);
