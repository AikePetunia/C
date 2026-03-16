#include <limits.h>
#include <stdio.h>
#include "change.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void print_table(int n, int k, int table[n][k]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (table[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", table[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Resuelve el problema de la moneda
 *
 * @param d denominaciones
 * @param n cantidad de denominaciones
 * @param k monto a pagar
 */
int change(int d[], int n, int k) {
    return 0;
}
