/*
Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
  b) una lista de adyacencia
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
int gradoVer(nodoGrafo v[],int n,char vertice);


int main(){
    nodoGrafo v[MAX];
    unsigned int n=0;
    llenarVector(v,&n);
    mostrarVector(v,n);
    printf("Grado del vertice B(1):%d\n",gradoVer(v,n,'B'));

    return 0;
}

int gradoVer(nodoGrafo v[],int n,char vertice){
    nodo * aux;
    int grado=0;
    for(int i=0;i<n;i++){
     aux=v[i].lista;
     while(aux!=NULL){
        if(v[i].letraPrincipal == vertice && aux->letra == vertice) {
           grado+=2;
        }else {
            if(aux->letra == vertice) 
              grado+=1;
        }
        aux=aux->sig;
     }
    }
    return grado;
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


