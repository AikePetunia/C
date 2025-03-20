#include <stdio.h>
#include <stdbool.h>
#define N 5

typedef char clave_t;
typedef int valor_t;

struct asoc {
    clave_t clave;
    valor_t valor;
};

bool asoc_existe(int tam, struct asoc a[], clave_t c) {
    int i = 0;
    while (i < N) {
        if (a[i].clave == c) {
            return true;
        }
        i = i + 1;
    }
    return false;
}

int main (void) {
    struct asoc a[N];
    int i = 0;
    char c;

    while (i < N) {
        printf("Elemento %d \n", i + 1);

        printf("Ingrese una clave char: ");
        scanf(" %c", &a[i].clave); //para limpiar buffer

        printf("Ingrese una valor int: ");
        scanf("%d", &a[i].valor);
        i = i + 1;
    }

    printf("Ingrese la clave que desea buscar: \n");
    scanf(" %c", &c);

    bool respuesta = asoc_existe(N, a, c);
    if (respuesta == true) {
        printf("Existe en el arreglo");
    } else {
        printf("no existe en el arreglo");
    }
    return 0;
}
