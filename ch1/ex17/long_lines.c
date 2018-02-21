/**
 * @file long_lines.c
 * @brief The C Programming Language - 2nd Edition, 
 * Exercise 1-17
 * @author Caio A N Rocha
 * @date 12 Feb 2018 
 */
#include <stdio.h>

#define MAXLINE 100  // maximum input line size
#define LONGLINE 80  // long line minimum size

int getLine(char line[], int maxline);
void copy(char line[], char from[]);

/**
 * @brief Print only long lines and their length
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len, len_buffer;    // current line lennght
    char line[MAXLINE];     // current input line

    len_buffer = 0;
    while((len = getLine(line, MAXLINE)) > 0) {
        // check for line overflow and add to lenght buffer or reset
        if(line[len-1] == '\n') {
            // if line is long, print line (last characters)
            if(len_buffer + len >= LONGLINE)
                printf("[%dc]: %s", len_buffer+len, line);
            len_buffer = 0;            
        }
        else {
            len_buffer += len;
        }
    }
    return 0;
}

/**
 * @brief Read a line and save into s, return length 
 * @param s line
 * @param lim maximum line length
 * @return line lenght
 */
int getLine(char s[], int lim) {
    int c, i;

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
 * @brief Copy 'from' into 'to'; assume 'to' is big enough 
 * @param to output array
 * @param from input array
 * @return @c void
 */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}