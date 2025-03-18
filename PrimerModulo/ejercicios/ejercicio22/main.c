/*
Responder:
a) ¿Por qué no es correcta la siguiente sentencia: scanf("%s", &cad)?
// cad es una cadena, como es un vector ya se pasa por referencia o memoria
b) ¿Qué instrucción resulta conveniente para leer por teclado apellido y nombre de una
persona: gets o scanf? Justificar la elección.
gets porque no se corta en espacios, pero fue eliminada por inseguridad
c) ¿Qué representan los valores devueltos por la función strcmp?
-1 si las cad1 es menor que cad2
0 si son iguales
>0 si cad1 es mayor que cad 2  PREGUNTAR
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
