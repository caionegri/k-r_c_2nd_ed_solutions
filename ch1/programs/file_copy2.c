/**
 * @file file_copy2.c
 * @brief The C Programming Language - 2nd Edition,
 * Section 1.5.1 example
 */
#include <stdio.h>

/* Copy input to output; 2nd version. */
int main(int argc, char *argv[]) {
    int c;

    printf("EOF = %d\n", EOF);  /* EOF is a const. defined in stdio.h */
    while ((c = getchar()) != EOF) { 
        putchar(c);
    }
    
    return 0;
}