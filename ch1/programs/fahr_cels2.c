/**
 * @file cels_fahr.c
 * @brief The C Programming Language - 2nd Edition, Chapter 1 example
 */
#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */
main() {
    float fahr, cels;
    float lower, upper, step;

    lower = 0;      /* lower temperature limit */
    upper = 300;    /* upper limit */
    step = 20;       /* step size */

    fahr = lower;
    printf("Fahr Cels\n");
    while(fahr <= upper) {
        cels = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, cels);
        fahr = fahr + step;
    }
}