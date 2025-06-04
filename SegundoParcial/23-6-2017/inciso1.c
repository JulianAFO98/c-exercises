

int todosCumplen(arbol a,int X){
    int cumple=1;
    if(a!=NULL){
        while(a!=NULL && cumple) {
           cumple=cumpleArbol(a,X);
           a=a->der;
        }
    }else 
      cumple=0;
     
    return cumple;
}

int cumpleArbol(arbol a,int X){
    int cumple=0,grado=0;
    arbol hijo;
    if(a!=NULL) {
        hijo=a->izq;
        while(hijo!=NULL && !cumple) {
            grado++;
            cumple = cumple || cumpleArbol(hijo,X);
            hijo=hijo->der;
        }
        return cumple || grado == X;
    }
    return cumple;
}