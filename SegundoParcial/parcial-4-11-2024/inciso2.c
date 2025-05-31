/*
Vacio(A) Devuelve verdadero si A es árbol Vacío.

Nulo(p) Devuelve verdadero si p es la posición Nula

HijoMasIzq(p,A) Devuelve la posición del hijo más a la izquierda de p, si p es hoja devuelve una
posición nula.

HermanoDer(p,A) Devuelve la posición del hermano a la derecha de p (tiene el mismo padre de p), si p
es el de la extrema derecha devuelve una posición nula.

Info(p,A) Devuelve el dato del en la posición p en el árbol A.

Raiz(A) Devuelve una posición que es la raíz del árbol A.

Padre(p,A) Devuelve la posición del padre de la posición p en el árbol A, si p es la raíz devuelve una
posición nula.

*/


int cuantosCumplen(arbol a,pos p,int K,int nivelAct){
    pos hijo,hijoInicial;
    int cont=0,cumple=1;
    if(!Nulo(p) && nivelAct<K){
         hijo=hijoMasIzq(p,a);
         hijoInicial=hijo;
         while(!Nulo(hijo)) {
            cont= cont + cuantosCumplen(a,hijo,K,nivelAct+1);
            cumple = cumple && (Info(hijo, a) % Info(hijoInicial, a) == 0);
            hijo=HermanoDer(hijo,a);
         }
          if (nivelAct < K && (!Nulo(hijoInicial) && Nulo(hijoMasIzq(hijoInicial, a))) && cumple) {
             cont += 1;
           }
          return cont; 
    }else {
        return 0;
    }

}