

#include "string.h"

/*String crear(char *c) {

    String string;
    unsigned short int i=0;

    while (*(c+i)!='\0') {
        string.c[i]=*(c+i);
        i++;
    }
    string.length = i;
    return string;

}*/


String crear(char *c) {

    String string;
    unsigned short int i=0;

    while (*(c+i)!='\0') {
        i++;
    }
    string.length = i;

    string.c = (char *) malloc(i* sizeof(char));

    for (int j=0; j<i; j++) {
        *(string.c+j)=*(c+j);
    }

    return string;

}

void deleteString(String s) {

    free(s.c);
}

void imprimir(String str) {
    for(int i=0; i<str.length; i++) {
        printf("%c",str.c[i]);
    }
    printf("\n");
}

char charAt(String s, int pos) {
    return s.c[pos];
}

String concat(String  s1, String s2) {
    String aux;
    aux.c = (char *) malloc((s1.length+s2.length)* sizeof(char));;
    for( int i=0; i<s1.length; i++) {
        *(aux.c+i)=*(s1.c+i);
    }
    for(int i=0; i<s2.length; i++) {
        *(aux.c+i+s1.length)=*(s2.c+i);
    }
    aux.length=s1.length+s2.length;
    return aux;
}

/*String concat(String  s1, String s2) {
    String aux;
    for( int i=0; i<s1.length; i++) {
        *(aux.c+i)=*(s1.c+i);
    }
    imprimir(aux);
    for(int i=0; i<s2.length; i++) {
        *(aux.c+i+s1.length)=*(s2.c+i);
    }
    aux.length=s1.length+s2.length;
    return aux;
}*/

String reemplazar(String s, char caracter, char nuevoCaracter) {
    String aux;
    aux.c = (char *) malloc(s.length* sizeof(char));
    for (int i=0; i<s.length; i++) {
        if(s.c[i]==caracter) {
            aux.c[i]=nuevoCaracter;
        } else {
            aux.c[i]=s.c[i];
        }
    }
    aux.length=s.length;
    return aux;
}


int startsWith(String s, String prefijo) {
    int cont=0;
    while(s.c[cont]==prefijo.c[cont]  && cont < s.length)
        cont++;
    return cont == prefijo.length;
}

int endsWith(String s, String sufijo) {

    int cont=0;
    int pos=s.length-sufijo.length;
    while(s.c[pos] == sufijo.c[cont] && cont<sufijo.length) {
        cont++;
        pos++;
    }
    return cont == sufijo.length;
}


void imprimirArch(String s, FILE* arch) {
    //fwrite(s, sizeof(String), 1, arch);
}



String subString(String s, int desde, int hasta) {
    String aux;
    aux.c = (char *) malloc((hasta-desde)* sizeof(char));;
    for(int i=0; i<=hasta; i++) {
        aux.c[i] = s.c[i+desde];
    }
    aux.length = hasta-desde;
    return aux;
}





int tamanio(String s) {
    return s.length;
}
