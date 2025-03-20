#include <stdio.h>
#include <stdbool.h>
#define N 5

struct cinco_t {
    int primero;
    int segundo;
    int tercero;
    int cuarto;
    int quinto;
};

bool es_primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i * i <= n; i += 2) {  
        if (n % i == 0) return false;
    }
    return true;
}

struct cinco_t cinco_primos(int a[], int tam) {
    struct cinco_t numero = {-1, -1, -1, -1, -1};
    int i = 0;
    while (i < N) {
        if (es_primo(a[i]) == true && i == 0) {
            numero.primero = a[i];
        } else if (es_primo(a[i]) == true && i == 1) {
            numero.segundo = a[i];
        } else if (es_primo(a[i]) == true && i == 2) {
            numero.tercero = a[i];
        } else if (es_primo(a[i]) == true && i == 3) {
            numero.cuarto = a[i];
        } else if (es_primo(a[i]) == true && i == 4) {
            numero.quinto = a[i];
        }
    i = i + 1;
    }
    return numero;
}

int main (void) {
    int a[N];
    int i = 0;

    while (i < N ) {
        printf("Elemento %d:", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }

    struct cinco_t respuesta = cinco_primos(a, N);

    printf("Primos encontrados:\n");
    printf("Primero: %d\nSegundo: %d\nTercero: %d\nCuarto: %d\nQuinto: %d\n",
           respuesta.primero, respuesta.segundo, respuesta.tercero, respuesta.cuarto, respuesta.quinto);
    return 0;
}