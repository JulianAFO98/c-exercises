
#define MAX 100

typedef struct {
    int num;
} ElementoPila;

typedef struct {
  ElementoPila Pila[MAX];
  int tope;
} TPila;

void iniciaP(TPila *P);
void sacaP(TPila *P,ElementoPila * pelem);
void poneP(TPila *P,ElementoPila elem);
int vaciaP(TPila P);
ElementoPila consultaP(TPila P);
