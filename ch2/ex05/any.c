/**
 * @brief The C Programming Language - 2nd Edition, Exercise 2-5.
 * 
 * @file any.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 06/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>
#include <limits.h>

#define MAXLINE 100 /* maximum input line size */

int any(const char s1[], const char s2[]);
void squeeze(char s1[], const char s2[]);
int getLine(char line[], int maxline);

/**
 * @brief Test function any().
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                        /* current line lenght */
    char line[MAXLINE] = {'\0'};        /* current input line */
    char chars[MAXLINE] = {'\0'};       /* chars to be located */
    int loc = -1;                       /* location of first match */
    
    printf("Enter characters to be located:\n"); 
    len = getLine(chars, MAXLINE);
    squeeze(chars, "\n"); /* so we don't consider line feed */
    printf("Imput line:\n");

    while((len = getLine(line, MAXLINE)) > 0) {
        loc = any(line, chars);
        if(loc == -1)
            printf("Match not found\n");
        else
            printf("Match found in position %d\n", loc);
    }
 
    return 0;
}

/**
 * @brief Return the first location in s1 where any character in s2 occurs,
 * requires <limits.h>.
 * 
 * @param s1 
 * @param s2 
 * @return first index
 * @return -1 if no match found 
 */
int any(const char s1[], const char s2[]) {
    int imin = INT_MAX;

    for(int j = 0; s2[j] != '\0'; j++)
        for(int i = 0; s1[i] != '\0'; i++)
            if(s1[i] == s2[j] && i < imin)
                imin = i;
    if(imin == INT_MAX)
        return -1;
    else
        return imin;
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