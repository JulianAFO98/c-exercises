
void insertaAlFinal(TListaS *L,char codigoEst) {
    nodito* nuevo,*aux;
    nuevo= (nodito*)malloc(sizeof(nodito));
    nuevo->codigoEst=codigoEst;
    nuevo->sig=NULL;

    if(*L == NULL) {
        *L=nuevo;
    }else {
        aux=*L;
        while(aux->sig != NULL) {
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }
}



void llenarLista(TListaD *LD){
    nodoD* auxDoble,*nuevo;
    FILE*arch = fopen("archivo.txt","r");
    char codigoEst,nombreEst[30],codigoEstPas;
    unsigned int cantEsp;
    
    if(arch==NULL){
        printf("No se pudo abrir el archivo");
    }else {
       while(fscanf(arch,"%c %s %u",&codigoEst,nombreEst,&cantEsp)==3) {
            auxDoble = (*LD).pri;
            while(auxDoble!= NULL && strcmp(codigoEst,auxDoble->codigoEst)>0){
                auxDoble=auxDoble->sig;
            }
            if(auxDoble!=NULL && strcmp(codigoEst,auxDoble->codigoEst)==0){
                  for(int i=0;i<cantEsp;i++) {
                    fscanf(arch," %c",&codigoEstPas);
                    insertaAlFinal(&auxDoble->sub,codigoEstPas);
                  }
            }else {
                nuevo= (nodoD*)malloc(sizeof(nodoD));
                nuevo->codigoEst = codigoEst;
                nuevo->sub=NULL;
                strcpy(nuevo->nombreEst,nombreEst);
                if(auxDoble == NULL || strcmp(codigoEst,auxDoble->codigoEst)<0) {
                    nuevo->ant =NULL;
                    nuevo->sig = (*LD).pri;
                    if((*LD).pri == NULL) {
                        (*LD).ult = nuevo;
                    }else {
                        (*LD).pri->ant=nuevo;
                    }
                    (*LD).pri=nuevo;
                }else {
                    if(strcmp(codigoEst,(*LD).ult->codigoEst)>0){
                        (*LD).ult -> sig = nuevo;
                        nuevo->ant = (*LD).ult;
                        nuevo->sig = NULL;
                        (*LD).ult = nuevo;
                    }else {
                        nuevo->sig=auxDoble;
                        auxDoble->ant->sig=nuevo;
                        nuevo->ant= auxDoble->ant;
                        auxDoble->ant=nuevo;
                    }
                }
                for(int i=0;i<cantEsp;i++) {
                    fscanf(arch," %c",&codigoEstPas);
                    insertaAlFinal(&nuevo->sub,codigoEstPas);
                }
            }

       }
       fclose(arch);
    }
}

void ascenso(TLista *L,TPila *tren, unsigned int *pasajerosActu,unsigned int CAPA,char estacionActual,char idaOVuelta) {

   nodito*aux,*ant,*elim;
   int condicionAscenso;
   ant=NULL;
   aux=*L;
   while(aux!=NULL && *pasajerosActu < CAPA) {
       condicionAscenso = (idaOVuelta == 'I') ? aux->codigoEst>estacionActual : aux->codigoEst<estacionActual;
       if(condicionAscenso) {
          elim=aux;
          poneP(tren,aux->codigoEst);
          (*pasajerosActu)+=1;
          if(aux==*L) {
             *L=(*L)->sig;
          }else {
            ant->sig=aux->sig;
          }
          aux=aux->sig;
          free(elim);
       }else {
        ant=aux;
        aux=aux->sig;
       }
   }
}

void descenso(char codigoEst,TPila *tren,unsigned int *pasajerosActuales){
   
    char elem;
    if(!vaciaP(*tren)) {
        sacaP(tren,&elem);
        descenso(codigoEst,tren,pasajerosActuales);
        if(elem == codigoEst)
           (*pasajerosActuales)-=1;
        else 
          poneP(tren,elem);   
    }

}

void recorridoEnTren(TListaD *LD,TPila* tren,unsigned int CAPA){
  unsigned int pasajerosActu=0;
  nodoD*auxDoble=(*LD).pri;
  while(auxDoble !=NULL) {
    descenso(auxDoble->codigoEst,tren,&pasajerosActu);
    ascenso(&(auxDoble->sub),tren,&pasajerosActu,CAPA,auxDoble->codigoEst,'I');
    auxDoble=auxDoble->sig;
  }
  auxDoble=(*LD).ult;
  pasajerosActu=0;
  while(auxDoble !=NULL) {
    descenso(auxDoble->codigoEst,tren,&pasajerosActu);
    ascenso(&(auxDoble->sub),tren,&pasajerosActu,CAPA,auxDoble->codigoEst,'V');
    auxDoble=auxDoble->ant;
  }



}