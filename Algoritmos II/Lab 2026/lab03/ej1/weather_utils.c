
#include "weather_utils.h"

// temperatura minima historica
int h_min_temp(WeatherTable a) {
    int min_temp = HIGH_VALUE;

    unsigned int day = 0;
    while (day < DAYS) {
    unsigned int month = 0;
        while(month < MONTHS) {
    unsigned int year = 0; 
            while (year < YEARS) {
                if (a[year][month][day]._min_temp < min_temp) {
                    min_temp = a[year][month][day]._min_temp;
                }
                year++;
            }
            month++;
        }
        day++;
    }

    return min_temp;
}

void year_max_temp(WeatherTable a, int output[YEARS]) { 
    unsigned int year = 0; 
    while (year < YEARS) {
        int max_temp_year = LOW_VALUE;
        unsigned int month = 0;
        while(month < MONTHS) {
            unsigned int day = 0;
            while (day < DAYS) {
                if (a[year][month][day]._max_temp > max_temp_year) {
                    max_temp_year = a[year][month][day]._max_temp;
                }
                day++;
            }
            month++;
        }
        output[year] = max_temp_year;
        year++;
    }
}

void max_rainfall_year(WeatherTable a, int output[YEARS]) {
    unsigned int year = 0; 
    while (year < YEARS) {
        int max_year_rainfall = LOW_VALUE;
        unsigned int month = 0;
        while(month < MONTHS) {
            int month_rainfall = 0;
            unsigned int day = 0;
            while (day < DAYS) {
                month_rainfall += a[year][month][day]._rainfall;
                day++;
            }
            if (month_rainfall > max_year_rainfall) {
                max_year_rainfall = month_rainfall;
            }
            month++;
        }
        output[year] = max_year_rainfall;
        year++;
    }
}

/*
gcc -Wall -Wextra -pedantic -std=c99 -c weather_table.c weather_utils.c weather.c main.c
gcc -Wall -Wextra -pedantic -std=c99 weather_table.o weather_utils.o weather.o main.o -o weather
./weather ../input/weater_cordoba.in > weather_cordoba.out
*/

