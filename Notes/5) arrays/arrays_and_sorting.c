#include <stdio.h>
#include <string.h>

// Function to sort an array using bubble sort
void sort(int numbers[], int size) 
{
    for (int i = 0; i < size - 1; i++)   // iterates from first element to second-to-last
    {
        for (int j = 0; j < size - i - 1; j++) // iterates through the list up to the next number
        {
            if (numbers[j] > numbers[j+1]) 
            { // if numbers[j] > numbers[j+1] (greater than the next one, will swap them using a temporary variable)
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            } // analyzes if the next number is less than "the first" to sort them from smallest to largest
        }
    }
}

// Function to print array elements
void printNumbers(int numbers[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d\n", numbers[i]);
    }
}

int main() {
    // ARRAYS
    // An array can store multiple values of the same type.

    double prices[] = {5.0, 3.1, 10.23, 20.0};

    printf("%lf\n", prices[0]);  // Array positions start at 0. Use [] to select an item.
    
    double prices1[5];  // You can define an array without initializing values, indicating the size.
    
    prices1[2] = 3.2;
    prices1[4] = 1.2;  // Index correction. Indices range from 0 to 4 in this case.
    prices1[1] = 3.4;

    // How to print all items in an array.

    int precios[] = {2, 3, 45, 14, 4, 25, 66, 31, 45, 24, 4};

    // Loop correction: index should start at 0 and use < instead of <=.
    for (int i = 0; i < sizeof(precios)/sizeof(precios[0]); i++) {
        printf("$%d\n", precios[i]);
    }

    // 2D ARRAYS: each element is an array, useful for tables or matrices.
    
    int numbers2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 3 (columns) is the number of elements in each array, 2 (rows) is the number of arrays.
    
    int number3[2][3];
    int rows = sizeof(number3)/sizeof(number3[0]);      // Number of rows.
    int columns = sizeof(number3[0])/sizeof(number3[0][0]);  // Number of columns.

    number3[0][0] = 1;   // First row, first column.
    number3[0][1] = 2;   // First row, second column.
    number3[0][2] = 3;   // First row, third column.
    number3[1][0] = 4;   // Second row, first column.
    number3[1][1] = 5;   // Second row, second column.
    number3[1][2] = 4;   // Second row, third column.

    // Print the elements of the 2D array.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", number3[i][j]);
        }
        printf("\n");
    }

    // Array of strings

    char cars[][10] = {"Mustang", "Corvette", "Camaro"};  // the second [] is the number of characters
    // char cars[0] = "Tesla";  // can't do this unless... we import #include <string.h>

    strcpy(cars[0], "Tesla");

    for (int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++)  // 3 divided by 1
    {
        printf("%s\n", cars[i]);
    }

    // Variable swap

    char x[15] = "lemon";
    char y[15] = "lime";
    char temp[15];

    strcpy(temp, x);        // COPY FROM x TO temp
    strcpy(x, y);           // COPY FROM y TO x     [15] is necessary so x doesn't end up empty
    strcpy(y, temp);        // COPY FROM temp TO y

    // It's like the transitive property in discrete mathematics

    // Sorting a list

    int crazyNumbers[] = {1, 34, 4, 12, 2, 5, 56, 2, 2233, 42, 67};
    int size = sizeof(crazyNumbers)/sizeof(crazyNumbers[0]);

    printf("Array before sorting:\n");
    printNumbers(crazyNumbers, size);

    sort(crazyNumbers, size);

    printf("Array after sorting:\n");
    printNumbers(crazyNumbers, size);

    return 0;
}
