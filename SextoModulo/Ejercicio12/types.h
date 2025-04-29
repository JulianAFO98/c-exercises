typedef struct nodoSub
{
    int dato;
    struct nodoSub *sig;
} nodoSub;

typedef nodoSub *subLista;
typedef struct nodoD
{
    int A, B;
    subLista sub;
    struct nodoD *sig;
    struct nodoD *ant;
} nodoD;

typedef struct
{
    nodoD *pri;
    nodoD *ult;
} TListaD;

typedef struct nodoS
{
    float prom;
    int cantFueraDeRango;
    struct nodoS *sig;
} nodoS;

typedef nodoS *TListaS;