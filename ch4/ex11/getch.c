/**
 * @brief The C Programming Language - 2nd Edition, Exercise 4-11.
 *
 * @file getch.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 29/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define BUFFSIZE 100

int buf[BUFFSIZE] = {'\0'}; /* buffer for ungetch */
int bufp = 0;               /* next ferr position in buf */

/**
 * @brief Get a (possibly pushed back) character.
 *
 * @return int
 */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

/**
 * @brief Push character back on input.
 *
 * @param c
 */
void ungetch(int c) {
    if (bufp >= BUFFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}