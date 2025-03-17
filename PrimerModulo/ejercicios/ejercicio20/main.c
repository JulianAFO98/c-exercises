/*
. Realizar un programa iterativo que calcule e imprima el equivalente binario de un número
entero positivo dado.

*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE 32
void convertirABinario(int [],unsigned int *,unsigned int);
void mostrarNumeroBinario(int [],unsigned int);

int main()
{
    int binario[SIZE];
    unsigned int x,bits;
    printf("Ingrese un valor positivo para convertir a binario\n");
    scanf("%u",&x);
    convertirABinario(binario,&bits,x);
    mostrarNumeroBinario(binario,bits);

    return 0;
}



void convertirABinario(int v[],unsigned int *pbits, unsigned int x){

  unsigned int resto,cociente,dividendo = x;
  *pbits=0;

  do{
     cociente=dividendo / 2;
     resto = dividendo % 2;
     v[*pbits]=resto;
     *pbits=*pbits+1;
     dividendo = cociente;
  }while  (dividendo > 0);

}



void mostrarNumeroBinario(int v[],unsigned int n){
   for (int i = n-1;i>=0;i--) {
      printf("%d",v[i]);
   }
}
