typedef struct nodoPasaje
{
    char DNI[10];
    struct nodoPasaje *sig;
} nodoPasaje;

typedef nodoPasaje *subListaPasaje;

typedef struct nodoViaje
{
    char codigoVuelo[10];
    char fechaHoraSalida[25];
    unsigned int capPasajeros;
    subListaPasaje pasajeros;
    struct nodoViaje *sig;
} nodoViaje;

typedef nodoViaje *subListaViajes;

typedef struct nodo
{
    char destino[100];
    subListaViajes viajes;
    struct nodo *sig;
} nodo;

typedef nodo *TLista;