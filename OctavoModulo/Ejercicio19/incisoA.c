/*
Desarrollar un subprograma que determine si un vértice (vj) es alcanzable desde otro (vj) para
un digrafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void llenarMatriz(int mat[MAX][MAX], int *n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void  alcanza(int mat [MAX][MAX],int i ,int j,int n,int *ok,int vv[]);

int main()
{
    int mat[MAX][MAX], n = 0,vertice=0,max=0,vv[MAX]={0,0,0,0,0,0},ok=0;
    llenarMatriz(mat, &n);
    mostrarMatriz(mat, n);
    alcanza(mat,0,2,n,&ok,vv);
    printf("%d\n",ok);
    return 0;
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
        for (int i = 1; i <= *n; i++)
            for (int j = 1; j <= *n; j++)
                fscanf(arch, "%d", &mat[i][j]);
        fclose(arch);
    }
}

void mostrarMatriz(int mat[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}




void  alcanza(int mat [MAX][MAX],int i ,int j,int n,int *ok,int vv[]){
    int k;
    if(mat[i][j]!=0)
     *ok=1;
    else{
        k=0;
        while(k<n && *ok == 0){
            if(vv[k]==0){
                vv[k]=1;
                alcanza(mat,k,j,n,ok,vv);
            }
            k++;
        } 
    }     
}