#include <stdio.h>
#include <assert.h>

int main() {
    int x, y, min;

    printf("Introduce el valor de x: ");
    scanf("%d", &x);
    printf("Introduce el valor de y: ");
    scanf("%d", &y);

    if (x < y) {
        min = x;
    } else {
        min = y;
    }

    // verificar que min es el mínimo de x e y
    assert((min <= x && min <= y) && (min == x || min == y));

    printf("El mínimo entre %d y %d es: %d\n", x, y, min);
    return 0;
}
