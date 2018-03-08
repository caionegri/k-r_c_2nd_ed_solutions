/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-9.
 * 
 * @file rightrot.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 08/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>
#include <limits.h>

#define X 0xDAB /* 1101 1010 1011 */

int bitcount(unsigned x);

/**
 * @brief Test function bitcount().
 * 
 * @param argc command line argument count
 * @param argv command line argument vector 
 * @return zero 
 */
int main(int argc, char *argv[]) {

    printf("X     : %08X\n", X);
    printf("result: %8d\n", bitcount(X));

    return 0;  
}

/**
 * @brief Count 1 bits in @p x.
 * 
 * @param x input value
 * @return number of 1 bits 
 */
int bitcount(unsigned x) {
    int b = 0;

    for(; x != 0; x &= x - 1)
        b++;
    
    return b;    
}