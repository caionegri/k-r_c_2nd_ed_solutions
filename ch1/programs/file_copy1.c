/**
 * @file file_copy1.c
 * @brief The C Programming Language - 2nd Edition,
 * Section 1.5.1 example
 */
#include <stdio.h>

/* Copy input to output; 1st version. */
int main(int argc, char *argv[]) {
    int c;

    c = getchar();
    while (c != EOF) { /* EOF is a const. defined in stdio.h */
        putchar(c);
        c = getchar();
    }
    
    return 0;
}