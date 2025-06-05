#include <stdio.h>

// Function to print elements at even positions in an array
void printEvenPositionElements(int arr[], int length) {
    printf("Elements at even positions:\n");
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            printf("%d ", arr[i]); // Print the element at even position
        }
    }
    printf("\n");
}

int main() {
    /*
    Arrays, Arrays
    Arrays allow storing vectors and matrices. 
    One-dimensional arrays are used to represent vectors 
    Two-dimensional arrays for two-dimensional matrices.

    When to use them:
    It's an abstract data type suitable for situations where access to data is random and unpredictable.
    Otherwise, when elements can be ordered and sequential access will be used, a list would be more appropriate.
    N-dimensional matrices can be represented.

    Array declaration:
    To declare an array in the "C" language, use the following instruction:

    int a[5];

    NOTE: this instruction declares an array of 5 elements with indices from 0 to 4.

    To initialize them:
    To initialize or assign a value to the second element of the previously defined array, use the following instruction:

    a[1] = 10;

    Reading:
    To read the second element of the previously defined array, use the following instruction:

    x = a[1];
    */
    
    // Example of accessing even position elements
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int length = sizeof(arr) / sizeof(arr[0]); // Calculate the list size

    printEvenPositionElements(arr, length);

    return 0;
}
