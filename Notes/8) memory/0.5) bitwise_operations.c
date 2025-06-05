#include <stdio.h>

// Function to print a number in binary format
void print_binary(int num) {
    printf("Binary representation of %d: ", num);
    for (int i = 31; i >= 0; i--) {
        // Test each bit using bitwise AND with a bit mask
        printf("%d", (num & (1 << i)) ? 1 : 0);
        if (i % 8 == 0) printf(" "); // Add space for readability
    }
    printf("\n");
}

int main() {
    // BITWISE OPERATORS = Special operators for bit-level programming
    printf("=== BITWISE OPERATIONS EXAMPLES ===\n\n");

    /*
     * & (AND): Sets each bit to 1 if both bits are 1
     * | (OR): Sets each bit to 1 if at least one bit is 1
     * ^ (XOR): Sets each bit to 1 if exactly one bit is 1
     * ~ (NOT): Inverts all bits (ones complement)
     * << (LEFT SHIFT): Shifts bits left, filling with zeros
     * >> (RIGHT SHIFT): Shifts bits right (sign depends on number)
     */
    
    int x = 6;  // 6 = 0000 0110 in binary
    int y = 12; // 12 = 0000 1100 in binary
    int z = 0;  // Result variable

    printf("Values in decimal and binary:\n");
    printf("x = %d\n", x);
    print_binary(x);
    printf("y = %d\n", y);
    print_binary(y);
    printf("\n");

    // Bitwise AND (&): 1 if both bits are 1, otherwise 0
    z = x & y;  // 6 & 12 = 0000 0110 & 0000 1100 = 0000 0100 = 4
    printf("x & y (AND): %d\n", z);
    print_binary(z);
    printf("Explanation: Sets bits that are 1 in BOTH operands\n\n");
    
    // Bitwise OR (|): 1 if at least one bit is 1, otherwise 0
    z = x | y;  // 6 | 12 = 0000 0110 | 0000 1100 = 0000 1110 = 14
    printf("x | y (OR): %d\n", z);
    print_binary(z);
    printf("Explanation: Sets bits that are 1 in EITHER operand\n\n");

    // Bitwise XOR (^): 1 if exactly one bit is 1, otherwise 0
    z = x ^ y;  // 6 ^ 12 = 0000 0110 ^ 0000 1100 = 0000 1010 = 10
    printf("x ^ y (XOR): %d\n", z);
    print_binary(z);
    printf("Explanation: Sets bits that are 1 in EXACTLY ONE operand\n\n");

    // Bitwise NOT (~): Inverts all bits
    z = ~x;  // ~6 = ~0000 0110 = 1111 1001 = -7 (in two's complement)
    printf("~x (NOT): %d\n", z);
    print_binary(z);
    printf("Explanation: Inverts ALL bits (ones complement)\n\n");

    // Bitwise right shift (>>): Shifts bits to the right
    z = x >> 1; // 6 >> 1 = 0000 0110 >> 1 = 0000 0011 = 3
    printf("x >> 1 (Right shift): %d\n", z);
    print_binary(z);
    printf("Explanation: Shifts bits right (divides by 2^n)\n\n");

    // Bitwise left shift (<<): Shifts bits to the left
    z = x << 1; // 6 << 1 = 0000 0110 << 1 = 0000 1100 = 12
    printf("x << 1 (Left shift): %d\n", z);
    print_binary(z);
    printf("Explanation: Shifts bits left (multiplies by 2^n)\n\n");

    // PRACTICAL APPLICATIONS OF BITWISE OPERATIONS:
    printf("=== PRACTICAL APPLICATIONS ===\n\n");

    // 1. Setting a bit
    int num = 0;          // 0000 0000
    int bit_position = 3; // 4th bit from right
    num = num | (1 << bit_position); // Set the bit at position 3
    printf("Setting bit %d: %d\n", bit_position, num);
    print_binary(num);

    // 2. Clearing a bit
    num = 15;             // 0000 1111
    bit_position = 2;     // 3rd bit from right
    num = num & ~(1 << bit_position); // Clear bit at position 2
    printf("Clearing bit %d: %d\n", bit_position, num);
    print_binary(num);

    // 3. Toggling a bit
    num = 10;             // 0000 1010
    bit_position = 1;     // 2nd bit from right
    num = num ^ (1 << bit_position); // Toggle bit at position 1
    printf("Toggling bit %d: %d\n", bit_position, num);
    print_binary(num);

    // 4. Checking if a bit is set
    num = 6;              // 0000 0110
    bit_position = 2;     // 3rd bit from right
    int is_set = (num & (1 << bit_position)) != 0;
    printf("Is bit %d set in %d? %s\n", bit_position, num, is_set ? "Yes" : "No");

    return 0;
}
