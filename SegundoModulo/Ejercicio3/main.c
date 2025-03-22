/*Implementar un programa que cree dinámicamente 3 variables enteras, muestre su suma y su
producto. Asegurarse de administrar correctamente la memoria e implementar una función
para evitar duplicaciones de código en la creación y lectura de cada variable. */

#include <stdio.h>
#include <stdlib.h>

void llenarValor(int **);

int main()
{
    int *pint1,*pint2,*pint3,result; // DEBO INGRESARLES DIRECCIONES DE MEMORIA


    llenarValor(&pint1); // SE LO PASO CON & => LE PASO LA DIRECCION DE MEMORIA DEL PUNTERO
    llenarValor(&pint2);
    llenarValor(&pint3);
    printf("%d",*pint1);
    printf("%d",*pint2);
    printf("%d",*pint3);

    result = *pint1+*pint2+*pint3;
    printf("La suma da %d\n",result);
    result = (*pint1)*(*pint2)*(*pint3);
    printf("La mult da %d\n",result);
    free(pint1);
    free(pint2);
    free(pint3);

    return 0;
}

void llenarValor(int **p){
  *p = (int *) malloc(sizeof(int));
  scanf("%d",*p);
}
