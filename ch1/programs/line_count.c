/**
 * @file line_count.c
 * @brief The C Programming Language - 2nd Edition,
 * Section 1.5.3 example
 */
#include <stdio.h>

/* Count lines in input */
int main(int argc, char *argv[]) {
    int c, nl = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
    }
        
    printf("Line count: %d\n", nl);

    return 0;
}