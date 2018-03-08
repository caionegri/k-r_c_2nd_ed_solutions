/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-4.
 * 
 * @file squeeze2.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 05/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

void squeeze(char s1[], const char s2[]);
int getLine(char line[], int maxline);

/**
 * @brief Test function squeeze().
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                        /* current line lenght */
    char line[MAXLINE] = {'\0'};        /* current input line */
    char rem[MAXLINE] = {'\0'};         /* characters to remove from line */
    
    printf("Enter characters to be removed:\n"); 
    len = getLine(rem, MAXLINE);
    squeeze(rem, "\n"); /* so we don't remove line feed */
    printf("Imput line:\n");

    while((len = getLine(line, MAXLINE)) > 0) {
        squeeze(line, rem);
        printf("%s", line);
    }
 
    return 0;
}

/**
 * @brief Delete all characters in s2 from s1.
 * 
 * @param s1 imput string
 * @param s2 string of characters to be removed
 * @return @c void
 */
void squeeze(char s1[], const char s2[]) {
    int i = 0, j = 0, k = 0;

    for(k = 0; s2[k] != '\0'; k++) {
        for(i = 0, j = 0; s1[i] != '\0'; i++)
            if(s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
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