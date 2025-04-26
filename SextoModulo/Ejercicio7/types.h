
typedef struct
{
    char titulo[100];
    char autor[100];
    unsigned int anioEdicion;
} Libro;

typedef struct nodito
{
    Libro libro;
    struct nodito *sig;
} nodito;

typedef nodito *subLista;

typedef struct nodoS
{
    char socio[100];
    struct nodoS *sig;
    subLista sub;
} nodoS;

typedef struct nodo
{
    char autor[100];
    struct nodo *sig;
    subLista sub;
} nodo;

typedef nodo *TLista;
typedef nodoS *TListaS;
