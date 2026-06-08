#include "weather_table.h"

// devuelve la temperatura mas minima de todo el timepo
int minor_historic_temp(WeatherTable a) {
    int day = 0;
    int month = 0;
    int year = 0;
    int historic_min = 0;
    while (year < YEARS) {
        while(month < MONTHS) {
            while(day < DAYS) {
                if (historic_min < a[year][month][day]._min_temp) {
                    historic_min = a[year][month][day]._min_temp;
                }
                day++;
            }
            month++;
        }
        year++;
    }
    return historic_min;
}

// devulve el año con mayor temperatura promedio
void max_temp_year(WeatherTable a, int output[YEARS]) {

    int year = 0;
    while (year < YEARS) {
        int max_temp_year = 0;
        int month = 0;
        int day = 0;
        while (month < MONTHS) {
            while (day < DAYS) {
                if (max_temp_year < a[year][month][day]._max_temp) {
                    max_temp_year = a[year][month][day]._max_temp;
                }
                day++;
            }
            month++;
        }
        printf(" max temp on year %d is %d \n", year + FST_YEAR, max_temp_year);
        output[YEARS] = max_temp_year;
        year++;
    }
}

// devuelve el mes con mayor cantidad de rainfall en el año
void max_monthly_rainfall(WeatherTable a, int output[YEARS]) {
 
        int year = 0;
    while (year < YEARS) {
        int max_rainfall_on_year = 0;
        
        
        int month = 0;
        while (month < MONTHS) {
            int monthly_rainfall_on_year = 0;

            int day = 0;
            while (day < DAYS) {
                monthly_rainfall_on_year += a[year][month][day]._rainfall;
                day++;
            }

            if (monthly_rainfall_on_year >= max_rainfall_on_year) {
                max_rainfall_on_year = monthly_rainfall_on_year;
            }
            month++;
        }

        output[YEARS] = max_rainfall_on_year;
        printf("max rainfall on year %d is %d \n", year + FST_YEAR, max_rainfall_on_year);
        year++;
    }
}