

typedef struct {
    int vertice;
    float prom;
}regVec;


void generarVector(int mat[MAX][MAX], regVec vec[MAX], int n , int *k){
    int gradoSal,gradoEntr;
    for(int i=0;i<n;i++){
        gradoSal=calcularGradoSalida(mat,n,i);
        gradoEntr=calcularGradoEntrada(mat,n,i);
        if(gradoSal<gradoEntr){
            vec[*k].vertice=i;
            vec[*k].prom=gradoSal+gradoEntr/2;
            (*k)++;
        }
    }
}