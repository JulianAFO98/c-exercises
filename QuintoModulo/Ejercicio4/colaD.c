
/*#include "colaD.h"
#include <stdio.h> 
#include <stdlib.h>


void poneC(TC *C , TEC e){
  nodo * aux;
  aux = (nodo *) malloc(sizeof(nodo));
  aux->dato=e;
  aux->sig=NULL;
  if((*C).pri == NULL) {
     (*C).pri =aux;
  }else {
     (*C).ult->sig = aux;
  }
  (*C).ult=aux;

}
void sacaC(TC *C , TEC * e){
 nodo * aux;
 if((*C).pri!=NULL) {
     aux = (*C).pri;
     *e = aux->dato;
     (*C).pri=(*C).pri->sig;
     if((*C).pri == NULL) {
        (*C).ult=NULL;
     }
     free(aux);
 }
}

TEC consultaC(TC C){
    return C.pri->dato;
}
int vaciaC(TC C){
    return  C.pri == NULL;
}
void iniciaC(TC * C){
    (*C).pri = (*C).ult = NULL;
}
    */