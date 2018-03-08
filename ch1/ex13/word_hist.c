/**
 * @brief The C Programming Language - 2nd Edition, Exercise 1-13.
 *
 * @file word_hist.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 14/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define IN 1        // inside a word
#define OUT 0       // outside a word
#define MAX_LEN 10  // histogram upper limit

/**
 * @brief Prints histogram of word length in input
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */
int main(int argc, char *agrv[]) {
    int c, nchar, maxf, state;
    int nword[MAX_LEN] = {0};
    
    nchar = 0;
    state = OUT;
    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') {
            if(nchar > MAX_LEN)
                ++nword[MAX_LEN-1];
            else
                ++nword[nchar-1];
            nchar = 0;
            state = OUT;
        }
        else if(state == OUT) {
            // starting a word
            state = IN;
            ++nchar;
        }
        else {
            // still inside a word
            ++nchar;
        }
    }
    // find maximum frequenchary
    maxf = 0;
    for(int i = 0; i < MAX_LEN; ++i)
            if(nword[i] > maxf)
                maxf = nword[i];
    // print histogram
    printf("Word length histogram\n");
    for(int j = maxf; j > 0; --j) {
        for(int i = 0; i < MAX_LEN; ++i) {
            if(nword[i] >= j)
                printf("_ ");
            else
                printf("  ");
        }
        printf("\n");
    }
    for(int i = 0; i < MAX_LEN; ++i)
        printf("%d ", i+1); // x axis lebels
    return 0;
}