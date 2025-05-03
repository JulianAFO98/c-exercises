typedef struct nodo
{
    struct nodo *sig;
    struct nodo *ant;
    char apellido[100];
    char nombre[100];
    char categoria;
} nodo;

typedef struct
{
    nodo *pri;
    nodo *ult;
} TListaD;