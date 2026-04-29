/*
    @file weather_utils.h
    @brief defines utils for printing stats 
*/

#ifndef _TABLE_UTILS_H
#define _TABLE_UTILS_H

#include "weather_table.h"
#include <stdbool.h>
#include "weather.h"

#define HIGH_VALUE 999999 // "neutro/ancla" para buscar minimo
#define LOW_VALUE -99999  // "neutro/ancla" para buscar maximo

int h_min_temp(WeatherTable a);

void year_max_temp(WeatherTable a, int output[YEARS]);

void max_rainfall_year(WeatherTable a, int output[YEARS]);

#endif