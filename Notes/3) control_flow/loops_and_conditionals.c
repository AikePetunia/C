#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    printf("===== CONTROL FLOW STRUCTURES IN C =====\n");

    // ===== CONDITIONAL STATEMENTS =====
    printf("\n===== CONDITIONAL STATEMENTS =====\n");
    
    // IF statement - basic decision making
    int age;
    printf("\nWhat's your age?\n");
    scanf("%d", &age);

    if (age > 18) {
        printf("You are allowed to view this content\n");
    }
    else if (age == 18) {
        printf("You're in luck, you're just 18\n");
    }
    else if (age <= 0) {
        printf("You haven't been born yet\n");
    }
    else {
        printf("You're still too young\n");
    }

    // Nested if statements - if inside another if
    printf("\n===== NESTED IF EXAMPLE =====\n");
    int num = 15;
    
    if (num >= 0) {
        printf("%d is non-negative\n", num);
        
        if (num % 2 == 0) {
            printf("%d is even\n", num);
        } else {
            printf("%d is odd\n", num);
        }
        
        if (num % 3 == 0 && num % 5 == 0) {
            printf("%d is divisible by both 3 and 5\n", num);
        } else if (num % 3 == 0) {
            printf("%d is divisible by 3\n", num);
        } else if (num % 5 == 0) {
            printf("%d is divisible by 5\n", num);
        }
    } else {
        printf("%d is negative\n", num);
    }

    // SWITCH statements - multi-way decision
    // Used when comparing a variable against multiple values
    int grade;
    printf("\n===== SWITCH STATEMENT =====\n");
    printf("Enter the grade (1-10):");
    scanf("%d", &grade);

    switch (grade) {
        case 1: 
        case 2: 
        case 3:
            printf("You're struggling (Failed)\n");
            break;  // Break prevents fall-through to next case
        case 4:
        case 5:
            printf("You're passing but need improvement\n");
            break;
        case 6:
        case 7:
            printf("Good job\n");
            break;
        case 8:
        case 9:
            printf("Very good\n");
            break;
        case 10:
            printf("Excellent!!\n");
            break;
        default:  // Executed if no case matches
            printf("Invalid grade\n");
    }
    
    // Demonstrating switch with char
    printf("\nSwitch with character example:\n");
    char grade_letter = 'B';
    
    switch (grade_letter) {
        case 'A':
            printf("Excellent performance\n");
            break;
        case 'B':
            printf("Good performance\n");
            break;
        case 'C':
            printf("Average performance\n");
            break;
        case 'D':
            printf("Below average\n");
            break;
        case 'F':
            printf("Failed\n");
            break;
        default:
            printf("Invalid grade letter\n");
    }

    // ===== ITERATION STATEMENTS (LOOPS) =====
    
    // FOR LOOP - used when number of iterations is known
    printf("\n===== FOR LOOP =====\n");
    printf("Counting from 1 to 10:\n");
    for (int i = 1; i <= 10; i++) { // (initialization; condition; update)
        printf("%d ", i);
    }
    printf("\n");
    
    // FOR loop with multiple expressions
    printf("\nFOR loop with multiple expressions:\n");
    for (int i = 0, j = 10; i <= 10 && j >= 0; i++, j--) {
        printf("i = %d, j = %d\n", i, j);
    }

    // WHILE LOOP - used when iterations depend on a condition
    printf("\n===== WHILE LOOP =====\n");
    
    char name[25];
    printf("WHILE loop example - input validation\n");
    
    // Clearing input buffer
    while ((getchar()) != '\n');
    
    printf("What's your name? (minimum 3 characters)\n");
    fgets(name, 25, stdin);
    name[strlen(name) - 1] = '\0';  // Remove newline from fgets

    while (strlen(name) < 3) {
        printf("Name too short. Please enter at least 3 characters:\n");
        fgets(name, 25, stdin);
        name[strlen(name) - 1] = '\0';
    }

    printf("Hello %s!\n", name);

    // DO-WHILE LOOP - executes at least once before checking condition
    printf("\n===== DO-WHILE LOOP =====\n");
    printf("Sum positive numbers (enter 0 or negative to exit):\n");

    int number = 0;
    int sum = 0;

    do {
        printf("Enter a number: ");
        scanf("%d", &number);
        
        if (number > 0) {
            sum += number;
            printf("Running sum: %d\n", sum);
        }
    } while (number > 0);

    printf("Final sum: %d\n", sum);

    // NESTED LOOPS - loop inside another loop
    printf("\n===== NESTED LOOPS =====\n");

    int rows = 5;
    int columns = 5;
    char symbol = '*';

    printf("Pattern using nested loops:\n");
    
    // Creates a pattern like:
    // *
    // **
    // ***
    // ****
    // *****
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }

    // LOOP CONTROL STATEMENTS: continue & break
    printf("\n===== LOOP CONTROL: continue & break =====\n");
    
    printf("Numbers from 1 to 20 (skipping 13):\n");
    for (int i = 1; i <= 20; i++) {
        if (i == 13) {
            continue;  // SKIP number 13 and continue with next iteration
        }
        printf("%d ", i);
    }
    printf("\n");
    
    printf("\nPrinting numbers until reaching 13:\n");
    for (int i = 1; i <= 20; i++) {
        if (i == 13) {
            printf("\nFound 13! Breaking the loop.\n");
            break;  // EXIT loop completely when i is 13
        }
        printf("%d ", i);
    }
    
    // GOTO STATEMENT (generally discouraged but shown for completeness)
    printf("\n===== GOTO STATEMENT =====\n");
    printf("goto is generally discouraged but can be useful in specific cases like error handling:\n");
    
    int error_code = 2;
    
    if (error_code == 1) {
        goto error1;
    } else if (error_code == 2) {
        goto error2;
    }
    
    printf("This won't be printed if there's an error\n");
    goto end;  // Skip error handling if no error
    
error1:
    printf("Error 1: Input error\n");
    goto end;
    
error2:
    printf("Error 2: Processing error\n");
    
end:
    printf("Program completed with error code: %d\n", error_code);
    
    // INFINITE LOOPS AND HOW TO USE THEM SAFELY
    printf("\n===== INFINITE LOOPS =====\n");
    printf("Infinite loops can be useful with proper exit conditions:\n");
    
    /*
    // Example of a controlled infinite loop (commented out to avoid actually running it)
    int counter = 0;
    while (1) {  // Infinite loop
        counter++;
        printf("Iteration %d\n", counter);
        
        if (counter >= 5) {
            printf("Reached 5 iterations, exiting loop\n");
            break;  // Safe exit condition
        }
    }
    */
    printf("(Infinite loop example is commented out in the code)\n");
    
    return 0;
}
