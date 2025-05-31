

struct nodoGrafo {
    char LetraPrinc;
    nodo * lista ; // tambien puede ser TLista lista
}

int recorrerMat(int mat[MAX][MAX],nodoGrafo vecLista[MAX],int i,int j,int n,int gradoEntrada, int bucle){
    int cumpleGPrima;
    if(j<n){
       if(i<n){
         if(mat[i][j]!=0){
            gradoEntrada+=1;
            if(i==j)
              bucle=1;
         }
         return recorrerMat(mat,vecLista,i+1,j,n,gradoEntrada,bucle);  
       }else {
          if(gradoEntrada % 2 == 0 && bucle){
             cumpleGPrima=verificarCumpleGPrima(vecLista,n,j);
             if(cumpleGPrima)
                return recorrerMat(mat,vecLista,0,j+1,n,0,0);
             else 
                return 0;   
          }else {
             return recorrerMat(mat,vecLista,0,j+1,n,0,0);
          }
       }
    }else {
      return 1;
    }


}



int verificarCumpleGPrima(nodoGrafo vecLista[MAX],int n,int posBuscada){
    int cantNodos=0,tieneBucle=0;
    nodo * aux = vecLista[posBuscada].lista;
    char letraEnPosAct=vecLista[posBuscada].letraPrinc;
    while(aux!=NULL){
         cantNodos++;
         if(aux->letra == letraEnPosAct)
            tieneBucle =1;
        aux=aux->sig;    
    }
    return (cantNodos % 2 == 1) && !tieneBucle;
}