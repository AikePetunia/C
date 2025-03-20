#include <stdio.h>
#include <stdbool.h>

int main () {

    int x, y, z; 
    int resultado1, resultado2, resultado3, resultado4;
    bool resultado5 = false;

    printf("ingrese el valor de x: ");
    scanf("%d", &x);
    printf("ingrese el valor de y: ");
    scanf("%d", &y);
    printf("ingrese el valor de z: ");
    scanf("%d", &z);

    resultado1 = x + y + z;
    resultado2 = z * z + y * 45 - 15 * x;
    resultado3 = y - 2 == (x * 3 + 1) % 5;
    resultado4 = y / 2 * x;
    resultado5 = y < x * z;

    printf("El resultado1: %d\n", resultado1 );
    printf("El resultado2: %d\n", resultado2 );
    printf("El resultado3: %d\n", resultado3 );
    printf("El resultado4: %d\n", resultado4 );
    printf("El resultado5: %d\n", resultado5 );

//Chekiado

    return 0;
}