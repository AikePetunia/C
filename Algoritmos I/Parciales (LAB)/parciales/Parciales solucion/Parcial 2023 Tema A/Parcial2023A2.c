#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
    int x;
    scanf("%d", &x);
    return x;
}

int imprimirEntero(int x, int y, int z) {

    printf("El valor de x es: %d \n", x);
    printf("El valor de y es: %d\n", y);
    printf("El valor de z es: %d", z);

}
int main (void) {
    int x, y, z, X, Z, Y;

    printf("Ingrese un entero para x");
    x = pedirEntero();
    printf("Ingrese un entero para y");
    y = pedirEntero();
    printf("Ingrese un entero para z");
    z = pedirEntero();

    X = x;
    Y = y;
    Z = z;

    assert(x == X); 
    assert(y == Y); 
    assert(z == Z); 
    assert(Y > X); 
    assert(X > 0);

    if (x < y) {
        x = y;
        y = z+y+X;
        z = 2*X;
    }   else if (x >= y) {
        x = y;
        y = z+2*Y;
        z = Y / X;
    }

    assert(X<Y);
    assert((x==Y && y==Z+Y+X && z==2*X) || (X>=Y && (x==Y && y==Z+2*Y && z==Y/X))); 
    imprimirEntero(x,y,z);
}

/*
Ingrese un entero para x1
Ingrese un entero para y2
Ingrese un entero para z2
El valor de x es: 2 
El valor de y es: 5
El valor de z es: 2[1] + Done 
*/