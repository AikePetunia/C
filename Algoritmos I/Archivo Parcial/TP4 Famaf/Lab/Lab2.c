#include <stdio.h>

int main () {
    //Asignaciones múltiples
    int x, y, z, xaux;
    x = 5;
    y = 8;
    z = 3;
    
    
    int xaux = x;
    int yaux = y;
    int zaux = z;
    

    x = x + 1;
    y = x + y;

    
    //Asignaciones simples
    x = y;
    y = yaux + xaux + zaux;
    z = yaux + xaux;
    
    printf("los valores son de x %d de y %d  de z %d \n", x, y, z);

    return 0;
}

//Las variables auxiliares son útiles en el caso de asignaciones 
//múltiples para preservar los valores originales de las variables antes de que sean modificadas.