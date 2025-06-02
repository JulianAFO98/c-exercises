

int contarNoVocales(arbol a , int K,int nivelAct) {
    int izq,der;
    if(a!=NULL && nivelAct<=K) {
        izq=contarNoVocales(a->izq,K,nivelAct+1);
        der=contarNoVocales(a->der,K,nivelAct);
        return !esVocal(a->dato) + izq + der;
    }
     return 0;
}


int esVocal(char letra){
    return letra == 'a' || letra == 'e' || letra == 'i' || letra == 'u' || letra == 'o';
}