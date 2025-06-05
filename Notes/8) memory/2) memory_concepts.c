#include <stdio.h>
#include <stdlib.h>

int main() {
    /* MEMORY CONCEPTS
     * memory = an ordered list of bytes in RAM (like a long street)
     * memory block = a unit (byte) in memory, used to store some value (a house on the street)
     * memory address = the location identifier where a memory block is assigned (house address)
     */

    // MEMORY TYPES IN C:
    // 1. Stack: Automatic, managed by compiler, fast but limited size
    //    - Local variables, function parameters
    //    - Automatic allocation/deallocation
    //    - Limited size (can cause stack overflow)
    //    - LIFO (Last In First Out) structure
    // 2. Heap: Dynamic, managed by programmer, slower but larger size
    //    - Created with malloc(), calloc(), realloc()
    //    - Must be freed manually with free()
    //    - Can cause memory leaks if not managed properly
    // 3. Static/Global: Fixed throughout program execution
    //    - Global variables, static variables
    //    - Initialized data (.data) and uninitialized data (.bss)
    // 4. Code/Text: Read-only, stores the executable instructions

    /* MEMORY SIZES FOR DIFFERENT DATA TYPES */
    long int a = 'x';   
    char b = 'y';
    long int c = 'z';
    double d = 123.456;
    int *ptr = NULL;  // Pointer variable. Must be initialized as NULL

    printf("MEMORY SIZES FOR COMMON DATA TYPES:\n");
    printf("long int: %d bytes\n", sizeof(a));
    printf("char: %d bytes\n", sizeof(b));
    printf("long int: %d bytes\n", sizeof(c));
    printf("double: %d bytes\n", sizeof(d));
    printf("pointer: %d bytes\n", sizeof(ptr));  // Usually 4 bytes on 32-bit systems, 8 on 64-bit

    /* MEMORY ALIGNMENT
     * Modern computers access memory most efficiently when data is aligned
     * For example, 4-byte integers are often aligned on 4-byte boundaries
     * This can cause "padding" in structures
     */

    // Now, where are they located? Each variable has a memory address
    printf("\nMEMORY ADDRESSES (in hexadecimal):\n");
    printf("Address of a: %p\n", &a);     // Hexadecimal representation (0-9, A-F)
    printf("Address of b: %p\n", &b);
    printf("Address of c: %p\n", &c);
    printf("Address of d: %p\n", &d);
    printf("Value of ptr: %p\n", ptr);    // NULL is typically represented as 0x0

    // MEMORY LAYOUT visualization (more detailed)
    printf("\nMEMORY LAYOUT:\n");
    printf("High addresses\n");
    printf("  ↑  ┌───────────┐\n");
    printf("  │  │ Command   │ Environment & command line arguments\n");
    printf("  │  │ Line Args │\n");
    printf("  │  ├───────────┤\n");
    printf("  │  │   Stack   │ Function parameters, local variables (a, b, c, d)\n");
    printf("  │  │    ↓      │ Grows downward - LIFO structure\n");
    printf("  │  │           │ Limited size, automatic allocation/deallocation\n");
    printf("  │  │    ↑      │\n");
    printf("  │  │   Heap    │ Dynamic memory allocation (malloc, calloc, realloc)\n");
    printf("  │  │           │ Grows upward, manual memory management\n");
    printf("  │  │           │ Must use free() to avoid memory leaks\n");
    printf("  │  ├───────────┤\n");
    printf("  │  │ Uninitialized │ BSS segment - uninitialized static/global vars\n");
    printf("  │  │    Data    │ Initialized to zero by the system\n");
    printf("  │  ├───────────┤\n");
    printf("  │  │ Initialized │ Data segment - initialized static/global vars\n");
    printf("  │  │    Data    │ Contains values from the source code\n");
    printf("  │  ├───────────┤\n");
    printf("  │  │   Text    │ Program instructions (machine code)\n");
    printf("  │  │           │ Read-only section\n");
    printf("Low addresses\n");

    // DYNAMIC MEMORY ALLOCATION EXAMPLE
    int *dynamic_array = (int*)malloc(5 * sizeof(int));
    if (dynamic_array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("\nDYNAMIC MEMORY ALLOCATION:\n");
    printf("Address of dynamic_array: %p\n", dynamic_array);
    
    // Initialize the array
    for (int i = 0; i < 5; i++) {
        dynamic_array[i] = i * 10;
        printf("dynamic_array[%d] = %d (at address %p)\n", 
               i, dynamic_array[i], &dynamic_array[i]);
    }
    
    // IMPORTANT: Always free dynamically allocated memory to avoid memory leaks
    free(dynamic_array);
    dynamic_array = NULL;  // Good practice to prevent use after free
   
    return 0;
}
