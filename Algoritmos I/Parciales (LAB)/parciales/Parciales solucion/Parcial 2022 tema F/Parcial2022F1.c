#include <stdio.h>
#include <stdbool.h>

int pedirEntero(char var) {
    int value;
    printf("Ingrese un entero para %c: \n", var);
    scanf("%d", &value);
    assert(value != 0);
    return value;
}


bool pedirBooleano() {
    int z;
    printf("Ingrese un valor booleano para z (1 o 0): \n");
    scanf("%d", &z);
    return z; 
}

void imprimirEntero(int x, int y) {
    printf("El valor de x final es: %d\n", x);
    printf("El valor de y final es: %d\n", y);
}

void imprimirBooleano(bool z) {
    printf("El valor de z final es: %d\n", z);
}

int main (void) {
    int x = pedirEntero('x');
    int y = pedirEntero('y');
    bool z = pedirBooleano();

    int xaux, yaux;
    bool zaux;
    int X = x, Y = y, Z = z;

    pedirEntero(x);
    pedirEntero(y);

    assert( X = x, Y = y, z = Z, y != 0); //pre

    x = xaux;
    y = yaux;
    z = zaux;

    xaux = x * x + y * y;
    yaux = x % y;
    zaux = x < y;

    assert(x == (X*X + Y*Y));   //post
    assert(y == (X % Y));   //post
    assert(z == (X < y));   //post
    return 0;
}