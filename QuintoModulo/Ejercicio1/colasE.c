#include "colasE.h"


void IniciaC (TCola * C) {
    C->primero=-1;
    C->ultimo=-1;
}
int VaciaC (TCola C){
    return C.ultimo==-1;
}
TElementoC consultaC (TCola C){
    if(C.ultimo!=-1)
     return C.elementos[C.primero];
}

void sacaC (TCola *C, TElementoC* x){
    if(C->primero != -1) {
        *x = C->elementos[C->primero];
        if(C->primero == C->ultimo) {
            IniciaC(C);
        }else
          C->primero++;
    }
}

void poneC (TCola *C, TElementoC x) {
    if(C->ultimo!=SIZE-1) {
        if(C->primero ==-1) {
            C->primero = 0;
        }
        C->elementos[++(C->ultimo)] = x;
    }
}
