
typedef struct
{
    char cadena[100];
    unsigned int apariciones;
} Palabra;

typedef struct nodo
{
    Palabra pal;
    struct nodo *sig;
} nodo;

typedef nodo *TLista;
