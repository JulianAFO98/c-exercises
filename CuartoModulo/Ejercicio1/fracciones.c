
#include "fracciones.h"
#include <stdio.h>

Fraccion crearFraccion(int numerador, int denominador) {
    Fraccion frac;
    frac.denominador = denominador;
    frac.numerador = numerador;
    return frac;
}


int getNumerador(Fraccion frac) {
    return frac.numerador;
}


int getDenominador(Fraccion frac) {
    return frac.denominador;
}

Fraccion sumar(Fraccion f1, Fraccion f2) {
    Fraccion fracSuma;
    fracSuma.numerador=f1.numerador*f2.denominador+f1.denominador*f2.numerador;
    fracSuma.denominador=f1.denominador*f2.denominador;
    return fracSuma;
}

Fraccion restar(Fraccion f1,Fraccion f2) {
    Fraccion fracResta;
    fracResta.numerador=f1.numerador*f2.denominador-f1.denominador*f2.numerador;
    fracResta.denominador=f1.denominador*f2.denominador;
    return fracResta;

}

Fraccion multiplicar(Fraccion f1, Fraccion f2) {
    Fraccion frac;
    frac.numerador=f1.numerador*f2.numerador;
    frac.denominador=f1.denominador*f2.denominador;
    return frac;
}


Fraccion dividir(Fraccion f1, Fraccion f2) {
    Fraccion frac;
    frac.numerador=f1.numerador*f2.denominador;
    frac.denominador=f1.denominador*f2.numerador;
    return frac;
}

Fraccion simplificar(Fraccion f) {
    int max,min;

    if(f.numerador>f.denominador) {
        max=f.numerador;
        min=f.denominador;

    } else {
        max=f.denominador;
        min=f.numerador;
    }

    int mcd = MCD(max,min);

    f.denominador /=mcd;
    f.numerador /=mcd;

    return f;

}

int iguales(Fraccion f1, Fraccion f2){
       Fraccion f3 = simplificar(f1);
       Fraccion f4 = simplificar(f2);
       return f3.denominador == f4.denominador && f3.numerador == f4.numerador;
}

int MCD(int dividendo, int divisor) {

    int resto,restoUtil;

    do {
        resto = dividendo % divisor; //1
        dividendo=divisor;
        divisor=resto;
    } while(resto!=0);
    return dividendo;

}

