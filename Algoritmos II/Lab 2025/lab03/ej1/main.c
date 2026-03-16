/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create a table variable */
    WeatherTable table;

    /* parse the file to fill the table */
    table_from_file(table, filepath);

    int max_year_temperatur[YEARS];

    int rainfall_months[YEARS];

    printf("Menor temperatura mínima histórica: %g \n", min_history(table)/10.0);

    printf("Las temperaturas máximas de cada año fueron:\n[ ");
    max_year_temperature(table, max_year_temperatur);
    for (int i = 0; i < YEARS; i++) {
        printf("%g ",max_year_temperatur[i]/10.0);
    }
    printf("].\n");

    printf("Los meses con más precipitaciones de cada año son:\n[ ");
    max_rainfall(table, rainfall_months);
    for (int i = 0; i < YEARS; i++) {
        printf("%d ",rainfall_months[i]);
    }
    printf("].\n");

    /* show the table in the screen */
    //table_dump(table);

    return EXIT_SUCCESS;
}

/*
gcc -Wall -Wextra -pedantic -std=c99 weather_table.c weather_utils.c weather.c main.c
gcc -Wall -Wextra -pedantic -std=c99 weather_table.o weather_utils.o weather.o main.o -o weather
./weather ../input/weather_cordoba.in > weather_cordoba.out

*/