/**
 * @brief The C Programming Language - 2nd Edition, Exercise 3-3.
 *
 * @file expand.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 12/03/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100 /* maximum input line size */

void expand(const char s1[], char s2[]);
int getLine(char s[], int lim);

/**
 * @brief Test function expand(...).
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                    /* current line lenght */
    char line[MAXLINE] = {'\0'};    /* current input line */
    char lineExp[MAXLINE] = {'\0'}; /* current output line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        expand(line, lineExp);
        printf("%s", lineExp);
    }
    return 0;
}

/**
 * @brief Expand shorthand notations like a-z into the equivalent complete list
 * abc...xyz. Assume sequence is alphanumeric and @p s2 is big enough.
 *
 * @param s1 input string
 * @param s2 output string
 * @return @c void
 */
void expand(const char s1[], char s2[]) {
    int c = '\0';       /* current char */
    int c_start = '\0'; /* previous char OR starting char in short notation */
    int shorthand = 0;  /* 1 if shorthand notation detected, 0 if not */
    int i = 0, j = 0;

    for (; (c = s1[i]) != '\0'; i++) {
        if (shorthand) {
            if (isalnum(c)) {   /* short notation completed */
                if (c > c_start) {
                    while (c > c_start++) { /* expand forward */
                        s2[j++] = c_start;
                    }
                } else if (c < c_start) {
                    while (c < c_start--) { /* expand backward */
                        s2[j++] = c_start;
                    }
                }
            } else {            /* trailing '-' */
                s2[j++] = '-';
                s2[j++] = c;
            }
            shorthand = 0;
        } else {
            if (c == '-' && isalnum(c_start)) {
                /* not a leading '-', short notation started */
                shorthand = 1;
            } else {
                s2[j++] = c;
                c_start = c;
            }
        }
    }
    s2[j] = '\0';
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

    for (; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}