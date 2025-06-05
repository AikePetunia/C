#include <stdio.h>
#include <string.h>

// Player structure definition
struct Player 
{
    char name[12];
    int score;
};

// User structure with typedef
typedef struct  
{
    char name[25];
    char password[12];
    int id;
} User; // In typedef structs, the name comes at the end

// Student structure
struct student
{
    char sName[12];
    float gpa;
};

// Days of the week enum
enum Day {
    SUNDAY,     // hover over any variable to see its value
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main() {
    // struct = collection of variables of different types in a single memory block
    // group different variables (possibly of different types) under the same name
    // similar to "CLASSES" in other languages, but without methods
    // in C, structures cannot have methods, only data
    
    struct Player player1;
    struct Player player2;

    strcpy(player1.name, "Vicky");       // the . is a member access operator
    player1.score = 4;

    strcpy(player2.name, "Aike");
    player2.score = 6;

    printf("%d ", player1.score);
    printf("%s\n", player1.name);

    printf("%d ", player2.score);
    printf("%s\n", player2.name);

    // typedef = Basically assigns a variable with a certain number of bytes for reuse
    // instead of writing char user1[25] = "X" multiple times, we can do typedef char user[25]; and then for each user do "user user1 = "x"
    // typedef + struct = good practice

    User user1 = {"Ana", "passwor3d123", 1231421};
    User user2 = {"Vick", "1password123", 12314111};

    printf("%s\n", user1.name);
    printf("PASS: %s\n", user1.password);
    printf("ID: %d\n", user1.id);
    printf("\n");

    printf("%s\n", user2.name);
    printf("PASS: %s\n", user2.password);
    printf("ID: %d\n", user2.id);
    printf("\n");

    // array of structs

    struct student student1 = {"Manuel", 3.0};
    struct student student2 = {"Aja", 5.0};
    struct student student3 = {"Ajo", 2.0};

    struct student students[] = {student1, student2, student3}; // array of structs

    for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++)
    {
        printf("%-12s\n", students[i].sName);
        printf("%.2f\n", students[i].gpa);
    }

    // enum = can be declared inside or outside main() for better readability. "Enumerated in order".
    // An enum (short for "enumeration") is a data type in C that allows defining a set of named constants
    // Integer Values: Internally, enum identifiers are represented as integer values.
    // Explicit Values: You can assign explicit values to some or all identifiers.
    // they are "interpreted as ints"

    enum Day today = FRIDAY;

    printf("%d", today);

    if (today == SUNDAY || today == SATURDAY) // instead of using numbers like today == 7, use today == SATURDAY for better readability
    {
        printf("\nIt's the weekend");
    } else {
        printf("\nIt's not the weekend");
    }

    /*
    An array is a data structure that allows storing a collection of elements of the same type.
    In general, an array is declared as follows:
    
    type arrayName[size];
    
    where 'type' indicates the type of elements in the array and 'size' is the number of elements the array can contain.
    For example:
    
    int numbers[4];  // declares an array of 4 elements of integer type.
    bool flags[2];   // declares an array of 2 elements of boolean type.
    
    The number of elements in an array is equal to the value specified in 'size'.
    It is possible to declare empty arrays, although it is not common in C.
    
    The first index of the array need not be 0, but in C, arrays always start at index 0.
    An element of an array is referenced by its index, for example:
    
    numbers[0] = 10; // assigns the value 10 to the first element of the 'numbers' array.
    
    We will say that a value 'v' is in the array if some element of the array is equal to 'v'.
    
    It is possible to use quantified variables in relation to arrays.
    For example, if we have an array of integers 'a' of size 'n', we can find the maximum element of the array with:
    
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    */

    return 0;
}
