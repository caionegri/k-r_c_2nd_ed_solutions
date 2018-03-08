/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-10.
 * 
 * @file lower.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 08/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

int lower(int c);
int getLine(char line[], int maxline);

/**
 * @brief Test function lower().
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                        /* current line lenght */
    char line[MAXLINE] = {'\0'};        /* current input line */
    
    printf("Enter line:\n"); 
    
    while((len = getLine(line, MAXLINE)) > 0) {
        for(int i = 0; i < len; i++)
            printf("%c", lower(line[i]));
    }
 
    return 0;
}

/**
 * @brief Convert @p c to lower case.
 * 
 * @param c input character integer value
 * @return lower case @p c integer value
 */
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
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