/**
 * @brief The C Programming Language - 2nd Edition, Exercise 3-2.
 *
 * @file escape.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 10/03/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

void escape(char s[], const char t[]);
int getLine(char s[], int lim);

/**
 * @brief Test function escape(...).
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                    /* current line lenght */
    char line[MAXLINE] = {'\0'};    /* current input line */
    char lineEsc[MAXLINE] = {'\0'}; /* current output line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        escape(lineEsc, line);
        printf("%s\n", lineEsc);
    }
    return 0;
}

/**
 * @brief Convert escape characters into visible escape sequences.
 * Assume @p s is big enough.
 *
 * @param s output string
 * @param t input string
 * @return @c void
 */
void escape(char s[], const char t[]) {
    int c = '\0';
    int j = 0;

    for (int i = 0; (c = t[i]) != '\0'; i++) {
        switch (c) {
            case '\a':
                s[j++] = '\\';
                s[j++] = 'a';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\v':
                s[j++] = '\\';
                s[j++] = 'v';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            case '\'':
                s[j++] = '\\';
                s[j++] = '\'';
                break;
            case '\"':
                s[j++] = '\\';
                s[j++] = '\"';
                break;
            case '\?':
                s[j++] = '\\';
                s[j++] = '\?';
                break;
            default:
                s[j++] = c;
                break;
        }
    }
    s[j] = '\0';
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