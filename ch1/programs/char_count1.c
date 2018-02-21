/**
 * @file char_count1.c
 * @brief The C Programming Language - 2nd Edition,
 * Section 1.5.2 example
 */
#include <stdio.h>

/* Count characters in input; 1st version */
int main(int argc, char *argv[]) {
    long nc = 0;

    while(getchar() != EOF) {
        ++nc;
    }
    printf("\n%ld\n", nc);

    return 0;
}