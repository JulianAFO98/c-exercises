/*Desarrollar una macro que devuelva cada uno de los siguientes resultados:
a) Máximo de 2 números b) Caracter es alfabético
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (a>b ? a : b)
#define isAlphabetical(car) ((car>=65 && car<=90  || car>=97 && car<=122) ? 1 : 0)

int main()
{
    /*int maxValue = MAX(155,200);
    printf("%d",maxValue);
    */
    char letra;
    printf("Ingrese una letra\n");
    scanf(" %c",&letra);
    if(isAlphabetical(letra)) {
        printf("Es un caracter alfabetico");
    }else {
        printf("No es un caracter alfabetico");
    }
    return 0;
}
