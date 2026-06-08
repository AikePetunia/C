/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

Weather weather_from_file(FILE* file)
{
    Weather weather;
    int averageTemp = 0;
    int minTemp = 0;
    int maxTemp = 0;
    unsigned int pressure = 0;
    unsigned int moisture = 0;
    unsigned int rainfall = 0;
    int res = fscanf(file, " %d %d %d %u %u %u \n", &averageTemp, &maxTemp, &minTemp, &pressure, &moisture, &rainfall);
    printf("res en weather_from_file %d \n", res);

    if (res != 6)
    {
      printf("no suficiente res coso %d \n", res);
      exit(EXIT_FAILURE);
    }

    weather._average_temp = averageTemp;
    weather._max_temp = maxTemp;
    weather._min_temp = minTemp;
    weather._moisture = moisture;
    weather._pressure = pressure;
    weather._rainfall = rainfall;

    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
