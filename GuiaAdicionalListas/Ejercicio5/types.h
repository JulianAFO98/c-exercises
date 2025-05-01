
typedef int TElementoL;

typedef struct nodo
{
    TElementoL dato;
    struct nodo *sig;
    struct nodo *ant;
} nodo;

typedef struct
{
    nodo *pri;
    nodo *ult;
} TLista;