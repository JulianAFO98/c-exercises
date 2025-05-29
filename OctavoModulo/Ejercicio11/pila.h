
typedef int TElementoP;

typedef struct nodoP {
    TElementoP dato;
    struct nodoP * sig;
} nodoP;

typedef nodoP * TPila;

int vaciaP(TPila P);
void iniciaP(TPila * P);
void sacaP(TPila * P, TElementoP * e);
void poneP(TPila * P, TElementoP e);
TElementoP consultaP(TPila P);
