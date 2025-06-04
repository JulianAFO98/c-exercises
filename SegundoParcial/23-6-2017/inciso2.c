

int contarNodos(arbol a,pos p,int K,int nivAct){
    int cumplen=0,tieneHijoK=0;
    arbol hijo;
    if(!Nulo(a)){
         if(nivAct<=K){
            hijo=hijoMasIzq(p,a);
            while(!Nulo(hijo)){
                cumplen+=contarNodos(a,hijo,K,nivAct+1);
                if(nivAct==K && Info(hijo,a) == K){
                   tieneHijoK=1;
                }
                hijo=hijo->der;
            }
            return (cumplen + tieneHijoK);
         }
    }
    return cumplen;
}