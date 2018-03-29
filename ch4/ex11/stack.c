/**
 * @brief The C Programming Language - 2nd Edition, Exercise 4-11.
 *
 * @file stack.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 29/03/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/**
 * @brief Push f onto value stack.
 *
 * @param f
 */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/**
 * @brief Pop and return top value from stack.
 *
 * @return double
 */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}