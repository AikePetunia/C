#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound; // valor >= a todos los elementos del arreglo
    bool is_lowerbound; // valor <= a todos los elementos del arreglo
    bool exists;        // si existe
    unsigned int where; // indice del arreglo del numero
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    unsigned int i = 0;
    
    while (i < length) {
        if (value == arr[i]) {
            res.where = i; 
            res.exists = true;

        }

        if (value >= arr[i]) {
            res.is_upperbound = true;
        }

        if (value <= arr[i]) {
            res.is_lowerbound = true;
        }

        i++;
    }

    return res;
}

int main(void) {
    struct bound_data result;
    int a[ARRAY_SIZE];
    int value;
    int i = 0;
    printf("dar un arreglo \n");

    while (i < ARRAY_SIZE) {
        printf("pos 1: ");
        scanf("%d", &a[i]);
        printf("\n");
        i++;
    }

    printf("valor a encontrar: ");
    scanf("%d", &value);
    result = check_bound(value, a, ARRAY_SIZE);

    printf("%d \n", result.is_upperbound); // Imprime 1
    printf("%d \n", result.is_lowerbound); // Imprime 0
    printf("%u \n", result.exists);        // Imprime 1
    printf("%u \n", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

