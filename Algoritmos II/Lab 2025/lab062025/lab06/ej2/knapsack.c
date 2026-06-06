#include <limits.h>
#include <stdio.h>
#include "knapsack.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

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
 * @brief Resuelve el problema de la mochila
 *
 * @param values valores de los objetos
 * @param weights pesos de los objetos
 * @param n cantidad de objetos
 * @param W capacidad de la mochila
 */
int knapsack(int values[], int weights[], int n, int W) {
    return 0;
}
