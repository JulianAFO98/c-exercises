#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo
{
    TElememtoA dato;
    struct nodo *izq;
    struct nodo *der;
} NODO;
typedef NODO *arbol;

void addnodo(arbol *a, TElememtoA e);
void insertaIte(arbol *a,int X);
int main()
{
    arbol a;
    addnodo(&a, 15);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 10);

    addnodo(&a->der, 20);
    addnodo(&a->der->izq, 18);
    addnodo(&a->der->izq->der, 19);
    insertaIte(&a,40);
    return 0;
}
void insertaIte(arbol *a,int X)
{
    arbol aux=*a,nuevo,ant;
    int direc;
    nuevo=(NODO *)malloc(sizeof(NODO));
    nuevo->dato=X;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    if(*a == NULL) {
        *a=nuevo;
    }else {
        ant=NULL;
        aux=*a;
        while(aux!=NULL){
            ant=aux;
            if(aux->dato<X){
                aux=aux->der;
                direc=1;
            }
            else{
                aux=aux->izq; 
                direc=0;
            }
        }
        if(direc)
           ant->der=nuevo;
        else 
           ant->izq=nuevo;    

        
    }
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}