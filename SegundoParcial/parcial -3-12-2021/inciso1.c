

int cumpleAlgunArbol(arbol a,int K){
    int cumple=0;
    if(a!=NULL){
       while(a!=NULL && !cumple){
           cumple=verificarArbol(a,K,1);
           a=a->der;
       }
    }
    return cumple;
}

int verificarArbol(arbol a,int K,int nivAct){
    int cumple=0,cumpleAnterior=1;
    arbol hijo,hijoAnt;
    if(a!=NULL){
        if(nivAct<=K){
            hijo=a->izq;
            while(hijo!=NULL && !cumple){
                cumple = cumple || verificarArbol(hijo,K,nivAct+1);
                hijoAnt=hijo;
                hijo=hijo->der;
                if(hijo!=NULL && hijoAnt->dato>hijo->dato)
                  cumpleAnterior=0;
            }
            return cumple || (cumpleAnterior && nivAct==K);
        }
    }
    return 0;
}