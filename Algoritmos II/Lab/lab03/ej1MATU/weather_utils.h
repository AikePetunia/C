#ifndef _TABLE_UTILS_H

#include "weather_table.h"

int temp_min(WeatherTable a);

void temp_max_anual(WeatherTable a, int output[YEARS]);

void mes_precip_max_anual(WeatherTable a, int output[YEARS]);

#endif