/**
 * @file fahr_cels.c
 * @brief The C Programming Language - 2nd Edition, 
 * Exercise 1-5
 * @author Caio A N Rocha
 * @date 14 Feb 2018
 */
#include <stdio.h>

#define LOWER 0     /* lower temperature limit */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */

/**
 * @brief Print Fahrenheit-Celsius table
 * for fahr = 300, 280, ...,0 
 */
main() {
    int fahr;
    
    printf("Fahr Cels\n");  
    for(fahr = UPPER; fahr >= LOWER;  fahr = fahr - STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0*(fahr-32)));
}