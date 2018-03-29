/**
 * @brief The C Programming Language - 2nd Edition, Exercise 4-1.
 *
 * @file strrindex.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 15/03/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

int getLine(char s[], int lim);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/**
 * @brief Find matching pattern in lines.
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    char line[MAXLINE] = {'\0'}; /* current input line */
    int index = 0;               /* index of match */
    int found = 0;

    while (getLine(line, MAXLINE) > 0) {
        if ((index = strrindex(line, pattern)) >= 0) {
            while (--index > 0) {
                printf(" ");
            }
            printf("^\n");

            found++;
        }
    }
    return found;
}

/**
 * @brief Find the pattern @p t in @p s and return the rightmost index.
 *
 * @param s string
 * @param t pattern
 * @return rightmost index
 * @return -1 if not found
 */
int strrindex(char s[], char t[]) {
    int i = 0, j = 0, k = 0;

    for (; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            return i + k;
        }
    }
    return -1;
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