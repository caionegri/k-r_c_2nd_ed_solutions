/**
 * @brief The C Programming Language - 2nd Edition, Exercise 1-7.
 *
 * @file eof.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 14/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

/**
 * @brief Print the numeric value of EOF
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */
int main(int argc, char *argv[]) {
    printf("EOF is defined as %d in stdio.h", EOF);
    
    return 0;
}