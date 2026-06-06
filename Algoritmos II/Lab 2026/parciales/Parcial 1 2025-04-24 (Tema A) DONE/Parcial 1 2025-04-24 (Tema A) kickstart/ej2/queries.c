/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Total de lluvias de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_rainfall(WeatherTable a, int year) {
  // recorro los meses del año dado, acumulado el rainfaill
  int month = 0;
  int day = 0;
  int max_rainfall_year = 0;
  // recordar que los arreglos es desde la posicon 0, pero los meses y dias en 1. 
  while (month < MONTHS) {
    day = 0;
    while (day < DAYS)
    {
      max_rainfall_year += a[year - FST_YEAR][month][day]._rainfall;
      day++;
    }
    month++;
  }

  return max_rainfall_year;
}


/*
gcc -Wall -Wextra -pedantic -std=c99 weather.c weather_table.c queries.c tests.c -o tests 
./tests 
*/