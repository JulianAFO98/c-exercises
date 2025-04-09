

typedef struct {
 int numerador,denominador;
} Fraccion;



Fraccion crearFraccion(int numerador, int denominador);
int getNumerador(Fraccion frac);
int getDenominador(Fraccion frac);
Fraccion sumar(Fraccion f1, Fraccion f2);
Fraccion restar(Fraccion f1,Fraccion f2);
Fraccion multiplicar(Fraccion f1, Fraccion f2);
Fraccion dividir(Fraccion f1, Fraccion f2);
Fraccion simplificar(Fraccion f);
int iguales(Fraccion f1, Fraccion f2);

