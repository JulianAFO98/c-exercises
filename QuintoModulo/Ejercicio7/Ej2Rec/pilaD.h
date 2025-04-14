

typedef struct nodo
{
    char c;
    struct nodo *sig;
} nodo;
typedef nodo *TipoP;

void sacaP(TipoP *P, char *c);
void poneP(TipoP *P, char c);
void iniciaP(TipoP *P);
char consultaP(TipoP P);
int vaciaP(TipoP P);
