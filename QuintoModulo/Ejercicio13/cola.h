/*Desarrollar la implementación del TDA cola estática circular. */
#define MAX 255
typedef int TEC;

typedef struct
{
    TEC v[MAX];
    unsigned int pri, ult;
} Cola;

void poneC(Cola *c, TEC e);
void sacaC(Cola *c, TEC *e);
TEC consultaC(Cola c);
int vaciaC(Cola c);
void iniciaC(Cola *c);
