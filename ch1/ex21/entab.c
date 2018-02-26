/**
 * @file entab.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 19/02/2018
 * @brief The C Programming Language - 2nd Edition, 
 * Exercise 1-21.
 * @see https://github.com/caionegri 
 */
#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */
#define NCOLS 8     /* number of columns between tab stops */

int getLine(char line[], int maxline);
void replaceBlanks(char lineB[], char line[], int ncols);

/**
 * @brief Replace blanks in input with the minimum amount of tabs and blanks
 * to achieve the same spacing and print resulting line. Only works properly for
 * lines below the maximum length.
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                        /* current line lenght */
    char line[MAXLINE] = {'\0'};        /* current input line */
    char lineTabs[MAXLINE] = {'\0'};    /* input line with no tabs */

    printf("Enter input to replace spaces with tabs.\n"); 
    printf("Tab stops are set every %d columns\n", NCOLS);
    
    while((len = getLine(line, MAXLINE)) > 0) {
        replaceBlanks(lineTabs, line, NCOLS);
        printf("%s", lineTabs);
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

/**
 * @brief Replace strings of blanks in @p line with the minimum amount of tabs and
 * blanks to achieve the same spacing.
 * @param lineB array with spaces instead of tabs
 * @param line input array
 * @return @c void
 */
void replaceBlanks(char lineB[], char line[], int ncols) {
    int i = 0, j = 0, nblanks = 0;

    while(line[j] != '\0') {
        if(line[j] == ' ')         
            ++nblanks;
        else {
            while(nblanks > 0) {
                /* (j-nblanks) is the column being filled. 
                 * If the the number of blanks left is greater or equal than
                 * the distance to the next tab stop, place a tab. */
                if(nblanks >= ncols - (j-nblanks)%ncols) {  
                    lineB[i] = '\t';
                    ++i;
                    nblanks -= ncols - (j-nblanks)%ncols;
                }
                /* Place blank since we won't hit the next tab stop */
                else {
                    lineB[i] = ' ';
                    ++i;
                    --nblanks;
                }
            }
            lineB[i] = line[j];
            ++i;
            nblanks = 0;
        }
        ++j;
    }
    lineB[i] = '\0';
}