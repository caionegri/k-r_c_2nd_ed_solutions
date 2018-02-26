/**
 * @file nocomment.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 24/02/2018
 * @brief The C Programming Language - 2nd Edition, 
 * Exercise 1-23.
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */
#define IN 1        /* inside a comment */
#define OUT 0       /* outside a comment */

int getLine(char line[], int maxline);

/**
 * @brief 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                    /* current line lenght */
    char line[MAXLINE] = {'\0'};    /* current input line */
    char lineNC[MAXLINE] = {'\0'};  /* output line with no comments */    
    int last_char = '\0';           /* last input character */
    int state = 0;                  /* current state */
    int last_state = 0;             /* previous state */

    printf("Enter C code to remove comments.\n"); 
    
    while((len = getLine(line, MAXLINE)) > 0) {
        int j = 0;
        for(int i = 0; i < len; ++i) {
            if(state == IN) {
                if(last_char == '*' && line[i] == '/')
                    state = OUT;    /* comment ended */
                last_state = IN;
            }
            else {  /* state == OUT */
                if(line[i] == '/')
                    ;   /* might be a comment start, wait for next character */
                else if(last_char == '/' && line[i] == '*')
                    state = IN;     /* comment started */
                else {
                    if(last_char == '/' && last_state == OUT) {
                        /* '/' was not part of a comment sequence, print it */
                        lineNC[j] = '/';
                        ++j;
                    }
                    lineNC[j] = line[i];
                    ++j;
                }
                last_state = OUT;                
            }
            last_char = line[i];
        }
        lineNC[j] = '\0';
        printf("%s", lineNC);
    }
    return 0;
}

/**
 * @brief Read a line and save into s, return length.
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