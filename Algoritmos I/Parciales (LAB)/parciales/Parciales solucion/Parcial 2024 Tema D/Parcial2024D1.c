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
    assert(x == X && y == Y && z == Z && Y > 0 );
    
    //cuerpo
    x = y;
    y = X+y-z;
    z = X*(1 + Y*Y);

    //pos
    assert(x == Y && y == X+Y-Z && z == X*(1 + Y * Y)); //acá la potencia es con math.h?? wtf
    
    printf("Los valores finales son x %d, Y %d, y z %d", x, y, z);
    return 0;
}