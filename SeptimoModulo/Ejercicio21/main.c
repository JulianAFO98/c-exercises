/*
Dado un árbol binario que proviene de la transformación de un bosque,  
a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada) 
b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque. 
c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada). 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef int TElememtoA;
typedef struct nodo
{
    TElememtoA dato;
    struct nodo *izq;
    struct nodo *der;
} NODO;
typedef NODO *arbol;



void addnodo(arbol *a, TElememtoA e);
int obtenerAlturaOriginal(arbol a);
int hallarCantAlturaK(arbol a , int k);
void generarVectorMaximosArbol(arbol a,int vec[],unsigned int *dimV);
int obtenerMaxArbol(arbol a);
int verificarBosqueGradoK(arbol a, int k);
int esGradoK(arbol a,int k);
int main()
{
    arbol a;
    int k,vec[MAX];
    unsigned int dimV=0;
    addnodo(&a,30);
    addnodo(&a->izq,35);
    addnodo(&a->izq->izq,14);
    addnodo(&a->izq->izq->der,15);
    addnodo(&a->izq->izq->der->der,25);
    addnodo(&a->izq->der,24);
    addnodo(&a->izq->der->der,73);
    addnodo(&a->izq->der->der->izq,60);
    addnodo(&a->izq->der->der->izq->der,28);
    //Segundo arbol
    addnodo(&a->der,40);
    addnodo(&a->der->izq,50);
    addnodo(&a->der->izq->der,60);
    addnodo(&a->der->izq->der->der,70);
    addnodo(&a->der->izq->der->der->izq,80);
    //a
    printf("Ingrese k: ");
    scanf("%d",&k);
    printf("La cantidad de arboles con altura original %d es %d\n",k,hallarCantAlturaK(a,k));
    //b
    generarVectorMaximosArbol(a,vec,&dimV);
    for(int i=0;i<dimV;i++) {
        printf("%d ",vec[i]);
    }
    //c
    printf("Ingrese k nuevamente: \n");
    scanf("%d",&k);
    printf(verificarBosqueGradoK(a,k)?"Cumple\n":"No cumple\n");
    return 0;
}

int verificarBosqueGradoK(arbol a,int k){
    arbol aux;
    int verifica=0;
    while(a!=NULL && !verifica) {
        verifica=esGradoK(a,k);
        a=a->der; 
    }
    return verifica;
}

int esGradoK(arbol a,int k) {
    int cont=0,cumple=0;
    arbol hijo;
    if(a!=NULL) {
       
        hijo = a->izq;
        while(hijo!=NULL && !cumple) {
            cont++;
            cumple= cumple || esGradoK(hijo,k);
            hijo=hijo->der;
        }
        return cumple || cont == k;

    }else 
      return 0;
}



void generarVectorMaximosArbol(arbol a,int vec[],unsigned int *dimV){
   
    while(a!=NULL) {
        vec[(*dimV)++]=obtenerMaxArbol(a);
        a=a->der; 
    }
}

int obtenerMaxArbol(arbol a){
     int izq,der;
     if(a!=NULL) {
       izq=obtenerMaxArbol(a->izq);
       der=obtenerMaxArbol(a->der);
       if(a->dato>=izq && a->dato>=der)
         return a->dato;
       else 
         if(izq>=der && izq>=a->dato)
           return izq;
         else 
           return der;    
     }else 
      return -32000; // valor Imposible
}

int hallarCantAlturaK(arbol a , int k){
    arbol aux;
    int alt,cont=0;
    aux=a;
    while(aux!=NULL) {
        alt=obtenerAlturaOriginal(aux);
        if(alt>=k)
         cont++;
        aux=aux->der; 
    }
    return cont;
}

int obtenerAlturaOriginal(arbol a){
    int izq,der;
    if(a!=NULL) {
        izq = 1 + obtenerAlturaOriginal(a->izq);
        der = obtenerAlturaOriginal(a->der);
        return izq>der ? izq:der;
    }else
     return 0;
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

