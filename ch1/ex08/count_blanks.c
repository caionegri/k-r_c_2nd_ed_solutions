/**
 * @file count_blanks.c
 * @brief The C Programming Language - 2nd Edition,
 * Excercise 1-8
 */
#include <stdio.h>

/**
 * @brief Count lines, tabs and blanks in input
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */
int main(int argc, char *argv[]) {
    int c, nl, nt, nb = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++nb;
    }
        
    printf("Line count: %d\n", nl);
    printf("Tab count: %d\n", nt);
    printf("Blank count: %d\n", nb);

    return 0;
}