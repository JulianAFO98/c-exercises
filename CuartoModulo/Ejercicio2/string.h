


/*typedef struct {
    char c[256];
    unsigned short int length;
} String;
*/

typedef struct {
    char *c;
    unsigned short int length;
} String;


String crear(char *c);
void imprimir(String str);

int tamanio(String s);


char charAt(String s, int pos);

String concat(String  s1, String s2);

String reemplazar(String s, char caracter, char nuevoCaracter);

String subString(String s, int desde, int hasta);

int startsWith(String s, String prefijo);

void deleteString(String s);

//String imprimirArch(String s, FILE* arch);

int endsWith(String s, String sufijo);
