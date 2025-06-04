/*
Desarrollar un subprograma que determine si un vértice (vj) es alcanzable desde otro (vj) para
un digrafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
*/


typedef struct nodo {
    int vertice;
    struct nodo * sig;
}nodo;

typedef nodo * TLista;

typedef struct {
    int verticePrincipal;
    TLista lista;
} nodoGrafo;

#include <stdlib.h>
#include <stdio.h>

#define MAX 20

void llenarVector(nodoGrafo v[],unsigned int *n);
void insertarAlFinal(TLista * L,int vertice);
void mostrarVector(nodoGrafo v[],unsigned int n);
void alcanza(nodoGrafo v[],int n,int vi ,int vj,int *ok,int vv[]);
int main(){
    nodoGrafo v[MAX];
    unsigned int n=0;
    int ok=0,vv[MAX]={0,0,0,0,0,0};
    llenarVector(v,&n);
    mostrarVector(v,n);
    alcanza(v,n,0,2,&ok,vv);
    printf("%d\n",ok);
    return 0;
}

void alcanza(nodoGrafo v[],int n,int vi ,int vj,int *ok,int vv[]){
    nodo*aux;
    if(vi == vj){
         *ok=1;
    }else {
        vv[vi]=1;
        aux=v[vi].lista;
        while (aux!=NULL && !(*ok))
        {
            if(vv[aux->vertice]==0)
              alcanza(v,n,aux->vertice,vj,ok,vv);
            aux=aux->sig;  
        }
        
    }
}






void mostrarVector(nodoGrafo v[],unsigned int n){
    TLista aux;
    for(int i=0;i<n;i++) {
        printf("%c \n",v[i].verticePrincipal + 'A');
        printf("'-----");
        aux=v[i].lista;
        while(aux!=NULL) {
            printf(" %c ----- ",aux->vertice + 'A');
            aux=aux->sig;
        }
        printf("NULL\n");
    }
}


void insertarAlFinal(TLista * L,int vertice){
    TLista aux=*L;
    nodo * nuevo = (nodo *) malloc(sizeof(nodo));
    nuevo->sig=NULL;
    nuevo->vertice=vertice;
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
    int k,vertice;

    arch=fopen("datos.txt","r");
    if(arch == NULL){
        printf("El archivo no existe\n");
    }else {
        while(fscanf(arch,"%d %d",&(v[*n].verticePrincipal),&k)==2){
            v[*n].lista=NULL;
            for(int i=0;i<k;i++){
                fscanf(arch," %d",&vertice);
                insertarAlFinal(&(v[*n].lista),vertice);
            }
            (*n)++;
           
        }
        fclose(arch);
    }
}
