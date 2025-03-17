/*
Responder, siendo x un arreglo de 10 enteros (int x[10]):
a) ¿Se puede determinar por la siguiente invocación funarr(x, n) si x
es parámetro de entrada o de salida?
b) ¿Se puede acceder al contenido de x[10]? ¿Qué representa el valor
obtenido?
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[10];
    /*
    a) No se puede ya que los arreglos se pasan por referencia directamente
    asi que no sabemos si se modifico o no*/
    printf("%d",x[10]);
    /*
    b)Un valor basura? Se genera un comportamiento indefinido
    */

    return 0;
}
