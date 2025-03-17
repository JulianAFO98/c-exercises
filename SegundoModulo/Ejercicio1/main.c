/*
Describir lo que imprime el siguiente fragmento de código:
*/


#include <stdio.h>
#include <stdlib.h>

int main() {

    int *p, a = 4,b = 5;

    p = &b; // p => apunta a la memoria de b
    *p *= 2; // b = b * 2 => 10
    printf("b=%d *p=%d\n", b, *p); // 10 y 10
    printf("&b=%p p=%p &p=%p\n", &b, p, &p); // Espacio en memoria,Espacio en memoria de b, espacio en memoria del puntero


    b = *p * 3; //30
    printf("b=%d *p=%d\n", b, *p); // 30 y 30
    printf("&b=%p p=%p\n", &b, p); // espacio en memoria,espacio en memoria (ambos iguales)


    a = b; // a = 30
    p = &a;// p guarda direccion de a
    (*p)++; //31
    printf("b=%d a=%d *p=%d\n", b, a, *p); // 30  31 31
    printf("&b=%p &a=%p p=%p &p=%p\n", &b, &a, p, &p); // EM 1, EM2 ,EM2, EM3

    return 0;
}
