#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
int main (void) {
    bool x, y;
    bool X, Y;
    
    printf("Ingrese un valor bool de x (1 o 0): \n");
    scanf("%d", &x);
    printf("Ingrese un valor bool de y (1 o 0): \n");
    scanf("%d", &y);

    X = x;
    Y = y;
    assert(x == X && y == Y);

    x = Y;
    y = X;

    assert(x == Y && y == X);

    printf("los valores finales son, x: %d y: %d", x, y);
    return 0;
}