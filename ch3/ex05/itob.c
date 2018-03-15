/**
 * @brief The C Programming Language - 2nd Edition, Exercise 3-5.
 *
 * @file itob.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 14/03/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXLINE 100 /* maximum line size */
#define NUM INT_MIN
#define BASE 16

void itob(int n, int base, char s[]);
void reverse(char s[]);

/**
 * @brief Test function itob(...).
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int num = NUM;
    int base = BASE;
    int len = 0;                 /* current line lenght */
    char line[MAXLINE] = {'\0'}; /* current input line */

    itob(num, base, line);
    printf("%d[base 10]: %s[base %d]\n", num, line, base);

    return 0;
}

/**
 * @brief Convert digits in @p n to characters in @p
 *
 * @param n @c int
 * @param base @c int
 * @param s output string
 */
void itob(int n, int base, char s[]) {
    int i = 0;
    unsigned n_u = n;

if (n == INT_MIN) {                 /* prevent overflow */
        n_u = (unsigned)INT_MAX + 1;
    } else if (n < 0) {
        n = -n;                     /* make n positive */
        n_u = n;
    }
    do {                            /* generate digits in reverse order */
        s[i++] = n_u % base + '0';  /* get next digit */
    } while ((n_u /= base) > 0);    /* delete it */
    if (n < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

/**
 * @brief Reverse input string and save result.
 *
 * @param s string
 * @return @c void
 */
void reverse(char s[]) {
    int end = strlen(s) - 1;
    char aux = '\0';

    for (int i = 0; i < end; end--) {
        if (s[end] != '\r' && s[end] != '\n' && s[end] != EOF) {
            aux = s[end];
            s[end] = s[i];
            s[i++] = aux;
        }
    }
}