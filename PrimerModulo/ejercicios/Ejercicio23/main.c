/*
Corregir el siguiente código para que asigne el contenido de la cadena cad1 a cad3, solamente
si cad1 y cad2 son distintas.
char cad1[20], cad2[20], cad3[20];
gets(cad1); gets(cad2);
if(cad1 != cad2)
 cad3 = cad1;

*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    char cad1[20], cad2[20], cad3[20];
    gets(cad1);
    gets(cad2);
    if(strcmp(cad1,cad2) != 0) {
        strcpy(cad3,cad1);
    }

    puts(cad3);

    return 0;
}
