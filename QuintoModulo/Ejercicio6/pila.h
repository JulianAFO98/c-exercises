

typedef int TEP;

typedef  struct nodo {
   TEP dato;
   struct nodo * sig;
}nodo;

typedef nodo * TP;


void poneP(TP *P,TEP e);
void sacaP(TP *P,TEP * e);
TEP consultaP(TP P);
void iniciaP(TP* P);
int vaciaP(TP P);
