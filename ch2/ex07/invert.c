/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-7.
 * 
 * @file invert.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 07/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define X 0xDEADBEEF
#define P 11
#define N 8

unsigned invert(unsigned x, int p, int n);

/**
 * @brief Test function invert().
 * 
 * @param argc command line argument count
 * @param argv command line argument vector 
 * @return zero 
 */
int main(int argc, char *argv[]) {

    printf("X     : %08X\n", X);
    printf("P     : %d\n", P);
    printf("N     : %d\n", N);    

    printf("result: %08X\n", invert(X, P, N));

    return 0;  
}

/**
 * @brief Invert @p n bits in @p x beginning position @p p and return.
 * 
 * @param x input value
 * @param p initial position
 * @param n number of bits
 * @return modified input 
 */
unsigned invert(unsigned x, int p, int n) {
    int xi = 0, mask = 0;

    /* mask off all but n bits from position p 
    eg.: 00001110 , p = 3, n = 3*/
    mask = ~(~0 << (p+1)) & (~0 << (p+1-n));
    /* invert x and apply mask
    eg.: 0000yyy0, y = ~x */
    xi = ~x & mask;
    /* apply inverted mask to non inverted x 
    eg.: xxxx000x */
    x = x & ~mask;
    
    return x | xi;  /* xxxxyyyx */     
}