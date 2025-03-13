/*
Corregir los errores del siguiente fragmento de código para que muestre los números naturales
impares hasta el 15 inclusive.
#define <stdio.h>
#define N 9
int i;
for(i = 1; I < N; i++);
 printf(“%d”, &I);
 */


#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    for(i = 1; i<=15; i+=2){
         printf("%d\n", i);
    }


    return 0;
}
