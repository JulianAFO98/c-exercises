/*
Obtener el resultado de las siguientes expresiones, previa asignación de valores a las cuatro
*/

//variables:
//a) a + b * c / d
//b) (a + b) * c % d
//c) d < 65 && 3 == d
//d) a <= b || (3 > a)
//e) (a >= d) && (2 - 14 == c + 1)
//f) a>b || a<c && a = c || a >= b


main() {

    int a=10,b=5,c=7,d=2;

//a)
    int result = a + b * c / d ;
    printf("%d\n",result); // deberia imprimir 27

//b
    result = (a + b) * c % d;
    printf("%d\n",result); // deberia imprimir 1
//c
    result = d < 65 && 3 == d;
    printf("%d\n",result); // deberia imprimir false o 0(falsy);
//d
    result = a <= b || (3 > a);
    printf("%d\n",result); // deberia imprimir false o 0(falsy);

//e
    result = (a >= d) && (2 - 14 == c + 1);
    printf("%d\n",result); // deberia imprimir false o 0(falsy);

//f
    result = a>b || a<c && a = c || a >= b;
    printf("%d\n",result); // deberia imprimir error => con doble == muestra 1;

    return 0;
}
