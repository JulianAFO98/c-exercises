
#define MAX 256

typedef struct {
    char car;
 } TEC; //tipo elemento cola


typedef struct {
    TEC datos[MAX];
    int pri,ult;
} TC; //tipo cola





void poneC(TC *C , TEC e);
void sacaC(TC *C , TEC * e);
TEC consultaC(TC C);
int vaciaC(TC C);
void iniciaC(TC * C);