#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include "weather_table.h"

int minor_historic_temp(WeatherTable a);

// devulve el año con mayor temperatura promedio
void max_temp_year(WeatherTable a, int output[YEARS]);

// devuelve el mes con mayor cantidad de rainfall en el año
void max_monthly_rainfall(WeatherTable , int output[YEARS]);

#endif