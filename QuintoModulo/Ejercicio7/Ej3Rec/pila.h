

typedef struct {
  char DNI[20];
} TElementoP; 

typedef struct nodo{
   TElementoP dato;
   struct nodo * sig;
} nodo;

typedef nodo * TipoP;

void poneP(TipoP *P,TElementoP x);
void sacaP(TipoP *P,TElementoP *e);
void iniciaP(TipoP *P);
int vaciaP(TipoP P);
TElementoP consultaP(TipoP P);



