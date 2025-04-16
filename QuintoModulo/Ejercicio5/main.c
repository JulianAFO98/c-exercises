/*Corregir los errores en el siguiente código manualmente, el cual carga una cola y luego calcula y
muestra la suma de sus elementos.
#include <stdio.h>
#include "tdacola.h"
void leerCola(TCOLA *c);
int main(void) {
 TCOLA cola;
 TELEMENTOC n, suma;
 iniciac(cola);
 leerCola(&cola);
 suma == 0;
 while(!vaciac(*cola)) {
 sacac(cola, &n);
 suma -= n;
 }
 printf("%d", suma);
 return 0;
}
void leerCola(TCOLA *c) {
 TELEMENTOC n;
 iniciac(&c);
 while(scanf("%d", n))
 ponec(c, &n);
}  */

#include <stdio.h>
#include "tdacola.h"

void leerCola(TCOLA *c);
int main(void)
{
    TCOLA cola;
    TELEMENTOC n, suma; // suma de tipo elemento cola?
    iniciac(cola);      // Falta el &
    leerCola(&cola);
    suma == 0; // suma = 0;
    while (!vaciac(*cola))
    {                    // sin *
        sacac(cola, &n); // falta &
        suma -= n;       // suma+=n
    }
    printf("%d", suma); // suma es un TELEMENTOC
    return 0;
}
void leerCola(TCOLA *c)
{
    TELEMENTOC n;
    iniciac(&c);           // el *& se anula, iria solo iniciac(c)
    while (scanf("%d", n)) // que es n, no puedo leer si no tengo el tipo concreto, posible pero inseguro, asegurar con scanf()==1
        ponec(c, &n);      // n le sobra el &
}