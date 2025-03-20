#include <assert.h> //aca debo usar para la precondicion
#include <stdio.h>

struct div_t {
    int cociente;
    int resto;
};

struct div_t division(int numerador, int divisor){
    struct div_t res;
    res.resto = numerador % divisor;
    res.cociente = numerador / divisor;
    return res;
}

int main (void) {
    int numerador;
    int divisor;

    printf("Ingrese un numerador: ");
    scanf("%d", &numerador);

    printf("Ingrese un divisor: ");
    scanf("%d", &divisor);
    assert(divisor != 0);

    struct div_t res = division(numerador, divisor);

    printf("El numerador ingresado es: %d \n", numerador);
    printf("El divisor ingresado es: %d \n", divisor);
    printf("El resto ingresado es: %d \n", res.resto);
    printf("El cociente ingresado es: %d \n", res.cociente);

    return 0;
}