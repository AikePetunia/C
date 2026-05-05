/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/
#include <limits.h>
#include "queries.h"

/**
 * @brief Dado un año, calcula para cada mes de ese año la máxima precipitación
 * en un día.
 *
 * @param a Tabla de datos climáticos
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016)
 * @param output Arreglo de salida
 */
void max_daily_rainfall(WeatherTable a, int year, int output[MONTHS]) {

  // para cada mes de un año dado, dar la precipitacion
  int day = 0;
  int month = 0;
  int max_daily_in_month = 0;
  int newMax = -9999; // neutro para poder encontrar >
  // tengo que recorrer todos los dias de un mes.
  while (month < MONTHS) {
    day = 0;
    max_daily_in_month = 0;
    while (day < DAYS)
    {
      // printf("date: %d/%d/%d \n", year - FST_YEAR, month, day);
      newMax = a[year - FST_YEAR][month][day]._rainfall;
      if (newMax > max_daily_in_month)
      {
        max_daily_in_month = a[year - FST_YEAR][month][day]._rainfall;
      }
      day++;
    }

    printf("max daily stuff %d on month %d \n", max_daily_in_month, month);
    output[month] = max_daily_in_month;
    month++;
  }
}
/*
gcc -Wall -Wextra -pedantic -std=c99 weather.c weather_table.c queries.c tests.c -o tests 
./tests
*/