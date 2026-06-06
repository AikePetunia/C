/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    int *p = NULL;
    p = &x;
    *p = 9;

    int *p2 = NULL;
    p2 = &a[1];
    *p2 = 42;


    m.age = 100;
    /* 
       Al finalizar la ejecución las variables d
       deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42
    */

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}


/*
gcc -Wall -Wextra -pedantic -std=c99 -c weather_table.c weather_utils.c weather.c main.c
gcc -Wall -Wextra -pedantic -std=c99 weather_table.o weather_utils.o weather.o main.o -o weather
./weather ../input/weater_cordoba.in > weather_cordoba.out
*/