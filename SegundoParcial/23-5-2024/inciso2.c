

int cumpleArbol(arbol a ,pos p){
    int gradoAnt=-1,gradoAct=0,cumple=0,cumpleAscendente=1;
    pos hijo;
    if(!Nulo(a)){
        hijo=hijoMasIzq(p,a);
        if(!Nulo(hijo)){
            gradoAnt = calcularGrado(hijo);
            hijo = hermanoDer(hijo, a);
            while(!Nulo(hijo) && !cumple){
                cumple = cumple || cumpleArbol(hijo,a);
                gradoAct=calcularGrado(hijo);
                if(gradoAnt>gradoAct){
                    cumpleAscendente=0;
                }
                gradoAnt = gradoAct;
                hijo=hermanoDer(hijo,a); 
            }
            return cumple || cumpleAscendente;
        }
    }
    return 0;
}