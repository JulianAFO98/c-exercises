/*
Dado un árbol binario proveniente de la conversión de un árbol general: 
a)  hallar la cantidad de nodos que habia en niveles impares.  
b) obtener el promedio de las claves cuyo grado era K (dato de entrada). 
c)  obtener la altura del árbol original 
d) determinar el grado del árbol original. 
*/

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
int contarNodosEnNivelImpar(arbol a,int nivel);
void obtenerPromK(arbol a,int K,int *sum,int *cont);
int obtenerAlturaOriginal(arbol a);
void obtenerGradoOriginal(arbol a, int *maxGrado,int cont);
int main()
{
    arbol a;
    int maxGrado=0,sum=0,cont=0;
    addnodo(&a,30);
    addnodo(&a->izq,35);
    addnodo(&a->izq->izq,14);
    addnodo(&a->izq->izq->der,15);
    addnodo(&a->izq->izq->der->der,25);
    addnodo(&a->izq->der,24);
    addnodo(&a->izq->der->der,73);
    addnodo(&a->izq->der->der->izq,60);
    addnodo(&a->izq->der->der->izq->der,28);
    printf("Cantidad de nodos impares %d\n",contarNodosEnNivelImpar(a,1));
    printf("Altura original:%d\n",obtenerAlturaOriginal(a));
    obtenerGradoOriginal(a,&maxGrado,0);
    printf("El  grado del AO es:%d\n",maxGrado);
    obtenerPromK(a,3,&sum,&cont);
    printf("Promedio de los nodos de grado 3: %.2f\n",(float)sum/cont);
    return 0;
}


void obtenerPromK(arbol a,int K,int *sum,int *cont){ // Siendo K un grado solicitado
  arbol hijo;
  int contH=0;
  if(a!=NULL) {
     hijo = a->izq;
     while(hijo!=NULL) {
       contH++;
       obtenerPromK(hijo,K,sum,cont);
       hijo=hijo->der;
     }
     if(contH==K) {
        (*sum)+=a->dato;
        (*cont)+=1;
     }

  }
}


//Version 1
void obtenerGradoOriginal(arbol a, int *maxGrado,int cont){
  if(a!=NULL) {
    if(a->der == NULL) {
      if(*maxGrado<cont) 
         *maxGrado =cont;
    }else {
      obtenerGradoOriginal(a->der,maxGrado,cont+1);
    }
    a->izq == NULL ? 
     obtenerGradoOriginal(a->izq,maxGrado,0):
     obtenerGradoOriginal(a->izq,maxGrado,1);  
  }
}

/* Version 2
void obtenerGradoOriginal(arbol a, int *maxGrado) {
    if (a == NULL) return;

    int grado = 0;
    arbol hijo = a->izq;

    while (hijo != NULL) {
        grado++;
        obtenerGradoOriginal(hijo, maxGrado);
        hijo = hijo->der;
    }

    if (grado > *maxGrado)
        *maxGrado = grado;
}
*/



int obtenerAlturaOriginal(arbol a){
    int izq,der;
    if(a!=NULL) {
        izq = 1 + obtenerAlturaOriginal(a->izq);
        der = obtenerAlturaOriginal(a->der);
        return izq>der ? izq:der;
    }else
     return 0;
}


int contarNodosEnNivelImpar(arbol a,int nivel){
  /*if(a!=NULL) {
    printf("%d %d\n",a->dato,(nivel % 2 == 1));
    return  (nivel % 2 == 1) + contarNodosEnNivelImpar(a->izq,nivel+1) +contarNodosEnNivelImpar(a->der,nivel);
  }else 
   return 0;
   */
   return a!=NULL ? (nivel % 2 == 1) + contarNodosEnNivelImpar(a->izq,nivel+1) +contarNodosEnNivelImpar(a->der,nivel):0;
}


void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}