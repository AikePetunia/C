#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // For atoi, atof functions

int main() {
    // ===== INPUT/OUTPUT METHODS IN C =====
    
    // === USER INPUT METHODS ===
    char name[25]; // Limited size for overflow prevention
    int age;
    
    printf("===== INPUT METHODS DEMONSTRATION =====\n\n");
    
    // METHOD 1: scanf()
    // Pros: Simple, efficient for basic types
    // Cons: Unsafe, can cause buffer overflows, stops at whitespace for strings
    printf("METHOD 1: scanf() - Basic input\n");
    printf("What's your name? ");
    // scanf("%s", name);  // UNSAFE - no bounds checking! Only reads until first whitespace
    
    // METHOD 2: fgets() - SAFER ALTERNATIVE
    // Pros: Safe, handles whitespace
    // Cons: Includes newline character, needs extra processing
    printf("\nMETHOD 2: fgets() - Safer string input\n");
    printf("What's your name? ");
    // fgets(name, 25, stdin);                 // Reads up to 24 chars + null terminator
    // name[strlen(name)-1] = '\0';            // Removes the trailing newline
    
    // METHOD 3: scanf with field width limit
    // Pros: Prevents buffer overflow, simple
    // Cons: Still stops at whitespace
    printf("\nMETHOD 3: scanf with width limit\n");
    printf("What's your name? ");
    // scanf("%24s", name);  // Limits input to 24 characters
    
    // METHOD 4: getchar() for character-by-character input
    // Pros: Fine-grained control
    // Cons: Requires more code
    printf("\nMETHOD 4: getchar() for character input\n");
    printf("Enter a character: ");
    // char c = getchar();
    // printf("You entered: %c\n", c);
    
    printf("\nFor this demo, we'll use hardcoded values\n");
    strcpy(name, "John Doe");
    age = 30;
    
    printf("\nHello %s, how are you?", name);
    printf("\nYou are %d years old\n", age);
    
    // === INPUT VALIDATION EXAMPLE ===
    printf("\n===== INPUT VALIDATION EXAMPLE =====\n");
    int valid_input = 0;
    int number;
    
    printf("In a real program, you would validate user input like this:\n");
    printf("Enter a number between 1 and 100: ");
    
    // while (!valid_input) {
    //     if (scanf("%d", &number) != 1) {
    //         // Clear input buffer on error
    //         while (getchar() != '\n');
    //         printf("Invalid input. Please enter a number: ");
    //     } 
    //     else if (number < 1 || number > 100) {
    //         printf("Number must be between 1 and 100. Try again: ");
    //     }
    //     else {
    //         valid_input = 1;
    //     }
    // }
    
    // Simulate valid input
    number = 42;
    printf("You entered: %d (simulated for this demo)\n", number);
    
    // === STRING CONVERSION FUNCTIONS ===
    printf("\n===== STRING CONVERSION FUNCTIONS =====\n");
    
    char num_str[] = "12345";
    char float_str[] = "123.45";
    
    printf("String to convert: \"%s\"\n", num_str);
    printf("atoi(): %d\n", atoi(num_str));       // Convert string to int
    printf("atol(): %ld\n", atol(num_str));      // Convert string to long
    printf("atof(): %f\n", atof(float_str));     // Convert string to double
    
    // strtol, strtod for more control and error checking
    char *endptr;
    long int li = strtol(num_str, &endptr, 10);  // Base 10 conversion
    printf("strtol(): %ld (remaining: \"%s\")\n", li, endptr);
    
    // === MATHEMATICS WITH <math.h> ===
    printf("\n===== MATHEMATICAL FUNCTIONS =====\n");
    
    double value = 25.0;
    printf("Value: %f\n", value);
    
    double A = sqrt(value);              // Square root
    double B = pow(value, 0.5);          // Alternative square root
    double C = pow(3, 4);                // Powers: 3^4 = 81
    int D = round(3.14159);              // Rounds to nearest integer
    int E = ceil(3.14159);               // Rounds up (ceiling)
    int F = floor(3.14159);              // Rounds down (floor)
    double G = fabs(-41.5);              // Absolute value
    double H = log(20.085);              // Natural logarithm (base e)
    double I = log10(100.0);             // Base 10 logarithm
    double J = exp(1.0);                 // e^x
    double K = sin(M_PI/2);              // Sine (radians)
    double L = cos(M_PI);                // Cosine (radians)
    double M = tan(M_PI/4);              // Tangent (radians)
    
    printf("sqrt(%.1f) = %.4f\n", value, A);
    printf("pow(%.1f, 0.5) = %.4f\n", value, B);
    printf("pow(3, 4) = %.1f\n", C);
    printf("round(3.14159) = %d\n", D);
    printf("ceil(3.14159) = %d\n", E);
    printf("floor(3.14159) = %d\n", F);
    printf("fabs(-41.5) = %.1f\n", G);
    printf("log(20.085) = %.4f\n", H);
    printf("log10(100.0) = %.1f\n", I);
    printf("exp(1.0) = %.4f\n", J);
    printf("sin(π/2) = %.4f\n", K);
    printf("cos(π) = %.4f\n", L);
    printf("tan(π/4) = %.4f\n", M);
    
    // === FORMAT SPECIFIERS ===
    printf("\n===== FORMAT SPECIFIER EXAMPLES =====\n");
    
    int num = 12345;
    double dbl = 123.456789;
    char chr = 'X';
    char str[] = "Hello";
    void *ptr = &num;
    
    printf("%%d (int): %d\n", num);
    printf("%%6d (right-aligned): |%6d|\n", num);
    printf("%%-6d (left-aligned): |%-6d|\n", num);
    printf("%%06d (zero-padded): |%06d|\n", num);
    
    printf("\n%%f (double): %f\n", dbl);
    printf("%%.2f (2 decimals): %.2f\n", dbl);
    printf("%%10.2f (field width 10, 2 decimals): |%10.2f|\n", dbl);
    printf("%%-10.2f (left-aligned): |%-10.2f|\n", dbl);
    
    printf("\n%%c (char): %c\n", chr);
    printf("%%s (string): %s\n", str);
    printf("%%15s (right-aligned): |%15s|\n", str);
    printf("%%-15s (left-aligned): |%-15s|\n", str);
    
    printf("\n%%p (pointer): %p\n", ptr);
    printf("%%x (hex): %x\n", num);
    printf("%%o (octal): %o\n", num);
    
    // === STRING OPERATIONS with string.h ===
    printf("\n===== STRING OPERATIONS =====\n");
    
    char string1[50] = "Hello";
    char string2[50] = "World";
    char string3[50];
    
    printf("string1: \"%s\"\n", string1);
    printf("string2: \"%s\"\n", string2);
    
    // String length
    printf("\nstrlen(string1): %lu\n", strlen(string1));
    
    // String copy
    strcpy(string3, string1);
    printf("strcpy(string3, string1): \"%s\"\n", string3);
    
    // String concatenation
    strcat(string3, " ");
    strcat(string3, string2);
    printf("strcat(string3, string2): \"%s\"\n", string3);
    
    // String comparison
    printf("\nstrcmp(string1, string2): %d\n", strcmp(string1, string2));
    printf("strcmp(string1, \"Hello\"): %d\n", strcmp(string1, "Hello"));
    
    // String search
    char *substr = strstr(string3, "World");
    printf("strstr(string3, \"World\"): \"%s\"\n", substr ? substr : "Not found");
    
    // Find character
    char *chr_pos = strchr(string1, 'e');
    printf("strchr(string1, 'e'): Position %ld\n", chr_pos ? chr_pos - string1 + 1 : -1);
    
    return 0;
}
