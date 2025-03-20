#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
    int x;
    scanf("%d", &x);
    return x;
}

int imprimirEntero(int x, int y, int z) {

    printf("El valor de x es %d : ", x);
    printf("El valor de y es %d : ", y);
    printf("El valor de z es %d : ", z);
    return x, y, z;
}
int main (void) {
    int x, y, z, X, Y, Z;
    
    printf("Ingrese un valor para x:");
    x = pedirEntero();

    printf("Ingrese un valor para y:");
    y = pedirEntero();

    printf("Ingrese un valor para z:");
    z = pedirEntero();

    X = x;
    Y = y;
    Z = z;

    assert(x == X);
    assert(y == Y);
    assert(z == Z);
    assert(Y > X);
    assert(X > 0);

    if (x <= y) {
        x = y*z;
        y = z+y+X;
        z = X+Y;
    } else if ( x > y) {
        x = Y;
        y = Z;
        z = X;
    }

    assert((X <= Y && x == Y * Z && y == Z + Y + X && z == X + Y) ||
           (X > Y && x == Y && y == Z && z == X));

    imprimirEntero(x,y,z);
    return 0;
}