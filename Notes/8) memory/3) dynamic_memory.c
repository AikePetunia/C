#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("==== DYNAMIC MEMORY MANAGEMENT ====\n\n");

    /*
     * STACK VS HEAP:
     * 
     * STACK:
     * - Automatic memory management
     * - Fast allocation/deallocation
     * - Limited size (can cause stack overflow)
     * - Used for local variables and function calls
     * - Memory freed automatically when function returns
     * 
     * HEAP:
     * - Manual memory management
     * - Slower allocation/deallocation
     * - Much larger size (limited by physical memory)
     * - Used for dynamic data structures and large objects
     * - Must be explicitly freed with free()
     */
    
    printf("1. STACK MEMORY:\n");
    int stack_array[5] = {1, 2, 3, 4, 5}; // Allocated on stack
    
    printf("   stack_array address: %p\n", stack_array);
    printf("   Stack memory allocation is fast and automatic\n");
    printf("   But size is limited (usually a few MB)\n");
    printf("   This memory will be freed when function returns\n\n");
    
    /*
     * DYNAMIC MEMORY ALLOCATION:
     * 
     * malloc(): Allocates specified bytes of memory
     * calloc(): Allocates and initializes memory to zero
     * realloc(): Resizes previously allocated memory
     * free(): Releases allocated memory
     */
    
    printf("2. HEAP MEMORY - malloc():\n");
    
    // malloc(): Allocates memory without initialization
    int *heap_array = (int*)malloc(5 * sizeof(int));
    
    if (heap_array == NULL) {
        printf("   Memory allocation failed!\n");
        return 1;
    }
    
    printf("   heap_array address: %p\n", heap_array);
    printf("   Allocated %lu bytes of memory\n", 5 * sizeof(int));
    
    // Initialize values
    for (int i = 0; i < 5; i++) {
        heap_array[i] = 10 + i;
        printf("   heap_array[%d] = %d\n", i, heap_array[i]);
    }
    
    // Free the memory
    free(heap_array);
    printf("   Memory freed with free()\n\n");
    
    printf("3. HEAP MEMORY - calloc():\n");
    
    // calloc(): Allocates and initializes memory to zero
    int *calloc_array = (int*)calloc(5, sizeof(int));
    
    if (calloc_array == NULL) {
        printf("   Memory allocation failed!\n");
        return 1;
    }
    
    printf("   calloc_array address: %p\n", calloc_array);
    printf("   Allocated and zeroed %lu bytes of memory\n", 5 * sizeof(int));
    
    // Show values (should all be zero)
    for (int i = 0; i < 5; i++) {
        printf("   calloc_array[%d] = %d\n", i, calloc_array[i]);
    }
    
    printf("4. HEAP MEMORY - realloc():\n");
    
    // Resize the array to hold 8 elements instead of 5
    calloc_array = (int*)realloc(calloc_array, 8 * sizeof(int));
    
    if (calloc_array == NULL) {
        printf("   Memory reallocation failed!\n");
        return 1;
    }
    
    printf("   calloc_array address after realloc: %p\n", calloc_array);
    printf("   Resized to %lu bytes of memory\n", 8 * sizeof(int));
    
    // Initialize new elements
    for (int i = 5; i < 8; i++) {
        calloc_array[i] = 20 + i;
    }
    
    // Show all values
    for (int i = 0; i < 8; i++) {
        printf("   calloc_array[%d] = %d\n", i, calloc_array[i]);
    }
    
    // Free the memory
    free(calloc_array);
    printf("   Memory freed with free()\n\n");
    
    /*
     * MEMORY LEAKS:
     * - Occur when allocated memory is not freed
     * - The memory becomes inaccessible but still allocated
     * - Can cause program to run out of memory over time
     */
    
    printf("5. MEMORY LEAK PREVENTION:\n");
    printf("   1. Always initialize pointers to NULL\n");
    printf("   2. Always check if malloc/calloc succeeded\n");
    printf("   3. Always free memory when done using it\n");
    printf("   4. Set pointers to NULL after freeing\n");
    printf("   5. Use valgrind to detect memory leaks\n\n");
    
    /*
     * SIZEOF OPERATOR:
     * - Returns the size in bytes of its operand
     * - Essential for proper memory allocation
     */
    
    printf("6. SIZEOF OPERATOR:\n");
    printf("   sizeof(char) = %lu bytes\n", sizeof(char));
    printf("   sizeof(int) = %lu bytes\n", sizeof(int));
    printf("   sizeof(float) = %lu bytes\n", sizeof(float));
    printf("   sizeof(double) = %lu bytes\n", sizeof(double));
    printf("   sizeof(void*) = %lu bytes\n", sizeof(void*));
    
    // Structure padding example
    typedef struct {
        char a;       // 1 byte
        int b;        // 4 bytes
        char c;       // 1 byte
    } StructWithPadding;
    
    printf("\n7. STRUCTURE PADDING:\n");
    printf("   sizeof(StructWithPadding) = %lu bytes\n", sizeof(StructWithPadding));
    printf("   Notice it's larger than 1+4+1=6 bytes due to padding\n");
    
    // The compiler adds padding for memory alignment
    printf("   Memory layout might be:\n");
    printf("   | a (1B) | padding (3B) | b (4B) | c (1B) | padding (3B) |\n");
    
    return 0;
}
