
typedef struct {
    int i,j;
}regCamino;

#include <stdio.h>
#include <stdlib.h>


#define MAX 20

void llenarMatriz(int mat[MAX][MAX], int *n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void kruskal(int mat[MAX][MAX], int n);
void inicializarVector(int vec[MAX],int n);
int sonTodosIguales(int vec[MAX],int n);
void actualizarValores(int vec[MAX],int n,int vi,int vj);
void prim(int mat[MAX][MAX], int n,int inicial);


int main()
{
    int mat[MAX][MAX], n = 0;
    llenarMatriz(mat, &n);
    mostrarMatriz(mat, n);
    kruskal(mat,n);
    prim(mat,n,3);
    return 0;
}

int hayaCeros(int v[MAX],int n){
    int i=0;
    while(i<n && v[i]!=0){
        i++;
    }
    return i<n;
}


void prim(int mat[MAX][MAX], int n,int inicial){
    int U[MAX]={0},minimo,costoTotal=0,k=0;
    regCamino vecCamino[MAX];
    U[inicial]=1;
    while(hayaCeros(U,n)){
       minimo=9999;
       for(int i=0;i<n;i++){
        if(U[i]==1){
            for(int j=0;j<n;j++){
                if((mat[i][j]!=0 && mat[i][j]<minimo) && U[j]==0){
                   minimo=mat[i][j];
                   vecCamino[k].i=i;
                   vecCamino[k].j=j;
                }
            }
        }
    }
       U[vecCamino[k].j]=1;
       costoTotal+=minimo;
       k++;
    }
    printf("Costo total del camino:%d\n",costoTotal);
    for (int i = 0; i < k; i++) {
        printf("%d - %d\n", vecCamino[i].i + 1, vecCamino[i].j + 1);
    }
}









void inicializarVector(int vec[MAX],int n){
    for(int i=0;i<n;i++){
        vec[i]=i;
    }
}

int sonTodosIguales(int vec[MAX],int n){
    int primerValorArr=vec[0],i=1;
    while(i<n && primerValorArr == vec[i])
     i++;
    return i>=n;

}


void actualizarValores(int vec[MAX],int n,int vi,int vj){
    for(int i=0;i<n;i++){
        if(vec[i]==vi){
            vec[i]=vj;
        }
    }
}


void kruskal(int mat[MAX][MAX], int n){
    int vcc[MAX],k=0,minimo,costoTotal=0;
    regCamino vecCamino[MAX];
    inicializarVector(vcc,n);
    while(!sonTodosIguales(vcc,n)){
      minimo=9999;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if((mat[i][j]<minimo && mat[i][j]!=0) && vcc[i]!=vcc[j]){
            minimo=mat[i][j];
            vecCamino[k].i=i;
            vecCamino[k].j=j;
          }
        }
      }
      actualizarValores(vcc,n,vcc[vecCamino[k].i],vcc[vecCamino[k].j]);
      costoTotal+=minimo;
      k++;
    }
    printf("Costo total del camino:%d\n",costoTotal);
    for (int i = 0; i < k; i++) {
        printf("%d - %d\n", vecCamino[i].i + 1, vecCamino[i].j + 1);
    }
}


void llenarMatriz(int mat[MAX][MAX], int *n)
{
    FILE *arch;

    arch = fopen("datos.txt", "r");
    if (arch == NULL)
        printf("El archivo no existe\n");
    else
    {
        printf("Ingrese el valor de n\n");
        scanf("%d", n);
        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *n; j++)
                fscanf(arch, "%d", &mat[i][j]);
        fclose(arch);
    }
}

void mostrarMatriz(int mat[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}