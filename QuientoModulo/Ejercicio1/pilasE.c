
#include "pilasE.h"


void iniciaP(TPila *P) {
    P->tope = -1;
    //(*P).tope =-1;

}
void sacaP(TPila *P,ElementoPila * pelem){
      if(P->tope!=-1)
        *pelem = P->Pila[(P->tope)--];
}

void poneP(TPila *P,ElementoPila elem) {
    if(P->tope < MAX-1)
        P->Pila[++(P->tope)] = elem;
}

int vaciaP(TPila P) {
    return P.tope != -1;
}

ElementoPila consultaP(TPila P) {
    if (P.tope != -1)
        return P.Pila[P.tope];

}
