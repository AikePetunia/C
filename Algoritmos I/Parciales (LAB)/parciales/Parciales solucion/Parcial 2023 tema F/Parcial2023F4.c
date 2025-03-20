#include <stdio.h>
#include <stdbool.h>
#define N 5

struct rango {
    float cota_inf;
    float cota_sup;
};

struct rango_info {
    bool es_anterior;
    bool es_posterior;
    bool esta_dentro;
};

struct rango_info verificar_rango(float x, struct rango r) {
    struct rango_info res;
    res.es_anterior = false;
    res.es_posterior = false;
    res.esta_dentro = true;

    if (x < r.cota_inf) {
        res.es_anterior = true;
    }
    if(x > r.cota_sup) {
        res.es_posterior = true;
    }
    if(x >= r.cota_inf && x < r.cota_sup) {
        res.esta_dentro = true;
    }
    return res;
    
}

int main (void) {
    struct rango cotas;
    float x;

    printf("Ingrese una cota inf ");
    scanf("%f", &cotas.cota_inf);    
    printf("Ingrese una cota sup ");
    scanf("%f", &cotas.cota_sup);   

    printf("Ingrese un float x: ");
    scanf("%f", &x);

    struct rango_info res = verificar_rango(x, cotas);
    if (res.es_anterior == true) {
        printf("es anterior\n");
    } else {
        printf("no es anterior\n");
    }

    if (res.es_posterior == true) {
        printf("es posterior\n");
    } else {
        printf("no es posterior\n");
    }

    if (res.esta_dentro == true) {
        printf("esta dentro\n");
    } else {
        printf("no esta dentro\n");
    }
    return 0;
}