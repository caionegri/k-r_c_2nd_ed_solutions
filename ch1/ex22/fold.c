/**
 * @file fold.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 23/02/2018
 * @brief The C Programming Language - 2nd Edition, 
 * Exercise 1-22
 * @see https://github.com/caionegri 
 */
#include <stdio.h>

#define MAXLINE 80  /* maximum input line size */
#define MAXCOLS 80  /* maximum input column count */
#define NCOLS 8     /* number of columns between tab stops */

int getLine(char line[], int maxline);
int findFoldPoint(char line[], int ncols, int maxcols);
int findLastBlank(char line[], int index);
void splitLine(char line[], char lineB[], int splPoint);

/**
 * @brief Fold input lines longer than the maximum size. The folding point is
 * at the last blank charcter. When there are no blanks, folding is indicated 
 * with an underscore.
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                    /* current line lenght */
    char line[MAXLINE] = {'\0'};    /* current input line */
    char lineOvr[MAXLINE] = {'\0'}; /* section of line to be folded */
    int ifold = 0;                  /* index where line is folded */

    printf("Tab stops every %d columns\n", NCOLS);
    printf("Max columns: %d\n", MAXCOLS);
    for(int i = 0; i < MAXCOLS; ++i)
        printf("#");
    printf("\n");    

    while((len = getLine(line, MAXLINE)) > 0) {
        ifold = findFoldPoint(line, NCOLS, MAXCOLS);
        ifold = findLastBlank(line, ifold);
        
        if(ifold == len && line[ifold-1] != '\n') {
            /* line is max width with no blanks to fold at, place underscore */
            printf("%s_\n", line);
        }
        else {
            /* fold line at the last blank */
            splitLine(line, lineOvr, ifold);
            printf("%s", line);
            printf("%s", lineOvr);
        }
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
    int c = 0, i = 0;

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
 * @brief Find the point where line reaches the maximum number or columns
 * @param line input array
 * @param length input array lenght
 * @return index
 */
int findFoldPoint(char line[], int ncols, int maxcols) {
    int i = 0, col = 0;

    while(line[i] != '\0' && col < maxcols) {
        if(line[i] == '\t') {
            ++col;
            while((col)%ncols != 0) {   /* count up cols until next tab stop */
                ++col;
            }
        }
        else {
            ++col;
        }
        ++i;
    }
    //printf("cols: %d\n", col);
    return i;
}

/**
 * @brief Find last blank (space or tab) in @p line before index @p i and
 * return it's index.
 * @param line input array
 * @param index starting index
 * @return index of last blank
 * @return starting index if no blanks found
 */
int findLastBlank(char line[], int index) {
    int i = index;

    for(; line[i] != ' ' && line[i] != '\t' && i > 0; --i);

    if(i > 0)
        return i;
    else
        return index;
}

/**
 * @brief Split char array @p line at index @p splPoint placing a line feed
 * and save the rest (starting at @p index) in @p lineB.
 * @param line 
 * @param lineB 
 * @param splPoint 
 */
void splitLine(char line[], char lineB[], int splPoint) {
    int i = splPoint;
    int j = 0;

    for(; line[i] != '\0'; ++i, ++j)
        lineB[j] = line[i];
    lineB[j] = '\0';
    if(line[splPoint-1] != '\n') {
        line[splPoint] = '\n';
        line[splPoint + 1] = '\0';
    }
    else
        line[splPoint] = '\0'; 
}