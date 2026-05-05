/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

Weather weather_from_file(FILE* file)
{
    Weather weather;

    int res = fscanf(file, " %d %d %d %u %u %u ", &weather._average_temp, &weather._max_temp, &weather._min_temp, &weather._pressure, &weather._moisture, &weather._rainfall);
    if (res != 6) {
        fprintf(stderr, "Invalid table.\n");
        exit(EXIT_FAILURE);
    }

    return weather;
}
