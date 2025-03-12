//Reescribir las siguientes sentencias utilizando la instrucción switch:
#include <stdio.h>

int main() {
    int x=3,y=0;
    /*
     If (x == 4)
         y = 7;
     else if (x == 5)
         y = 9;
     else if(x == 9)
         y = 14;
     else
         y = 22;
     */

    switch(x) {
    case 3:
        y=7;
        break;
    case 5:
        y=9;
        break;
    case 9:
        y=14;
        break;
    default:
        y=22;
    }

    printf("%d",y);
}
