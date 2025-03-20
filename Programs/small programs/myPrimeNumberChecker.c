#include <stdio.h>
#include <math.h>

/*
 * Escribe un programa que se encargue de comprobar si un número es o no primo.
 * Hecho esto, imprime los números primos entre 1 y 100.
 */

int main() {
        for (int n = 1; n <= 100; n++) {
        if (n <= 1) {
            printf("%d no es primo\n", n);  // special case
        } else if (n <= 3) {
            printf("%d es primo\n", n);  // special case
        } else if (n % 2 == 0 || n % 3 == 0) {
            printf("%d no es primo\n", n);  // special case
        } else {
            //Raiz criteria (discreth maths thanks god)
            int raizCriteria = sqrt(n);
            int esPrimo = 1;  
            for (int i = 5; i <= raizCriteria; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0) {
                    esPrimo = 0;  
                    break;
                }
            }
            if (esPrimo) {
                printf("%d es primo\n", n);
            } else {
                printf("%d no es primo\n", n);
            }
        }
    }
    
    return 0;
}