/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-6.
 * 
 * @file setbits.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 06/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define X 0xDEADBEEF
#define Y 0x99999999
#define P 11
#define N 8

unsigned setbits(unsigned x, int p, int n, unsigned y);

/**
 * @brief Test function setbits().
 * 
 * @param argc command line argument count
 * @param argv command line argument vector 
 * @return zero 
 */
int main(int argc, char *argv[]) {

    printf("X     : %08X\n", X);
    printf("Y     : %08X\n", Y);
    printf("P     : %d\n", P);
    printf("N     : %d\n", N);    

    printf("result: %08X\n", setbits(X, P, N, Y));

    return 0;  
}

/**
 * @brief Replace @p n bits that begin at position @p p in @p x with the
 * rightmost @p n bits of @p y.
 * 
 * @param x base value
 * @param p initial position
 * @param n number of bits
 * @param y value to be inserted
 * @return base value with bits set
 */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    /* shift y (n-1)th bit to position p and mask off the bits after p */
    y = (y << (p+1-n)) & ~(~0 << (p+1));
    /* mask off n bits in x from position p */
    x &= (~0 << (p+1)) | ~(~0 << (p+1-n));

    return x | y;     
}