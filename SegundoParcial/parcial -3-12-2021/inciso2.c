int cantNodos(arbol a,pos p){
    pos hijo;
    int grado=0,acum=0,cantHijosCumplen=0;
    if(!Nulo(p,a)){
       hijo=hijoMasIzq(p,a);
       if(!Nulo(hijo,a)){
           while(!Nulo(hijo,a)){
            grado++;
            acum+=Info(hijo,a);
            cantHijosCumplen+=cantNodos(a,hijo);
            hijo=hermanoDer(hijo,a);
           }
           return (grado< (float)acum/grado) + cantHijosCumplen;
       }
    }
    return 0;
}