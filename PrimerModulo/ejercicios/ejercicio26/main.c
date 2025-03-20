/*
Declarar un tipo struct para almacenar nombre, matrícula y promedio de un alumno.
Desarrollar una función que realice lectura de una variable del tipo creado.

*/




#include <stdio.h>
#include <stdlib.h>
typedef struct {
  char nombre[60];
  char matricula[20];
  float promedio;
} TAlumno;

void leerAlumno(TAlumno *);
void mostrarAlumno(TAlumno *);

int main()
{
    TAlumno alumno;
    leerAlumno(&alumno);
    mostrarAlumno(&alumno);
    return 0;
}


void leerAlumno(TAlumno *pAlumno){
    printf("Ingrese su nombre\n");
    gets((*pAlumno).nombre);
    printf("Ingrese su matricula\n");    gets((*pAlumno).matricula);
    printf("Ingrese su promedio\n");
    scanf("%.2f",&(*pAlumno).promedio);
}


void mostrarAlumno(TAlumno *pAlumno){
    printf("Su nombre\n");
    puts((*pAlumno).nombre);
    printf("Su matricula\n");
    puts((*pAlumno).matricula);
    printf("Su promedio\n");
    printf("%.2f",(*pAlumno).promedio);
}
