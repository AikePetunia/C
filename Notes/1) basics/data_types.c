#include <stdio.h>
#include <stdbool.h>

int main() {
    /*
    About C: 
    - It's an imperative language.
    - It's known for its efficiency.
    - It's weakly typed and mid-level.
    - It's "Case Sensitive".
    - It follows the standard (ISO/IEC 9899:1990) making it cross-platform.
    
    In C language, multiple assignment doesn't exist!
    We must be careful how we translate to respect the semantics of the program.
    That is, they have equivalent states (the values of the variables are the same).
    */

    // Comments
    // This is a single line comment
    /*
    Multiple
    line
    comments
    */

    /*
    \n = new line in a print or others
    \t = tab spaces in texts
    */
    printf("THIS IS A NUMBER GRID\n");
    printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n");
    printf("THIS IS A NUMBER GRID\n");

    /*
    To print quotes, use the backslash (\)
    */
    printf("I ate a \"hamburger\" yesterday\n");

    // Variables

    int number1; // Declaration
    number1 = 5; // Initialization

    // Alternatively

    // Numbers 
    int number = 5;                        // 4 Bytes (-2b to 2b+)                                  %d
    unsigned int number8 = 4294967295;     // 4 bytes (0 to 4b) %u
    long long int number9 = 3123333333;    // 8 bytes (-9q to 9q) %lld
    unsigned long long int number10 = 414; // 8 bytes (0 to 18q) %llu
    short int number5 = 32767;             // 2 bytes (-32,768 to +32,767)                             %d
    unsigned short int number6 = 65535;    // 2 bytes (0 to +65,535)                                   %d
    short number7 = 32767;                 // 2 bytes (-32,768 to +32,767) (no need to declare int) %d
    unsigned short number123 = 65535;      // 2 bytes (0 to +65,535) (no need to declare int)    %d

    float number4 = 2.3123123514512;       // Decimal, 4 bytes (32 bits precision) 6-7 digits     %f
    float number2 = 2.04;                  // Decimal, 4 bytes (32 bits precision) 6-7 digits     %f
    double number3 = 2.3123123514512;      // Decimal, 8 bytes (64 bits precision) 15-16 digits   %lf

    printf("%0.15f NORMAL FLOAT WITH MANY NUMBERS, precision is lost with many digits\n", number4);
    printf("%0.15lf LONG FLOAT WITH capacity to handle more digits\n", number3);
    printf("%f normal float\n", number2);

    // Booleans
    // Need to declare at the beginning (before use) #include <stdbool.h>

    bool t = true;   // 1 Byte, works in binary 1 = True, 0 = False    %d
    bool f = false;  // 1 Byte, works in binary 1 = True, 0 = False    %d    
    printf("%d, %d,\n1 = True, 0 = False\n\n", t, f); 

    // Characters or strings

    char grades = 'F';             // Char, one character                                              %c
    char name[] = "Aike";          // Strings or list of characters                                  %s
    char numerito1 = 100;          // 1 byte (-128 to +127)                                           %d or %c
    signed char numerito2 = 100;   // 1 byte (-128 to +127) (really unnecessary, they're all signed already)
    unsigned char numerito3 = 255; // 1 byte (0 to +255)                                              %d or %c

    printf("Char with numbers according to ASCII, if I use \"%c\" a character is used according to ASCII, and \"%d\" will be a number\n\n");
    printf("This is a character\n%c\nASCII art according to table\n%d\nNormal number\n\n", numerito1, numerito1);

    printf("I am %d years old, my name is %s, the grade I have is %c, and without rounding it is %.2f\n\n\n\n\n", number, name, grades, number2); 
    
    /* %d is for integers
    (the type is specified, and then the variables that go in the print will be in order)
    There are no spaces to join strings with +
    For strings, it is not necessary to put the [], but it is necessary to put the %s for String
    */

    /* Other format specifiers (%)
    %.1 = Decimal precision              <- Number of decimals that will appear from a float
    %1 = minimum field width            <- white space after something )? $    1.00
    %- = Left align                     <-
    */

    // Constants <- unalterable variable

    const float pi = 3.14159;

    // ARITHMETIC

    /*
    + Addition
    - Subtraction
    * Multiplication
    % Modulo
    / Division
    ++ Increment
    -- Decrement 
    */

    int sum = 5; 
    sum++;
    int min = 2;
    min++;
    int operation = 5 - 2; 
    int division = 5 / (float) 2;   // You can do it this way. The remainder is not saved and there will be no display of a decimal if it is not FLOAT, it is with modulo
    float division1 = 5 / 2;        // You can do it this way

    printf("%d\n", operation);

    // The "arithmetic shortcut" works with all operators
    
    int x = 5;
    x = x + 1;
    // Alternatively
    x += 1;

    int z = 10;
    z = z + 2;
    // Alternatively 
    z += 2;

    return 0;
}
