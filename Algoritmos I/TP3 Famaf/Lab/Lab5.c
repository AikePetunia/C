#include <stdio.h>

int main() {

int x, y;

//a, b, c (ingrese los valores de cada punto.)
    printf("ingrese el valor de x: ");
    scanf("%d", &x);
    printf("ingrese el valor de y: ");
    scanf("%d", &y);

    if (x >= y) {
        x = 0;
    } else if (x <= y) {
        x = 2;
    } 
    printf("x: %d\n", x);

    //Chekieado

    return 0;
}