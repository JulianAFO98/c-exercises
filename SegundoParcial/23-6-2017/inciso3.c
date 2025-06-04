#define MAX 20
#include <stdlib.h>
#include <stdio.h>

int analizarMatrices(int A[MAX][MAX],int T[MAX][MAX],int i, int j,int n,int * costoAAM,int * aristas){
   if(i<=n){
     if(A[i][j]!=0){
        if(T[i][j]==1)
          (*costoAAM)+=A[i][j];
        else 
          (*aristas)++;
     }
     if(j<n) 
        analizarMatrices(A,T,i,j+1,n,costoAAM,aristas);
     else 
        analizarMatrices(A,T,i+1,i+1,n,costoAAM,aristas);
   }
}

int main() {
    int costoAAM=0, aristas=0, A[MAX][MAX],T[MAX][MAX],n;
    cargaA(A,&n);
    cargaT(T,n);
    //CODIGO EXTRA
    analizarMatrices(A,T,0,0,n-1,&costoAAM,&aristas);
    printf("Aristas que no estas en el AAM:%d,Costo total:%d\n",aristas,costoAAM);
    return 0;
}