


typedef struct {
    int num;
} ElementoPila;

typedef struct nodop {
  ElementoPila elem;
  struct nodop * sig;
} nodop;

typedef nodop * TPila;

void iniciaP(TPila *P);
void sacaP(TPila *P,ElementoPila * pelem);
void poneP(TPila *P,ElementoPila elem);
int vaciaP(TPila P);
ElementoPila consultaP(TPila P);
