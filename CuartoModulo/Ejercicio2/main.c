/*
Desarrollar un TDA que represente la idea de “texto”. En C no existe este tipo básico, con lo
cual las aplicaciones siempre quedan acopladas a la idea de que un string es una cadena de
caracteres, por lo que se manejan con punteros y posiciones. Realizar una implementación
estática y una dinámica. Analizar la manera de trabajar con la longitud del texto evitando tener
que almacenar el carácter '\0'. Las operaciones que deberá soportar el TDA son (se propone no
utilizar funciones strxxx):
◦ crear(char* c) retorna Texto
◦ destruir(Texto t) sin valor de retorno. Libera la memoria reservada en crear.
◦ tamaño(Texto t) retorna entero.
◦ imprimir(Texto t) (por pantalla)
◦ imprimirArch(Texto t, FILE* arch)
◦ caracterEn(Texto texto, entero posición) retorna caracter.
◦ concatenar(Texto t1, Texto t2) retorna Texto.
◦ reemplazar(Texto texto, char caracter, char nuevoCaracter) retorna Texto.
Ej: reemplazar('Balsa', 'a', 'o') >> 'Bolso'
◦ subTexto(Texto texto, entero desde, entero hasta) retorna Texto.
Ej: subTexto('HolaMundo', 4, 7) retorna 'Mun'
◦ comienzaCon(Texto texto, Texto prefijo) retorna entero|booleano.
◦ terminaCon(Texto texto, Texto sufijo) retorna entero|booleano.
*/


#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main()
{

    String str = crear("Hola");
    String str2 = crear("Mundo");
    imprimir(str);
    imprimir(str2);
    printf("\nLa longitud del string es %d", tamanio(str));
    printf("\nEl caracter en posicion 1 es %c\n", charAt(str,1));
    String str3 = concat(str,str2);
    imprimir(str3);
    String str4= crear("Bolso");
    String str5 = reemplazar(str4,'o','a');
    imprimir(str5);
    String str6 = crear("HolaMundo");
    String str7 = subString(str6,4,7);
    imprimir(str7);
    printf(startsWith(str6,str) ? "Empieza\n": "No empieza\n");
    printf(endsWith(str6,str2) ? "Termina": "No termina");
    deleteString(str);
    deleteString(str2);
    deleteString(str3);
    deleteString(str4);
    deleteString(str5);
    deleteString(str6);
    deleteString(str7);
    return 0;

}
