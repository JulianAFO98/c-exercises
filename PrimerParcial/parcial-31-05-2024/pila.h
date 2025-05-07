#define MAX 255
typedef struct
{
    char idCompuesto[20];
    unsigned int duracion;
} TElementoP;

typedef struct
{
    TElementoP datos[MAX];
    int tope;
} TPila;

void iniciaP(TPila *P);
void sacaP(TPila *P, TElementoP *E);
void poneP(TPila *P, TElementoP E);
TElementoP consultaP(TPila P);
int vaciaP(TPila P);