/**
 * @file precedence.c
 * @brief The C Programming Language - 2nd Edition,
 * Exercise 1-6
 * @author Caio A N Rocha
 * @date 14 Feb 2018
 */
#include <stdio.h>

/**
 * @brief Verify precedence between 
 * relational operations (==, !=, >, >=, <, <=) and assignment (=).
 * If precedence is higher for relational operations, output must
 * only contain ones and zeros.
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */
int main(int argc, char *argv[]) {
    int c;

    while (c = getchar() != EOF) {  // Warning: endless loop
        printf("%d", c);
    }
    
    return 0;
}