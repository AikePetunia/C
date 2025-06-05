#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* ===== FUNCTION DEFINITIONS IN C =====
 *
 * Function structure:
 * return_type function_name(parameter_list) {
 *     // function body
 *     return value;  // if return_type is not void
 * }
 *
 * Function characteristics:
 * 1. Functions break large programs into smaller, manageable pieces
 * 2. They promote code reusability and modularity
 * 3. They can be called multiple times
 * 4. They have their own scope for local variables
 */

/* Function prototypes (declarations) - good practice to place these at the top */
int add(int n, int m);
bool is_prime(int n);
void print_isPrime(bool n_isprime);
int factorial(int n);
void swap(int *a, int *b);
int sum_array(int arr[], int size);
void increment_by_value(int n);
void increment_by_reference(int *n);

/* Global variable example - accessible by all functions */
int global_counter = 0;

/* Main function - entry point of every C program */
int main(void) {
    int n, m, sum;
    bool n_isprime;

    /* INPUT/OUTPUT operations are usually placed in main */
    printf("===== FUNCTION DEMONSTRATION =====\n\n");
    
    printf("Enter a number\n");
    scanf("%d", &n);

    printf("Enter another number\n");
    scanf("%d", &m);

    /* Function call to add() */
    sum = add(n, m);
    printf("The sum of both numbers is %d\n", sum);

    /* Function call to is_prime() */
    n_isprime = is_prime(n);

    /* Function call to print_isPrime() */
    print_isPrime(n_isprime);
    
    /* Demonstrating factorial with recursion */
    if (n >= 0 && n <= 12) {  // Protect against overflow and negative input
        printf("%d! = %d\n", n, factorial(n));
    } else {
        printf("Factorial not calculated (input too large or negative)\n");
    }
    
    /* Demonstrating pass by value vs pass by reference */
    printf("\n===== PASS BY VALUE VS REFERENCE =====\n");
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    
    swap(&x, &y);  // Pass addresses to swap function
    printf("After swap: x = %d, y = %d\n", x, y);
    
    /* More examples of value vs reference */
    int value = 10;
    printf("\nOriginal value: %d\n", value);
    
    increment_by_value(value);
    printf("After increment_by_value: %d (unchanged)\n", value);
    
    increment_by_reference(&value);
    printf("After increment_by_reference: %d (changed)\n", value);
    
    /* Array example - arrays are always passed by reference */
    printf("\n===== ARRAY PROCESSING =====\n");
    int numbers[] = {1, 2, 3, 4, 5};
    int array_size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Array elements: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("Sum of array elements: %d\n", sum_array(numbers, array_size));
    
    /* Function pointer example */
    printf("\n===== FUNCTION POINTERS =====\n");
    int (*operation)(int, int);  // Declare a function pointer
    
    operation = add;  // Assign function address to pointer
    printf("Using function pointer to call add(3, 4): %d\n", operation(3, 4));
    
    return 0;
}

/* Function to add two integers */
int add(int n, int m) {
    /* Local variable - only accessible within this function */
    int res;
    
    /* Update global counter to demonstrate global variable usage */
    global_counter++;
    
    res = n + m;
    
    /* Every non-void function must have a return statement */
    return res;
}

/* Function to check if a number is prime
 * Specification: Given an integer n, returns true if it is prime,
 * false otherwise.
 */
bool is_prime(int n) {
    int i;
    bool res;

    /* Handle edge cases */
    if (n <= 1) return false;  // 0 and 1 are not prime
    if (n <= 3) return true;   // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false;  // Check divisibility by 2 and 3
    
    /* Optimized algorithm - check divisors up to sqrt(n) */
    i = 5;
    res = true;

    while (i * i <= n && res) {
        res = res && !(n % i == 0) && !(n % (i + 2) == 0);
        i = i + 6;  // Skip numbers that are not of form 6k±1
    }

    /* Update global counter */
    global_counter++;
    
    return res;
}

/* Function to print whether a number is prime
 * This is an example of a procedure (void function) that takes an argument
 * and returns nothing
 */
void print_isPrime(bool n_isprime) {
    if (n_isprime) {
        printf("The first number entered is prime.\n");
    }
    else {
        printf("The first number entered is NOT prime.\n");
    }
    
    /* No return statement needed for void functions (optional) */
}

/* Recursive function to calculate factorial
 * Demonstrates how a function can call itself
 */
int factorial(int n) {
    /* Base case - stop recursion when n is 0 */
    if (n == 0) {
        return 1;
    }
    /* Recursive case - function calls itself */
    else {
        return n * factorial(n - 1);
    }
}

/* Function demonstrating pass by reference using pointers
 * Swaps the values of two integers
 */
void swap(int *a, int *b) {
    int temp = *a;  // Dereference pointer to get value
    *a = *b;        // Modify value at address a
    *b = temp;      // Modify value at address b
}

/* Function to process an array (arrays are passed by reference) */
int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

/* Demonstrates pass by value - changes to parameter don't affect original */
void increment_by_value(int n) {
    n++;  // This only affects the local copy
    printf("Inside increment_by_value: n = %d\n", n);
}

/* Demonstrates pass by reference - changes affect the original variable */
void increment_by_reference(int *n) {
    (*n)++;  // Dereference and increment the value at the address
    printf("Inside increment_by_reference: *n = %d\n", *n);
}
