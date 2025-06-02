


void minMax(arbol a,pos p,int K,int nivelAct, int * max,int *min){
    arbol hijo;
    int grado=0;
    if(!Nulo(p)){
        hijo=hijoMasIzq(p,a);
        while(!Nulo(hijo) && nivelAct<=K) {
            grado++;
            minMax(a,hijo,K,nivelAct+1,max,min);
            hijo=hermanoDer(hijo,a);
        }
        if(nivelAct == K){
            if(grado>*max )
               *max=grado;
            if(grado<*min) 
               *min=grado;       
        }
    }
}