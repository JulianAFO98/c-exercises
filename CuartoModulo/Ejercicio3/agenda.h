

//Version con paralelos
/*
typedef char tipoVecNombre[100];
typedef char tipoVecCel[100];


typedef struct {
    tipoVecNombre nombres[100];
    tipoVecCel celulares[100];
    int cantNums;
} agendaContactos;

agendaContactos iniciarAgenda();
void agregarContacto(agendaContactos * agenda);
void listarAgenda(agendaContactos agenda);
int buscarPorNombre(agendaContactos agenda,tipoVecNombre nombre);
*/
//Version con registro

typedef struct {
   char nombre[100];
   char numero[100];
} Contacto;


typedef struct {
    Contacto contactos[100];
    int cantNums;
} agendaContactos;

agendaContactos iniciarAgenda();
void agregarContacto(agendaContactos * agenda);

