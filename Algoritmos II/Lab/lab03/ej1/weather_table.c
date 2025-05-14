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
 * @brief Write the content of the table 'a' into stdout.
 * @param[in] a table to dump in stdout
 */
void table_dump(WeatherTable a) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                // imprimir año, mes y día
                // stdout es la manera en la que es este output. Depende en donde se trabaje, aca sería un archivo.
                fprintf(stdout, "%u %u %u ", year + FST_YEAR, month + 1, day + 1);

                // imprimir datos para ese día
                weather_to_file(stdout, a[year][month][day]);

                // imprimir salto de línea
                fprintf(stdout, "\n");
            }
        }
    }
}

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

    file = fopen(filepath, "r"); // modo lectura de archivo
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int k_year = 0u; // declaracion de unsigned
    unsigned int k_month = 0u;
    unsigned int k_day = 0u;

    while (!feof(file)) {
        // lee las tres primeras lineas del arreglo multidimencional. Año, mes y día
        int res = fscanf(file, " %u %u %u ", &k_year, &k_month, &k_day); 
        fprintf(stderr, "%u/%u/%u \n", k_year, k_month, k_day); // printeamos en q año estamos viendo
        if (res != 3) { // si no son 3 numeros, dara error
            fprintf(stderr, "Invalid table.\n"); 
            exit(EXIT_FAILURE);
        }
        // Ir a la función 'weather_from_file' en weather.c
        Weather weather = weather_from_file(file);
        // se le resta estos numeros por que en el arreglo empiezan desde 0.
        // si no se hace, el arreglo empieza como a[1980][1][1]
        // si te da error al pasar los siguientes, es por que se tiene que completar weather.c 
        a[k_year - FST_YEAR][k_month - 1][k_day - 1] = weather;
        // se manejan 3 datos, luego 6 restantes de la linea
    }
    fclose(file);
}
