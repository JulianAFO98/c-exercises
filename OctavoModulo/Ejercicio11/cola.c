#include <stdlib.h>
#include "cola.h"


int vaciaC(TCola C){
    return C.pri == NULL;
}
void iniciaC(TCola * C){
    (*C).pri = (*C).ult == NULL;
}
void sacaC(TCola * C, TElementoC * e){
    nodo * aux;
    if((*C).pri!=NULL) {
       *e = (*C).pri->dato;
       aux = (*C).pri;
       (*C).pri = (*C).pri->sig;
       if((*C).pri==NULL)
          (*C).ult = NULL;
       free(aux);      
    }
}
void poneC(TCola * C, TElementoC e){
    nodo * nuevo = (nodo *) malloc(sizeof(nodo));
    nuevo->dato = e;
    nuevo->sig=NULL;
    if((*C).pri==NULL) {
        (*C).pri=nuevo;
    }else {
        (*C).ult->sig=nuevo;
    }
    (*C).ult=nuevo;
}
TElementoC consultaC(TCola C){
    if(C.pri != NULL)
      return C.pri->dato;
}
