#include <stdio.h>  
#include <assert.h>

int pedirEntero(void) {
    int x;
    scanf("%d", &x);
    return x;
}

void imprimirEntero(int x, int y, int z) {
    printf("Los valores son x %d, y %d, z %d", x, y, z);
}
int main (void) {
    int x, y, z, X, Y, Z;
    printf("Ingrese un numero entero para x");
    x = pedirEntero();
    printf("Ingrese un numero entero para y");
    y = pedirEntero();
    printf("Ingrese un numero entero para z");
    z = pedirEntero();
    
    X = x; 
    Y = y;
    Z = z;
    //Precondicion
    assert(x == X && y == Y && z == Z && x != y);

    x = y;
    y = X;
    z = X - Y;
    
    //post condicion
    assert(x == Y);
    assert(y == X);
    assert(z != 0);

    imprimirEntero(x,y,z);

    return 0;
}