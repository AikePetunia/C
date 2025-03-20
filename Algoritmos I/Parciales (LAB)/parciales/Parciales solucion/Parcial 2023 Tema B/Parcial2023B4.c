#include <stdio.h>
#include <stdbool.h>

struct triangulo {
    int l1;
    int l2;
    int l3;
};

struct caract_triangulo {
    bool es_equilatero;
    int perimetro;
};

struct caract_triangulo averiguar_caract(struct triangulo lado) {
    struct caract_triangulo respuesta;
    respuesta.es_equilatero = false;
    respuesta.perimetro = 0;

    if (lado.l1 == lado.l2 && lado.l2 == lado.l3) {
        respuesta.es_equilatero = true;
        respuesta.perimetro =  lado.l1 + lado.l2 + lado.l3;
    }   
    return respuesta;
};

int main (void) {
    struct triangulo respuesta;

    printf("Ingrese el l1");
    scanf("%d", &respuesta.l1);
    printf("Ingrese el l2");
    scanf("%d", &respuesta.l2);
    printf("Ingrese el l3");
    scanf("%d", &respuesta.l3);

    struct caract_triangulo resultado = averiguar_caract(respuesta);

    if (resultado.es_equilatero == true) {
        printf("Es equilatero y el perimetro es %d", resultado.perimetro);
    }   else {
        printf("no es equilatero y no se si deberia de ponerte el perimetro acá");
    }
    return 0;
}