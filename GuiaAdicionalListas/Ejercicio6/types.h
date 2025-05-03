
typedef int TElementoL;

typedef struct nodo
{
    TElementoL dato;
    struct nodo *sig;
} nodo;

typedef nodo *TLista;