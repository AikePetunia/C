#include <stdio.h>
#include <stdbool.h>
struct cuadrilatero {
    int l1;
    int l2;
    int l3;
    int l4;
};

struct tipo_cuadrilatero {
    bool es_cuadrado;
    bool es_rectangulo;
    bool es_trapecio;
    bool ninguno_anteriores;
};

struct tipo_cuadrilatero verificar_cuadrilatero(struct cuadrilatero lado) { //en vez de t, pongo lado para  no tener problemas al pasar los coso
    struct tipo_cuadrilatero cualcuadrilatero;
    cualcuadrilatero.es_cuadrado = false;
    cualcuadrilatero.es_rectangulo = false;
    cualcuadrilatero.es_trapecio = false;
    cualcuadrilatero.ninguno_anteriores = false;
    if ( lado.l1 == lado.l2 == lado.l3 == lado.l4) {
        cualcuadrilatero.es_cuadrado = true;
    }   else if ((lado.l1 == lado.l3) && (lado.l2 == lado.l4)) {// && lado.l2 != lado.l1 && lado.l2 != lado.l3 && lado.l4 != lado.l1 && lado.l4 != lado.l3 
        cualcuadrilatero.es_rectangulo = true;
    }   else if (lado.l1 == lado.l3 && lado.l2 != lado.l4) {
        cualcuadrilatero.es_trapecio = true;
    }   else {
        cualcuadrilatero.ninguno_anteriores = true;
    }
    return cualcuadrilatero;
};

int main (void) {
    struct cuadrilatero lado;
    printf("Ingrese el lado 1");
    scanf("%d", &lado.l1);
    printf("Ingrese el lado 2");
    scanf("%d", &lado.l2);
    printf("Ingrese el lado 3");
    scanf("%d", &lado.l3);
    printf("Ingrese el lado 4");
    scanf("%d", &lado.l4);

    struct tipo_cuadrilatero respuesta = verificar_cuadrilatero(lado);

    if (respuesta.es_cuadrado == true) {
        printf("Es cuadrado");
    }   else if (respuesta.es_rectangulo == true) {
        printf("Es rectangulo");
    }   else if (respuesta.es_trapecio == true) {
        printf("Es trapecio");
    }   else {
        printf("no es ninguno ");
    }
    return 0;
}