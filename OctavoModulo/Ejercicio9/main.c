/*
Hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia.
*/
typedef struct nodo {
    char letra;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    char letraPrincipal;
    TLista lista;
} nodoGrafo;

#include <stdlib.h>
#include <stdio.h>
#define MAX 20

void llenarVector(nodoGrafo v[],unsigned int *n);
void insertarAlFinal(TLista * L,char c);
void mostrarVector(nodoGrafo v[],unsigned int n);
int maxEntradaDigrafo(nodoGrafo v[],unsigned int n);
void inicializarVec(int v[],int n);
int buscarMax(int v[],int n);

int main(){
    nodoGrafo v[MAX];
    unsigned int n=0;
    llenarVector(v,&n);
    mostrarVector(v,n);
    printf("Maxima entrada de un digrafo en lista:%d\n",maxEntradaDigrafo(v,n));
    return 0;
}

int buscarMax(int v[],int n){
    int max=0;
    for (int i=0;i<n;i++){
        max = v[i]>max ? v[i] :max;
    }
    return max;
}

void inicializarVec(int v[],int n){
    for (int i=0;i<n;i++){
       v[i]=0;
    }
}

int maxEntradaDigrafo(nodoGrafo v[],unsigned int n){
    int vecAux[n],indice;
    inicializarVec(vecAux,n);
    nodo *aux;
    for(int i=0;i<n;i++){
      aux=v[i].lista;
      while(aux!=NULL){
        indice = aux->letra - 65;
        vecAux[indice]+=1;
        aux=aux->sig;
      }
    }
    return buscarMax(vecAux,n);
}






void mostrarVector(nodoGrafo v[],unsigned int n){
    TLista aux;
    for(int i=0;i<n;i++) {
        printf("%c \n",v[i].letraPrincipal);
        printf("'-----");
        aux=v[i].lista;
        while(aux!=NULL) {
            printf("%c ----> ",aux->letra);
            aux=aux->sig;
        }
        printf("NULL\n");
    }
}


void insertarAlFinal(TLista * L,char c){
    TLista aux=*L;
    nodo * nuevo = (nodo *) malloc(sizeof(nodo));
    nuevo->sig=NULL;
    nuevo->letra=c;
    if(*L==NULL) {
        *L =nuevo;
    }else {
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }

    

}


void llenarVector(nodoGrafo v[],unsigned int *n){
    FILE * arch;
    int k;
    char letraAux;

    arch=fopen("datos.txt","r");
    if(arch == NULL){
        printf("El archivo no existe\n");
    }else {
        while(fscanf(arch,"%c %d",&(v[*n].letraPrincipal),&k)==2){
            v[*n].lista=NULL;
            for(int i=0;i<k;i++){
                fscanf(arch," %c",&letraAux);
                insertarAlFinal(&(v[*n].lista),letraAux);
            }
            fscanf(arch,"%c",&letraAux);
            (*n)++;
           
        }
        fclose(arch);
    }
}
