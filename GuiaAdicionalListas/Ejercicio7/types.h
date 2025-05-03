
typedef struct
{
    char nombre[50];
    unsigned int edad;
    char estaActivo;
} Jugador;

typedef struct nodito
{
    Jugador dato;
    struct nodito *sig;
} nodito;

typedef nodito *subLista;

typedef struct
{
    char nombre[50];
    unsigned int puntaje;
} Equipo;

typedef struct nodo
{
    Equipo dato;
    struct nodo *sig;
    subLista sub;
} nodo;

typedef nodo *TLista;

typedef struct nodoD
{
    char nombre[50];
    unsigned int cantJugadores;
    float edadProm;
    struct nodoD *sig;
    struct nodoD *ant;
} nodoD;

typedef struct
{
    nodoD *pri;
    nodoD *ult;
} TListaD;