/*
Desarrollar un subprograma que duplique los elementos de un vector
ubicados en las posiciones pares.


Implementar 3 veces utilizando for, while y do while

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void duplicarVector(int []);
void mostrarVector(int []);


int main()
{
    int v[] = {1,2,3,4,5,6,7,8,9,10};

    mostrarVector(v);
    duplicarVector(v);
    mostrarVector(v);
    return 0;
}


void duplicarVector(int v[]){
    //Con For
    /*for(int i = 0 ; i < SIZE; i+=2) {
        v[i]*=2;
    }*/
    //Con While
    /*int i=0;
    while (i<SIZE){
        v[i]*=2;
        i+=2;
    }*/
    //Con DoWhile
    int i=0;
    do {
        v[i]*=2;
        i+=2;
    }while(i<SIZE);


}
void mostrarVector(int v[]){
    for(int i = 0 ; i < SIZE; i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}
