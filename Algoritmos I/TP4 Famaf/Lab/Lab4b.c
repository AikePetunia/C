#include <stdio.h>
#include <assert.h>

int main() {
    int n, abs_val;

    printf("Introduce un número entero negativo para calcular el abs: ");
    scanf("%d", &n);

    if (n >= 0) {
        abs_val = n; //intercambia variables para que el valor absoluto sea positivo
    } else {
        abs_val = -n;
    }

    // Postcondición: verificar que abs_val es el valor absoluto de n
    assert((abs_val >= 0) && (abs_val == n || abs_val == -n));

    printf("El valor absoluto de %d es: %d\n", n, abs_val);
    return 0;
}
