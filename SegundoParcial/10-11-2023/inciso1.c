
int contarArboles(arbol a,int K1,int K2){
    int cont=0;
    if(a==NULL){
        return 0;
    }else {
        while(a!=NULL){
            if(cumpleK1K2(a,K1,K2,1))
             cont++;
            a=a->der;
        }
        return cont;
    }
}

int cumpleK1K2(arbol a,int K1,int K2,int nivelAct){
    arbol hijo;
    int cumple=0;
    if(a!=NULL){
        if(nivelAct<=K2){
            hijo=a->izq;
            while(hijo!=NULL && !cumple){
                if(hijo->dato<0 && nivelAct>=K1 )
                  cumple=1;
                cumple = cumple || cumpleK1K2(hijo,K1,K2,nivelAct+1);
                hijo=hijo->der;
            }
            return cumple || (nivelAct >= K1 && a->dato<0); 
        }
    }
    return cumple;
}