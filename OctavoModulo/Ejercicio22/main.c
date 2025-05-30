/*
Desarrollar un subprograma para mostrar el camino del vértice origen al vértice v (dato) a partir
del vector P generado por el algoritmo de Dijkstra
*/
#define MAX 20
#include <stdlib.h>
#include <stdio.h>

void mostrarCaminoP(int vec[MAX],int origen,int destino);

int main(){
    int vec[MAX] = {0,0,1,0},k;
    scanf("%d",&k);
    mostrarCaminoP(vec,3,k);
    return 0;
}

void mostrarCaminoP(int vec[MAX],int origen,int destino){ 
  if(destino!=origen) {
     if(vec[destino]!=0){
       mostrarCaminoP(vec,origen,vec[destino]);
     }else {
       mostrarCaminoP(vec,origen,origen);// Verificar si no es alcanzable
      }
      printf("%d ",destino);
  }else {
    printf("%d ",destino);
  }
}
