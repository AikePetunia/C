#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>  // For variadic functions

// ===== FUNCTION DEFINITIONS =====

// Basic function that takes parameters and returns nothing (void)
void milanesa(char name[], int age) {
    printf("\nI am a milanesa");
    printf("\nI am a milanesa %s", name);
    printf("\nI am a BEEF milanesa and it's %d", age);
    printf("\nI am a milanesa");
}

// Function that returns a value
double square(double x) {
    return x * x;  // Return statement sends value back to caller
}

// Function using the ternary operator for concise code
int findMax(int x, int y) {
    // Ternary operator: (condition) ? value_if_true : value_if_false
    return (x > y) ? x : y;
}

// Static function - retains its value between calls
static int counter() {
    static int count = 0;  // Static variable - initialized only once
    count++;
    return count;
}

// Inline function suggestion - compiler may substitute the code directly
inline int add(int a, int b) {
    return a + b;
}

// Variadic function example - takes variable number of arguments
double average(int count, ...) {
    va_list args;            // Declare va_list to hold variable arguments
    va_start(args, count);   // Initialize va_list with count parameter
    
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);  // Extract each argument
    }
    
    va_end(args);            // Clean up va_list
    return sum / count;
}

// Recursive function example
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function that takes function pointer as parameter
int operate(int x, int y, int (*operation)(int, int)) {
    return operation(x, y);
}

// ===== FUNCTION PROTOTYPES =====
// Function declarations - good practice to place at the top
void hello(char name[], int age);
int multiply(int a, int b);  // Prototype for function defined later

int main() {
    printf("===== FUNCTION BASICS DEMONSTRATION =====\n");
    
    // ===== LOGICAL OPERATORS =====
    printf("\n===== LOGICAL OPERATORS =====\n");
    // AND (&&): Checks if both conditions are true
    // OR (||): Checks if at least one condition is true
    // NOT (!): Negates the value of a condition

    float temp = 25;
    bool sunny = false;
    bool dragon = true;

    if ((temp >= 0 || temp <= 30) && sunny == true && !dragon) {
        printf("You won't freeze\n");
    } else {
        printf("The temperature is bad\n");
    }

    // ===== FUNCTION CALLS =====
    printf("\n===== BASIC FUNCTION CALLS =====\n");
    
    char name[] = "Aike";
    int age = 18;

    milanesa(name, age);  // Arguments for the function
    double x = square(33233);

    // Prints the result of the square function
    printf("\nThe square of 33233 is: %lf\n", x);
    printf("The square of %lf is: %lf\n", x, square(x));

    // ===== TERNARY OPERATOR =====
    printf("\n===== TERNARY OPERATOR =====\n");
    // Shortcut for if/else to assign values based on a condition
    int max = findMax(3, 4);
    printf("The maximum between 3 and 4 is: %d\n", max);

    // ===== USING FUNCTION PROTOTYPE =====
    printf("\n===== FUNCTION PROTOTYPE DEMONSTRATION =====\n");
    char name1[] = "Aike1";
    int age1 = 183;
    hello(name1, age1);
    
    // ===== STATIC FUNCTION DEMONSTRATION =====
    printf("\n===== STATIC FUNCTION DEMONSTRATION =====\n");
    printf("Counter calls: %d\n", counter());
    printf("Counter calls: %d\n", counter());
    printf("Counter calls: %d\n", counter());
    
    // ===== VARIADIC FUNCTION DEMONSTRATION =====
    printf("\n===== VARIADIC FUNCTION DEMONSTRATION =====\n");
    printf("Average of 2, 4, 6, 8, 10: %.2f\n", average(5, 2, 4, 6, 8, 10));
    printf("Average of 1, 3, 5: %.2f\n", average(3, 1, 3, 5));
    
    // ===== RECURSIVE FUNCTION DEMONSTRATION =====
    printf("\n===== RECURSIVE FUNCTION DEMONSTRATION =====\n");
    printf("Fibonacci(10): %d\n", fibonacci(10));
    
    // ===== FUNCTION POINTER DEMONSTRATION =====
    printf("\n===== FUNCTION POINTER DEMONSTRATION =====\n");
    int result = operate(5, 3, multiply);
    printf("operate(5, 3, multiply): %d\n", result);
    
    // Direct function pointer usage
    int (*func_ptr)(int, int) = &multiply;  // & is optional
    printf("Direct function pointer call: %d\n", func_ptr(4, 7));
    
    // ===== FUNCTION SCOPE DEMONSTRATION =====
    printf("\n===== FUNCTION SCOPE DEMONSTRATION =====\n");
    {
        int local_var = 10;  // Block-scoped variable
        printf("Inside block: local_var = %d\n", local_var);
    }
    // printf("Outside block: local_var = %d\n", local_var);  // Would cause error - out of scope
    
    return 0;
}

// Function definition after prototype
void hello(char name1[], int age1) {
    printf("\nI am a milanesa %s", name1);
    printf("\nI am a BEEF milanesa and it's %d", age1);
}

// Function for use with function pointers
int multiply(int a, int b) {
    return a * b;
}

/*
===== FUNCTION PARAMETER PASSING =====

1. Pass by Value:
   - The function receives a copy of the variable's value
   - Changes to the parameter don't affect the original variable
   - Default for simple data types (int, float, char, etc.)

2. Pass by Reference:
   - The function receives the memory address of the variable
   - Changes to the parameter affect the original variable
   - Implemented using pointers in C
   - Default for arrays (which decay to pointers)

===== FUNCTION RETURN TYPES =====

1. void - Function doesn't return a value
2. Any data type (int, float, char, etc.) - Function returns that type
3. Pointer type (int*, char*, etc.) - Function returns an address
4. struct or union - Function returns a structure or union
5. No explicit return in main() defaults to return 0

===== FUNCTION ATTRIBUTES =====

1. static - Function is only visible in its source file
2. inline - Suggests to compiler to insert function code at call site
3. extern - Function is defined in another file (default for functions)
*/
