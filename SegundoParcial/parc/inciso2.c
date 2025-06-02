

int tieneGradoGImparyNegativo(arbol a,pos p, int G){
    int grado=0,cumple=0;
    pos hijo;
    if(!Nulo(p)){
        hijo=hijoMasIzq(p,a);
        while(!Nulo(hijo) && !cumple) {
            grado++;
            cumple = cumple || tieneGradoGImparyNegativo(a,hijo,G);
            hijo=hermanoDer(hijo,a);
        }
        return cumple || (Info(p,a)<0 && Info(p,a)%2 == 1 && grado == G);
    }
    return 0;
}