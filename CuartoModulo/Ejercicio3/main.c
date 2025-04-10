/*
Desarrollar una agenda de contactos mediante un TDA. Para cada contacto se almacena
nombre y tel�fono. Los contactos deben estar ordenados alfab�ticamente. El TDA debe contar
con los siguientes operadores: iniciar agenda, agregar contacto, listar agenda, buscar por
nombre (b�squeda lineal).
Se solicitan dos implementaciones diferentes: una con arreglos paralelos y otra con arreglo de
registros.
Mejorar el operador buscar por nombre, recodific�ndolo como b�squeda binaria.

*/





#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main() {
    agendaContactos agenda = iniciarAgenda();
    agregarContacto(&agenda);
    agregarContacto(&agenda);
    listarAgenda(agenda);

    int pos =buscarPorNombre(agenda,"Julian");
    if(pos!=-1) {
        printf("Julian esta en pos %d",pos);
    } else {
        printf("Julian no esta");
    }
    return 0;
}
