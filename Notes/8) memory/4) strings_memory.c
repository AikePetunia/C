#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("==== STRINGS AND MEMORY ====\n\n");

    /*
     * STRINGS IN C:
     * - A string is a sequence of characters ending with a null character '\0'
     * - Can be represented as:
     *   1. Character arrays (static allocation)
     *   2. Pointers to characters (can be static or dynamic)
     */
    
    printf("1. STRINGS AS CHARACTER ARRAYS (STACK):\n");
    char str_arr[] = "Hello, world!"; // Includes the null terminator '\0'
    
    printf("   str_arr = \"%s\"\n", str_arr);
    printf("   Length = %lu bytes (including null terminator)\n", strlen(str_arr) + 1);
    printf("   Memory location: %p (on stack)\n", str_arr);
    
    // We can modify elements of the array
    str_arr[0] = 'h';
    printf("   After modification: \"%s\"\n\n", str_arr);
    
    printf("2. STRINGS AS POINTERS TO LITERALS (READ-ONLY):\n");
    char *str_ptr = "Hello, world!"; // Points to a string literal (global section)
    
    printf("   str_ptr = \"%s\"\n", str_ptr);
    printf("   Length = %lu bytes (including null terminator)\n", strlen(str_ptr) + 1);
    printf("   Memory location: %p (in read-only section)\n", str_ptr);
    
    printf("   Cannot modify string literals - would cause segmentation fault\n");
    // Uncommenting the next line would crash the program:
    // str_ptr[0] = 'h';
    
    // Can change where the pointer points to
    str_ptr = "Another string";
    printf("   After redirection: \"%s\"\n\n", str_ptr);
    
    printf("3. STRINGS IN DYNAMIC MEMORY (HEAP):\n");
    // Allocate memory for a string
    char *dynamic_str = (char*)malloc((strlen("Dynamic string") + 1) * sizeof(char));
    
    if (dynamic_str == NULL) {
        printf("   Memory allocation failed!\n");
        return 1;
    }
    
    // Copy a string into the allocated memory
    strcpy(dynamic_str, "Dynamic string");
    
    printf("   dynamic_str = \"%s\"\n", dynamic_str);
    printf("   Length = %lu bytes (including null terminator)\n", strlen(dynamic_str) + 1);
    printf("   Memory location: %p (on heap)\n", dynamic_str);
    
    // We can modify the string
    dynamic_str[0] = 'd';
    printf("   After modification: \"%s\"\n", dynamic_str);
    
    // Free the memory
    free(dynamic_str);
    printf("   Memory freed with free()\n\n");
    
    printf("4. MEMORY REPRESENTATION OF STRINGS:\n");
    char example[] = "abc";
    printf("   String \"abc\" in memory:\n");
    printf("   example[0] = '%c' (%d) at address %p\n", example[0], example[0], &example[0]);
    printf("   example[1] = '%c' (%d) at address %p\n", example[1], example[1], &example[1]);
    printf("   example[2] = '%c' (%d) at address %p\n", example[2], example[2], &example[2]);
    printf("   example[3] = '\\0' (%d) at address %p\n", example[3], &example[3]);
    
    printf("\n5. STRING FUNCTIONS WITHOUT <string.h>:\n");
    
    // Calculate string length manually
    char *test_str = "Testing";
    int length = 0;
    while (test_str[length] != '\0') {
        length++;
    }
    printf("   Manual strlen(\"%s\") = %d\n", test_str, length);
    
    // Manual string copy
    char source[] = "Source";
    char dest[10];
    int i = 0;
    while ((dest[i] = source[i]) != '\0') {
        i++;
    }
    printf("   Manual strcpy result: \"%s\"\n", dest);
    
    // String comparison
    char str1[] = "apple";
    char str2[] = "banana";
    i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0') break;
        i++;
    }
    int compare_result = str1[i] - str2[i];
    printf("   Manual strcmp(%s, %s) = %d\n", str1, str2, compare_result);
    printf("   Negative value means first string comes before second alphabetically\n\n");
    
    printf("6. COMMON STRING PITFALLS:\n");
    printf("   1. Forgetting the null terminator\n");
    printf("   2. Buffer overflow (writing beyond string bounds)\n");
    printf("   3. Using uninitialized strings\n");
    printf("   4. Modifying string literals\n");
    printf("   5. Not freeing dynamically allocated strings\n");
    printf("   6. Using strings after they've been freed\n");
    
    return 0;
}
