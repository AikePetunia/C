#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
    int x;
    scanf("%d", &x);
    return x;
}

int main (void) {
    int x,y,z,X,Y,Z;

    printf("Ingrese el valor de x:");
    x = pedirEntero();

    printf("Ingrese el valor de z:");
    z = pedirEntero();

    printf("Ingrese el valor de y:");
    y = pedirEntero();

    X = x;
    Y = y;
    Z = z;

    //pre
    assert(x == X && y == Y && z == Z && X > 0 && Y > 0 && Z > 0);
    
    //cuerpo
    x = y + z;
    y = z * X;
    z = X / Y;

    //pos
    assert(x == Y + Z && y == Z * X && z == X / Y);
    
    printf("Los valores finales son x %d, Y %d, y z %d", x, y, z);
    return 0;
}