#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
main() {
    int fahr, celcius;
    int lower, upper, step;

    lower = 0;      /* lower temperature limit */
    upper = 300;    /* upper limit */
    step = 20;       /* step size */

    fahr = lower;
    while(fahr <= upper) {
        celcius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celcius);
        fahr = fahr + step;
    }
}