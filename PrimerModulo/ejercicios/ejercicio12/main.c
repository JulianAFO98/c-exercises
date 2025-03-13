/*
Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
por teclado. La serie finaliza al ingresar el número 0.
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int num,sum=0;

    do {
        scanf("%d",&num);
        sum+=num;
    } while(num!=0);
    printf("%d",sum);

    return 0;
}
