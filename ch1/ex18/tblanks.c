/**
 * @brief The C Programming Language - 2nd Edition, Exercise 1-18
 *
 * @file tblanks.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 14/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define MAXLINE 100  /* maximum input line size */

int getLine(char line[], int maxline);
void removeTBlanks(char lineSB[], char line[]);
int isBlank(char line[]);

/**
 * @brief Remove trailing blanks and tabs from input lines and print non blank lines.
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len;                // current line lenght
    char line[MAXLINE];     // current input line
    char lineNTB[MAXLINE];  // input line with no trailing blanks

    while((len = getLine(line, MAXLINE)) > 0) {
        removeTBlanks(lineNTB, line);
        if(!isBlank(lineNTB))
            printf("%s", lineNTB);
        else 
            printf("(blank line)\n");
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
    int c = '\0', i = 0;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/**
 * @brief Remove trailing blanks and trailing tabs from 'input' 
 * and saves result into 'output'; assume 'output' is big enough.
 * 
 * @param lineSB array without trailing blanks and tabs
 * @param line input array
 * @return @c void
 */
void removeTBlanks(char lineSB[], char line[]) {
    int i = 0, j = 0, last = '\0';

    while(line[j] != '\0') {
        if(line[j] == ' ' && last == ' ')   // trailing blanks
            ;
        else if(line[j] == '\t' && last == '\t')    // trailing tabs
            ;
        else {
            lineSB[i] = line[j];
            ++i;
        }
        last = line[j];
        ++j;
    }
    lineSB[i] = '\0';
}

/**
 * @brief Check if line is blank.
 * 
 * @param line input array
 * @return one for true or zero for false 
 */
int isBlank(char line[]) {
    int i = 0;

    for(i = 0; line[i] != '\0'; ++i) {
        if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return 0;
    }
    return 1;
}
