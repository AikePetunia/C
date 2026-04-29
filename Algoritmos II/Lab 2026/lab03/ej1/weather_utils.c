
#include "weather_utils.h"

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

// temp maxima de cada año
void year_max_temp(WeatherTable a, int output[YEARS]) { 
    int max_temp_year = LOW_VALUE;

    unsigned int year = 0; 
    while (year < YEARS) {
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

/*
devuelve el mes con mayor precipitacion del año.
tenemos que acumular la precipitacion que hay por mes.
cuando se recorren todos los meses, ya deberia tener le maxima precipitacion de ese año.
y devolver la maxima precipitaicon de ese año.
*/
void max_rainfall_year(WeatherTable a, int output[YEARS]) {
    int max_year_rainfall = LOW_VALUE;
    
    unsigned int year = 0; 
    while (year < YEARS) {

        unsigned int month = 0;
        while(month < MONTHS) {
            int month_rainfall = 0;

            unsigned int day = 0;
            while (day < DAYS) {
                // sumamos el rainfall del mes
                month_rainfall += a[year][month][day]._rainfall;
                day++;
            }

            // pasado mes a mes, vamos a encontrar el mas alto
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

/* ? 
que dif hay entre las funciones tipo:
int main()
static int main()
void int main()
*/