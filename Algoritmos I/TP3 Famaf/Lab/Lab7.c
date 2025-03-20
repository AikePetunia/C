#include <stdio.h>

int main() {
    int i, j, x;
    printf("Ingrese un valor para i, debe ser mayor a 0: "); 
    scanf("%d", &i); 
    printf("Ingrese un valor para j, debe ser mayor a 0: ");
    scanf("%d", &j);
    printf("Ingrese un valor para x, debe ser mayor a 0: ");
    scanf("%d", &x);

    do {
        i = i - 1;
    } while (i != 0); 
    printf("El valor de i es: %d\n", i);

    do {
        j = j - 1;
    } while (j != 0);
    printf("El valor de j es: %d\n", j);

    do {
        x = x - 1;
    } while (x > 0);
    printf("El valor de x es: %d\n", x);
    return 0;

    //chekiado
}