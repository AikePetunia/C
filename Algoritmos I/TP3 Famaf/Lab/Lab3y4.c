#include <stdio.h>

int main() {
    //a
    int x, y;

    printf("ingrese el valor de x: ");
    scanf("%d", &x);
    printf("ingrese el valor de y: ");
    scanf("%d", &y);

    x = 5;
    printf ("%d \n", x);

    //b
    x = y + x;
    y = y + y; 

    printf("%d \n", y); 

    //c 
    y = y + y; 
    printf("%d \n", y); 
    x = x + y;
    printf ("%d \n", x);

    //d 

    //Implementacion en C:

    y, x = y + y, x + y;

    printf ("%d \n %d \n", x, y);

    //comentar el que no se usara. no quiero llenar esa tabla :)+

    //chekiado
    
    return 0;
}