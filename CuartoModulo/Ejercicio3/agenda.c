

#include "agenda.h"
#include <string.h>
//Version con registros



agendaContactos iniciarAgenda() {
    agendaContactos agenda;
    agenda.cantNums=0;
    return agenda;
}

void agregarContacto(agendaContactos * agenda) {
    Contacto contacto;

    printf("Ingrese nombre\n");
    gets(contacto.nombre);
    printf("Ingrese celular\n");
    gets(contacto.numero);

    int j = (*agenda).cantNums-1; // flecha? ->

    // hacer funcion aparte
    while (j>=0 && strcmp(contacto.nombre,(*agenda).contactos[j].nombre)<0) {
        (*agenda).contactos[j+1]=(*agenda).contactos[j];
        j--;
    }
    (*agenda).contactos[j+1]=contacto;
    (*agenda).cantNums++;

}

void listarAgenda(agendaContactos agenda) {
    for(int i = 0; i<agenda.cantNums; i++) {
        printf("Nombre:%s Numero:%s\n",agenda.contactos[i].nombre,agenda.contactos[i].numero);
    }
}

int buscarPorNombre(agendaContactos agenda,int nombre[]){
   int i=0;
   while(i<agenda.cantNums && strcmp(agenda.contactos[i].nombre,nombre)!=0)
    i++;
   return i<agenda.cantNums ? i : -1;
}
//Version con paralelos

/*agendaContactos iniciarAgenda() {
    agendaContactos agenda;
    agenda.cantNums=0;
    return agenda;
}

void agregarContacto(agendaContactos * agenda) {
    char nombre[100];
    char celular[100];


    printf("Ingrese nombre\n");
    gets(nombre);
    printf("Ingrese celular\n");
    gets(celular);


    int j = (*agenda).cantNums-1; // flecha? ->

    // hacer funcion aparte
    while (j>=0 && strcmp(nombre,(*agenda).nombres[j])<0) {
        strcpy((*agenda).celulares[j+1],(*agenda).celulares[j]);
        strcpy((*agenda).nombres[j+1],(*agenda).nombres[j]);
        j--;
    }
    strcpy((*agenda).celulares[j+1],celular);
    strcpy((*agenda).nombres[j+1],nombre);
    (*agenda).cantNums++;

}


void listarAgenda(agendaContactos agenda) {
    for(int i = 0; i<agenda.cantNums; i++) {
        printf("Nombre:%s Numero:%s\n",agenda.nombres[i],agenda.celulares[i]);
    }
}


int buscarPorNombre(agendaContactos agenda,tipoVecNombre nombre){
   int i=0;
   while(i<agenda.cantNums && strcmp(agenda.nombres[i],nombre)!=0)
    i++;
   return i<agenda.cantNums ? i : -1;


}
*/
