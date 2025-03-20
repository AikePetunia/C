#include <stdio.h>
#include <stdbool.h>
#define N 5

struct triangulo {
    int l1;
    int l2;
    int l3;
};

struct tipo_triangulo {
    bool es_equilatero;
    bool es_isosceles;
    bool es_escaleno;
};

struct tipo_triangulo verificar_triangulo(struct triangulo lado) {
    struct tipo_triangulo res; 
    res.es_equilatero = false;
    res.es_isosceles = false;
    res.es_escaleno = false;

    if (lado.l1 == lado.l2 && lado.l2 == lado.l3) {
        res.es_equilatero = true;
    } 
    if (lado.l1 == lado.l2 && lado.l2 != lado.l3|| lado.l2 == lado.l3 && lado.l2 != lado.l1|| lado.l1 == lado.l3 && lado.l1 != lado.l2) {
        res.es_isosceles = true;
    }
    if (lado.l1 != lado.l2 && lado.l2 != lado.l3 && lado.l1 != lado.l3) {
        res.es_escaleno = true;
    }
    return res;
}

int main (void) {
    struct triangulo lado;
    printf("Ingrese el lado 1: ");
    scanf("%d", &lado.l1);
    printf("Ingrese el lado 2: ");
    scanf("%d", &lado.l2);
    printf("Ingrese el lado 3: ");
    scanf("%d", &lado.l3);

    struct tipo_triangulo res = verificar_triangulo(lado);

    if (res.es_equilatero == true) {
        printf("es esquilatero");
    }   else if (res.es_escaleno == true) {
        printf("es escaleno");
    }   else if (res.es_isosceles == true) {
        printf("es isosceles");
    }  
    return 0;
}

