/**
 * @file detab.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 15 Feb 2018
 * @brief The C Programming Language - 2nd Edition, 
 * Exercise 1-20.
 * @see https://github.com/caionegri 
 */
#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */
#define NCOLS 8     /* number of columns between tab stops */

int getLine(char line[], int maxline);
void replaceTabs(char lineB[], char line[]);

/**
 * @brief Replace tabs in input with the proper amount of blanks to space
 * to the next tab stop and print resulting line.
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                        /* current line lenght */
    char line[MAXLINE] = {'\0'};        /* current input line */
    char lineNoTabs[MAXLINE] = {'\0'};  /* input line with no tabs */

    printf("Enter input to replace tabs with spaces.\n"); 
    printf("Tab stops are set every %d columns\n", NCOLS);
    
    while((len = getLine(line, MAXLINE)) > 0) {
        replaceTabs(lineNoTabs, line);
        printf("%s", lineNoTabs);
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
 * @brief Replace tabs in @p line with the proper amount of blanks to space
 * to the next tab stop, save result in @p lineB.
 * @param lineB array with spaces instead of tabs
 * @param line input array
 * @return @c void
 */
void replaceTabs(char lineB[], char line[]) {
    int i = 0, j = 0;

    while(line[j] != '\0') {
        if(line[j] == '\t') {
            lineB[i] = ' '; /* replace tab with space */
            ++i;
            while(i%NCOLS != 0) {   /* place more spaces until next tab stop */
                lineB[i] = ' ';
                ++i;
            }
        }
        else {
            lineB[i] = line[j];
            ++i;
        }
        ++j;
    }
    lineB[i] = '\0';
}