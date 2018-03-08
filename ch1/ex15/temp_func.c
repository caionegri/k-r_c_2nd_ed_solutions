/**
 * @brief The C Programming Language - 2nd Edition, Exercise 1-15.
 *
 * @file temp_func.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 14/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define LOWER 0     // lower temperature limit
#define UPPER 300   // upper limit
#define STEP 20     // step size

float fahrToCels(int fahr);

/**
 * @brief Print Fahrenheit-Celsius table.
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */
int main(int argc, char *argv[]) {
    int fahr;
    
    printf("Fahr Celcius\n");  
    for(fahr = LOWER; fahr <= UPPER;  fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, fahrToCels(fahr));
    }
}

/**
 * @brief Convert temperature in Fahrenheit to Celcius.
 * 
 * @param fahr temperature in Fahrenheit
 * @return temperature in Celcius 
 */
float fahrToCels(int fahr) {
    return (5.0 / 9.0 * (fahr - 32));
}