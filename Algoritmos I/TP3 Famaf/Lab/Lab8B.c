#include <stdio.h>
#include <stdbool.h>

int main() {
    int x = 5;
    int i = 2; 
    bool res = true;  // Inicializamos como true, asumiendo que x es primo

    do {
        if (x % i == 0) {
            res = false;  // Si x es divisible por i, no es primo
        }
        i = i + 1;
    } while (i < x && res == true);
    
    
    printf("El resultado de la division entera es \ni = %d\nx = %d\nres = %d\n", i, x, res);
    return 0;
}

//Chekiado.
// si res = 1, es true, caso contrario es false.
