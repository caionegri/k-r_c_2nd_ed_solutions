/**
 * @file char_count2.c
 * @brief The C Programming Language - 2nd Edition,
 * Section 1.5.2 example
 */
#include <stdio.h>

/* Count characters in input; 2nd version */
int main(int argc, char *argv[]) {
    double nc;

    for(nc = 0; getchar() != EOF; ++nc)
        ;
    printf("\n%.0f\n", nc);

    return 0;
}