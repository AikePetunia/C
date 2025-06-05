#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("==== POINTER BASICS ====\n\n");

    /*
     * POINTER CONCEPTS:
     * - A pointer is a variable that stores a memory address (ODC)
     * - Pointers have specific types (int*, char*, etc.) which determine:
     *   a) The type of data they point to
     *   b) The arithmetic operations (e.g., pointer + 1 moves to the next element)
     */
    
    /*
     * REFERENCE OPERATOR (&):
     * - Gets the memory address of a variable
     * - Also called the "address operator"
     * - Example: &x returns the address where x is stored
     */
    int x = 3;
    int *p = NULL; // Always initialize pointers to NULL
    
    printf("1. REFERENCE OPERATOR (&):\n");
    printf("   x = %d\n", x);
    printf("   Address of x (&x) = %p\n", &x);
    
    // Assign the address of x to pointer p
    p = &x;
    printf("   p = %p (now p points to x)\n", p);
    
    /*
     * Memory visualization:
     *
     * Memory:
     * ...
     * Address: &x → Value: 3
     * ...
     *
     * p → points to &x
     */
    
    /*
     * DEREFERENCE OPERATOR (*):
     * - Gets the value stored at the address in a pointer
     * - Also called the "indirection operator"
     * - Example: *p returns the value at the address stored in p
     */
    printf("\n2. DEREFERENCE OPERATOR (*):\n");
    printf("   Value pointed by p (*p) = %d\n", *p);
    
    // Modify the value of x through the pointer
    *p = 10;
    printf("   After *p = 10:\n");
    printf("   x = %d (changed indirectly through pointer)\n", x);
    printf("   *p = %d\n", *p);
    
    /*
     * Memory visualization after modification:
     *
     * Memory:
     * ...
     * Address: &x → Value: 10 (changed from 3)
     * ...
     *
     * p → still points to &x
     */
    
    /*
     * NULL POINTERS:
     * - NULL represents an invalid memory address (usually 0)
     * - Used to indicate that a pointer doesn't point to anything valid
     * - Always initialize pointers to NULL if not immediately assigned
     * - Always check for NULL before dereferencing (*)
     */
    printf("\n3. NULL POINTERS:\n");
    int *null_ptr = NULL;
    printf("   null_ptr = %p\n", null_ptr);
    
    printf("   Attempting to dereference NULL would cause a segmentation fault\n");
    // Uncommenting the next line would crash the program:
    // printf("   *null_ptr = %d\n", *null_ptr);
    
    /*
     * INDEXING AND ARROW OPERATORS:
     * - p[n] is equivalent to *(p+n)
     * - p->member is equivalent to (*p).member (for struct pointers)
     */
    printf("\n4. INDEXING AND ARROW OPERATORS:\n");
    
    // Array indexing with pointers
    int arr[5] = {10, 20, 30, 40, 50};
    int *arr_ptr = arr; // arr is equivalent to &arr[0]
    
    printf("   Array values using pointer indexing:\n");
    for (int i = 0; i < 5; i++) {
        printf("   arr_ptr[%d] = %d (equivalent to *(arr_ptr+%d))\n", 
               i, arr_ptr[i], i);
    }
    
    // Arrow operator with structs
    typedef struct {
        int id;
        char name[20];
    } Person;
    
    Person person = {1, "John"};
    Person *person_ptr = &person;
    
    printf("\n   Struct access with arrow operator:\n");
    printf("   person_ptr->id = %d (equivalent to (*person_ptr).id)\n", person_ptr->id);
    printf("   person_ptr->name = %s (equivalent to (*person_ptr).name)\n", person_ptr->name);
    
    /*
     * PARAMETER TYPES IN C FUNCTIONS:
     * 1. IN parameters: Pass by value (default in C)
     * 2. OUT parameters: Simulated using pointers
     * 3. IN/OUT parameters: Also simulated using pointers
     */
    printf("\n5. SIMULATING OUT PARAMETERS WITH POINTERS:\n");
    int original = -5, result = 0;
    
    // Example of simulating an OUT parameter
    printf("   Before: original = %d, result = %d\n", original, result);
    
    // Function to get absolute value (simulated inline)
    if (original >= 0) {
        result = original;  // Direct assignment in actual code
    } else {
        result = -original; // Direct assignment in actual code
    }
    
    printf("   After: original = %d, result = %d\n", original, result);
    
    // The same would be done with pointers in a real function:
    // void absolute(int x, int *y) {
    //     if (x >= 0) {
    //         *y = x;
    //     } else {
    //         *y = -x;
    //     }
    // }
    
    return 0;
}
