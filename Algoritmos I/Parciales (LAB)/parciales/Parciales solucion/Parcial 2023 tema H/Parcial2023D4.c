#include <stdio.h>
#include <stdbool.h>
#define N 5

struct coordenada {
    float ordenada;
    float abscisa;
    float error;
};

struct coordenadas_superpuestas {
    bool coincide;
    bool contiene;
    bool es_contenida;
};

struct coordenadas_superpuestas verificar_superposicion(struct coordenada original, struct coordenada nueva) {
    struct coordenadas_superpuestas res;
    res.coincide = false;
    res.contiene = false;
    res.es_contenida = false;
    nueva.error = 0.0;

    if(nueva.ordenada == original.ordenada && original.abscisa == nueva.abscisa && original.error == nueva.error) {
        res.coincide = true;
    }   else if (original.ordenada == nueva.ordenada && original.abscisa == nueva.abscisa && original.error > nueva.error) {
        res.contiene = true;
    }   else if (original.ordenada == nueva.ordenada && original.abscisa == nueva.abscisa  && original.error < nueva.error) {
        res.es_contenida = true;
    }

    return res;
    
}

int main (void) {
    struct coordenada original, nueva;
    int i = 0;

    printf("Ingrese los valores para la coordenada original:\n");
    printf("Ordenada: ");
    scanf("%f", &original.ordenada);
    printf("Abscisa: ");
    scanf("%f", &original.abscisa);
    printf("Error: ");
    scanf("%f", &original.error);

    // Solicitar valores para la nueva coordenada
    printf("Ingrese los valores para la nueva coordenada:\n");
    printf("Ordenada: ");
    scanf("%f", &nueva.ordenada);
    printf("Abscisa: ");
    scanf("%f", &nueva.abscisa);
    printf("Error: ");
    scanf("%f", &nueva.error);

    struct coordenadas_superpuestas respuesta = verificar_superposicion(original, nueva);

    printf("\nResultados:\n");
    printf("Coincide: %s\n", respuesta.coincide ? "true" : "false");
    printf("Contiene: %s\n", respuesta.contiene ? "true" : "false");
    printf("Es contenida: %s\n", respuesta.es_contenida ? "true" : "false");

    return 0;
}