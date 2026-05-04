/*
  @file weather_table.c
  @brief Weather table implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather_table.h"

/**
 * @brief reads a table of weather information from file
 * @details
 *
 *  Each element is read from the file located at 'filepath'.
 *  The file must exist in disk and must have its contents in a sequence of
 *  lines, each with the following format:
 *
 *   <year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>
 *
 *   Those elements are copied into the multidimensional table 'a'.
 *
 * @param a table which will contain read file
 * @param filepath file with weather data
 */
void table_from_file(WeatherTable a, const char *filepath) {
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int k_year = 0u;
    unsigned int k_month = 0u;
    unsigned int k_day = 0u;
    while (!feof(file)) {
        int res = fscanf(file, " %u %u %u ", &k_year, &k_month, &k_day);
        if (res != 3) {
            fprintf(stderr, "Invalid table.\n");
            exit(EXIT_FAILURE);
        }

        Weather weather = weather_from_file(file);

        a[k_year-FST_YEAR][k_month-1][k_day-1] = weather;
    }

    fclose(file);
}
