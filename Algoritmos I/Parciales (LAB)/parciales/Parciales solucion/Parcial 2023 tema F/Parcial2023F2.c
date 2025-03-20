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

int main (void){
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
    assert(Z % 2 != Y % 2);

    if (x % 2 == 0) {
        x = y * x;
        y = y + X + z + 1;
        z = 2*z;
    } else if (x % y != 0) {
        x = 2*y + x + 1;
        y = y + X + z;
        z = 2*z;
    }

    assert((x+y+z) % 2 == 0 && z==2*Z && ((x==Y*X && y==Y+X+Z+1)) || (x==2*Y+X+1 && y==Y+X+Z));
    
    imprimir_entero(x,y,z);
    return 0;
}