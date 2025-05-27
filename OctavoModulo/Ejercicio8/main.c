/*
Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.
b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.
c) determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
(triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).
d) generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
   unsigned int grado,vertice;
}regVer;

void llenarMatriz(int mat[MAX][MAX], int *n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void generarVector(int mat[MAX][MAX], int vec[MAX], int n);
int hallarMayorGradoEntradaDigrafo(int mat[MAX][MAX], int n);
int alMenosUnoK(int mat[MAX][MAX], int n,int k);
void generarVectRegistros(int mat[MAX][MAX],int n,regVer vec[],int * m);

int main()
{
    int mat[MAX][MAX], n = 0, vec[MAX],k,m=0;
    regVer vecReg[MAX];
    llenarMatriz(mat, &n);
    mostrarMatriz(mat, n);
    //a
    /*generarVector(mat, vec, n);
    for(int i=0;i<n;i++){
        printf("%d ",vec[i]);
    }
    printf("\n");
    */
    //b
    //printf("Mayor grado del digrafo:%d\n",hallarMayorGradoEntradaDigrafo(mat,n));
    //c
    /*
    printf("Ingrese K\n");
    scanf("%d",&k);
    printf(alMenosUnoK(mat,n,k)?"cumple\n":"no cumple\n");
    */
    generarVectRegistros(mat,n,vecReg,&m);
    for(int t=0;t<m;t++){
        printf("Vertice %d Grado %d\n",vecReg[t].vertice,vecReg[t].grado);
    }
    return 0;
}

void generarVectRegistros(int mat[MAX][MAX],int n,regVer vec[],int * m){
    int grado, i,j;
    for (int i = 0; i < n; i++)
    {
         grado = 0;

        for (int j = i + 1; j < n; j++) {
            grado += mat[i][j];
        }

        for (int j = 0; j < i; j++) {
            grado += mat[j][i];
        }

        grado += mat[i][i] * 2; // cuenta por 2
        
        if(grado>3) {
            vec[*m].grado=grado;
            vec[*m].vertice=i;
            (*m)++;
        }
        
    }
}



int alMenosUnoK(int mat[MAX][MAX], int n,int k){ // Preguntar por adyacente de uno mismo, y por Maximo un bucle(costos) ,tri sup incluye diagonal?
   int cumple,cumpleFinal=1,j;

    for (int i = 0; i < n; i++)
    {
        
        j=i+1;
        cumple=0;
        if(mat[i][i] >=k) {
            cumple=1;
        }else {
            while(j<n && !cumple) {
              if(mat[i][j]>=k)
                cumple=1;
              j++;
            }
            j=0;
            while(j<i && !cumple){
                if(mat[j][i]>=k)
                 cumple=1;
                j++;
            }
        }
        
        cumpleFinal=cumpleFinal && cumple;
    }
    return cumpleFinal;
}


int hallarMayorGradoEntradaDigrafo(int mat[MAX][MAX], int n){
   int grado,gradoMax=0;

   for (int i=0;i<n;i++){
     grado=0;
     for(int j=0;j<n;j++){
        grado+=mat[j][i];
     }
     gradoMax = grado>gradoMax ? grado : gradoMax;
   }
   return gradoMax;
}


void generarVector(int mat[MAX][MAX], int vec[MAX], int n)
{
    int grado, i,j,k;
    for (int i = 0; i < n; i++)
    {
         grado = 0;

        for (int j = i + 1; j < n; j++) {
            grado += mat[i][j];
        }

        for (int j = 0; j < i; j++) {
            grado += mat[j][i];
        }

        grado += mat[i][i] * 2;
        vec[i]=grado;
        
    }
}

void llenarMatriz(int mat[MAX][MAX], int *n)
{
    printf("Ingrese el valor de n\n");
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
        {
            printf("Ingrese [%d,%d]\n", i, j);
            scanf("%d", &mat[i][j]);
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
