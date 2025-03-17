/*5. Desarrollar una función que reciba tres números enteros y devuelva si son consecutivos entre sí
o si no lo son. */

#include <stdio.h>
#include <stdlib.h>

sonConsecutivos(int,int,int);

int main() {
    int a = 5,b =6,c = 8;
    printf(sonConsecutivos(a,b,c)? "true":"false");
    return 0;
}

int sonConsecutivos(int a,int b, int c) {
    int max,min;

    if(a>b && a>c) {
        max=a;
        if(b>c) {
            min = c;
        } else {
            min = b;
        }
    } else {
        if(b>a && b>c) {
            max=b;
            if(a>c) {
                min = c;
            } else {
                min = a;
            }
        } else {
            max=c;
            if(b>a) {
                min = a;
            } else {
                min = b;
            }
        }
    }

    return (max-min) == 2 ? 1 : 0;
    // Opcion con ordenamiento

    /*
    if (a > b) { int aux = a; a = b; b = aux; }
    if (b > c) { int aux = b; b = c; c = aux; }
    if (a > b) { int aux = a; a = b; b = aux; }


    return (b == a + 1 && c == b + 1);

    */
}
