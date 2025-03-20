#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#define N 5

struct datos {
    bool esta_ordenado_desc;
    char maximo;
};

struct datos esta_ordenado_desc(int tam, char a[]) {
    int i = 0;
    struct datos res;
    res.esta_ordenado_desc = false;
    res.maximo = ' ';
    while (i < N) {
        if (a[i] < a[i + 1]) {
            res.esta_ordenado_desc = false;
        }
        if (a[i] > res.maximo) {
            res.maximo = a[i];
        }
        i = i + 1;
    }
    return res;
}

int main (void) {
    assert(N > 2);
    char a[N];
    int i = 0;

    while (i < N ) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf(" %c", &a[i]);
        i = i + 1;
    }

    struct datos res = esta_ordenado_desc(N, a);
    if (res.esta_ordenado_desc == true) {
        printf("Esta en orden descendiente y su maximo es %c", res.maximo);
    }   else {
        printf("No esta en orden descendiente y su maximo es %c", res.maximo);
        
    }
    return 0;
}