/**
 * @file single_blank.c
 * @brief The C Programming Language - 2nd Edition,
 * Excercise 1-9
 */
#include <stdio.h>

/**
 * @brief Replace multiple blanks with a single one
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */
int main(int argc, char *argv[]) {
    int c, last;

    while((c = getchar()) != EOF) {
        if (c == ' ' && last == ' ') /* If double blank, do nothing */
            ;                    
        else
            putchar(c);
        last = c;
    }

    return 0;
}