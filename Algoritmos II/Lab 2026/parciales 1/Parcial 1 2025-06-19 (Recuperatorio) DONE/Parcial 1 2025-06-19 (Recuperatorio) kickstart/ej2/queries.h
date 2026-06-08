/*
  @file queries.h
  @brief Consultas sobre tablas de datos climáticos.
*/
#ifndef _QUERIES_H
#define _QUERIES_H

#include "weather_table.h"

/**
 * @brief Dado un año, calcula para cada mes de ese año la máxima precipitación
 * en un día.
 *
 * @param a Tabla de datos climáticos
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016)
 * @param output Arreglo de salida
 */
void max_daily_rainfall(WeatherTable a, int year, int output[MONTHS]);

#endif // _QUERIES_H
