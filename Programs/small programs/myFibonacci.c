#include <stdio.h>
long long int cb1 = 0;
long long int cb2 = 1;
long long int fibonacciSum = 0;
/*
 * Escribe un programa que imprima los 50 primeros números de la sucesión
 * de Fibonacci empezando en 0.
 * - La serie Fibonacci se compone por una sucesión de números en
 *   la que el siguiente siempre es la suma de los dos anteriores.
 *   0, 1, 1, 2, 3, 5, 8, 13...
*/

long long int fibonacci() {
    cb1 = cb2;          // 1, 0, 1
    cb2 = fibonacciSum; //0, 1, 1
    fibonacciSum = cb1 + cb2; // =1, 1,bla bla
    return fibonacciSum; // = 1, 1, 2
}

int main() {
    for (int i = 0; i <= 50; i++) {
        printf("%d\n", fibonacci());
    }
    return 0;
}