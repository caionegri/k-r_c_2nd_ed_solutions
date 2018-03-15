/**
 * @brief The C Programming Language - 2nd Edition, Exercise 3-6.
 *
 * @file itoa.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 13/03/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

#define MAXLINE 100 /* maximum line size */
#define NUM INT_MIN
#define WIDTH 16

void itoa(int n, int width, char s[]);
void reverse(char s[]);

/**
 * @brief Test function itoa(...).
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int num = NUM;
    int width = WIDTH;
    int len = 0;                 /* current line lenght */
    char line[MAXLINE] = {'\0'}; /* current input line */

    itoa(num, width, line);
    printf("%d: %s\n", num, line);

    return 0;
}

/**
 * @brief Convert @p n to characters in @p s.
 *
 * @param n @c int
 * @param width minimum width
 * @param s output string
 */
void itoa(int n, int width, char s[]) {
    int i = 0;
    unsigned n_u = n;

    if (n == INT_MIN) { /* prevent overflow */
        n_u = (unsigned)INT_MAX + 1;
    } else if (n < 0) {
        n = -n; /* make n positive */
        n_u = n;
    }
    do {                         /* generate digits in reverse order */
        s[i++] = n_u % 10 + '0'; /* get next digit */
        width--;
    } while ((n_u /= 10) > 0);                  /* delete it */
    for (; n_u < pow(10, width) - 1; width--) { /* pad with zeros */
        s[i++] = '0';
    }
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