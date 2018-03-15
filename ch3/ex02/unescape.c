/**
 * @brief The C Programming Language - 2nd Edition, Exercise 3-2.
 *
 * @file unescape.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 10/03/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

void unescape(char s[], const char t[]);
int getLine(char s[], int lim);

/**
 * @brief Test function unescape(...).
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
        unescape(lineEsc, line);
        printf("%s", lineEsc);
    }
    return 0;
}

/**
 * @brief Convert escape sequences into respective characters.
 *
 * @param s output string
 * @param t input string
 * @return @c void
 */
void unescape(char s[], const char t[]) {
    int c = '\0';
    int esc = 0; /* 1 if last char was '//', 0 if not */
    int j = 0;

    for (int i = 0; (c = t[i]) != '\0'; i++) {
        switch (esc) {
            case 0:
                switch (c) {
                    case '\\':
                        esc = 1;
                        break;
                    default:
                        s[j++] = c;
                        break;
                }
                break;
            case 1:
                esc = 0;
                switch (c) {
                    case '\\':
                        esc = 1;
                        s[j++] = '\\';
                        break;
                    case 'a':
                        s[j++] = '\a';
                        break;
                    case 'b':
                        s[j++] = '\b';
                        break;
                    case 'f':
                        s[j++] = '\f';
                        break;
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 'r':
                        s[j++] = '\r';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    case 'v':
                        s[j++] = '\v';
                        break;
                    case '\'':
                        s[j++] = '\'';
                        break;
                    case '\"':
                        s[j++] = '\"';
                        break;
                    case '\?':
                        s[j++] = '\?';
                        break;
                    default:
                        s[j++] = c;
                        break;
                }
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