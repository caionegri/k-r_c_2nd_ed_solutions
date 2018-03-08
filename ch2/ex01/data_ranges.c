/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-1.
 * 
 * @file data_ranges.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 27/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>
/* defines constants with the limits of fundamental integral types for the
specific system and compiler implementation used. */
#include <limits.h> 

/**
 * @brief Print data type ranges.
 * 
 * @param argc command line argument count
 * @param argv command line argument vector 
 * @return zero 
 */
int main(int argc, char *argv[]) {
    printf("Data type ranges\n");
    printf("signed char:    %d\t\tto\t%d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char:  %u\t\tto\t%u\n", 0, UCHAR_MAX);
    printf("signed int:     %d\tto\t%d\n", INT_MIN, INT_MAX);
    printf("unsigned int:   %u\t\tto\t%u\n", 0, UINT_MAX);
    printf("signed short:   %d\t\tto\t%d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %u\t\tto\t%u\n", 0, USHRT_MAX);

    return 0;  
}