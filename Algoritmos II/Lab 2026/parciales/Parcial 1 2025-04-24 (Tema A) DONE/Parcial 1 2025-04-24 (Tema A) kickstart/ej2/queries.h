/*
  @file queries.h
  @brief Consultas sobre tablas de datos climáticos.
*/
#ifndef _QUERIES_H
#define _QUERIES_H

#include "weather_table.h"

/**
 * @brief Total de lluvias de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_rainfall(WeatherTable a, int year);

#endif // _QUERIES_H
