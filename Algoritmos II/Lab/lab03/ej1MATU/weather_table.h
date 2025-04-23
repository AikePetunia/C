/*
  @file weather_table.h
  @brief defines table helpers methods. These methods operates over multidimensional (year, month, day) array of weather
*/
#ifndef _TABLE_HELPERS_H
#define _TABLE_HELPERS_H

#include <stdbool.h>
#include "weather.h"

#define FST_YEAR 1980
#define LST_YEAR 2016
#define YEARS 37

typedef enum {january, february, march, april, may, june, july, august, september, october, november, december} month_t;

#define MONTHS 12

#define DAYS 28

typedef Weather WeatherTable [YEARS][MONTHS][DAYS];

/**
 * @brief Write the content of the table 'a' into stdout.
 * @param[in] a table to dump in stdout
 */
void table_dump(WeatherTable a);


/**
 * @brief reads an table of weather information from file
 * @details
 *
 *  Each element is read from the file located at 'filepath'.
 *  The file must exist in disk and must have its contents in a sequence of
 *  lines, each with the following format:
 *
 *   <year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>
 *
 *   Those elements are copied into the multidimensional table 'a'.
 *
 * @param a table which will contain read file
 * @param filepath file with weather data
 */
void table_from_file(WeatherTable a, const char *filepath);

#endif // _TABLE_HELPERS_H
