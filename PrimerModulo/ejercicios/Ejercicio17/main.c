
/*. Enumerar los valores de todos los componentes de los
siguientes arreglos. Especificar los
arreglos de caracteres que pueden ser utilizados
 correctamente como cadenas.
a) int v1[4] = {0};
b) int v2[5] = {6};
c) int v3[] = {2,4,6};
d) char s1[4] = {‘h’,’o’,’y’};
e) char s2[] = {‘h’,’o’,’y’};
f) char s3[4]= {‘h’,’o’,’y’,’\0’};
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
    int v1[4] = {0};

    for (int i = 0; i<4;i++) {
        printf("%d",v1[i]);
    }
    */
    //Se Inicializa todo con 0

    /*int v2[5] = {6};
    for (int i = 0; i<5; i++) {
        printf("%d",v2[i]);
    }
    */

    // Se inicializa (pos,valor) => {0:6 , 1:0 , 2:0 , 3:0 , 4:0}

    /*
     int v3[] = {2,4,6};
     for (int i = 0; i<3; i++) {
         printf("%d",v3[i]);
     }
    */

    // Se inicializa (pos,valor) => {0:2 , 1:4 , 2:6}

    //char s1[4] = {'h','o','y'}; // No sirve como cadena
    //char s2[] = {'h','o','y'};  // No sirve como cadena
    char s3[4]= {'h','o','y','\0'}; // Sirve
    for (int i = 0; i<4; i++) {
        printf("%c",s3[i]);
    }
    puts(s2);
    return 0;
}
