/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-2.
 * 
 * @file dumb_loop.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 28/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

int getLine(char line[], int maxline);

/**
 * @brief Get and print lines using the modified (dumb) getLine function.
 * 
 * @param argc command line argument count
 * @param argv command line argument vector 
 * @return zero 
 */
int main(int argc, char *argv[]) {
    int len = 0;                    /* current line lenght */
    char line[MAXLINE] = {'\0'};    /* current input line */

    while((len = getLine(line, MAXLINE)) > 0) {
        printf("%s", line);
    }

    return 0;  
}

/**
 * @brief Read a line and save into s, return length 
 * (dumb version using nested if statements instead of logical operators).
 * 
 * @param s line
 * @param lim maximum line length
 * @return line lenght
 */
int getLine(char s[], int lim) {
    int c = '\0', i = 0;

    for(; i < lim - 1; ++i) {
        if((c = getchar()) != EOF)
            if(c != '\n')
                s[i] = c;
            else
                break;
        else
            break;
    }
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}