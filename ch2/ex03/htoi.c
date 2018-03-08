/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-3.
 * 
 * @file htoi.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 28/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100 /* maximum input line size */

int htoi(const char hex[]);
int getLine(char line[], int maxline);

/**
 * @brief Test function htoi().
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                        /* current line lenght */
    char line[MAXLINE] = {'\0'};        /* current input line */
    
    printf("Enter line with hexadecimal numbers\n"); 
    
    while((len = getLine(line, MAXLINE)) > 0) {
        printf("decimal value: %d\n", htoi(line));
    }
 
    return 0;
}

/**
 * @brief Convert a string of hexadecimal digits @p hex into it's equivalent integer value.
 * Allowable digits are 0 through 9, a through f and A through F.
 * 
 * @param hex input string
 * @return int
 */
int htoi(const char hex[]) {
    int c = '\0';
    enum digits {A = 'a', B, C, D, E, F};
    int n = 0;

    for(int i = 0; (c = tolower(hex[i])) != '\0'; ++i) {
        if(c == 'x')
            c = '0';            /* replacing 'x' with '0' does not alter the value */

        if(c >= '0' && c <= '9') {
            c = c - '0';        /* decimal value */
            n = 16*n + c;       /* summing of digits */
        }
        else if(c >= A && c <= F) {
            c = 10 + c - A;     /* convert to equivalent integer value */
            n = 16*n + c;      
        }
    }

    return n;
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

    for(; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}