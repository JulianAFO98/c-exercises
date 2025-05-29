/*
Para un grafo almacenado en una lista de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas 
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
#include "cola.h"
#include "pila.h"
#define MAX 20

void llenarVector(nodoGrafo v[],unsigned int *n);
void insertarAlFinal(TLista * L,char c);
void mostrarVector(nodoGrafo v[],unsigned int n);
void mostrarEnAmplitud(nodoGrafo v[], int n);
int hayaCeros(int vec[], int n);
int buscarNodoDisp(int vec[MAX], int n);
void agregarAdyacentes(TCola *C, nodoGrafo v[], int n, int indice, int vecVisitados[]);
void mostrarEnProfundidad(nodoGrafo v[], int n);
int caminoDisponible(nodoGrafo v[], int n, int indice, int vecVisitados[]);
int cantConexos(nodoGrafo v[],int n);
int main(){
    nodoGrafo v[MAX];
    unsigned int n=0;
    llenarVector(v,&n);
    mostrarVector(v,n);
    //mostrarEnAmplitud(v,n);
    printf("\n");
    mostrarEnProfundidad(v,n);
    printf("\n");
    printf("Cantidad de conexos:%d\n",cantConexos(v,n));
    return 0;
}

int cantConexos(nodoGrafo v[],int n){
     TPila P;
    int vecVisitados[MAX] = {0}, nodoActual, indice,k=1;
    iniciaP(&P);
    poneP(&P, 4); // Mi primer nodo es E(4)
    while (hayaCeros(vecVisitados, n))
    {
        if (vaciaP(P))
        {   
            k++;
            poneP(&P, buscarNodoDisp(vecVisitados, n));
        }

        while (!vaciaP(P))
        {
            nodoActual = consultaP(P);
            if (!vecVisitados[nodoActual])
            {
                vecVisitados[nodoActual] = k;
            }
            indice = caminoDisponible(v, n, nodoActual, vecVisitados);
            if (indice == -1)
                sacaP(&P, &nodoActual);
            else
                poneP(&P, indice);
        }
    }
    return k;
}


int hayaCeros(int vec[], int n)
{
    int i = 0;
    while (i < n && vec[i] != 0)
        i++;
    return i < n;
}

int buscarNodoDisp(int vec[MAX], int n)
{
    int i = 0;
    while (i < n && vec[i] != 0)
        i++;
    return i;
}

void mostrarEnProfundidad(nodoGrafo v[], int n)
{
    TPila P;
    int vecVisitados[MAX] = {0}, nodoActual, indice,k=1;
    iniciaP(&P);
    poneP(&P, 4); // Mi primer nodo es E(4)
    while (hayaCeros(vecVisitados, n))
    {
        if (vaciaP(P))
        {   
            k++;
            poneP(&P, buscarNodoDisp(vecVisitados, n));
        }

        while (!vaciaP(P))
        {
            nodoActual = consultaP(P);
            if (!vecVisitados[nodoActual])
            {
                printf("%c ", nodoActual + 65);
                vecVisitados[nodoActual] = k;
            }
            indice = caminoDisponible(v, n, nodoActual, vecVisitados);
            if (indice == -1)
                sacaP(&P, &nodoActual);
            else
                poneP(&P, indice);
        }
    }
}

int caminoDisponible(nodoGrafo v[], int n, int indice, int vecVisitados[]){
    int letraEnNumero,existe=0;
    nodo * aux = v[indice].lista;
    while(aux!=NULL && !existe){
        letraEnNumero=aux->letra-65;
        if(vecVisitados[letraEnNumero] == 0){
            existe=1;
        }else{
            aux=aux->sig;
        }
    }
    return existe ? letraEnNumero : -1;
}

void mostrarEnAmplitud(nodoGrafo v[], int n)
{
    TCola C;
    int vecVisitados[MAX]={0}, nodoActual,k=1;
    iniciaC(&C);
    poneC(&C, 4); // Mi primer nodo es E(4)
    while (hayaCeros(vecVisitados, n))
    {
        if (vaciaC(C))
        {
            k++;
            poneC(&C, buscarNodoDisp(vecVisitados, n));
        }
        while (!vaciaC(C))
        {
            sacaC(&C, &nodoActual);
            if (!vecVisitados[nodoActual])
            {
                printf("%c ", nodoActual + 65);
                vecVisitados[nodoActual] = k;
                agregarAdyacentes(&C, v, n, nodoActual, vecVisitados);
            }
        }
    }
}

void agregarAdyacentes(TCola *C, nodoGrafo v[], int n, int indice, int vecVisitados[]){
   int letraEnNumero;
   nodo* aux=v[indice].lista;
   while(aux!=NULL){
    letraEnNumero=aux->letra-65; // Convierte la letra en numero A = 0 B = 1 etc
    if(vecVisitados[letraEnNumero]==0)
      poneC(C,letraEnNumero);
    aux=aux->sig;
   }


}





void mostrarVector(nodoGrafo v[],unsigned int n){
    TLista aux;
    for(int i=0;i<n;i++) {
        printf("%c \n",v[i].letraPrincipal);
        printf("'-----");
        aux=v[i].lista;
        while(aux!=NULL) {
            printf(" %c ----- ",aux->letra);
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
