




int todosCumplen(arbol a){
    int cumple;
    if(a==NULL)
     return 0;
    else {
        while(a!=NULL && cumple){
            cumple=verificarArbol(a);
            a=a->der;  
        }
        return cumple;
    } 
}

int consonante(char palabra[]) {
    char c = tolower(palabra[0]);
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}


int verificarArbol(arbol a) {
    arbol hijo;
    int grado=0,cumple=0;

    if(a!=NULL){
        hijo=a->izq;
        while(hijo!=NULL){
             cumple = cumple || verificarArbol(hijo);
             grado++;
             hijo=hijo->der;
        }
        return cumple || (consonante(a->dato) && grado % 2 == 0);  
    }else {
        return 0;
    }
}