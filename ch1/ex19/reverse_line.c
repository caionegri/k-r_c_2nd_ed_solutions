/**
 * @brief The C Programming Language - 2nd Edition, Exercise 1-19.
 *
 * @file reverse_line.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 14/02/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>

#define MAXLINE 100  // maximum input line size

int getLine(char line[], int maxline);
void reverse(char enil[], char line[], int lenght);

/**
 * @brief Reverse input lines.
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len;              // current line lenght
    char line[MAXLINE];   // current input line
    char lineR[MAXLINE];  // input line reversed

    while ((len = getLine(line, MAXLINE)) > 0) {
        reverse(lineR, line, len);
        printf("%s", lineR);
        if (line[len - 2] != '\n' && len == MAXLINE - 1) {
            printf("(OVERFLOW)");
        }
    }
    return 0;
}

/**
 * @brief Read a line and save into s, return length.
 *
 * @param s line
 * @param lim maximum line length
 * @return line lenght
 */
int getLine(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/**
 * @brief Reverse input line and save result.
 *
 * @param enil array reversed
 * @param line array
 * @return void
 */
void reverse(char enil[], char line[], int length) {
    int i = 0, j = 0;
    int creturn = 0, lfeed = 0, eof = 0;
    
    for (i = length - 1; i >= 0; --i) {
        if (line[i] == '\r') {
            creturn = 1;
        } else if (line[i] == '\n') {
            lfeed = 1;
        } else if (line[i] == EOF) {
            eof = 1;
        } else if (line[i] == '\0') {
            ;
        } else {
            enil[j] = line[i];
            ++j;
        }
    }
    if (creturn == 1) {
        enil[j] = '\r';
        ++j;
    }
    if (lfeed == 1) {
        enil[j] = '\n';
        ++j;
    }
    if (eof == 1) {
        enil[j] = EOF;
        ++j;
    }
    enil[j] = '\0';
}
