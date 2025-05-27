/*
Dado un vértice determinado de un digrafo representado en una lista de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice 
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
int gradoSalida(nodoGrafo v[],int n,char vertice);
int gradoEntrada(nodoGrafo v[],int n,char vertice);
int gradoVer(nodoGrafo v[],int n,char vertice);


int main(){
    nodoGrafo v[MAX];
    unsigned int n=0;
    llenarVector(v,&n);
    mostrarVector(v,n);
    printf("El grado de salida para D es:%d(-1 si no existe el nodo)\n",gradoSalida(v,n,'D'));
    printf("El grado de entrada para D es:%d(-1 si no existe el nodo)\n",gradoEntrada(v,n,'D'));
    printf("Grado de D:%d\n",gradoVer(v,n,'D'));
    return 0;
}


int gradoVer(nodoGrafo v[],int n,char vertice){
    int gradoSal=0,gradoEnt=0,bucles=0;
    nodo * aux;
    for(int i=0;i<n;i++) {
       aux=v[i].lista;
       while(aux!=NULL){
          if(v[i].letraPrincipal==vertice) {
            if(aux->letra==v[i].letraPrincipal)
                bucles++;
            gradoSal++;
          }
          if(aux->letra==vertice)
            gradoEnt++;
          aux=aux->sig;
       }
    }   
    return gradoEnt+gradoSal-bucles;
    
}


int gradoSalida(nodoGrafo v[],int n,char vertice){
    int i=0,grado=0;
    nodo * aux;
    while (i<n && v[i].letraPrincipal!=vertice)
      i++;
    if(i<n){
        aux = v[i].lista;
        while (aux!=NULL){
            grado++;
            aux=aux->sig;
        }
        return grado;
    }else 
        return -1;
    
}

int gradoEntrada(nodoGrafo v[],int n,char vertice){
    int i=0,grado=0,existe=0;
    nodo * aux;
    for(int i=0;i<n;i++){
        aux = v[i].lista;
        while (aux!=NULL){
            if(aux->letra==vertice){
                existe=1;
                grado++;
            }
            aux=aux->sig;
        }
    }
    return existe ? grado : -1;
     
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
