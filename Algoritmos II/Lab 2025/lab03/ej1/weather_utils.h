// es a traves de los headers que se pasan parametros
#ifndef _TABLE_UTILS_H

#include "weather_table.h"

int min_history(WeatherTable a);

void max_year_temperature(WeatherTable a, int output[YEARS]);

void max_rainfall(WeatherTable a, int output[YEARS]);

#endif