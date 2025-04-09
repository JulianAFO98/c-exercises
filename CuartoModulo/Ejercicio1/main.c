/*
Realizar un TDA para números fraccionarios, es decir aquellos que se expresan como el
cociente de dos números enteros. Las operaciones que deberá soportar el TDA son:
◦ crear(entero numerador, entero denominador) retorna fracción.
◦ numerador(fracción f) retorna entero.
◦ denominador(fracción f) retorna entero.
◦ sumar(fracción f1, fracción f2) retorna fracción.
◦ restar(fracción f1, fracción f2) retorna fracción.
◦ multiplicar(fracción f1, fracción f2) retorna fracción.
◦ dividir(fracción f1, fracción f2) retorna fracción.
◦ simplificar(fracción f) retorna fracción simplificada.
◦ iguales(fracción f1, fracción f2) retorna verdadero o falso
*/


#include <stdio.h>
#include <stdlib.h>
#include "fracciones.h"



int main() {
    Fraccion fraccion1 = crearFraccion(3,9);
    Fraccion fraccion2 = crearFraccion(1,3);
    printf("Numerador:%d Denominador:%d\n",getNumerador(fraccion1),getDenominador(fraccion1));
    Fraccion fraccion3 = sumar(fraccion1,fraccion2);
    printf("Numerador:%d Denominador:%d\n",getNumerador(fraccion3),getDenominador(fraccion3));
    Fraccion fraccion4 = restar(fraccion1,fraccion2);
    printf("Numerador:%d Denominador:%d\n",getNumerador(fraccion4),getDenominador(fraccion4));
    Fraccion fraccion5 = multiplicar(fraccion1,fraccion2);
    printf("Numerador:%d Denominador:%d\n",getNumerador(fraccion5),getDenominador(fraccion5));
    Fraccion fraccion6 = dividir(fraccion1,fraccion2);
    printf("Numerador:%d Denominador:%d\n",getNumerador(fraccion6),getDenominador(fraccion6));
    Fraccion fraccion7 = simplificar(fraccion1);
    printf("Numerador:%d Denominador:%d\n",getNumerador(fraccion7),getDenominador(fraccion7));
    printf(iguales(fraccion1,fraccion2) ? "Son iguales ":"No son iguales");
    return 0;
}
