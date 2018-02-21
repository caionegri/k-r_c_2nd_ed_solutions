/**
 * @file cels_fahr.c
 * @brief The C Programming Language - 2nd Edition,
 * Section 1.3 example
 */
#include <stdio.h>

#define LOWER 0     /* lower temperature limit */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */

/* print Fahrenheit-Celsius table */
main() {
    int fahr;
    
    for(fahr = LOWER; fahr <= UPPER;  fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0*(fahr-32)));
}