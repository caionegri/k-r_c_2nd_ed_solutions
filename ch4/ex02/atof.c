/**
 * @brief The C Programming Language - 2nd Edition, Exercise 4-2.
 *
 * @file atof.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 16/03/2018
 * @see https://github.com/caionegri
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

double atof(char s[]);
int getLine(char s[], int lim);

/**
 * @brief Rudimentary calculator for testing function atof(...).
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    char line[MAXLINE] = {'\0'}; /* current input line */
    double sum = 0;

    while (getLine(line, MAXLINE) > 0) {
        printf("\t%e\n", sum += atof(line));
    }
    return 0;
}

/**
 * @brief Convert the string s to double.
 *
 * @param s
 * @return double
 */
double atof(char s[]) {
    double val = 0.0;
    int e = 0, power = 1;
    int sign = 1, e_sign = 1;
    int i = 0;

    for (; isspace(s[i]); i++) { /* skip white space */
        ;
    }
    sign = (s[i] == '-') ? -1 : 1; /* number sign */
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (; isdigit(s[i]); i++) { /* integer part */
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (; isdigit(s[i]); i++) { /* decimal part */
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    }
    e_sign = (s[i] == '-') ? -1 : 1; /* exponent sign */
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (; isdigit(s[i]); i++) { /* exponent part */
        e = 10 * e + (s[i] - '0');
    }
    return sign * val * pow(10, e_sign * e) / power;
}

/**
 * @brief Read a line and save into s, return length.
 *
 * @param s line
 * @param lim maximum line length
 * @return line lenght
 */
int getLine(char s[], int lim) {
    int c = '\0', i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}