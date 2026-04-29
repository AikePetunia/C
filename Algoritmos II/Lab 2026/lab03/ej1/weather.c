/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

// esta wea solo RECIBE el archivo, pero no está manipulado / formateado

/**
 * @brief reads weather mesureament from file line
 * @details
 * Weather file line must contain:
 * <int> <int> <int> <unsigned int> <unsigned int> <unsigned int>
 *
 * @param[in] file Opened file stream
 * @return Weather structure which contain read information from file
 */
// Weather weather_from_file(FILE* file);

Weather weather_from_file(FILE* file) {
    Weather weather;

    int res = fscanf(file, "%d, %d, %d %u %u %u \n",  &weather._average_temp, &weather._max_temp, &weather._min_temp, &weather._pressure, &weather._moisture, &weather._rainfall);
    // los otros 6 datos
    if (res != 6) exit(EXIT_FAILURE);
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}

/*
gcc -Wall -Wextra -pedantic -std=c99 -c weather_table.c weather.c main.c
gcc -Wall -Wextra -pedantic -std=c99 weather_table.o weather.o main.o -o weather
./weather ../input/weater_cordoba.in > weather_cordoba.out
*/