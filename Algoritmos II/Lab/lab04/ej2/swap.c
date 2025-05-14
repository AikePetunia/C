#include <stdio.h>

// los out en c son punteros
void swap(int *a, int *b) {
    int aux;
    aux = *a; // guardar a
    *a = *b; // asignar a b
    *b = aux; // asignar b a a
}

int main(void) {
    int x, y;
    x = 6;
    y = 4;
    printf("x:%d, y:%d \n", x, y);
    swap(&x, &y);
    printf("x:%d, y:%d \n", x, y);
    return 0;
}