/*
  @file weather.h
  @brief Defines weather mesuarement structure and methods
*/

#ifndef _WEATHER_H
#define _WEATHER_H
#include <stdio.h>

/** @brief Type used to represent a weather mesuarement.*/
typedef struct _weather
{
    int _average_temp;
    int _max_temp;
    int _min_temp;
    unsigned int _pressure;
    unsigned int _moisture;
    unsigned int _rainfall;
} Weather;

/**
 * @brief reads weather mesureament from file line
 * @details
 * Weather file line must contain:
 * <int> <int> <int> <unsigned int> <unsigned int> <unsigned int>
 *
 * @param[in] file Opened file stream
 * @return Weather structure which contain read information from file
 */
Weather weather_from_file(FILE* file);

#endif //_WEATHER_H
