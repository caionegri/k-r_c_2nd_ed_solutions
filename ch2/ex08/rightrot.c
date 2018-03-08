/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-8.
 * 
 * @file rightrot.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 08/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>
#include <limits.h>

#define X 0xDEADBEEF
#define N 16

unsigned rightrot(unsigned x, int n);

/**
 * @brief Test function rightrot().
 * 
 * @param argc command line argument count
 * @param argv command line argument vector 
 * @return zero 
 */
int main(int argc, char *argv[]) {

    printf("X     : %08X\n", X);
    printf("N     : %d\n", N);    
    printf("result: %08X\n", rightrot(X, N));

    return 0;  
}
/**
 * @brief Return the value in @p x rotated to the right by @p n bit positions.
 * 
 * @param x input value
 * @param n rotation magnitude in bits
 * @return rotated input 
 */
unsigned rightrot(unsigned x, int n) {
    unsigned xr = 0;    

    for(; n > 0; n--) {
        xr = x & ~(~0 << 1);    /* rightmost digit of x */
        x = x >> 1;
        /* bitwise OR xr shifted to the leftmost position - that is, shifted 
        left nbits-1 - to x */
        x |= xr << (sizeof(xr)*CHAR_BIT - 1);
    }
    
    return x;    
}