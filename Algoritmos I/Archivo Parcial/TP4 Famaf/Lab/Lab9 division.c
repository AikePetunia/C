#include <stdio.h>
#include <assert.h>
struct div_t {
    int cociente;
    int resto;
};

struct div_t division(int x, int y) { //numerador, divisor
    struct div_t res;  
    res.cociente = x / y; 
    res.resto = x % y;     
    return res;        //el res actua como una variable extra para poder asignas valor a un valor del struct)?
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
    printf("Quedando el algoritmo de division como: %d = %d * %d + %d\n", numerador, divisor, res.cociente, res.resto);

 //defino una variable nueva que es res del tipo struct div_t que actua como:
    /*
    struct div_t res; //Crear la variable 
    res.cociente = x / y; // Asignación a res
    res.resto = x % y;    // Asignación a res
    return res;   //Devolución de res
    */

    return 0;
}

// El algoritmo de divison es:
// a = b * q + r
// donde a es el dividendo, b es el divisor, q es el cociente y r es el resto.

//deberia de poner floats?