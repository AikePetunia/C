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
    assert(Y > X);
    assert(X > 0);

    if (x < y) {
        x = y;
        y = z+y+X;
        z = X;
    } else if (x >= y) {
        x = y;
        y = z + y;
        z = x / y;
    }

    assert(X < Y && (x==Y && y==Z+Y+X && z==X) || (X>=Y && (x==Y && y==Z+Y && z==X/Y)));
    
    imprimir_entero(x,y,z);
    return 0;
}