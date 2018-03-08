/**
 * @brief The C Programming Language - 2nd Edition, Exercise 1-12.
 *
 * @file 1word.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 14/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/**
 * @brief Count lines, words and characters in input. Print one word per line.
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */
int main(int argc, char *agrv[]) {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') {
            ++nl;
            putchar(c);
        }
        if(c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if(state == OUT) {
            state = IN;
            ++nw;
            putchar('\n');            
            putchar(c); /* starting a word */
        }
        else {
            putchar(c); /* inside a word */
        }
    }
    printf("Lines: %d Words: %d Characters: %d\n", nl, nw, nc);

    return 0;
}