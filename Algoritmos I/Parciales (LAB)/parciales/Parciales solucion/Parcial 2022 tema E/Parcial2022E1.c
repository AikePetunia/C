#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int pedirEntero(char var) {
    int value;
    printf("Ingrese un valor entero para %c: \n", var);
    scanf("%d", &value);
    assert(value > 0); //llamo uno a la vez, por q puede devolver uno a la vez ?
    return value;
}

bool pedirBooleano() {
    int z;
    printf("Ingrese un valor booleano para z (1 o 0): \n");
    scanf("%d", &z);
    return z; 
}

void imprimirEntero(int x, int y) {
    printf("El valor de x final es: %d\n", x);
    printf("El valor de y final es: %d\n", y);
}

void imprimirBooleano(bool z) {
    printf("El valor de z final es: %d\n", z);
}

int main(void) {
    int x = pedirEntero('x');
    int y = pedirEntero('y');
    bool z = pedirBooleano();

    int X = x, Y = y, Z = z;

    //cuerpo
    int xaux = x * x + y * y;
    int yaux = x + y;
    bool zaux = x > y;

    //Post condicion
    assert(x == X * X + Y * Y);
    assert(y == X + Y);
    assert(z == (X > Y));

    imprimirEntero(x, y);
    imprimirBooleano(z); //independientemente de q ponga, dependera del assert

    return 0;
}
