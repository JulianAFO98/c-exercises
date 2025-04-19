#define MAX 255

typedef struct
{
    char nombre[30];
    char apellido[30];
} MaratonistaC;

typedef struct
{
    MaratonistaC v[MAX];
    unsigned int pri, ult;
} Cola;

void poneC(Cola *c, MaratonistaC m);
void sacaC(Cola *c, MaratonistaC *m);
MaratonistaC consultaC(Cola c);
int vaciaC(Cola c);
void iniciaC(Cola *c);
