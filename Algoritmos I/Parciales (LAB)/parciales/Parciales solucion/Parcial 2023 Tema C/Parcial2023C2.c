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
    assert(Z % 2 != Y % 2);

    if (x % 2 == 0) {
        x = X+1;
        y = z+y+y;
        z = 2*X;
    } else {
        x = X - 1;
        y = y - z - y;
        z = 2*X;
    }

    assert(2==2*X && (x == X + 1 && y==Y+Z+Y) ||
           (x==X-1 && y==Y-Z-Y));

    imprimirEntero(x,y,z);
    return 0;
}