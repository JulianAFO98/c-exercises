
typedef struct nodoS
{
    int dato;
    struct nodoS *sig;
} nodoS;

typedef nodoS *TListaS;

typedef struct nodoD
{
    int dato;
    struct nodoD *sig;
    struct nodoD *ant;
} nodoD;

typedef struct
{
    nodoD *pri;
    nodoD *ult;
} TListaD;