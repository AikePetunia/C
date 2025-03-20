#include <stdio.h>

typedef enum { //enumero los poligonos
    TRIANGULO,
    CUADRADO,
    RECTANGULO,
} Poligonos;

/*
    triangulo: (base * altura) / 2
    cuadrado: base * base
    rectangulo: base * altura
    necesito, base y altura.
*/

typedef struct { //colecciono las variables a usar
    Poligonos tipo;
    int altura;
    int base;
} Poligonos;

double calcArea(Poligonos p) {
    //calc Area
    switch (p.tipo)
    {
    case TRIANGULO:
        return (p.base * p.altura) / 2; //por que uso la var altrua y base de p, definida como p.algo
        break;
    case CUADRADO:
        return (p.base * p.altura) / 2; 
        break;
    case RECTANGULO:
        return (p.base * p.altura) / 2; 
        break;
    default:
        printf("De una forma poligona!");
        break;
    }
} 

int main() {
    Poligonos triangulo = {TRIANGULO, 5.0, 3.0};
    Poligonos cuadrado = {CUADRADO, 4.0, 4.0};
    Poligonos rectangulo = {RECTANGULO, 6.0, 2.0};

    printf("area del triángulo: %.2f\n", calcularArea(triangulo));
    printf("area del cuadrado: %.2f\n", calcularArea(cuadrado));
    printf("area del rectángulo: %.2f\n", calcularArea(rectangulo));
    return 0;
}