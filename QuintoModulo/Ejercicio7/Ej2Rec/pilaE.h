#define SIZE 100

typedef struct
{
    char texto[SIZE];
    int tope;
} TipoP;

void sacaP(TipoP *P, char *c);
void poneP(TipoP *P, char c);
void iniciaP(TipoP *P);
char consultaP(TipoP P);
int vaciaP(TipoP P);
