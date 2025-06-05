#include <stdio.h>
#define N 5  // Using #define to create a constant for array size

int main(void) {
    int i;
    int a[N];  // Declares an array of size N (5) - Memory is allocated on the stack
    // Arrays in C are zero-indexed: valid indices are 0 to N-1
    // Memory allocation for this array: 5 integers * 4 bytes = 20 bytes (on most systems)

    // Input array elements
    i = 0;
    printf("--- Array Input Phase ---\n");
    while (i < N) {
        printf("Enter element %d of the array:\n", i);
        scanf("%d", &a[i]);  // & operator gets the address of a[i] where the value will be stored
        i = i + 1;  // Could also use i++ for incrementing
    }

    // Display array elements
    i = 0;
    printf("\n\nThe entered array:\n");
    printf("Index\tValue\tMemory Address\n");
    printf("-----\t-----\t--------------\n");
    while (i < N) {
        printf("%d\t%d\t%p\n", i, a[i], &a[i]);  // Shows index, value, and memory address
        i = i + 1;
    }

    // Calculate and display sum of array elements
    int sum = 0;
    for (i = 0; i < N; i++) {
        sum += a[i];
    }
    printf("\nSum of all elements: %d\n", sum);
    printf("Average of elements: %.2f\n", (float)sum / N);

    // Find maximum and minimum values
    int max = a[0], min = a[0];
    for (i = 1; i < N; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    /* Important array concepts:
     * 1. Arrays have fixed size once declared (cannot be resized)
     * 2. Array name (a) is a pointer to the first element
     * 3. No bounds checking - accessing a[N] or beyond is undefined behavior
     * 4. Arrays are passed to functions by reference (pointer)
     * 5. sizeof(a) gives the total bytes of the array, not the number of elements
     */

    return 0;
}
