/*Completar la expresión del siguiente if para que se ejecute su parte verdadera y la variable a
contenga el valor 1 luego de esa sentencia.*/

main() {
    int a = 0;
    if( a++==0 )
        printf("a vale 0");
    else
        printf("a vale 1");

    printf("\n%d",a);
    return 0;
}
