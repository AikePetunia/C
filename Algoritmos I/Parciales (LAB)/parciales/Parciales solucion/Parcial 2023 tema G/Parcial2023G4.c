#include <stdio.h>
#include <assert.h>
int pedirEntero (void) {
    int x;
    scanf("%d", &x);
    return x;
}

int imprimir_entero(int x, int y, int z){

    printf("los valores son %d %d %d ", x, y, z);
}


int main ( void ){
    int x, y, z, X, Y, Z;
    printf("Ingrese un entero x:");
    x = pedirEntero();

    printf("Ingrese un entero y:");
    y = pedirEntero();

    printf("Ingrese un entero z:");
    z = pedirEntero();

    X = x;
    Y = y;
    Z = z;

    //precondición
    assert(x == X);
    assert(y == Y);
    assert(z == Z);
    assert(x > 0);

    if (x < y) {
        x = Z;
        y = X + 2 * y + 3 * z;
        z = X * Y;
    } else if (x >= y) {
        x = x + 1;
        y = 1 / X;
        z = Y / X;
    }

    assert(X < Y && (x==Z && y==X+2*Y+3*Z && z==X*Y) || (X>=Y && x==X+1 && y==1/X && z==Y/X));
    imprimir_entero(x,y,z);
    return 0;
}