/**
 * @file word_count.c
 * @brief The C Programming Language - 2nd Edition,
 * Section 1.5.4 example
 */
#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* count lines, words and characters in input */
int main(int argc, char *agrv[]) {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("Lines: %d Words: %d Characters: %d\n", nl, nw, nc);

    return 0;
}