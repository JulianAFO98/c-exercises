
#include "colaE.h"

void poneC(TC *C , TEC e){
    if(C->ult != MAX -1) {
        if(C->pri == -1) {
            C->pri = 0;
        }
        C->datos[++(C->ult)] = e;
    }
}
void sacaC(TC *C , TEC * e){
   
    if(C->pri!=-1) {
        *e = C->datos[C->pri];
        if(C->pri == C->ult) {
            iniciaC(C);
        }else {
            C->pri++;
        }
    }

}

TEC consultaC(TC C){
    if(C.pri != -1) {
        return C.datos[C.pri];
    }
}
int vaciaC(TC C){
    return C.pri == -1;
}
void iniciaC(TC * C){
    C->pri=C->ult=-1;
}