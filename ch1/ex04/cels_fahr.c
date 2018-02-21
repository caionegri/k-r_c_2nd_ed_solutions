/**
 * @file cels_fahr.c
 * @brief The C Programming Language - 2nd Edition, Exercise 1-4
 * @author Caio A N Rocha
 * @date 14 Feb 2018 
 */
#include <stdio.h>

#define LOWER 0     /* lower temperature limit */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */

/**
 * @brief Print Celsius-Fahrenheit table
 */
main() {
    int cels;
    
    printf("Cels Fahr\n");  
    for(cels = LOWER; cels <= UPPER;  cels = cels + STEP) {
        printf("%3d %6.1f\n", cels, (9.0/5.0*cels+32));
    }
}