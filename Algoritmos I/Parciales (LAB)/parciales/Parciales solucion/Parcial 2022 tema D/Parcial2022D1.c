#include <stdio.h>
#include <assert.h>

int pedirEntero(int x, int y, int z) {
    printf("Ingrese un numero para x: ");
    scanf("%d", &x);
    printf("Ingrese un numero para y: ");
    scanf("%d", &y);
    printf("Ingrese un numero para z: ");
    scanf("%d", &z);
    return x, y, z;
}

int imprimeEntero(int x, int y, int z) {
    printf("El valor de x es: %d", x);
    printf("El valor de y es: %d", y);
    printf("El valor de z es: %d", z);

}

int main (void) {
    int x, y, z;
    int X, Y, Z;
    pedirEntero(x, y, z);

    x = X;
    y = Y;
    z = Z;
    //Pre
    assert(x == X);
    assert(y == Y);
    assert(z == Z);
    assert(y != 0);
    assert(z > 0);

    //Guardo los valroes originales
    //cuerpo { S }
    x = y * z;
    y = X % z;
    z = X / Y;

    //pos

    assert(x == (Y * Z));
    assert(y == (X % z));
    assert(z == (X / Y));

    imprimeEntero(x, y, z);
    return 0;
}